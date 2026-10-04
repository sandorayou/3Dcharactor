"""Add owner-approved Twitch credentials locally to an unsigned personal IPA."""
import configparser
import json
import os
from pathlib import Path
import re
import uuid
import zipfile
from urllib.request import urlopen


def main():
    root = Path(__file__).resolve().parents[1]
    profiles = Path(os.environ['APPDATA']) / 'obs-studio/basic/profiles'
    candidates = []
    for profile in profiles.iterdir():
        ini = configparser.ConfigParser(strict=False, interpolation=None)
        ini.read(profile / 'basic.ini', encoding='utf-8-sig')
        if ini.get('Twitch', 'Name', fallback='').lower() == 'sandareyou':
            candidates.append(profile)
    if len(candidates) != 1:
        raise RuntimeError('Expected one OBS profile for sandareyou')
    service = json.loads((candidates[0] / 'service.json').read_text(encoding='utf-8-sig'))
    if service.get('settings', {}).get('service') != 'Twitch':
        raise RuntimeError('Expected Twitch profile')
    key = service['settings'].get('key', '').split('?', 1)[0]
    if not re.fullmatch(r'live_[A-Za-z0-9_]+', key):
        raise RuntimeError('Saved Twitch credential is unavailable')
    with urlopen('https://ingest.twitch.tv/ingests', timeout=15) as response:
        ingests = json.load(response)['ingests']
    template = next(x['url_template'] for x in ingests if 'Tokyo' in x['name'])
    if not re.fullmatch(r'rtmp://[a-z0-9.-]+/app/\{stream_key\}', template):
        raise RuntimeError('Unexpected Twitch endpoint')
    run = json.loads((root / 'Builds/iOS-WindowsPort/github-run.json').read_text(encoding='utf-8-sig'))
    source = root / 'Builds/iOS-IPA' / str(run['databaseId']) / 'MyProject5-unsigned.ipa'
    output = source.with_name('MyProject5-sandareyou-unsigned.ipa')
    config = dict(channel='sandareyou', server=template.replace('/{stream_key}', ''),
                  key=key, revision=uuid.uuid4().hex)
    with zipfile.ZipFile(source) as original:
        app_roots = [x[:-len('Info.plist')] for x in original.namelist()
                     if re.fullmatch(r'Payload/[^/]+\.app/Info\.plist', x)]
        if len(app_roots) != 1:
            raise RuntimeError('Expected one application')
        config_name = app_roots[0] + 'personal-stream.json'
        with zipfile.ZipFile(output, 'w', zipfile.ZIP_DEFLATED) as personal:
            for item in original.infolist():
                if item.filename != config_name:
                    personal.writestr(item, original.read(item))
            personal.writestr(config_name, json.dumps(config).encode())
    with zipfile.ZipFile(output) as check:
        if check.testzip() is not None:
            raise RuntimeError('IPA archive verification failed')
        if json.loads(check.read(config_name)) != config:
            raise RuntimeError('Personal settings verification failed')
    print('Verified personal unsigned IPA for sandareyou: ' + str(output))


if __name__ == '__main__':
    main()
