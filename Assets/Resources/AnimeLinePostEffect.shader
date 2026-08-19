Shader "Hidden/RealtimeBodyTracking/AnimeLinePostEffect"
{
    Properties
    {
        _MainTex ("Texture", 2D) = "white" {}
        _LineColor ("Line Color", Color) = (0.008, 0.01, 0.016, 0.92)
        _Thickness ("Thickness", Float) = 1
        _Threshold ("Threshold", Float) = 0.115
        _Softness ("Softness", Float) = 0.07
        _Strength ("Strength", Float) = 0.82
    }
    SubShader
    {
        Cull Off ZWrite Off ZTest Always
        Pass
        {
            CGPROGRAM
            #pragma vertex vert_img
            #pragma fragment frag
            #include "UnityCG.cginc"

            sampler2D _MainTex;
            float4 _MainTex_TexelSize;
            float4 _LineColor;
            float _Thickness;
            float _Threshold;
            float _Softness;
            float _Strength;

            fixed4 frag(v2f_img input) : SV_Target
            {
                float2 stepSize = _MainTex_TexelSize.xy * _Thickness;
                float3 center = tex2D(_MainTex, input.uv).rgb;
                float3 left = tex2D(_MainTex, input.uv - float2(stepSize.x, 0)).rgb;
                float3 right = tex2D(_MainTex, input.uv + float2(stepSize.x, 0)).rgb;
                float3 down = tex2D(_MainTex, input.uv - float2(0, stepSize.y)).rgb;
                float3 up = tex2D(_MainTex, input.uv + float2(0, stepSize.y)).rgb;
                float3 diagonalA = tex2D(_MainTex, input.uv + stepSize).rgb;
                float3 diagonalB = tex2D(_MainTex, input.uv - stepSize).rgb;

                float horizontal = length(right - left);
                float vertical = length(up - down);
                float diagonal = length(diagonalA - diagonalB) * .65;
                float contrast = max(max(horizontal, vertical), diagonal);
                float edge = smoothstep(_Threshold, _Threshold + _Softness, contrast);

                // Preserve broad painted shading while darkening only narrow color borders.
                float localDifference = max(length(center - left), length(center - up));
                edge *= smoothstep(_Threshold * .55, _Threshold + _Softness, localDifference);
                edge = saturate(edge * _Strength * _LineColor.a);
                return fixed4(lerp(center, _LineColor.rgb, edge), 1);
            }
            ENDCG
        }
    }
}
