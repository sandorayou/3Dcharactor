import { defineConfig } from 'vite';

export default defineConfig({
  base: './',
  publicDir: process.env.WEB_PWA_PUBLIC_DIR || 'public',
  build: {
    target: 'es2022',
    assetsInlineLimit: 0,
    outDir: process.env.WEB_PWA_DIST_DIR || 'dist',
    rollupOptions: { input: 'index.html' },
  },
  server: { https: false },
});
