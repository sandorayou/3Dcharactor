using UnityEngine;

namespace RealtimeBodyTracking.Boxing
{
    public sealed class SparringGame : MonoBehaviour
    {
        const float RoundLength = 60f;
        Animator player;
        Transform leftHand, rightHand, leftElbow, rightElbow, leftShoulder, rightShoulder, head, chest;
        Vector3 previousLeft, previousRight;
        bool handsReady;
        float leftPunchCooldown, rightPunchCooldown;
        float playerHealth = 100f, npcHealth = 100f, playerStamina = 100f;
        float roundTime = RoundLength, npcNextAttack, npcAttackStarted, npcHitTime;
        bool npcAttacking, npcHitApplied;
        int npcAttackHeight;
        Transform npcRoot, npcLeftGlove, npcRightGlove, npcHead, npcBody;
        string eventText = "SPARRING START";
        float eventUntil;
        GUIStyle titleStyle, hudStyle, centerStyle;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
        static void Install()
        {
            if (FindObjectOfType<SparringGame>() == null)
                new GameObject("Sparring Game").AddComponent<SparringGame>();
        }

        void Start()
        {
            player = FindTrackedAnimator();
            if (player == null) { enabled = false; Debug.LogWarning("SparringGame: Humanoid Animator not found."); return; }
            CacheBones();
            CreateNpc();
            npcNextAttack = Time.time + 2f;
            eventUntil = Time.time + 1.5f;
        }

        static Animator FindTrackedAnimator()
        {
            var driver = FindObjectOfType<HumanoidPoseDriver>();
            if (driver != null)
            {
                var candidates = driver.GetComponentsInChildren<Animator>(true);
                foreach (var candidate in candidates) if (candidate.isHuman) return candidate;
            }
            foreach (var candidate in FindObjectsOfType<Animator>()) if (candidate.isHuman) return candidate;
            return null;
        }

        void CacheBones()
        {
            leftHand = player.GetBoneTransform(HumanBodyBones.LeftHand);
            rightHand = player.GetBoneTransform(HumanBodyBones.RightHand);
            leftElbow = player.GetBoneTransform(HumanBodyBones.LeftLowerArm);
            rightElbow = player.GetBoneTransform(HumanBodyBones.RightLowerArm);
            leftShoulder = player.GetBoneTransform(HumanBodyBones.LeftUpperArm);
            rightShoulder = player.GetBoneTransform(HumanBodyBones.RightUpperArm);
            head = player.GetBoneTransform(HumanBodyBones.Head);
            chest = player.GetBoneTransform(HumanBodyBones.Chest) ?? player.GetBoneTransform(HumanBodyBones.Spine);
        }

        void CreateNpc()
        {
            var origin = chest.position + player.transform.forward * 2.25f;
            npcRoot = new GameObject("Sparring Partner").transform;
            npcRoot.position = new Vector3(origin.x, player.transform.position.y, origin.z);
            npcRoot.rotation = Quaternion.LookRotation((chest.position - npcRoot.position).normalized, Vector3.up);
            npcBody = Part("NPC Body", PrimitiveType.Capsule, npcRoot, new Vector3(0, 1.25f, 0), new Vector3(.62f, .8f, .48f), new Color(.8f, .12f, .18f));
            npcHead = Part("NPC Head", PrimitiveType.Sphere, npcRoot, new Vector3(0, 2.35f, 0), Vector3.one * .58f, new Color(.9f, .65f, .5f));
            npcLeftGlove = Part("NPC Left Glove", PrimitiveType.Sphere, npcRoot, new Vector3(-.4f, 1.85f, -.35f), Vector3.one * .35f, new Color(.08f, .12f, .18f));
            npcRightGlove = Part("NPC Right Glove", PrimitiveType.Sphere, npcRoot, new Vector3(.4f, 1.85f, -.35f), Vector3.one * .35f, new Color(.08f, .12f, .18f));
        }

        static Transform Part(string name, PrimitiveType primitive, Transform parent, Vector3 localPosition, Vector3 scale, Color color)
        {
            var part = GameObject.CreatePrimitive(primitive).transform;
            part.name = name; part.SetParent(parent); part.localPosition = localPosition; part.localRotation = Quaternion.identity; part.localScale = scale;
            Destroy(part.GetComponent<Collider>());
            part.GetComponent<Renderer>().material.color = color;
            return part;
        }

        void Update()
        {
            if (!AllBonesAvailable()) return;
            roundTime = Mathf.Max(0f, roundTime - Time.deltaTime);
            playerStamina = Mathf.Min(100f, playerStamina + 18f * Time.deltaTime);
            leftPunchCooldown -= Time.deltaTime; rightPunchCooldown -= Time.deltaTime;
            DetectPlayerPunch(leftHand, leftShoulder, ref previousLeft, ref leftPunchCooldown, 0);
            DetectPlayerPunch(rightHand, rightShoulder, ref previousRight, ref rightPunchCooldown, 1);
            UpdateNpc();
            if (roundTime <= 0f || playerHealth <= 0f || npcHealth <= 0f) ResetRound();
        }

        bool AllBonesAvailable() => leftHand && rightHand && leftElbow && rightElbow && leftShoulder && rightShoulder && head && chest;

        void DetectPlayerPunch(Transform hand, Transform shoulder, ref Vector3 previous, ref float cooldown, int handIndex)
        {
            var current = hand.position;
            if (!handsReady) { previous = current; if (handIndex == 1) handsReady = true; return; }
            var velocity = (current - previous) / Mathf.Max(Time.deltaTime, .001f);
            var reach = Vector3.Distance(current, shoulder.position);
            var armLength = Vector3.Distance(shoulder.position, handIndex == 0 ? leftElbow.position : rightElbow.position) +
                            Vector3.Distance(handIndex == 0 ? leftElbow.position : rightElbow.position, current);
            var towardNpc = Vector3.Dot(velocity.normalized, (npcHead.position - current).normalized);
            if (cooldown <= 0f && velocity.magnitude > .75f && towardNpc > .35f && reach > armLength * .72f && playerStamina >= 8f)
            {
                playerStamina -= 8f;
                cooldown = .4f;
                ResolvePlayerSweep(previous, current);
            }
            previous = current;
        }

        void ResolvePlayerSweep(Vector3 start, Vector3 end)
        {
            const float gloveRadius = .12f;
            var headHit = BoxingHitGeometry.PointSegmentDistance(npcHead.position, start, end) < .38f + gloveRadius;
            var bodyHit = BoxingHitGeometry.PointSegmentDistance(npcBody.position, start, end) < .5f + gloveRadius;
            if (!headHit && !bodyHit) return;
            npcHealth = Mathf.Max(0f, npcHealth - (headHit ? 12f : 8f));
            ShowEvent(headHit ? "CLEAN HEAD SHOT" : "BODY SHOT");
        }

        void UpdateNpc()
        {
            if (!npcAttacking && Time.time >= npcNextAttack)
            {
                npcAttacking = true; npcHitApplied = false; npcAttackStarted = Time.time; npcHitTime = Time.time + .48f;
                npcAttackHeight = Random.value < .65f ? 1 : 0;
            }
            if (!npcAttacking) return;
            var elapsed = Time.time - npcAttackStarted;
            var phase = Mathf.Clamp01(elapsed / .48f);
            var returnPhase = Mathf.Clamp01((elapsed - .48f) / .3f);
            var glove = npcRightGlove;
            var guard = npcRoot.TransformPoint(new Vector3(.4f, 1.85f, -.35f));
            var target = npcAttackHeight == 1 ? head.position : chest.position;
            glove.position = elapsed <= .48f ? Vector3.Lerp(guard, target, Mathf.SmoothStep(0, 1, phase)) : Vector3.Lerp(target, guard, returnPhase);
            if (!npcHitApplied && Time.time >= npcHitTime)
            {
                npcHitApplied = true;
                ResolveNpcPunch(glove.position, npcAttackHeight == 1 ? head.position : chest.position);
            }
            if (elapsed >= .8f)
            {
                npcAttacking = false; npcNextAttack = Time.time + Random.Range(.75f, 1.55f);
                glove.localPosition = new Vector3(.4f, 1.85f, -.35f);
            }
        }

        void ResolveNpcPunch(Vector3 glove, Vector3 target)
        {
            if (IsBlocked(glove))
            {
                playerStamina = Mathf.Max(0f, playerStamina - 14f);
                ShowEvent("BLOCK");
                return;
            }
            var radius = npcAttackHeight == 1 ? .2f : .28f;
            if (Vector3.Distance(glove, target) <= radius)
            {
                playerHealth = Mathf.Max(0f, playerHealth - (npcAttackHeight == 1 ? 12f : 8f));
                ShowEvent(npcAttackHeight == 1 ? "HEAD HIT" : "BODY HIT");
            }
        }

        bool IsBlocked(Vector3 attackPoint)
        {
            const float fistDefenseRadius = .16f;
            const float armDefenseRadius = .11f;
            if (Vector3.Distance(attackPoint, leftHand.position) <= fistDefenseRadius + .16f ||
                Vector3.Distance(attackPoint, rightHand.position) <= fistDefenseRadius + .16f) return true;
            return BoxingHitGeometry.PointSegmentDistance(attackPoint, leftElbow.position, leftHand.position) <= armDefenseRadius + .16f ||
                   BoxingHitGeometry.PointSegmentDistance(attackPoint, rightElbow.position, rightHand.position) <= armDefenseRadius + .16f;
        }

        void ShowEvent(string text) { eventText = text; eventUntil = Time.time + .65f; }

        void ResetRound()
        {
            ShowEvent(playerHealth > npcHealth ? "ROUND WIN" : "ROUND LOST");
            playerHealth = npcHealth = playerStamina = 100f; roundTime = RoundLength;
            npcAttacking = false; npcNextAttack = Time.time + 2f;
        }

        void OnDrawGizmos()
        {
            if (!Application.isPlaying || !AllBonesAvailable()) return;
            Gizmos.color = new Color(0f, .8f, 1f, .7f);
            Gizmos.DrawWireSphere(leftHand.position, .16f); Gizmos.DrawWireSphere(rightHand.position, .16f);
            Gizmos.color = new Color(.1f, 1f, .35f, .7f);
            DrawArm(leftElbow.position, leftHand.position, .11f); DrawArm(rightElbow.position, rightHand.position, .11f);
        }

        static void DrawArm(Vector3 start, Vector3 end, float radius)
        {
            Gizmos.DrawWireSphere(start, radius); Gizmos.DrawWireSphere(end, radius); Gizmos.DrawLine(start, end);
        }

        void EnsureStyles()
        {
            if (titleStyle != null) return;
            titleStyle = new GUIStyle(GUI.skin.label) { fontSize = 26, fontStyle = FontStyle.Bold, alignment = TextAnchor.MiddleCenter, normal = { textColor = Color.white } };
            hudStyle = new GUIStyle(titleStyle) { fontSize = 17 };
            centerStyle = new GUIStyle(titleStyle) { fontSize = 36 };
        }

        void OnGUI()
        {
            if (!enabled) return;
            EnsureStyles();
            GUI.Label(new Rect(0, 8, Screen.width, 36), "MOTION CLASH  /  SPARRING", titleStyle);
            DrawBar(30, 52, Screen.width * .38f, 22, playerHealth / 100f, new Color(.05f, .65f, 1f));
            DrawBar(Screen.width * .62f, 52, Screen.width * .38f - 30, 22, npcHealth / 100f, new Color(1f, .18f, .25f));
            DrawBar(30, 80, Screen.width * .28f, 9, playerStamina / 100f, new Color(1f, .75f, .08f));
            GUI.Label(new Rect(Screen.width / 2 - 50, 48, 100, 30), Mathf.CeilToInt(roundTime).ToString("00"), hudStyle);
            if (Time.time < eventUntil) GUI.Label(new Rect(0, Screen.height * .25f, Screen.width, 55), eventText, centerStyle);
            GUI.Label(new Rect(0, Screen.height - 32, Screen.width, 24), "拳＝攻撃判定　拳＋前腕＝防御判定", hudStyle);
        }

        static void DrawBar(float x, float y, float width, float height, float ratio, Color color)
        {
            var original = GUI.color; GUI.color = new Color(.08f, .09f, .12f); GUI.DrawTexture(new Rect(x, y, width, height), Texture2D.whiteTexture);
            GUI.color = color; GUI.DrawTexture(new Rect(x + 2, y + 2, (width - 4) * Mathf.Clamp01(ratio), height - 4), Texture2D.whiteTexture); GUI.color = original;
        }
    }
}
