using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using VRM;

namespace RealtimeBodyTracking
{
    [DefaultExecutionOrder(10000)]
    public sealed class ManualAvatarController : MonoBehaviour
    {
        private const string SpeedParameter = "Speed";
        private const string ActionParameter = "Action";
        private const string FlyingParameter = "IsFlying";

        [SerializeField] private float moveSpeed = 2.25f;
        [SerializeField] private float verticalMoveSpeed = .8f;
        [SerializeField] private bool placementLocked;
        [SerializeField, Tooltip("Live state")] private int currentAction;
        [SerializeField, Tooltip("Live state")] private string currentExpression = "None";

        private Animator animator;
        private RuntimeAnimatorController motionController;
        private HumanoidPoseDriver poseDriver;
        private VRMBlendShapeProxy blendShapeProxy;
        private Vector3 manualOffset;
        private Vector3 lastAppliedOffset;
        private bool locomotionActive;
        private bool actionActive;
        private bool manualOverrideActive;

        public bool ShouldBlockTracking => locomotionActive || actionActive;
        public bool PlacementLocked => placementLocked;
        public Vector3 PlacementOffset => manualOffset;
        public bool ManualExpressionActive => currentExpression != "None";

        public void Initialize(Animator target, HumanoidPoseDriver driver)
        {
            animator = target;
            if (animator == null) return;
            motionController = Resources.Load<RuntimeAnimatorController>("VTuberAnimator");
            poseDriver = driver;
            blendShapeProxy = animator.GetComponentInChildren<VRMBlendShapeProxy>(true);
            animator.applyRootMotion = false;
        }

        private void Update()
        {
            if (animator == null) return;
            HandleWaistCoordinateToggle();
            HandlePlacementToggle();
            HandleMovement();
            HandleMotions();
            HandleExpressions();
            SynchronizeManualOverride();
        }

        private void HandleWaistCoordinateToggle()
        {
            if (!ControlHeld() || !Input.GetKeyDown(KeyCode.KeypadDivide)) return;
            poseDriver?.ToggleWaistCoordinateLock();
        }

        private void LateUpdate()
        {
            if (animator == null) return;
            if (placementLocked)
            {
                // HumanoidPoseDriver already includes PlacementOffset in its recorded
                // origin calculation while this mode is active.
                lastAppliedOffset = manualOffset;
            }
            else
            {
                var trackedPosition = animator.transform.position - lastAppliedOffset;
                animator.transform.position = trackedPosition + manualOffset;
                lastAppliedOffset = manualOffset;
            }
            if (ManualExpressionActive) ApplyManualExpression();
        }

        private void HandlePlacementToggle()
        {
            if (!ControlHeld() || !Input.GetKeyDown(KeyCode.Keypad9)) return;
            placementLocked = !placementLocked;
            if (placementLocked)
            {
                poseDriver?.RebaseBodyTracking();
            }
            else
            {
                manualOffset = Vector3.zero;
                lastAppliedOffset = Vector3.zero;
                poseDriver?.RebaseBodyTracking();
            }
        }

        private void HandleMovement()
        {
            if (!ControlHeld())
            {
                StopLocomotion();
                return;
            }

            var direction = Vector3.zero;
            if (Input.GetKey(KeyCode.LeftArrow)) direction += Vector3.left;
            if (Input.GetKey(KeyCode.RightArrow)) direction += Vector3.right;
            if (Input.GetKey(KeyCode.UpArrow) || Input.GetKey(KeyCode.PageUp))
                direction += CameraPlanarForward();
            if (Input.GetKey(KeyCode.DownArrow) || Input.GetKey(KeyCode.PageDown))
                direction -= CameraPlanarForward();
            if (Input.GetKey(KeyCode.KeypadPlus) || Input.GetKey(KeyCode.Equals)) direction += Vector3.up;
            if (Input.GetKey(KeyCode.KeypadMinus) || Input.GetKey(KeyCode.Minus)) direction += Vector3.down;

            if (direction.sqrMagnitude < .0001f)
            {
                StopLocomotion();
                return;
            }

            // Direction input always takes control from a one-shot/manual action.
            // Previously actionActive swallowed Ctrl+Arrow indefinitely.
            if (actionActive)
            {
                StopAllCoroutines();
                actionActive = false;
            }

            if (placementLocked)
            {
                var lockedStartingLocomotion = !locomotionActive;
                locomotionActive = true;
                EnsureMotionController();
                var delta = direction.normalized *
                            (Mathf.Abs(direction.y) > .5f ? verticalMoveSpeed : moveSpeed) * Time.deltaTime;
                manualOffset += delta;
                animator.transform.position += delta;
                animator.SetFloat(SpeedParameter, 1f);
                animator.SetBool(FlyingParameter, Mathf.Abs(direction.y) > .5f);
                if (lockedStartingLocomotion)
                    animator.Play(Mathf.Abs(direction.y) > .5f ? "Idle" : "Run", 0, 0f);
                if (Mathf.Abs(direction.y) < .5f)
                    animator.transform.rotation = Quaternion.LookRotation(direction.normalized, Vector3.up);
                return;
            }

            var startingLocomotion = !locomotionActive;
            locomotionActive = true;
            EnsureMotionController();
            manualOffset += direction.normalized *
                            (Mathf.Abs(direction.y) > .5f ? verticalMoveSpeed : moveSpeed) * Time.deltaTime;
            animator.SetFloat(SpeedParameter, 1f);
            animator.SetBool(FlyingParameter, Mathf.Abs(direction.y) > .5f);
            if (startingLocomotion)
                animator.Play(Mathf.Abs(direction.y) > .5f ? "Idle" : "Run", 0, 0f);
            if (Mathf.Abs(direction.y) < .5f)
                animator.transform.rotation = Quaternion.LookRotation(direction.normalized, Vector3.up);
        }

        private void StopLocomotion()
        {
            if (!locomotionActive) return;
            locomotionActive = false;
            if (animator == null) return;
            animator.SetFloat(SpeedParameter, 0f);
            animator.SetBool(FlyingParameter, false);
            if (!actionActive) PlayAction(0);
        }

        private void HandleMotions()
        {
            if (!ControlHeld() || Input.GetKey(KeyCode.LeftAlt) || Input.GetKey(KeyCode.RightAlt)) return;
            if (Input.GetKeyDown(KeyCode.Keypad0))
            {
                StopAllCoroutines();
                actionActive = false;
                PlayAction(0);
                return;
            }
            if (Input.GetKeyDown(KeyCode.Keypad1)) StartCoroutine(PlaySequence(1, 2));
            if (Input.GetKeyDown(KeyCode.Keypad2)) StartAction(3);
            if (Input.GetKeyDown(KeyCode.Keypad3)) StartAction(4);
            if (Input.GetKeyDown(KeyCode.Keypad4)) StartAction(5);
            if (Input.GetKeyDown(KeyCode.Keypad5)) StartAction(6);
            if (Input.GetKeyDown(KeyCode.Keypad6)) StartCoroutine(PlaySequence(7));
        }

        private void StartAction(int action)
        {
            if (actionActive) return;
            actionActive = true;
            PlayAction(action);
        }

        private IEnumerator PlaySequence(params int[] actions)
        {
            if (actionActive) yield break;
            actionActive = true;
            foreach (var action in actions)
            {
                PlayAction(action);
                yield return new WaitForSeconds(CurrentClipLength());
            }
            actionActive = false;
            PlayAction(0);
        }

        private void PlayAction(int action)
        {
            EnsureMotionController();
            currentAction = action;
            animator.SetInteger(ActionParameter, action);
            var state = ActionState(action);
            if (!string.IsNullOrEmpty(state))
            {
                animator.Play(state, 0, 0f);
                animator.Update(0f);
            }
        }

        private void HandleExpressions()
        {
            if (!AltHeld()) return;
            if (Input.GetKeyDown(KeyCode.Keypad1)) currentExpression = "None";
            if (Input.GetKeyDown(KeyCode.Keypad2)) currentExpression = "Joy";
            if (Input.GetKeyDown(KeyCode.Keypad3)) currentExpression = "Angry";
            if (Input.GetKeyDown(KeyCode.Keypad4)) currentExpression = "Sorrow";
            if (Input.GetKeyDown(KeyCode.Keypad5)) currentExpression = "Jitome";
            if (Input.GetKeyDown(KeyCode.Keypad6)) currentExpression = "Smug";
            if (Input.GetKeyDown(KeyCode.Keypad7)) currentExpression = "Blush";
            if (Input.GetKeyDown(KeyCode.Keypad8)) currentExpression = "Worried";
            if (Input.GetKeyDown(KeyCode.Keypad9)) currentExpression = "Crying";
            ApplyManualExpression();
        }

        private void ApplyManualExpression()
        {
            if (blendShapeProxy == null) return;
            var values = new Dictionary<BlendShapeKey, float>
            {
                [BlendShapeKey.CreateFromPreset(BlendShapePreset.Joy)] = 0f,
                [BlendShapeKey.CreateFromPreset(BlendShapePreset.Angry)] = 0f,
                [BlendShapeKey.CreateFromPreset(BlendShapePreset.Sorrow)] = 0f,
                [BlendShapeKey.CreateUnknown("Jitome")] = 0f,
                [BlendShapeKey.CreateUnknown("Smug")] = 0f,
                [BlendShapeKey.CreateUnknown("Blush")] = 0f,
                [BlendShapeKey.CreateUnknown("Worried")] = 0f,
                [BlendShapeKey.CreateUnknown("Crying")] = 0f,
            };
            if (currentExpression == "Joy") values[BlendShapeKey.CreateFromPreset(BlendShapePreset.Joy)] = 1f;
            else if (currentExpression == "Angry") values[BlendShapeKey.CreateFromPreset(BlendShapePreset.Angry)] = 1f;
            else if (currentExpression == "Sorrow") values[BlendShapeKey.CreateFromPreset(BlendShapePreset.Sorrow)] = 1f;
            else if (currentExpression != "None") values[BlendShapeKey.CreateUnknown(currentExpression)] = 1f;
            blendShapeProxy.SetValues(values);
        }

        private void EnsureMotionController()
        {
            animator.enabled = true;
            if (motionController != null && animator.runtimeAnimatorController != motionController)
                animator.runtimeAnimatorController = motionController;
        }

        private void SynchronizeManualOverride()
        {
            var active = ShouldBlockTracking;
            if (active == manualOverrideActive) return;
            manualOverrideActive = active;
            if (active) return;

            // The motion controller's Idle state still writes every humanoid bone.
            // Remove it completely, but keep Animator enabled: the humanoid tracking
            // driver requires the live Animator to resolve and update the body bones.
            animator.runtimeAnimatorController = null;
            animator.enabled = true;
            poseDriver?.ResumeAfterManualMotion();
        }

        private float CurrentClipLength()
        {
            var clips = animator.GetCurrentAnimatorClipInfo(0);
            return clips.Length > 0 && clips[0].clip != null ? clips[0].clip.length : 2f;
        }

        private Vector3 CameraPlanarForward()
        {
            var camera = Camera.main;
            if (camera == null) return Vector3.forward;
            var forward = camera.transform.forward;
            forward.y = 0f;
            return forward.sqrMagnitude > .0001f ? forward.normalized : Vector3.forward;
        }

        private static string ActionState(int action)
        {
            switch (action)
            {
                case 0: return "Idle";
                case 1: return "Stumble";
                case 2: return "StandUp";
                case 3: return "Dance";
                case 4: return "Boxing";
                case 5: return "Wave";
                case 6: return "Point";
                case 7: return "Jump";
                default: return null;
            }
        }

        private static bool ControlHeld() =>
            Input.GetKey(KeyCode.LeftControl) || Input.GetKey(KeyCode.RightControl);

        private static bool AltHeld() =>
            Input.GetKey(KeyCode.LeftAlt) || Input.GetKey(KeyCode.RightAlt);
    }
}
