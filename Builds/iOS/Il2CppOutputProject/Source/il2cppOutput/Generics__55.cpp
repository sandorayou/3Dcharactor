#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2)
	{
		void* params[2] = { &p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3;
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1*, T2, T3*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2, T3* p3)
	{
		void* params[3] = { p1, &p2, p3 };
		method->invoker_method(methodPtr, method, obj, params, params[2]);
	}
};
template <typename R, typename T1>
struct InvokerFuncInvoker1;
template <typename R, typename T1>
struct InvokerFuncInvoker1<R, T1*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		R ret;
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

struct Dictionary_2_t5C8F46F5D57502270DD9E1DA8303B23C7FE85588;
struct EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9;
struct Func_2_t781E8579E9FF2D1F9E663A289445D85212CBE782;
struct ShaderInfoStorage_1_t32194748F3ED0F5527B4E31A28D04606FAEE539A;
struct ShortEnumEqualityComparer_1_t93E714E73A6CDB76D15D51942E3800AB3E57DFF6;
struct SpanAction_2_t65B015FEFE1F64814AC2EFA0E19A38B1CFC53178;
struct SpanAction_2_t84FDFFEECCC96A9A407DCB490E60340E38185947;
struct SpanAction_2_t02885A83F58261D2CFDC8FFBBCD7C8ECAF105A7B;
struct SpanAction_2_t5907E59A3FE410EE3FC9FC29F5E9418DF5894C8B;
struct BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80;
struct BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B;
struct BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515;
struct BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A;
struct BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8;
struct BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F;
struct BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A;
struct Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389;
struct Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259;
struct ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2;
struct CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57;
struct CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB;
struct GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct RowU5BU5D_t325BC67027D8D4C3AB8E0375B85F72BEB5ADA376;
struct BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2;
struct BatchDrawCommand_t9DAB9B739DA9EBC6B1BB0D2DD51AF65B12F66BF0;
struct BatchDrawRange_t736D745E918A629658B80A0F7D2D17DAFBA6172F;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct Delegate_t;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5;
struct IFormatterConverter_t726606DAC82C384B08C82471313C340968DDB609;
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MethodInfo_t;
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37;
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C;
struct String_t;
struct Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700;
struct Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4;
struct Type_t;
struct UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct AreaNode_tB9A4250EFEA8C60BEDFFDA3E78F20EA6DE77DA7D;

IL2CPP_EXTERN_C RuntimeClass* BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UIRUtility_tBBCA94052EAE57F0A59876553C582FFCF52E706C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral0DB46164953228904843938099AF66650313FEE5;
IL2CPP_EXTERN_C String_t* _stringLiteral358A3678217D3CE720F0C294149170B975E33338;
IL2CPP_EXTERN_C String_t* _stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D;
IL2CPP_EXTERN_C String_t* _stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8;
IL2CPP_EXTERN_C const RuntimeType* Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80;
struct BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B;
struct BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515;
struct BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A;
struct BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8;
struct BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F;
struct BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A;
struct Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389;
struct Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259;
struct ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2;
struct CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57;
struct CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB;
struct GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct EmptyArray_1_tA6E339CF983886C190886835190061C2E3B679F2  : public RuntimeObject
{
};
struct EmptyArray_1_tD61E793B4EDBEE4AA2790494DEAA1AFF267A1F35  : public RuntimeObject
{
};
struct EmptyArray_1_t080248E0CE94C9EDF86D6BBE84F395794E5E43C3  : public RuntimeObject
{
};
struct EmptyArray_1_tA290AEF3927090408C0E0B2EC14CB3DB2C5163A6  : public RuntimeObject
{
};
struct EmptyArray_1_t353CE6E273731A6220E1AD1A702E6AF00E235055  : public RuntimeObject
{
};
struct EmptyArray_1_tF2E6E6E2B72D0BF7ECB89ECF4FD5717E4EDE97BF  : public RuntimeObject
{
};
struct EmptyArray_1_tA656C73B1CB77366F398AB7451929D79699A6181  : public RuntimeObject
{
};
struct EmptyArray_1_t7187E746F328254739F076CFBCAABB28D4B4554C  : public RuntimeObject
{
};
struct EmptyArray_1_t47661D704C83AA21034108CB0B840DB306FC3905  : public RuntimeObject
{
};
struct EmptyArray_1_t6FD6A997ADBD66902EAF4E27C5C77F3F67BD253E  : public RuntimeObject
{
};
struct EmptyArray_1_t7BBC8CED754F364A777871A238BBBE3F94FFDDE1  : public RuntimeObject
{
};
struct EmptyArray_1_t9FC4EAC7DDBFA164B697CFEBFF39A52B321CC8C9  : public RuntimeObject
{
};
struct EmptyArray_1_tC72AE83DCB4E240E4B2AC2595448148BB03F9498  : public RuntimeObject
{
};
struct EmptyArray_1_tB029523A05EA2FFE1EB90490D66A384F7A0D4574  : public RuntimeObject
{
};
struct EmptyArray_1_tA096FF5ABA9BBA8015C9E8E28FACB937691BFA36  : public RuntimeObject
{
};
struct EmptyArray_1_t27401338DAB1F4C8F9B8E695AB18ABBBF6573E17  : public RuntimeObject
{
};
struct EmptyArray_1_t640F34C5C1351444FCE089711FFEF74161372D64  : public RuntimeObject
{
};
struct EmptyArray_1_tFF976FF929BF18504D078013AD3BE659BC52BBEF  : public RuntimeObject
{
};
struct EmptyArray_1_tE700FA647008891EF64C31436B092B253493667F  : public RuntimeObject
{
};
struct EmptyArray_1_t0D07744D06CBE1D5EFB0F376FCD9DE664680DB24  : public RuntimeObject
{
};
struct EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9  : public RuntimeObject
{
};
struct SpanDebugView_1_t6B249F4737457563D0548242B2E940C385BF66E5  : public RuntimeObject
{
};
struct BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2  : public RuntimeObject
{
	bool ___U3CdisposedU3Ek__BackingField;
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37  : public RuntimeObject
{
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___m_members;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___m_data;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___m_types;
	Dictionary_2_t5C8F46F5D57502270DD9E1DA8303B23C7FE85588* ___m_nameToIndex;
	int32_t ___m_currMember;
	RuntimeObject* ___m_converter;
	String_t* ___m_fullTypeName;
	String_t* ___m_assemName;
	Type_t* ___objectType;
	bool ___isFullTypeNameSetExplicit;
	bool ___isAssemblyNameSetExplicit;
	bool ___requireSameTokenInPartialTrust;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7  : public RuntimeObject
{
	int32_t ___U3CmaxAtlasSizeU3Ek__BackingField;
	int32_t ___U3CmaxImageWidthU3Ek__BackingField;
	int32_t ___U3CmaxImageHeightU3Ek__BackingField;
	int32_t ___U3CvirtualWidthU3Ek__BackingField;
	int32_t ___U3CvirtualHeightU3Ek__BackingField;
	int32_t ___U3CphysicalWidthU3Ek__BackingField;
	int32_t ___U3CphysicalHeightU3Ek__BackingField;
	AreaNode_tB9A4250EFEA8C60BEDFFDA3E78F20EA6DE77DA7D* ___m_FirstUnpartitionedArea;
	RowU5BU5D_t325BC67027D8D4C3AB8E0375B85F72BEB5ADA376* ___m_OpenRows;
	int32_t ___m_1SidePadding;
	int32_t ___m_2SidePadding;
	bool ___U3CdisposedU3Ek__BackingField;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct EnumEqualityComparer_1_tBE0A26FDB9917D9CB482A0E2018093AB3394FC1A  : public EqualityComparer_1_t458C8DC3748A89A213F4738B57D3742C4896ABE9
{
};
struct SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0 
{
	void* ____buffer;
};
struct SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08 
{
	void* ____buffer;
};
struct Slot_t22B135B722F7D592A58FAEDAD31DDA9BB7CD2FC8 
{
	int32_t ___hashCode;
	int32_t ___next;
	int32_t ___value;
};
struct Slot_t4BB8CC974E5E3453C5B4BD5E6DC16498D0EF7744 
{
	int32_t ___hashCode;
	int32_t ___next;
	RuntimeObject* ___value;
};
struct Slot_tE40ADD3E3758BFA1DB21D9E728F98EBFEF2AE27E 
{
	int32_t ___hashCode;
	RuntimeObject* ___value;
	int32_t ___next;
};
struct Slot_t36E7BD2C949C62077BDCD89A5CA092508944F177 
{
	RuntimeObject* ___Item;
	int32_t ___SequenceNumber;
};
struct Slot_t0F2C4321FC082433EA1889FA7952BA1F9A0D2382 
{
	int32_t ___hashCode;
	int32_t ___next;
	uint32_t ___value;
};
typedef Il2CppFullySharedGenericStruct Slot_tEC146EEEF7022C6542EBF082D658446682962BFD;
typedef Il2CppFullySharedGenericStruct Slot_tF45120D6701798B3D99EA6E4D4BD09B970E2242B;
typedef Il2CppFullySharedGenericStruct Slot_t15722483BF8D3D9AE95C0F301EAB5E41F7E1E2B9;
struct ValueTuple_1_tBFF71B8F72F9D197DB09CFE88F0C8C7FE97CEF75 
{
	bool ___Item1;
};
struct ValueTuple_2_tC3717D4552EE1E5FC27BFBA3F5155741BC04557A 
{
	RuntimeObject* ___Item1;
	RuntimeObject* ___Item2;
};
struct ValueTuple_3_tFD2ADB3DA89E958885034AAFEF1ABDA8C814D987 
{
	RuntimeObject* ___Item1;
	int32_t ___Item2;
	int32_t ___Item3;
};
struct BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D 
{
	BatchDrawCommand_t9DAB9B739DA9EBC6B1BB0D2DD51AF65B12F66BF0* ___drawCommands;
	int32_t* ___visibleInstances;
	BatchDrawRange_t736D745E918A629658B80A0F7D2D17DAFBA6172F* ___drawRanges;
	float* ___instanceSortingPositions;
	int32_t* ___drawCommandPickingInstanceIDs;
	int32_t ___drawCommandCount;
	int32_t ___visibleInstanceCount;
	int32_t ___drawRangeCount;
	int32_t ___instanceSortingPositionFloatCount;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
#pragma pack(push, tp, 1)
struct Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 
{
	uint8_t ___x;
	uint8_t ___y;
	uint8_t ___z;
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B 
{
	uint8_t ___x;
	uint8_t ___y;
	uint8_t ___z;
	uint8_t ___w;
};
#pragma pack(pop, tp)
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	Il2CppChar ___m_value;
};
struct Color_tD001788D726C3A7F1379BEED0260B9591F440C1F 
{
	float ___r;
	float ___g;
	float ___b;
	float ___a;
};
struct Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___rgba;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___rgba_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t ___r;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t ___r_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___g_OffsetPadding[1];
			uint8_t ___g;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___g_OffsetPadding_forAlignmentOnly[1];
			uint8_t ___g_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___b_OffsetPadding[2];
			uint8_t ___b;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___b_OffsetPadding_forAlignmentOnly[2];
			uint8_t ___b_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___a_OffsetPadding[3];
			uint8_t ___a;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___a_OffsetPadding_forAlignmentOnly[3];
			uint8_t ___a_forAlignmentOnly;
		};
	};
};
struct DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 
{
	int32_t ___firstIndex;
	int32_t ___indexCount;
	int32_t ___minIndexVal;
	int32_t ___vertsReferenced;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175 
{
	int16_t ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 
{
	uint64_t ___jobGroup;
	int32_t ___version;
};
struct Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 
{
	float ___m00;
	float ___m10;
	float ___m20;
	float ___m30;
	float ___m01;
	float ___m11;
	float ___m21;
	float ___m31;
	float ___m02;
	float ___m12;
	float ___m22;
	float ___m32;
	float ___m03;
	float ___m13;
	float ___m23;
	float ___m33;
};
struct RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8 
{
	int32_t ___m_XMin;
	int32_t ___m_YMin;
	int32_t ___m_Width;
	int32_t ___m_Height;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
};
struct UIntPtr_t 
{
	void* ____pointer;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	float ___x;
	float ___y;
	float ___z;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct float3_t4AB5D88249ADB24F69FFD0793E8ED25E1CC3745E 
{
	float ___x;
	float ___y;
	float ___z;
};
struct float4_t89D9A294E7A79BD81BFBDD18654508532958555E 
{
	float ___x;
	float ___y;
	float ___z;
	float ___w;
};
struct int4_tBA77D4945786DE82C3A487B33955EA1004996052 
{
	int32_t ___x;
	int32_t ___y;
	int32_t ___z;
	int32_t ___w;
};
struct MaterialTarget_tE02828F1E0AC3E7D213D49DD96BC2B235D470694 
{
	String_t* ___MaterialName;
	String_t* ___ValueName;
};
struct MaterialTarget_tE02828F1E0AC3E7D213D49DD96BC2B235D470694_marshaled_pinvoke
{
	char* ___MaterialName;
	char* ___ValueName;
};
struct MaterialTarget_tE02828F1E0AC3E7D213D49DD96BC2B235D470694_marshaled_com
{
	Il2CppChar* ___MaterialName;
	Il2CppChar* ___ValueName;
};
struct ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 
{
	intptr_t ____value;
};
struct ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F 
{
	intptr_t ____value;
};
struct ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 
{
	intptr_t ____value;
};
struct ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF 
{
	intptr_t ____value;
};
struct ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 
{
	intptr_t ____value;
};
struct ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 
{
	intptr_t ____value;
};
struct ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 
{
	intptr_t ____value;
};
struct ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC 
{
	intptr_t ____value;
};
struct ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 
{
	intptr_t ____value;
};
struct ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 
{
	intptr_t ____value;
};
struct ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 
{
	intptr_t ____value;
};
struct ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 
{
	intptr_t ____value;
};
struct ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 
{
	intptr_t ____value;
};
struct ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 
{
	intptr_t ____value;
};
struct ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 
{
	intptr_t ____value;
};
struct ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 
{
	intptr_t ____value;
};
struct ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 
{
	intptr_t ____value;
};
struct ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 
{
	intptr_t ____value;
};
struct ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 
{
	intptr_t ____value;
};
struct ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 
{
	intptr_t ____value;
};
struct ByReference_1_t607C1F3BC28B0E21B969461CDB0720FB01A82141 
{
	intptr_t ____value;
};
struct ShortEnumEqualityComparer_1_t93E714E73A6CDB76D15D51942E3800AB3E57DFF6  : public EnumEqualityComparer_1_tBE0A26FDB9917D9CB482A0E2018093AB3394FC1A
{
};
struct SliderKey_t43E96838E1E854487D7A7516094E7659C6054D1C 
{
	int32_t ___value__;
};
struct SliderKey_t6D2D477078D3F87B046A5089EC099225FE23C471 
{
	int32_t ___value__;
};
struct SliderKey_t50E90577048B339A992940C01D208901E524828B 
{
	int32_t ___value__;
};
struct Slot_tFE3C2D7C976F354E209007AE68B0C68809F908B5 
{
	ValueTuple_2_tC3717D4552EE1E5FC27BFBA3F5155741BC04557A ___Item;
	int32_t ___SequenceNumber;
};
struct Slot_tA01C4D8C303CBA221F4856AE5422402E2C7A5374 
{
	int32_t ___hashCode;
	int32_t ___next;
	MaterialTarget_tE02828F1E0AC3E7D213D49DD96BC2B235D470694 ___value;
};
struct ValueTuple_5_t558B9F95CA55DE5694FC58A3BEAE441BF728FB57 
{
	intptr_t ___Item1;
	int32_t ___Item2;
	intptr_t ___Item3;
	int32_t ___Item4;
	bool ___Item5;
};
struct ValueTuple_8_t9B4E1B0569C36F02E150189D05FFCC0A69667F85 
{
	intptr_t ___Item1;
	int32_t ___Item2;
	intptr_t ___Item3;
	int32_t ___Item4;
	intptr_t ___Item5;
	int32_t ___Item6;
	bool ___Item7;
	ValueTuple_1_tBFF71B8F72F9D197DB09CFE88F0C8C7FE97CEF75 ___Rest;
};
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	int32_t ___value__;
};
struct BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 
{
	float4_t89D9A294E7A79BD81BFBDD18654508532958555E ____data;
};
struct ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 
{
	intptr_t ___vertSrc;
	intptr_t ___vertDst;
	int32_t ___vertCount;
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___transform;
	int32_t ___transformUVs;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___xformClipPages;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___ids;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___addFlags;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___opacityPage;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___textCoreSettingsPage;
	int32_t ___isText;
	float ___textureId;
	intptr_t ___indexSrc;
	intptr_t ___indexDst;
	int32_t ___indexCount;
	int32_t ___indexOffset;
	int32_t ___flipIndices;
};
struct CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 
{
	intptr_t ___vertSrc;
	intptr_t ___vertDst;
	int32_t ___vertCount;
	intptr_t ___indexSrc;
	intptr_t ___indexDst;
	int32_t ___indexCount;
	int32_t ___indexOffset;
};
struct CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___sphereCenter;
	float ___sphereRadius;
	int32_t ___cullingPlaneOffset;
	int32_t ___cullingPlaneCount;
	float ___cascadeBlendCullingFactor;
	float ___nearPlane;
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___cullingMatrix;
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct FilterMode_t4AD57F1A3FE272D650E0E688BA044AE872BD2A34 
{
	int32_t ___value__;
};
struct GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C 
{
	uint32_t ___offsetFromWriteStart;
	uint32_t ___size;
	uintptr_t ___source;
};
struct HideFlags_tC514182ACEFD3B847988C45D5DB812FF6DB1BF4A 
{
	int32_t ___value__;
};
struct Int32Enum_tCBAC8BA2BFF3A845FA599F303093BBBA374B6F0C 
{
	int32_t ___value__;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr;
};
struct ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD 
{
	intptr_t ___m_Ptr;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct StreamingContextStates_t5EE358E619B251608A9327618C7BFE8638FC33C1 
{
	int32_t ___value__;
};
struct TextureFormat_t87A73E4A3850D3410DC211676FC14B94226C1C1D 
{
	int32_t ___value__;
};
struct float3x3_tB318DB8C7E54B6CA9E14EB9AC7F5964C1189FC79 
{
	float3_t4AB5D88249ADB24F69FFD0793E8ED25E1CC3745E ___c0;
	float3_t4AB5D88249ADB24F69FFD0793E8ED25E1CC3745E ___c1;
	float3_t4AB5D88249ADB24F69FFD0793E8ED25E1CC3745E ___c2;
};
struct float4x3_t06008E654CCB12CD786C3E335A1E4C89A8AA13EC 
{
	float4_t89D9A294E7A79BD81BFBDD18654508532958555E ___c0;
	float4_t89D9A294E7A79BD81BFBDD18654508532958555E ___c1;
	float4_t89D9A294E7A79BD81BFBDD18654508532958555E ___c2;
};
struct float4x4_t7EDD16F7F57DC7F61A6302535F7C19FB97915DF2 
{
	float4_t89D9A294E7A79BD81BFBDD18654508532958555E ___c0;
	float4_t89D9A294E7A79BD81BFBDD18654508532958555E ___c1;
	float4_t89D9A294E7A79BD81BFBDD18654508532958555E ___c2;
	float4_t89D9A294E7A79BD81BFBDD18654508532958555E ___c3;
};
struct int4x2_t4B98454F51F5E8A8F4201FA33A01D2692B692996 
{
	int4_tBA77D4945786DE82C3A487B33955EA1004996052 ___c0;
	int4_tBA77D4945786DE82C3A487B33955EA1004996052 ___c1;
};
struct RawData_t37CAF2D3F74B7723974ED7CEEE9B297D8FA64ED0  : public RuntimeObject
{
	intptr_t ___Bounds;
	intptr_t ___Count;
	uint8_t ___Data;
};
struct RawData_t37CAF2D3F74B7723974ED7CEEE9B297D8FA64ED0_marshaled_pinvoke
{
	intptr_t ___Bounds;
	intptr_t ___Count;
	uint8_t ___Data;
};
struct RawData_t37CAF2D3F74B7723974ED7CEEE9B297D8FA64ED0_marshaled_com
{
	intptr_t ___Bounds;
	intptr_t ___Count;
	uint8_t ___Data;
};
struct NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct ReadOnlySpan_1_tE73282FE39C46EDD2EE2F61A9E3E69BE943784B7 
{
	ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t3D251E6627DBB106D7D34F8DC234D102B691FD49 
{
	ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tD81D75B0E0400301DC302920BCCBB9FBD97CA2A8 
{
	ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t70882B83461088DC23C3DB9AF59753CF91E1F3AA 
{
	ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t2EFE9320FC985EB4C740E0FD04D094F25024C51D 
{
	ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t5EE3C4B6EA25BB8F3F956DFD28820F5666342758 
{
	ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t9DCA2EC81EE91A02D7C140CF3376183B663C483A 
{
	ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t2AC1F24E0EEA27708EE5E3315C5E8A149DA4AC1B 
{
	ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t45FE292A8BF877FADC6630D8A86BD5BFDDC70267 
{
	ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 
{
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t7EE9E7096EE52CA433AA61A9353AD90B29B2C816 
{
	ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t2E193A80641154947640E9A71614019D7A8F3DFC 
{
	ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t1CFFA3B34C09F05622921AC4014011D43A25715A 
{
	ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t65511D2895327A8ECE2BF5A34FDD23AE34C83122 
{
	ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t7918A88B9E042EA0B873C90C85D2A8B97CB11BDF 
{
	ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tB185515663CA8B149175531C2C9804EB48DDEC9B 
{
	ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_tBE8F7CF96CF1493E2EA4ED19616DF91D5FF56E7C 
{
	ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t6190994DF094ABDFA6908C2C3FB347457E8E4282 
{
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 ____pointer;
	int32_t ____length;
};
struct ReadOnlySpan_1_t09FC5325A7B15784D246B5B71F829AB1C98B41DB 
{
	ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 ____pointer;
	int32_t ____length;
};
struct Slot_t0A95045068CA69D35855DB49026245B2D7F2E059 
{
	int32_t ___hashCode;
	int32_t ___next;
	int32_t ___value;
};
struct Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 
{
	ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 ____pointer;
	int32_t ____length;
};
struct Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 
{
	ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F ____pointer;
	int32_t ____length;
};
struct Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C 
{
	ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 ____pointer;
	int32_t ____length;
};
struct Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B 
{
	ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF ____pointer;
	int32_t ____length;
};
struct Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF 
{
	ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 ____pointer;
	int32_t ____length;
};
struct Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C 
{
	ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 ____pointer;
	int32_t ____length;
};
struct Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 
{
	ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 ____pointer;
	int32_t ____length;
};
struct Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC ____pointer;
	int32_t ____length;
};
struct Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E 
{
	ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 ____pointer;
	int32_t ____length;
};
struct Span_1_tCD30211080708598A3F07B04B84E8A37702B198C 
{
	ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 ____pointer;
	int32_t ____length;
};
struct Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D 
{
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 ____pointer;
	int32_t ____length;
};
struct Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 
{
	ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 ____pointer;
	int32_t ____length;
};
struct Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D 
{
	ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 ____pointer;
	int32_t ____length;
};
struct Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 
{
	ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 ____pointer;
	int32_t ____length;
};
struct Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE 
{
	ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 ____pointer;
	int32_t ____length;
};
struct Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 
{
	ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 ____pointer;
	int32_t ____length;
};
struct Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 
{
	ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 ____pointer;
	int32_t ____length;
};
struct Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 
{
	ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 ____pointer;
	int32_t ____length;
};
struct Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 
{
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 ____pointer;
	int32_t ____length;
};
struct Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 
{
	ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 ____pointer;
	int32_t ____length;
};
struct Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 
{
	ByReference_1_t607C1F3BC28B0E21B969461CDB0720FB01A82141 ____pointer;
	int32_t ____length;
};
struct BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF 
{
	float3x3_tB318DB8C7E54B6CA9E14EB9AC7F5964C1189FC79 ____data;
};
struct BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 
{
	float4x3_t06008E654CCB12CD786C3E335A1E4C89A8AA13EC ____data;
};
struct BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C 
{
	float4x4_t7EDD16F7F57DC7F61A6302535F7C19FB97915DF2 ____data;
};
struct BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 
{
	int4x2_t4B98454F51F5E8A8F4201FA33A01D2692B692996 ____data;
};
struct BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 
{
	float4x3_t06008E654CCB12CD786C3E335A1E4C89A8AA13EC ____localData;
	float4x4_t7EDD16F7F57DC7F61A6302535F7C19FB97915DF2 ____globalData;
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 
{
	RuntimeObject* ___m_additionalContext;
	int32_t ___m_state;
};
struct StreamingContext_t56760522A751890146EE45F82F866B55B7E33677_marshaled_pinvoke
{
	Il2CppIUnknown* ___m_additionalContext;
	int32_t ___m_state;
};
struct StreamingContext_t56760522A751890146EE45F82F866B55B7E33677_marshaled_com
{
	Il2CppIUnknown* ___m_additionalContext;
	int32_t ___m_state;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct Func_2_t781E8579E9FF2D1F9E663A289445D85212CBE782  : public MulticastDelegate_t
{
};
struct ShaderInfoStorage_1_t32194748F3ED0F5527B4E31A28D04606FAEE539A  : public BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2
{
	int32_t ___m_InitialSize;
	int32_t ___m_MaxSize;
	int32_t ___m_Format;
	Func_2_t781E8579E9FF2D1F9E663A289445D85212CBE782* ___m_Convert;
	UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* ___m_Allocator;
	Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* ___m_Texture;
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___m_Texels;
};
struct SpanAction_2_t65B015FEFE1F64814AC2EFA0E19A38B1CFC53178  : public MulticastDelegate_t
{
};
struct SpanAction_2_t84FDFFEECCC96A9A407DCB490E60340E38185947  : public MulticastDelegate_t
{
};
struct SpanAction_2_t02885A83F58261D2CFDC8FFBBCD7C8ECAF105A7B  : public MulticastDelegate_t
{
};
struct SpanAction_2_t5907E59A3FE410EE3FC9FC29F5E9418DF5894C8B  : public MulticastDelegate_t
{
};
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4  : public Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700
{
};
struct EmptyArray_1_tA6E339CF983886C190886835190061C2E3B679F2_StaticFields
{
	BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* ___Value;
};
struct EmptyArray_1_tD61E793B4EDBEE4AA2790494DEAA1AFF267A1F35_StaticFields
{
	BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* ___Value;
};
struct EmptyArray_1_t080248E0CE94C9EDF86D6BBE84F395794E5E43C3_StaticFields
{
	BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* ___Value;
};
struct EmptyArray_1_tA290AEF3927090408C0E0B2EC14CB3DB2C5163A6_StaticFields
{
	BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* ___Value;
};
struct EmptyArray_1_t353CE6E273731A6220E1AD1A702E6AF00E235055_StaticFields
{
	BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* ___Value;
};
struct EmptyArray_1_tF2E6E6E2B72D0BF7ECB89ECF4FD5717E4EDE97BF_StaticFields
{
	BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* ___Value;
};
struct EmptyArray_1_tA656C73B1CB77366F398AB7451929D79699A6181_StaticFields
{
	BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* ___Value;
};
struct EmptyArray_1_t7187E746F328254739F076CFBCAABB28D4B4554C_StaticFields
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___Value;
};
struct EmptyArray_1_t47661D704C83AA21034108CB0B840DB306FC3905_StaticFields
{
	Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* ___Value;
};
struct EmptyArray_1_t6FD6A997ADBD66902EAF4E27C5C77F3F67BD253E_StaticFields
{
	Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* ___Value;
};
struct EmptyArray_1_t7BBC8CED754F364A777871A238BBBE3F94FFDDE1_StaticFields
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___Value;
};
struct EmptyArray_1_t9FC4EAC7DDBFA164B697CFEBFF39A52B321CC8C9_StaticFields
{
	ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* ___Value;
};
struct EmptyArray_1_tC72AE83DCB4E240E4B2AC2595448148BB03F9498_StaticFields
{
	Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* ___Value;
};
struct EmptyArray_1_tB029523A05EA2FFE1EB90490D66A384F7A0D4574_StaticFields
{
	ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* ___Value;
};
struct EmptyArray_1_tA096FF5ABA9BBA8015C9E8E28FACB937691BFA36_StaticFields
{
	CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* ___Value;
};
struct EmptyArray_1_t27401338DAB1F4C8F9B8E695AB18ABBBF6573E17_StaticFields
{
	CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* ___Value;
};
struct EmptyArray_1_t640F34C5C1351444FCE089711FFEF74161372D64_StaticFields
{
	DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* ___Value;
};
struct EmptyArray_1_tFF976FF929BF18504D078013AD3BE659BC52BBEF_StaticFields
{
	GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* ___Value;
};
struct EmptyArray_1_tE700FA647008891EF64C31436B092B253493667F_StaticFields
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___Value;
};
struct EmptyArray_1_t0D07744D06CBE1D5EFB0F376FCD9DE664680DB24_StaticFields
{
	JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___Value;
};
struct BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_StaticFields
{
	int32_t ___s_TextureCounter;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___s_MarkerCopyTexture;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___s_MarkerGetTextureData;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___s_MarkerUpdateTexture;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7_StaticFields
{
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___s_MarkerTryAllocate;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject;
};
struct Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700_StaticFields
{
	int32_t ___GenerateAllMips;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771  : public RuntimeArray
{
	ALIGN_FIELD (8) Delegate_t* m_Items[1];

	inline Delegate_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Delegate_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Delegate_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Delegate_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80  : public RuntimeArray
{
	ALIGN_FIELD (8) BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D m_Items[1];

	inline BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D value)
	{
		m_Items[index] = value;
	}
};
struct BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B  : public RuntimeArray
{
	ALIGN_FIELD (8) BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF m_Items[1];

	inline BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF value)
	{
		m_Items[index] = value;
	}
};
struct BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515  : public RuntimeArray
{
	ALIGN_FIELD (8) BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 m_Items[1];

	inline BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 value)
	{
		m_Items[index] = value;
	}
};
struct BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A  : public RuntimeArray
{
	ALIGN_FIELD (8) BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C m_Items[1];

	inline BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C value)
	{
		m_Items[index] = value;
	}
};
struct BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8  : public RuntimeArray
{
	ALIGN_FIELD (8) BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 m_Items[1];

	inline BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 value)
	{
		m_Items[index] = value;
	}
};
struct BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F  : public RuntimeArray
{
	ALIGN_FIELD (8) BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 m_Items[1];

	inline BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 value)
	{
		m_Items[index] = value;
	}
};
struct BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A  : public RuntimeArray
{
	ALIGN_FIELD (8) BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 m_Items[1];

	inline BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 value)
	{
		m_Items[index] = value;
	}
};
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint8_t value)
	{
		m_Items[index] = value;
	}
};
struct Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A  : public RuntimeArray
{
	ALIGN_FIELD (8) Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 m_Items[1];

	inline Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 value)
	{
		m_Items[index] = value;
	}
};
struct Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348  : public RuntimeArray
{
	ALIGN_FIELD (8) Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B m_Items[1];

	inline Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B value)
	{
		m_Items[index] = value;
	}
};
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB  : public RuntimeArray
{
	ALIGN_FIELD (8) Il2CppChar m_Items[1];

	inline Il2CppChar GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Il2CppChar* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Il2CppChar value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Il2CppChar GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Il2CppChar* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Il2CppChar value)
	{
		m_Items[index] = value;
	}
};
struct ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389  : public RuntimeArray
{
	ALIGN_FIELD (8) Color_tD001788D726C3A7F1379BEED0260B9591F440C1F m_Items[1];

	inline Color_tD001788D726C3A7F1379BEED0260B9591F440C1F GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Color_tD001788D726C3A7F1379BEED0260B9591F440C1F GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F value)
	{
		m_Items[index] = value;
	}
};
struct Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259  : public RuntimeArray
{
	ALIGN_FIELD (8) Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B m_Items[1];

	inline Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B value)
	{
		m_Items[index] = value;
	}
};
struct ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2  : public RuntimeArray
{
	ALIGN_FIELD (8) ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 m_Items[1];

	inline ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 value)
	{
		m_Items[index] = value;
	}
};
struct CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57  : public RuntimeArray
{
	ALIGN_FIELD (8) CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 m_Items[1];

	inline CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 value)
	{
		m_Items[index] = value;
	}
};
struct CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61  : public RuntimeArray
{
	ALIGN_FIELD (8) CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 m_Items[1];

	inline CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 value)
	{
		m_Items[index] = value;
	}
};
struct DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB  : public RuntimeArray
{
	ALIGN_FIELD (8) DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 m_Items[1];

	inline DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 value)
	{
		m_Items[index] = value;
	}
};
struct GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30  : public RuntimeArray
{
	ALIGN_FIELD (8) GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C m_Items[1];

	inline GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C value)
	{
		m_Items[index] = value;
	}
};
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
struct JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC  : public RuntimeArray
{
	ALIGN_FIELD (8) JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 m_Items[1];

	inline JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 value)
	{
		m_Items[index] = value;
	}
};


IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SharedStatic_1__ctor_mF83D06637E10F1C230BA4F1A841E742F6A5ED399_gshared_inline (SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0* __this, void* ___0_buffer, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR intptr_t* UnsafeUtility_AsRef_TisIntPtr_t_m5E80CE586FADFB0EE0E808A1A736F9BF28C2B28B_gshared_inline (void* ___0_ptr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t* SharedStatic_1_get_Data_m42DD928B26C146E0D920D5348F2CEBC3C7F21C3D_gshared (SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SharedStatic_1__ctor_m467F9A64986F442AA4853C5C314D0A54D887CDDC_gshared_inline (SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08* __this, void* ___0_buffer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* SharedStatic_1_get_Data_m679BD82198B4EC1D89F2EDE946A60F4DEE8E47E2_gshared (SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m739A39BB426B19B7583557F308B2BDA52E2C3DD9_gshared_inline (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m9074142CF2F0828232AFEBB926F490D33E285B9B_gshared (BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* ___0_destination, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m729E93C65964D6955F3A0794056B0A8FA3E1FB44_gshared_inline (ReadOnlySpan_1_tE73282FE39C46EDD2EE2F61A9E3E69BE943784B7* __this, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mB2713B2424259A6D18038A2E29BD96DA081378D6_gshared_inline (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* Array_Empty_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m652D1F78F0DEF31A60A1D09589A89DE06F12C3E4_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m7126F92024E73EE43580A7A9D64C39CD973406CC_gshared_inline (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mF5DDBBF4783D0A55C88BFD79E1A1F8B5DDCF60C5_gshared_inline (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisBlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF_m3ED952566857853E08E1F43BA48367A61065281A_gshared (BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* ___0_destination, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m1C72072A1F9FFD48A21C4C5F2A81954708D29495_gshared_inline (ReadOnlySpan_1_t3D251E6627DBB106D7D34F8DC234D102B691FD49* __this, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m4F32D7D5653D612D237DDFD35C9850E16CA11C18_gshared_inline (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* Array_Empty_TisBlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF_mCD144DB8231D7EA3AF1DB4FEB94681C9E580CA9D_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mCA3E1FB18A1006842617ABD22464535398F4655D_gshared_inline (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m0A22C7814AA57E51DE4EDC241010E81DA05627F9_gshared_inline (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisBlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6_mE178FB3796A6A1A4F519A7BA46829D3A14F94CBD_gshared (BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* ___0_destination, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m143F99ABFB2902F2BE3AB6725D5F8AEAECDEC5F4_gshared_inline (ReadOnlySpan_1_tD81D75B0E0400301DC302920BCCBB9FBD97CA2A8* __this, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m6C9685057F182B8896BBE6B894974625E6DA4221_gshared_inline (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* Array_Empty_TisBlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6_m7D78EA1928C7379C27FE7337353FB51BEFD7476E_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mF80BBD6B1E4103830CA7E538A9EE8ABA983D97EC_gshared_inline (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m3C5D2034819739D3DDB78A3D890CEE1C94529B01_gshared_inline (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisBlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C_m107660B4F4107562042A7A5BD0F5123732E1C1BF_gshared (BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* ___0_destination, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mD794B63B35B4B58E5337728A24E1998CFDD74810_gshared_inline (ReadOnlySpan_1_t70882B83461088DC23C3DB9AF59753CF91E1F3AA* __this, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m773D9E2695DC1A1EAF17FDC94204CB7B1DE21582_gshared_inline (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* Array_Empty_TisBlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C_m48CDEF41C2F032666E4312F197041C0757708AE3_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mB392265B6A34EA59542E156547D1143AC4B0EBD4_gshared_inline (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m088CD07D38433F7795ED549A2139E5D41EA16706_gshared_inline (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisBlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54_m812A4F9C363B5C0D2AAE7D5E5D180DB7F7FEF824_gshared (BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* ___0_destination, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m1A260D918B5EB96D17E965BA7BA73DA0C3493361_gshared_inline (ReadOnlySpan_1_t2EFE9320FC985EB4C740E0FD04D094F25024C51D* __this, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mEA9008985414217BB660044157B6458716A8AB1D_gshared_inline (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* Array_Empty_TisBlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54_mDE388119C5F2CA6DED1F8895551BEDC81C379FF9_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mD521304CD3352077C22527BDFF5A3A6F5BBA2345_gshared_inline (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mE19749B8DE0A55279184BDD9C3F394605245F91A_gshared_inline (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisBlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901_mCB357A3CD61F6C424F89F1F9C63A4446F5B9C57E_gshared (BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* ___0_destination, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mE88D51223E12D11DE487A5E2C7AF2013C6413887_gshared_inline (ReadOnlySpan_1_t5EE3C4B6EA25BB8F3F956DFD28820F5666342758* __this, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m18D55B2B52C0EE4D379FCBBC6EE16E72CE2928E1_gshared_inline (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* Array_Empty_TisBlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901_m75A4A4FD904386887E2E78BA168595529AF13939_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mBC0A2A6F732CAD76B8E0B559AAF16DDDC7DA95FB_gshared_inline (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m27BEF44B2CCD3948DC00D344142E534E36BA7524_gshared_inline (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisBlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472_mDE86D51ADDC3C7F13B214DA755964EA5014FC510_gshared (BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* ___0_destination, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m83EAE3C4FCB23391B66637D0580733B85E12B21A_gshared_inline (ReadOnlySpan_1_t9DCA2EC81EE91A02D7C140CF3376183B663C483A* __this, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m0635E38BE51343FEA108E4BAC304A66703B9E727_gshared_inline (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* Array_Empty_TisBlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472_m6A8620E16588CCAE8CBA423DCB92B7E1D919A942_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mDAF271BFB6432EB8FCE7E7E95BB3A4918F1BCC92_gshared_inline (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m8E944E4954E037877A25B9FF6B901F1F901D4769_gshared_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB1465EEEBE0A608FA51B29BC3F145F287AD04190_gshared (uint8_t* ___0_destination, uint8_t* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m0FC0B92549C2968E80B5F75A85F28B96DBFCFD63_gshared_inline (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, uint8_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_gshared_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, uint8_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* Array_Empty_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m6080CA526758F4FA182A066B2780D1761CD36ED5_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m513968BDBFF3CFCE89F3F77FE44CAB22CA474EF9_gshared_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m6C31F03BA2113C74E17C5CDEEEB6F3127EED655F_gshared_inline (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisByte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87_mE057DC9F2C913014D2F0DA1582E3652DA81D4108_gshared (Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* ___0_destination, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mB2EBAFF15789F2361DDAE7F848E175DB33845102_gshared_inline (ReadOnlySpan_1_t2AC1F24E0EEA27708EE5E3315C5E8A149DA4AC1B* __this, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m31A2EA269EF672A7C251B615BA32E9B3B264E225_gshared_inline (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* Array_Empty_TisByte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87_m05CA261BA6F06533AB2F5C75B5B0CB6F63DEC412_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m9C0B3F87D446842B5C4638690ED90478A5B5073C_gshared_inline (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mF218AEBAC87C5B982A156B8286EF27B501363D4C_gshared_inline (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisByte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B_m321993B9B1BFF1674C614D34E70D2E0B23FA0B4B_gshared (Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* ___0_destination, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mF698E5C91A39EE4E9A4143E3EECCE2A9078FD390_gshared_inline (ReadOnlySpan_1_t45FE292A8BF877FADC6630D8A86BD5BFDDC70267* __this, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m29EE9A42F0B8B3317F565CF7FAAB5E0567DC495B_gshared_inline (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* Array_Empty_TisByte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B_m6D7C0121F09237151D13126E696B9A3344E0F93A_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mB15C95C53B11DF662E871E2732D51D09DBDB299E_gshared_inline (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mB79622153F80AD55A805C005842AF045F4FCF992_gshared_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisChar_t521A6F19B456D956AF452D926C32709DC03D6B17_m62AF071D7F91DFC9A4D8B847D6A4472B820B5446_gshared (Il2CppChar* ___0_destination, Il2CppChar* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m0152E50B40750679B83FF9F30CA539FFBB98EEE8_gshared_inline (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, Il2CppChar* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mC9BE2938B716B46BB6B9070B94DBE5CE814BC0E2_gshared_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, Il2CppChar* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* Array_Empty_TisChar_t521A6F19B456D956AF452D926C32709DC03D6B17_mD1C1362CB74B91496D984B006ADC79B688D9B50D_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m23CBCD46AD762681A232C97FE90B3A9EDD4991E5_gshared_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m83147EFB62B7FFBA49EEBEBE975F7348D665BAD0_gshared_inline (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_m3B15D4D61932A340BAAA5BE6E8D419605D3692E6_gshared (Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* ___0_destination, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mD46BD07C5320D1B1A225E53FAF466E153FFC1679_gshared_inline (ReadOnlySpan_1_t7EE9E7096EE52CA433AA61A9353AD90B29B2C816* __this, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m48419159317F9826172EDEA69FDB0598B87B34D2_gshared_inline (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* Array_Empty_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_m7E922E24AAEBD664256383832D53DDF17E1F3052_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mD8CCC80CA9129EEAC13B40BA31C6C577BDF46ECD_gshared_inline (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m413F20ECFE3F523163B62ED5BAB7DFA22F2FCCD4_gshared_inline (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_mA65CAF282F03FD4DB46666E2C44C22E3D0035A68_gshared (Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* ___0_destination, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m841651F5E0DEC77984A109EF01090F3F776571FB_gshared_inline (ReadOnlySpan_1_t2E193A80641154947640E9A71614019D7A8F3DFC* __this, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mD16E04B2ED38420390E0DE1D6E01DE23C583B434_gshared_inline (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* Array_Empty_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m5B415C4745E47108DD9258EBCCB422EFD6B8A0EB_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mDE7408B1AC4D3DDE1E8EB6C1A8AE8244CAB0BBB1_gshared_inline (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m3B50FB2CF29A0E7C0C8B69E4E5A72D75883EBC4B_gshared_inline (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1_m747B7D7DC0AA466783F69D3676EC5EE854D08D52_gshared (ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* ___0_destination, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mDB9E4DFF0687E0A5405FF4F6387379524B1B07AB_gshared_inline (ReadOnlySpan_1_t1CFFA3B34C09F05622921AC4014011D43A25715A* __this, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m1910D0E44CCD92AD908E1D5F61FFF27ADFE1EFAD_gshared_inline (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* Array_Empty_TisConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1_m164EDF2519D24430C10F8BB106ADB252BF225C26_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mE396EB49F11B34D41818F29E84D8865E2003B251_gshared_inline (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mEC383018256E25827F3B339475CABFC2C2237A88_gshared_inline (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisCopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044_m49C533FCD49E82DED6CE9BFF4EE71DBC632E91A0_gshared (CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* ___0_destination, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m4D4193A630867D8532F94829D1B330477153F6F5_gshared_inline (ReadOnlySpan_1_t65511D2895327A8ECE2BF5A34FDD23AE34C83122* __this, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mCD3AE57570C815AC4046DA4D9E7C0A9E2BBEB547_gshared_inline (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* Array_Empty_TisCopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044_mE213035FEF51FB6A504BDD242F0307E9FE074829_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m2817AF8060669CE2B4F3418E7732492AE1043541_gshared_inline (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m385F87A001B432F97C5381EF1F01B485642ED27D_gshared_inline (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m9A4B5780CB8BC1ACD63C193EC68D5E217CDBAC80_gshared (CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* ___0_destination, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m7515BCC9EAB305B335A968E684B597A1FC9A5F24_gshared_inline (ReadOnlySpan_1_t7918A88B9E042EA0B873C90C85D2A8B97CB11BDF* __this, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m938DD54F3773C27DD1393A85BB94346047AD1DA5_gshared_inline (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* Array_Empty_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m46787E1D6E481E4790F1F9E63000A067C9AF33CD_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m59E7D308EB85B51BA4162E76EE21E5568E986970_gshared_inline (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mFF4419EF107B2F1CD3364357F9723EAC96433F03_gshared_inline (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisDrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5_mDF1CDB2973A50B932ED2E72CC7A57E75C7FCAB54_gshared (DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* ___0_destination, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mB6153B16E29314D6497048CA9F509CF21C277F71_gshared_inline (ReadOnlySpan_1_tB185515663CA8B149175531C2C9804EB48DDEC9B* __this, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m52DDC62CEE4B57B1A97604C59D91F867D9C9472B_gshared_inline (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* Array_Empty_TisDrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5_m05A4DA3A4ACD6D784909779870EE466DF7778EC7_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m7F574E10BF82902E6DFCF264F060076901BC34C0_gshared_inline (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m4AFBDAB740A9ECD13948F54329A3D84FD198CB73_gshared_inline (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisGfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C_m2CA00C03921B3C30B95A8129FDEA92912124ED5E_gshared (GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* ___0_destination, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m8560DF2D26A1CC196BDE7BB7DFC896FB3D65EA16_gshared_inline (ReadOnlySpan_1_tBE8F7CF96CF1493E2EA4ED19616DF91D5FF56E7C* __this, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mABCC2BDB018D99B11CE82B53D6EDE75D4455193F_gshared_inline (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* Array_Empty_TisGfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C_mC6C376B567AC6FA4773E73349EE73E984E47852B_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mEAFD68654E9CB51239357C3D94CDB5056137D70B_gshared_inline (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m87AB3C694F2E4802F14D006F21C020816045285F_gshared_inline (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m1CD5B4A82FDDB0C96C8ABC21339D0339688CEEAB_gshared (int32_t* ___0_destination, int32_t* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mA0D85386F3D3AAF59FC429C4A2A9E7CD6B7DCF2A_gshared_inline (ReadOnlySpan_1_t6190994DF094ABDFA6908C2C3FB347457E8E4282* __this, int32_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m89B8042F831A4ACF35D15B29B8141AE29CFFDF84_gshared_inline (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, int32_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* Array_Empty_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m4D53E0E0F90F37AD5DBFD2DC75E52406F90C7ABC_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m176441CFA181B7C6097611CC13C24C5ED7F14CFF_gshared_inline (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m0BE6EA932B404A54A3AF19C9654ED2611196FAE5_gshared_inline (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_Memmove_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m4DF13B5C2D27E38BFD7112649345659B81B99988_gshared (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___0_destination, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m5146D98DC32810D3BC61D690968758CF2711417A_gshared_inline (ReadOnlySpan_1_t09FC5325A7B15784D246B5B71F829AB1C98B41DB* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m495B7963DA5CE2A2F3D69EAEBDD7BF73A1B34A31_gshared_inline (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* Array_Empty_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m65AF0C73C7E00505BCE35B9CC15EE8C8F6F0A01E_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m639F3CC8B14984E278FC347886BA5C0D86C7A4B9_gshared_inline (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseShaderInfoStorage__ctor_m5CD6C884D6587272D9C90F8DEE2BE0C38A5C4DBB (BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SystemInfo_get_maxTextureSize_mEE557C09643222591C6F4D3F561D7A60CD403991 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_Assert_m6E778CACD0F440E2DEA9ACDD9330A22DAF16E96D (bool ___0_condition, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Mathf_IsPowerOfTwo_m58172AEBE272F53FD34CC10641057847181E960A (int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool BaseShaderInfoStorage_get_disposed_mAF7F54A791E6AF75BF1AD71B1DDA85099BFCE1EF_inline (BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIRUtility_Destroy_m9E925E79E7B4A4853B47C1EFACEF2ED0A7844A23 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIRAtlasAllocator_Dispose_mB956D63F99999BA479695669265B4E6F9755D155 (UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseShaderInfoStorage_Dispose_m4346D0BFF23C896046CB1A774E6EB4F4EFC9E56F (BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2* __this, bool ___0_disposing, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DisposeHelper_NotifyDisposedUsed_m7A9C988A4B96B0920E470EEA604BA42C5ABB437F (RuntimeObject* ___0_disposable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UIRAtlasAllocator__ctor_m4263398EB9C4D3D4C8B752C441A1D8F1044B8DF2 (UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* __this, int32_t ___0_initialAtlasSize, int32_t ___1_maxAtlasSize, int32_t ___2_sidePadding, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UIRAtlasAllocator_TryAllocate_m4DE2C4C9761F6C736122F59AA11BA6E29021E187 (UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* __this, int32_t ___0_width, int32_t ___1_height, RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* ___2_location, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RectInt_get_x_mA1E7EF6DEAD2E900D7D56B7A3957C05081EBA9CA_inline (RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RectInt_get_y_m440422264E6FCAA91E01F81486A78037AC29D878_inline (RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RectInt__ctor_m6E8B3A6C7EE11257A6B438E36274116FE39B5B42_inline (RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* __this, int32_t ___0_xMin, int32_t ___1_yMin, int32_t ___2_width, int32_t ___3_height, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ProfilerMarker_Begin_mD07DB736ADA7D8BAF9D969CC7F3C55848A218C6E_inline (ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ProfilerMarker_End_m025AE3EF0F96F6DADC53489A53FC6EE65073DE60_inline (ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Texture2D_Apply_m36EE27E6F1BF7FB8C70A1D749DC4EE249810AA3A (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* __this, bool ___0_updateMipmaps, bool ___1_makeNoLongerReadable, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UIRAtlasAllocator_get_physicalWidth_m0B06147154436A555CEABB9C9EB319D7D33A5398_inline (UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UIRAtlasAllocator_get_physicalHeight_m736C92B2C509CE66BAFFBA87110103BBC72DBD88_inline (UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Texture2D__ctor_mECF60A9EC0638EC353C02C8E99B6B465D23BE917 (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* __this, int32_t ___0_width, int32_t ___1_height, int32_t ___2_textureFormat, bool ___3_mipChain, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5 (int32_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_set_name_mC79E6DC8FFD72479C90F0C4CC7F42A0FEAF5AE47 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_set_hideFlags_mACB8BFC903FB3B01BBD427753E791BF28B5E33D4 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Texture_set_filterMode_mE423E58C0C16D059EA62BA87AD70F44AEA50CCC9 (Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* __this, int32_t ___0_value, const RuntimeMethod* method) ;
inline void SharedStatic_1__ctor_mF83D06637E10F1C230BA4F1A841E742F6A5ED399_inline (SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0* __this, void* ___0_buffer, const RuntimeMethod* method)
{
	((  void (*) (SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0*, void*, const RuntimeMethod*))SharedStatic_1__ctor_mF83D06637E10F1C230BA4F1A841E742F6A5ED399_gshared_inline)(__this, ___0_buffer, method);
}
inline intptr_t* UnsafeUtility_AsRef_TisIntPtr_t_m5E80CE586FADFB0EE0E808A1A736F9BF28C2B28B_inline (void* ___0_ptr, const RuntimeMethod* method)
{
	return ((  intptr_t* (*) (void*, const RuntimeMethod*))UnsafeUtility_AsRef_TisIntPtr_t_m5E80CE586FADFB0EE0E808A1A736F9BF28C2B28B_gshared_inline)(___0_ptr, method);
}
inline intptr_t* SharedStatic_1_get_Data_m42DD928B26C146E0D920D5348F2CEBC3C7F21C3D (SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0* __this, const RuntimeMethod* method)
{
	return ((  intptr_t* (*) (SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0*, const RuntimeMethod*))SharedStatic_1_get_Data_m42DD928B26C146E0D920D5348F2CEBC3C7F21C3D_gshared)(__this, method);
}
inline void SharedStatic_1__ctor_m467F9A64986F442AA4853C5C314D0A54D887CDDC_inline (SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08* __this, void* ___0_buffer, const RuntimeMethod* method)
{
	((  void (*) (SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08*, void*, const RuntimeMethod*))SharedStatic_1__ctor_m467F9A64986F442AA4853C5C314D0A54D887CDDC_gshared_inline)(__this, ___0_buffer, method);
}
inline Il2CppFullySharedGenericStruct* SharedStatic_1_get_Data_m679BD82198B4EC1D89F2EDE946A60F4DEE8E47E2 (SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08* __this, const RuntimeMethod* method)
{
	return ((  Il2CppFullySharedGenericStruct* (*) (SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08*, const RuntimeMethod*))SharedStatic_1_get_Data_m679BD82198B4EC1D89F2EDE946A60F4DEE8E47E2_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1 (int16_t* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t* Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline (RuntimeArray* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D (uint8_t* ___0_b, uint64_t ___1_byteLength, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A (uint8_t* ___0_startAddress, uint8_t ___1_value, uint32_t ___2_byteCount, const RuntimeMethod* method) ;
inline int32_t Span_1_get_Length_m739A39BB426B19B7583557F308B2BDA52E2C3DD9_inline (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428*, const RuntimeMethod*))Span_1_get_Length_m739A39BB426B19B7583557F308B2BDA52E2C3DD9_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m9074142CF2F0828232AFEBB926F490D33E285B9B (BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* ___0_destination, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m9074142CF2F0828232AFEBB926F490D33E285B9B_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D (const RuntimeMethod* method) ;
inline void ReadOnlySpan_1__ctor_m729E93C65964D6955F3A0794056B0A8FA3E1FB44_inline (ReadOnlySpan_1_tE73282FE39C46EDD2EE2F61A9E3E69BE943784B7* __this, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_tE73282FE39C46EDD2EE2F61A9E3E69BE943784B7*, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_m729E93C65964D6955F3A0794056B0A8FA3E1FB44_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC (Type_t* ___0_left, Type_t* ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2 (String_t* __this, Il2CppChar* ___0_value, int32_t ___1_startIndex, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
inline void Span_1__ctor_mB2713B2424259A6D18038A2E29BD96DA081378D6_inline (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428*, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*, int32_t, const RuntimeMethod*))Span_1__ctor_mB2713B2424259A6D18038A2E29BD96DA081378D6_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* Array_Empty_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m652D1F78F0DEF31A60A1D09589A89DE06F12C3E4_inline (const RuntimeMethod* method)
{
	return ((  BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* (*) (const RuntimeMethod*))Array_Empty_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m652D1F78F0DEF31A60A1D09589A89DE06F12C3E4_gshared_inline)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, String_t* ___0_message, const RuntimeMethod* method) ;
inline void Span_1__ctor_m7126F92024E73EE43580A7A9D64C39CD973406CC_inline (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428*, BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80*, const RuntimeMethod*))Span_1__ctor_m7126F92024E73EE43580A7A9D64C39CD973406CC_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_mF5DDBBF4783D0A55C88BFD79E1A1F8B5DDCF60C5_inline (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671*, const RuntimeMethod*))Span_1_get_Length_mF5DDBBF4783D0A55C88BFD79E1A1F8B5DDCF60C5_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisBlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF_m3ED952566857853E08E1F43BA48367A61065281A (BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* ___0_destination, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisBlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF_m3ED952566857853E08E1F43BA48367A61065281A_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_m1C72072A1F9FFD48A21C4C5F2A81954708D29495_inline (ReadOnlySpan_1_t3D251E6627DBB106D7D34F8DC234D102B691FD49* __this, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t3D251E6627DBB106D7D34F8DC234D102B691FD49*, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_m1C72072A1F9FFD48A21C4C5F2A81954708D29495_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m4F32D7D5653D612D237DDFD35C9850E16CA11C18_inline (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671*, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*, int32_t, const RuntimeMethod*))Span_1__ctor_m4F32D7D5653D612D237DDFD35C9850E16CA11C18_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* Array_Empty_TisBlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF_mCD144DB8231D7EA3AF1DB4FEB94681C9E580CA9D_inline (const RuntimeMethod* method)
{
	return ((  BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* (*) (const RuntimeMethod*))Array_Empty_TisBlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF_mCD144DB8231D7EA3AF1DB4FEB94681C9E580CA9D_gshared_inline)(method);
}
inline void Span_1__ctor_mCA3E1FB18A1006842617ABD22464535398F4655D_inline (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671*, BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B*, const RuntimeMethod*))Span_1__ctor_mCA3E1FB18A1006842617ABD22464535398F4655D_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m0A22C7814AA57E51DE4EDC241010E81DA05627F9_inline (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C*, const RuntimeMethod*))Span_1_get_Length_m0A22C7814AA57E51DE4EDC241010E81DA05627F9_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisBlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6_mE178FB3796A6A1A4F519A7BA46829D3A14F94CBD (BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* ___0_destination, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisBlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6_mE178FB3796A6A1A4F519A7BA46829D3A14F94CBD_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_m143F99ABFB2902F2BE3AB6725D5F8AEAECDEC5F4_inline (ReadOnlySpan_1_tD81D75B0E0400301DC302920BCCBB9FBD97CA2A8* __this, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_tD81D75B0E0400301DC302920BCCBB9FBD97CA2A8*, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_m143F99ABFB2902F2BE3AB6725D5F8AEAECDEC5F4_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m6C9685057F182B8896BBE6B894974625E6DA4221_inline (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C*, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*, int32_t, const RuntimeMethod*))Span_1__ctor_m6C9685057F182B8896BBE6B894974625E6DA4221_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* Array_Empty_TisBlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6_m7D78EA1928C7379C27FE7337353FB51BEFD7476E_inline (const RuntimeMethod* method)
{
	return ((  BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* (*) (const RuntimeMethod*))Array_Empty_TisBlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6_m7D78EA1928C7379C27FE7337353FB51BEFD7476E_gshared_inline)(method);
}
inline void Span_1__ctor_mF80BBD6B1E4103830CA7E538A9EE8ABA983D97EC_inline (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C*, BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515*, const RuntimeMethod*))Span_1__ctor_mF80BBD6B1E4103830CA7E538A9EE8ABA983D97EC_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m3C5D2034819739D3DDB78A3D890CEE1C94529B01_inline (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B*, const RuntimeMethod*))Span_1_get_Length_m3C5D2034819739D3DDB78A3D890CEE1C94529B01_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisBlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C_m107660B4F4107562042A7A5BD0F5123732E1C1BF (BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* ___0_destination, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisBlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C_m107660B4F4107562042A7A5BD0F5123732E1C1BF_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_mD794B63B35B4B58E5337728A24E1998CFDD74810_inline (ReadOnlySpan_1_t70882B83461088DC23C3DB9AF59753CF91E1F3AA* __this, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t70882B83461088DC23C3DB9AF59753CF91E1F3AA*, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_mD794B63B35B4B58E5337728A24E1998CFDD74810_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m773D9E2695DC1A1EAF17FDC94204CB7B1DE21582_inline (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B*, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*, int32_t, const RuntimeMethod*))Span_1__ctor_m773D9E2695DC1A1EAF17FDC94204CB7B1DE21582_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* Array_Empty_TisBlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C_m48CDEF41C2F032666E4312F197041C0757708AE3_inline (const RuntimeMethod* method)
{
	return ((  BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* (*) (const RuntimeMethod*))Array_Empty_TisBlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C_m48CDEF41C2F032666E4312F197041C0757708AE3_gshared_inline)(method);
}
inline void Span_1__ctor_mB392265B6A34EA59542E156547D1143AC4B0EBD4_inline (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B*, BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A*, const RuntimeMethod*))Span_1__ctor_mB392265B6A34EA59542E156547D1143AC4B0EBD4_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m088CD07D38433F7795ED549A2139E5D41EA16706_inline (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF*, const RuntimeMethod*))Span_1_get_Length_m088CD07D38433F7795ED549A2139E5D41EA16706_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisBlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54_m812A4F9C363B5C0D2AAE7D5E5D180DB7F7FEF824 (BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* ___0_destination, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisBlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54_m812A4F9C363B5C0D2AAE7D5E5D180DB7F7FEF824_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_m1A260D918B5EB96D17E965BA7BA73DA0C3493361_inline (ReadOnlySpan_1_t2EFE9320FC985EB4C740E0FD04D094F25024C51D* __this, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t2EFE9320FC985EB4C740E0FD04D094F25024C51D*, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_m1A260D918B5EB96D17E965BA7BA73DA0C3493361_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_mEA9008985414217BB660044157B6458716A8AB1D_inline (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF*, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*, int32_t, const RuntimeMethod*))Span_1__ctor_mEA9008985414217BB660044157B6458716A8AB1D_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* Array_Empty_TisBlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54_mDE388119C5F2CA6DED1F8895551BEDC81C379FF9_inline (const RuntimeMethod* method)
{
	return ((  BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* (*) (const RuntimeMethod*))Array_Empty_TisBlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54_mDE388119C5F2CA6DED1F8895551BEDC81C379FF9_gshared_inline)(method);
}
inline void Span_1__ctor_mD521304CD3352077C22527BDFF5A3A6F5BBA2345_inline (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF*, BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8*, const RuntimeMethod*))Span_1__ctor_mD521304CD3352077C22527BDFF5A3A6F5BBA2345_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_mE19749B8DE0A55279184BDD9C3F394605245F91A_inline (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C*, const RuntimeMethod*))Span_1_get_Length_mE19749B8DE0A55279184BDD9C3F394605245F91A_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisBlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901_mCB357A3CD61F6C424F89F1F9C63A4446F5B9C57E (BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* ___0_destination, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisBlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901_mCB357A3CD61F6C424F89F1F9C63A4446F5B9C57E_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_mE88D51223E12D11DE487A5E2C7AF2013C6413887_inline (ReadOnlySpan_1_t5EE3C4B6EA25BB8F3F956DFD28820F5666342758* __this, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t5EE3C4B6EA25BB8F3F956DFD28820F5666342758*, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_mE88D51223E12D11DE487A5E2C7AF2013C6413887_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m18D55B2B52C0EE4D379FCBBC6EE16E72CE2928E1_inline (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C*, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*, int32_t, const RuntimeMethod*))Span_1__ctor_m18D55B2B52C0EE4D379FCBBC6EE16E72CE2928E1_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* Array_Empty_TisBlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901_m75A4A4FD904386887E2E78BA168595529AF13939_inline (const RuntimeMethod* method)
{
	return ((  BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* (*) (const RuntimeMethod*))Array_Empty_TisBlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901_m75A4A4FD904386887E2E78BA168595529AF13939_gshared_inline)(method);
}
inline void Span_1__ctor_mBC0A2A6F732CAD76B8E0B559AAF16DDDC7DA95FB_inline (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C*, BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F*, const RuntimeMethod*))Span_1__ctor_mBC0A2A6F732CAD76B8E0B559AAF16DDDC7DA95FB_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m27BEF44B2CCD3948DC00D344142E534E36BA7524_inline (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1*, const RuntimeMethod*))Span_1_get_Length_m27BEF44B2CCD3948DC00D344142E534E36BA7524_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisBlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472_mDE86D51ADDC3C7F13B214DA755964EA5014FC510 (BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* ___0_destination, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisBlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472_mDE86D51ADDC3C7F13B214DA755964EA5014FC510_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_m83EAE3C4FCB23391B66637D0580733B85E12B21A_inline (ReadOnlySpan_1_t9DCA2EC81EE91A02D7C140CF3376183B663C483A* __this, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t9DCA2EC81EE91A02D7C140CF3376183B663C483A*, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_m83EAE3C4FCB23391B66637D0580733B85E12B21A_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m0635E38BE51343FEA108E4BAC304A66703B9E727_inline (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1*, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*, int32_t, const RuntimeMethod*))Span_1__ctor_m0635E38BE51343FEA108E4BAC304A66703B9E727_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* Array_Empty_TisBlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472_m6A8620E16588CCAE8CBA423DCB92B7E1D919A942_inline (const RuntimeMethod* method)
{
	return ((  BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* (*) (const RuntimeMethod*))Array_Empty_TisBlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472_m6A8620E16588CCAE8CBA423DCB92B7E1D919A942_gshared_inline)(method);
}
inline void Span_1__ctor_mDAF271BFB6432EB8FCE7E7E95BB3A4918F1BCC92_inline (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1*, BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A*, const RuntimeMethod*))Span_1__ctor_mDAF271BFB6432EB8FCE7E7E95BB3A4918F1BCC92_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m8E944E4954E037877A25B9FF6B901F1F901D4769_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305*, const RuntimeMethod*))Span_1_get_Length_m8E944E4954E037877A25B9FF6B901F1F901D4769_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB1465EEEBE0A608FA51B29BC3F145F287AD04190 (uint8_t* ___0_destination, uint8_t* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (uint8_t*, uint8_t*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB1465EEEBE0A608FA51B29BC3F145F287AD04190_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_m0FC0B92549C2968E80B5F75A85F28B96DBFCFD63_inline (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, uint8_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D*, uint8_t*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_m0FC0B92549C2968E80B5F75A85F28B96DBFCFD63_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, uint8_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305*, uint8_t*, int32_t, const RuntimeMethod*))Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* Array_Empty_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m6080CA526758F4FA182A066B2780D1761CD36ED5_inline (const RuntimeMethod* method)
{
	return ((  ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* (*) (const RuntimeMethod*))Array_Empty_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m6080CA526758F4FA182A066B2780D1761CD36ED5_gshared_inline)(method);
}
inline void Span_1__ctor_m513968BDBFF3CFCE89F3F77FE44CAB22CA474EF9_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305*, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, const RuntimeMethod*))Span_1__ctor_m513968BDBFF3CFCE89F3F77FE44CAB22CA474EF9_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m6C31F03BA2113C74E17C5CDEEEB6F3127EED655F_inline (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E*, const RuntimeMethod*))Span_1_get_Length_m6C31F03BA2113C74E17C5CDEEEB6F3127EED655F_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisByte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87_mE057DC9F2C913014D2F0DA1582E3652DA81D4108 (Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* ___0_destination, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisByte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87_mE057DC9F2C913014D2F0DA1582E3652DA81D4108_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_mB2EBAFF15789F2361DDAE7F848E175DB33845102_inline (ReadOnlySpan_1_t2AC1F24E0EEA27708EE5E3315C5E8A149DA4AC1B* __this, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t2AC1F24E0EEA27708EE5E3315C5E8A149DA4AC1B*, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_mB2EBAFF15789F2361DDAE7F848E175DB33845102_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m31A2EA269EF672A7C251B615BA32E9B3B264E225_inline (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E*, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*, int32_t, const RuntimeMethod*))Span_1__ctor_m31A2EA269EF672A7C251B615BA32E9B3B264E225_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* Array_Empty_TisByte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87_m05CA261BA6F06533AB2F5C75B5B0CB6F63DEC412_inline (const RuntimeMethod* method)
{
	return ((  Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* (*) (const RuntimeMethod*))Array_Empty_TisByte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87_m05CA261BA6F06533AB2F5C75B5B0CB6F63DEC412_gshared_inline)(method);
}
inline void Span_1__ctor_m9C0B3F87D446842B5C4638690ED90478A5B5073C_inline (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E*, Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A*, const RuntimeMethod*))Span_1__ctor_m9C0B3F87D446842B5C4638690ED90478A5B5073C_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_mF218AEBAC87C5B982A156B8286EF27B501363D4C_inline (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C*, const RuntimeMethod*))Span_1_get_Length_mF218AEBAC87C5B982A156B8286EF27B501363D4C_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisByte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B_m321993B9B1BFF1674C614D34E70D2E0B23FA0B4B (Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* ___0_destination, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisByte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B_m321993B9B1BFF1674C614D34E70D2E0B23FA0B4B_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_mF698E5C91A39EE4E9A4143E3EECCE2A9078FD390_inline (ReadOnlySpan_1_t45FE292A8BF877FADC6630D8A86BD5BFDDC70267* __this, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t45FE292A8BF877FADC6630D8A86BD5BFDDC70267*, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_mF698E5C91A39EE4E9A4143E3EECCE2A9078FD390_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m29EE9A42F0B8B3317F565CF7FAAB5E0567DC495B_inline (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C*, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*, int32_t, const RuntimeMethod*))Span_1__ctor_m29EE9A42F0B8B3317F565CF7FAAB5E0567DC495B_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* Array_Empty_TisByte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B_m6D7C0121F09237151D13126E696B9A3344E0F93A_inline (const RuntimeMethod* method)
{
	return ((  Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* (*) (const RuntimeMethod*))Array_Empty_TisByte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B_m6D7C0121F09237151D13126E696B9A3344E0F93A_gshared_inline)(method);
}
inline void Span_1__ctor_mB15C95C53B11DF662E871E2732D51D09DBDB299E_inline (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C*, Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348*, const RuntimeMethod*))Span_1__ctor_mB15C95C53B11DF662E871E2732D51D09DBDB299E_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_mB79622153F80AD55A805C005842AF045F4FCF992_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D*, const RuntimeMethod*))Span_1_get_Length_mB79622153F80AD55A805C005842AF045F4FCF992_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisChar_t521A6F19B456D956AF452D926C32709DC03D6B17_m62AF071D7F91DFC9A4D8B847D6A4472B820B5446 (Il2CppChar* ___0_destination, Il2CppChar* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (Il2CppChar*, Il2CppChar*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisChar_t521A6F19B456D956AF452D926C32709DC03D6B17_m62AF071D7F91DFC9A4D8B847D6A4472B820B5446_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_m0152E50B40750679B83FF9F30CA539FFBB98EEE8_inline (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, Il2CppChar* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1*, Il2CppChar*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_m0152E50B40750679B83FF9F30CA539FFBB98EEE8_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_mC9BE2938B716B46BB6B9070B94DBE5CE814BC0E2_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, Il2CppChar* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D*, Il2CppChar*, int32_t, const RuntimeMethod*))Span_1__ctor_mC9BE2938B716B46BB6B9070B94DBE5CE814BC0E2_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* Array_Empty_TisChar_t521A6F19B456D956AF452D926C32709DC03D6B17_mD1C1362CB74B91496D984B006ADC79B688D9B50D_inline (const RuntimeMethod* method)
{
	return ((  CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* (*) (const RuntimeMethod*))Array_Empty_TisChar_t521A6F19B456D956AF452D926C32709DC03D6B17_mD1C1362CB74B91496D984B006ADC79B688D9B50D_gshared_inline)(method);
}
inline void Span_1__ctor_m23CBCD46AD762681A232C97FE90B3A9EDD4991E5_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D*, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*, const RuntimeMethod*))Span_1__ctor_m23CBCD46AD762681A232C97FE90B3A9EDD4991E5_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m83147EFB62B7FFBA49EEBEBE975F7348D665BAD0_inline (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018*, const RuntimeMethod*))Span_1_get_Length_m83147EFB62B7FFBA49EEBEBE975F7348D665BAD0_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_m3B15D4D61932A340BAAA5BE6E8D419605D3692E6 (Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* ___0_destination, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_m3B15D4D61932A340BAAA5BE6E8D419605D3692E6_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_mD46BD07C5320D1B1A225E53FAF466E153FFC1679_inline (ReadOnlySpan_1_t7EE9E7096EE52CA433AA61A9353AD90B29B2C816* __this, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t7EE9E7096EE52CA433AA61A9353AD90B29B2C816*, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_mD46BD07C5320D1B1A225E53FAF466E153FFC1679_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m48419159317F9826172EDEA69FDB0598B87B34D2_inline (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018*, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*, int32_t, const RuntimeMethod*))Span_1__ctor_m48419159317F9826172EDEA69FDB0598B87B34D2_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* Array_Empty_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_m7E922E24AAEBD664256383832D53DDF17E1F3052_inline (const RuntimeMethod* method)
{
	return ((  ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* (*) (const RuntimeMethod*))Array_Empty_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_m7E922E24AAEBD664256383832D53DDF17E1F3052_gshared_inline)(method);
}
inline void Span_1__ctor_mD8CCC80CA9129EEAC13B40BA31C6C577BDF46ECD_inline (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018*, ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389*, const RuntimeMethod*))Span_1__ctor_mD8CCC80CA9129EEAC13B40BA31C6C577BDF46ECD_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m413F20ECFE3F523163B62ED5BAB7DFA22F2FCCD4_inline (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D*, const RuntimeMethod*))Span_1_get_Length_m413F20ECFE3F523163B62ED5BAB7DFA22F2FCCD4_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_mA65CAF282F03FD4DB46666E2C44C22E3D0035A68 (Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* ___0_destination, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_mA65CAF282F03FD4DB46666E2C44C22E3D0035A68_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_m841651F5E0DEC77984A109EF01090F3F776571FB_inline (ReadOnlySpan_1_t2E193A80641154947640E9A71614019D7A8F3DFC* __this, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t2E193A80641154947640E9A71614019D7A8F3DFC*, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_m841651F5E0DEC77984A109EF01090F3F776571FB_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_mD16E04B2ED38420390E0DE1D6E01DE23C583B434_inline (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D*, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*, int32_t, const RuntimeMethod*))Span_1__ctor_mD16E04B2ED38420390E0DE1D6E01DE23C583B434_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* Array_Empty_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m5B415C4745E47108DD9258EBCCB422EFD6B8A0EB_inline (const RuntimeMethod* method)
{
	return ((  Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* (*) (const RuntimeMethod*))Array_Empty_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m5B415C4745E47108DD9258EBCCB422EFD6B8A0EB_gshared_inline)(method);
}
inline void Span_1__ctor_mDE7408B1AC4D3DDE1E8EB6C1A8AE8244CAB0BBB1_inline (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D*, Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259*, const RuntimeMethod*))Span_1__ctor_mDE7408B1AC4D3DDE1E8EB6C1A8AE8244CAB0BBB1_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m3B50FB2CF29A0E7C0C8B69E4E5A72D75883EBC4B_inline (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48*, const RuntimeMethod*))Span_1_get_Length_m3B50FB2CF29A0E7C0C8B69E4E5A72D75883EBC4B_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1_m747B7D7DC0AA466783F69D3676EC5EE854D08D52 (ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* ___0_destination, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1_m747B7D7DC0AA466783F69D3676EC5EE854D08D52_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_mDB9E4DFF0687E0A5405FF4F6387379524B1B07AB_inline (ReadOnlySpan_1_t1CFFA3B34C09F05622921AC4014011D43A25715A* __this, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t1CFFA3B34C09F05622921AC4014011D43A25715A*, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_mDB9E4DFF0687E0A5405FF4F6387379524B1B07AB_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m1910D0E44CCD92AD908E1D5F61FFF27ADFE1EFAD_inline (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48*, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*, int32_t, const RuntimeMethod*))Span_1__ctor_m1910D0E44CCD92AD908E1D5F61FFF27ADFE1EFAD_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* Array_Empty_TisConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1_m164EDF2519D24430C10F8BB106ADB252BF225C26_inline (const RuntimeMethod* method)
{
	return ((  ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* (*) (const RuntimeMethod*))Array_Empty_TisConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1_m164EDF2519D24430C10F8BB106ADB252BF225C26_gshared_inline)(method);
}
inline void Span_1__ctor_mE396EB49F11B34D41818F29E84D8865E2003B251_inline (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48*, ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2*, const RuntimeMethod*))Span_1__ctor_mE396EB49F11B34D41818F29E84D8865E2003B251_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_mEC383018256E25827F3B339475CABFC2C2237A88_inline (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE*, const RuntimeMethod*))Span_1_get_Length_mEC383018256E25827F3B339475CABFC2C2237A88_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisCopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044_m49C533FCD49E82DED6CE9BFF4EE71DBC632E91A0 (CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* ___0_destination, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisCopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044_m49C533FCD49E82DED6CE9BFF4EE71DBC632E91A0_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_m4D4193A630867D8532F94829D1B330477153F6F5_inline (ReadOnlySpan_1_t65511D2895327A8ECE2BF5A34FDD23AE34C83122* __this, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t65511D2895327A8ECE2BF5A34FDD23AE34C83122*, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_m4D4193A630867D8532F94829D1B330477153F6F5_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_mCD3AE57570C815AC4046DA4D9E7C0A9E2BBEB547_inline (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE*, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*, int32_t, const RuntimeMethod*))Span_1__ctor_mCD3AE57570C815AC4046DA4D9E7C0A9E2BBEB547_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* Array_Empty_TisCopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044_mE213035FEF51FB6A504BDD242F0307E9FE074829_inline (const RuntimeMethod* method)
{
	return ((  CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* (*) (const RuntimeMethod*))Array_Empty_TisCopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044_mE213035FEF51FB6A504BDD242F0307E9FE074829_gshared_inline)(method);
}
inline void Span_1__ctor_m2817AF8060669CE2B4F3418E7732492AE1043541_inline (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE*, CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57*, const RuntimeMethod*))Span_1__ctor_m2817AF8060669CE2B4F3418E7732492AE1043541_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m385F87A001B432F97C5381EF1F01B485642ED27D_inline (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116*, const RuntimeMethod*))Span_1_get_Length_m385F87A001B432F97C5381EF1F01B485642ED27D_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m9A4B5780CB8BC1ACD63C193EC68D5E217CDBAC80 (CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* ___0_destination, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m9A4B5780CB8BC1ACD63C193EC68D5E217CDBAC80_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_m7515BCC9EAB305B335A968E684B597A1FC9A5F24_inline (ReadOnlySpan_1_t7918A88B9E042EA0B873C90C85D2A8B97CB11BDF* __this, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t7918A88B9E042EA0B873C90C85D2A8B97CB11BDF*, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_m7515BCC9EAB305B335A968E684B597A1FC9A5F24_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m938DD54F3773C27DD1393A85BB94346047AD1DA5_inline (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116*, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*, int32_t, const RuntimeMethod*))Span_1__ctor_m938DD54F3773C27DD1393A85BB94346047AD1DA5_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* Array_Empty_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m46787E1D6E481E4790F1F9E63000A067C9AF33CD_inline (const RuntimeMethod* method)
{
	return ((  CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* (*) (const RuntimeMethod*))Array_Empty_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m46787E1D6E481E4790F1F9E63000A067C9AF33CD_gshared_inline)(method);
}
inline void Span_1__ctor_m59E7D308EB85B51BA4162E76EE21E5568E986970_inline (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116*, CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61*, const RuntimeMethod*))Span_1__ctor_m59E7D308EB85B51BA4162E76EE21E5568E986970_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_mFF4419EF107B2F1CD3364357F9723EAC96433F03_inline (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73*, const RuntimeMethod*))Span_1_get_Length_mFF4419EF107B2F1CD3364357F9723EAC96433F03_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisDrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5_mDF1CDB2973A50B932ED2E72CC7A57E75C7FCAB54 (DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* ___0_destination, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisDrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5_mDF1CDB2973A50B932ED2E72CC7A57E75C7FCAB54_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_mB6153B16E29314D6497048CA9F509CF21C277F71_inline (ReadOnlySpan_1_tB185515663CA8B149175531C2C9804EB48DDEC9B* __this, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_tB185515663CA8B149175531C2C9804EB48DDEC9B*, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_mB6153B16E29314D6497048CA9F509CF21C277F71_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m52DDC62CEE4B57B1A97604C59D91F867D9C9472B_inline (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73*, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*, int32_t, const RuntimeMethod*))Span_1__ctor_m52DDC62CEE4B57B1A97604C59D91F867D9C9472B_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* Array_Empty_TisDrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5_m05A4DA3A4ACD6D784909779870EE466DF7778EC7_inline (const RuntimeMethod* method)
{
	return ((  DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* (*) (const RuntimeMethod*))Array_Empty_TisDrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5_m05A4DA3A4ACD6D784909779870EE466DF7778EC7_gshared_inline)(method);
}
inline void Span_1__ctor_m7F574E10BF82902E6DFCF264F060076901BC34C0_inline (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73*, DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB*, const RuntimeMethod*))Span_1__ctor_m7F574E10BF82902E6DFCF264F060076901BC34C0_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m4AFBDAB740A9ECD13948F54329A3D84FD198CB73_inline (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68*, const RuntimeMethod*))Span_1_get_Length_m4AFBDAB740A9ECD13948F54329A3D84FD198CB73_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisGfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C_m2CA00C03921B3C30B95A8129FDEA92912124ED5E (GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* ___0_destination, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisGfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C_m2CA00C03921B3C30B95A8129FDEA92912124ED5E_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_m8560DF2D26A1CC196BDE7BB7DFC896FB3D65EA16_inline (ReadOnlySpan_1_tBE8F7CF96CF1493E2EA4ED19616DF91D5FF56E7C* __this, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_tBE8F7CF96CF1493E2EA4ED19616DF91D5FF56E7C*, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_m8560DF2D26A1CC196BDE7BB7DFC896FB3D65EA16_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_mABCC2BDB018D99B11CE82B53D6EDE75D4455193F_inline (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68*, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*, int32_t, const RuntimeMethod*))Span_1__ctor_mABCC2BDB018D99B11CE82B53D6EDE75D4455193F_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* Array_Empty_TisGfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C_mC6C376B567AC6FA4773E73349EE73E984E47852B_inline (const RuntimeMethod* method)
{
	return ((  GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* (*) (const RuntimeMethod*))Array_Empty_TisGfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C_mC6C376B567AC6FA4773E73349EE73E984E47852B_gshared_inline)(method);
}
inline void Span_1__ctor_mEAFD68654E9CB51239357C3D94CDB5056137D70B_inline (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68*, GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30*, const RuntimeMethod*))Span_1__ctor_mEAFD68654E9CB51239357C3D94CDB5056137D70B_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m87AB3C694F2E4802F14D006F21C020816045285F_inline (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316*, const RuntimeMethod*))Span_1_get_Length_m87AB3C694F2E4802F14D006F21C020816045285F_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m1CD5B4A82FDDB0C96C8ABC21339D0339688CEEAB (int32_t* ___0_destination, int32_t* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (int32_t*, int32_t*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m1CD5B4A82FDDB0C96C8ABC21339D0339688CEEAB_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_mA0D85386F3D3AAF59FC429C4A2A9E7CD6B7DCF2A_inline (ReadOnlySpan_1_t6190994DF094ABDFA6908C2C3FB347457E8E4282* __this, int32_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t6190994DF094ABDFA6908C2C3FB347457E8E4282*, int32_t*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_mA0D85386F3D3AAF59FC429C4A2A9E7CD6B7DCF2A_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m89B8042F831A4ACF35D15B29B8141AE29CFFDF84_inline (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, int32_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316*, int32_t*, int32_t, const RuntimeMethod*))Span_1__ctor_m89B8042F831A4ACF35D15B29B8141AE29CFFDF84_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* Array_Empty_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m4D53E0E0F90F37AD5DBFD2DC75E52406F90C7ABC_inline (const RuntimeMethod* method)
{
	return ((  Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* (*) (const RuntimeMethod*))Array_Empty_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m4D53E0E0F90F37AD5DBFD2DC75E52406F90C7ABC_gshared_inline)(method);
}
inline void Span_1__ctor_m176441CFA181B7C6097611CC13C24C5ED7F14CFF_inline (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316*, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, const RuntimeMethod*))Span_1__ctor_m176441CFA181B7C6097611CC13C24C5ED7F14CFF_gshared_inline)(__this, ___0_array, method);
}
inline int32_t Span_1_get_Length_m0BE6EA932B404A54A3AF19C9654ED2611196FAE5_inline (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211*, const RuntimeMethod*))Span_1_get_Length_m0BE6EA932B404A54A3AF19C9654ED2611196FAE5_gshared_inline)(__this, method);
}
inline void Buffer_Memmove_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m4DF13B5C2D27E38BFD7112649345659B81B99988 (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___0_destination, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___1_source, uint64_t ___2_elementCount, const RuntimeMethod* method)
{
	((  void (*) (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, uint64_t, const RuntimeMethod*))Buffer_Memmove_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m4DF13B5C2D27E38BFD7112649345659B81B99988_gshared)(___0_destination, ___1_source, ___2_elementCount, method);
}
inline void ReadOnlySpan_1__ctor_m5146D98DC32810D3BC61D690968758CF2711417A_inline (ReadOnlySpan_1_t09FC5325A7B15784D246B5B71F829AB1C98B41DB* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlySpan_1_t09FC5325A7B15784D246B5B71F829AB1C98B41DB*, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, int32_t, const RuntimeMethod*))ReadOnlySpan_1__ctor_m5146D98DC32810D3BC61D690968758CF2711417A_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline void Span_1__ctor_m495B7963DA5CE2A2F3D69EAEBDD7BF73A1B34A31_inline (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211*, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, int32_t, const RuntimeMethod*))Span_1__ctor_m495B7963DA5CE2A2F3D69EAEBDD7BF73A1B34A31_gshared_inline)(__this, ___0_ptr, ___1_length, method);
}
inline JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* Array_Empty_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m65AF0C73C7E00505BCE35B9CC15EE8C8F6F0A01E_inline (const RuntimeMethod* method)
{
	return ((  JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* (*) (const RuntimeMethod*))Array_Empty_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m65AF0C73C7E00505BCE35B9CC15EE8C8F6F0A01E_gshared_inline)(method);
}
inline void Span_1__ctor_m639F3CC8B14984E278FC347886BA5C0D86C7A4B9_inline (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, const RuntimeMethod* method)
{
	((  void (*) (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211*, JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*, const RuntimeMethod*))Span_1__ctor_m639F3CC8B14984E278FC347886BA5C0D86C7A4B9_gshared_inline)(__this, ___0_array, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerUnsafeUtility_BeginSample_mB5106F4E7ECEF54906545665ED23928D14F5FCA7 (intptr_t ___0_markerPtr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerUnsafeUtility_EndSample_mFDB4EFB160A9CB817D2F8ED21B88693616B27409 (intptr_t ___0_markerPtr, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ShaderInfoStorage_1__ctor_mFE6521060564BB839835FA902AA1D9BA02F85E86_gshared (ShaderInfoStorage_1_t32194748F3ED0F5527B4E31A28D04606FAEE539A* __this, int32_t ___0_format, Func_2_t781E8579E9FF2D1F9E663A289445D85212CBE782* ___1_convert, int32_t ___2_initialSize, int32_t ___3_maxSize, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var);
		BaseShaderInfoStorage__ctor_m5CD6C884D6587272D9C90F8DEE2BE0C38A5C4DBB((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2*)__this, NULL);
		int32_t L_0 = ___3_maxSize;
		int32_t L_1;
		L_1 = SystemInfo_get_maxTextureSize_mEE557C09643222591C6F4D3F561D7A60CD403991(NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Assert_m6E778CACD0F440E2DEA9ACDD9330A22DAF16E96D((bool)((((int32_t)((((int32_t)L_0) > ((int32_t)L_1))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_2 = ___2_initialSize;
		int32_t L_3 = ___3_maxSize;
		Debug_Assert_m6E778CACD0F440E2DEA9ACDD9330A22DAF16E96D((bool)((((int32_t)((((int32_t)L_2) > ((int32_t)L_3))? 1 : 0)) == ((int32_t)0))? 1 : 0), NULL);
		int32_t L_4 = ___2_initialSize;
		bool L_5;
		L_5 = Mathf_IsPowerOfTwo_m58172AEBE272F53FD34CC10641057847181E960A(L_4, NULL);
		Debug_Assert_m6E778CACD0F440E2DEA9ACDD9330A22DAF16E96D(L_5, NULL);
		int32_t L_6 = ___3_maxSize;
		bool L_7;
		L_7 = Mathf_IsPowerOfTwo_m58172AEBE272F53FD34CC10641057847181E960A(L_6, NULL);
		Debug_Assert_m6E778CACD0F440E2DEA9ACDD9330A22DAF16E96D(L_7, NULL);
		Func_2_t781E8579E9FF2D1F9E663A289445D85212CBE782* L_8 = ___1_convert;
		Debug_Assert_m6E778CACD0F440E2DEA9ACDD9330A22DAF16E96D((bool)((!(((RuntimeObject*)(Func_2_t781E8579E9FF2D1F9E663A289445D85212CBE782*)L_8) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0), NULL);
		int32_t L_9 = ___2_initialSize;
		__this->___m_InitialSize = L_9;
		int32_t L_10 = ___3_maxSize;
		__this->___m_MaxSize = L_10;
		int32_t L_11 = ___0_format;
		__this->___m_Format = L_11;
		Func_2_t781E8579E9FF2D1F9E663A289445D85212CBE782* L_12 = ___1_convert;
		__this->___m_Convert = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Convert), (void*)L_12);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ShaderInfoStorage_1_Dispose_m3A95983FB76FC8AFBD0EB90D9B7FAD40536E05C4_gshared (ShaderInfoStorage_1_t32194748F3ED0F5527B4E31A28D04606FAEE539A* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIRUtility_tBBCA94052EAE57F0A59876553C582FFCF52E706C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* G_B3_0 = NULL;
	UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* G_B2_0 = NULL;
	{
		NullCheck((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2*)__this);
		bool L_0;
		L_0 = BaseShaderInfoStorage_get_disposed_mAF7F54A791E6AF75BF1AD71B1DDA85099BFCE1EF_inline((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2*)__this, NULL);
		bool L_1 = ___0_disposing;
		V_0 = (bool)((int32_t)(((((int32_t)L_0) == ((int32_t)0))? 1 : 0)&(int32_t)L_1));
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_004a;
		}
	}
	{
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_3 = __this->___m_Texture;
		il2cpp_codegen_runtime_class_init_inline(UIRUtility_tBBCA94052EAE57F0A59876553C582FFCF52E706C_il2cpp_TypeInfo_var);
		UIRUtility_Destroy_m9E925E79E7B4A4853B47C1EFACEF2ED0A7844A23((Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)L_3, NULL);
		__this->___m_Texture = (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Texture), (void*)(Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4*)NULL);
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_4 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Texels);
		il2cpp_codegen_initobj(L_4, sizeof(NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18));
		UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* L_5 = __this->___m_Allocator;
		UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* L_6 = L_5;
		if (L_6)
		{
			G_B3_0 = L_6;
			goto IL_003c;
		}
		G_B2_0 = L_6;
	}
	{
		goto IL_0042;
	}

IL_003c:
	{
		NullCheck(G_B3_0);
		UIRAtlasAllocator_Dispose_mB956D63F99999BA479695669265B4E6F9755D155(G_B3_0, NULL);
	}

IL_0042:
	{
		__this->___m_Allocator = (UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Allocator), (void*)(UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7*)NULL);
	}

IL_004a:
	{
		bool L_7 = ___0_disposing;
		NullCheck((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2*)__this);
		BaseShaderInfoStorage_Dispose_m4346D0BFF23C896046CB1A774E6EB4F4EFC9E56F((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2*)__this, L_7, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* ShaderInfoStorage_1_get_texture_m6C37ECA9DABA5D261E358801335376BE5A4ECE4B_gshared (ShaderInfoStorage_1_t32194748F3ED0F5527B4E31A28D04606FAEE539A* __this, const RuntimeMethod* method) 
{
	{
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_0 = __this->___m_Texture;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ShaderInfoStorage_1_AllocateRect_mF0004D550D493D1C12BB4B259293F1DD082BEC88_gshared (ShaderInfoStorage_1_t32194748F3ED0F5527B4E31A28D04606FAEE539A* __this, int32_t ___0_width, int32_t ___1_height, RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* ___2_uvs, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	{
		NullCheck((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2*)__this);
		bool L_0;
		L_0 = BaseShaderInfoStorage_get_disposed_mAF7F54A791E6AF75BF1AD71B1DDA85099BFCE1EF_inline((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2*)__this, NULL);
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_001e;
		}
	}
	{
		DisposeHelper_NotifyDisposedUsed_m7A9C988A4B96B0920E470EEA604BA42C5ABB437F((RuntimeObject*)__this, NULL);
		RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* L_2 = ___2_uvs;
		il2cpp_codegen_initobj(L_2, sizeof(RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8));
		V_1 = (bool)0;
		goto IL_0080;
	}

IL_001e:
	{
		UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* L_3 = __this->___m_Allocator;
		V_2 = (bool)((((RuntimeObject*)(UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7*)L_3) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		bool L_4 = V_2;
		if (!L_4)
		{
			goto IL_0043;
		}
	}
	{
		int32_t L_5 = __this->___m_InitialSize;
		int32_t L_6 = __this->___m_MaxSize;
		UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* L_7 = (UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7*)il2cpp_codegen_object_new(UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7_il2cpp_TypeInfo_var);
		UIRAtlasAllocator__ctor_m4263398EB9C4D3D4C8B752C441A1D8F1044B8DF2(L_7, L_5, L_6, 0, NULL);
		__this->___m_Allocator = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Allocator), (void*)L_7);
	}

IL_0043:
	{
		UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* L_8 = __this->___m_Allocator;
		int32_t L_9 = ___0_width;
		int32_t L_10 = ___1_height;
		RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* L_11 = ___2_uvs;
		NullCheck(L_8);
		bool L_12;
		L_12 = UIRAtlasAllocator_TryAllocate_m4DE2C4C9761F6C736122F59AA11BA6E29021E187(L_8, L_9, L_10, L_11, NULL);
		V_3 = (bool)((((int32_t)L_12) == ((int32_t)0))? 1 : 0);
		bool L_13 = V_3;
		if (!L_13)
		{
			goto IL_005c;
		}
	}
	{
		V_1 = (bool)0;
		goto IL_0080;
	}

IL_005c:
	{
		RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* L_14 = ___2_uvs;
		RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* L_15 = ___2_uvs;
		int32_t L_16;
		L_16 = RectInt_get_x_mA1E7EF6DEAD2E900D7D56B7A3957C05081EBA9CA_inline(L_15, NULL);
		RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* L_17 = ___2_uvs;
		int32_t L_18;
		L_18 = RectInt_get_y_m440422264E6FCAA91E01F81486A78037AC29D878_inline(L_17, NULL);
		int32_t L_19 = ___0_width;
		int32_t L_20 = ___1_height;
		RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8 L_21;
		memset((&L_21), 0, sizeof(L_21));
		RectInt__ctor_m6E8B3A6C7EE11257A6B438E36274116FE39B5B42_inline((&L_21), L_16, L_18, L_19, L_20, NULL);
		*(RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8*)L_14 = L_21;
		((  void (*) (ShaderInfoStorage_1_t32194748F3ED0F5527B4E31A28D04606FAEE539A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 3)))(__this, il2cpp_rgctx_method(method->klass->rgctx_data, 3));
		V_1 = (bool)1;
		goto IL_0080;
	}

IL_0080:
	{
		bool L_22 = V_1;
		return L_22;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ShaderInfoStorage_1_SetTexel_m5F6938D6AD91CBA99FD3A575B4E1D2CB02669A89_gshared (ShaderInfoStorage_1_t32194748F3ED0F5527B4E31A28D04606FAEE539A* __this, int32_t ___0_x, int32_t ___1_y, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___2_color, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_T_tDC969906238A4B266B1EEEE339C754265058C711 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 8));
	const Il2CppFullySharedGenericStruct L_14 = alloca(SizeOf_T_tDC969906238A4B266B1EEEE339C754265058C711);
	bool V_0 = false;
	bool V_1 = false;
	{
		NullCheck((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2*)__this);
		bool L_0;
		L_0 = BaseShaderInfoStorage_get_disposed_mAF7F54A791E6AF75BF1AD71B1DDA85099BFCE1EF_inline((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2*)__this, NULL);
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		DisposeHelper_NotifyDisposedUsed_m7A9C988A4B96B0920E470EEA604BA42C5ABB437F((RuntimeObject*)__this, NULL);
		goto IL_0077;
	}

IL_0015:
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_2 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Texels);
		bool L_3;
		L_3 = ((  bool (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 4)))(L_2, il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		V_1 = (bool)((((int32_t)L_3) == ((int32_t)0))? 1 : 0);
		bool L_4 = V_1;
		if (!L_4)
		{
			goto IL_0050;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var);
		ProfilerMarker_Begin_mD07DB736ADA7D8BAF9D969CC7F3C55848A218C6E_inline((&((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_StaticFields*)il2cpp_codegen_static_fields_for(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var))->___s_MarkerGetTextureData), NULL);
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_5 = __this->___m_Texture;
		NullCheck(L_5);
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_6;
		L_6 = ((  NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 (*) (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 6)))(L_5, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		__this->___m_Texels = L_6;
		ProfilerMarker_End_m025AE3EF0F96F6DADC53489A53FC6EE65073DE60_inline((&((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_StaticFields*)il2cpp_codegen_static_fields_for(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var))->___s_MarkerGetTextureData), NULL);
	}

IL_0050:
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_7 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Texels);
		int32_t L_8 = ___0_x;
		int32_t L_9 = ___1_y;
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_10 = __this->___m_Texture;
		NullCheck((Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_10);
		int32_t L_11;
		L_11 = VirtualFuncInvoker0< int32_t >::Invoke(4, (Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_10);
		Func_2_t781E8579E9FF2D1F9E663A289445D85212CBE782* L_12 = __this->___m_Convert;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_13 = ___2_color;
		NullCheck(L_12);
		InvokerActionInvoker2< Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 7)), il2cpp_rgctx_method(method->klass->rgctx_data, 7), L_12, L_13, (Il2CppFullySharedGenericStruct*)L_14);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 9)), il2cpp_rgctx_method(method->klass->rgctx_data, 9), L_7, ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)il2cpp_codegen_multiply(L_9, L_11)))), L_14);
	}

IL_0077:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ShaderInfoStorage_1_UpdateTexture_m9ACE3AFEC8022BA9756E8A10C8FB4F8D058FBBDA_gshared (ShaderInfoStorage_1_t32194748F3ED0F5527B4E31A28D04606FAEE539A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	int32_t G_B5_0 = 0;
	{
		NullCheck((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2*)__this);
		bool L_0;
		L_0 = BaseShaderInfoStorage_get_disposed_mAF7F54A791E6AF75BF1AD71B1DDA85099BFCE1EF_inline((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2*)__this, NULL);
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		DisposeHelper_NotifyDisposedUsed_m7A9C988A4B96B0920E470EEA604BA42C5ABB437F((RuntimeObject*)__this, NULL);
		goto IL_006a;
	}

IL_0015:
	{
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_2 = __this->___m_Texture;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605((Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)L_2, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (L_3)
		{
			goto IL_0033;
		}
	}
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_4 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Texels);
		bool L_5;
		L_5 = ((  bool (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 4)))(L_4, il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		G_B5_0 = ((((int32_t)L_5) == ((int32_t)0))? 1 : 0);
		goto IL_0034;
	}

IL_0033:
	{
		G_B5_0 = 1;
	}

IL_0034:
	{
		V_1 = (bool)G_B5_0;
		bool L_6 = V_1;
		if (!L_6)
		{
			goto IL_003a;
		}
	}
	{
		goto IL_006a;
	}

IL_003a:
	{
		il2cpp_codegen_runtime_class_init_inline(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var);
		ProfilerMarker_Begin_mD07DB736ADA7D8BAF9D969CC7F3C55848A218C6E_inline((&((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_StaticFields*)il2cpp_codegen_static_fields_for(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var))->___s_MarkerUpdateTexture), NULL);
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_7 = __this->___m_Texture;
		NullCheck(L_7);
		Texture2D_Apply_m36EE27E6F1BF7FB8C70A1D749DC4EE249810AA3A(L_7, (bool)0, (bool)0, NULL);
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_8 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Texels);
		il2cpp_codegen_initobj(L_8, sizeof(NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18));
		ProfilerMarker_End_m025AE3EF0F96F6DADC53489A53FC6EE65073DE60_inline((&((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_StaticFields*)il2cpp_codegen_static_fields_for(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var))->___s_MarkerUpdateTexture), NULL);
	}

IL_006a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ShaderInfoStorage_1_CreateOrExpandTexture_m8642AC345100DA2F4FA6D2DC5E283FB777730361_gshared (ShaderInfoStorage_1_t32194748F3ED0F5527B4E31A28D04606FAEE539A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UIRUtility_tBBCA94052EAE57F0A59876553C582FFCF52E706C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral358A3678217D3CE720F0C294149170B975E33338);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	bool V_2 = false;
	Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* V_3 = NULL;
	bool V_4 = false;
	bool V_5 = false;
	int32_t V_6 = 0;
	bool V_7 = false;
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 V_8;
	memset((&V_8), 0, sizeof(V_8));
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 V_9;
	memset((&V_9), 0, sizeof(V_9));
	int32_t G_B4_0 = 0;
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 G_B11_0;
	memset((&G_B11_0), 0, sizeof(G_B11_0));
	{
		UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* L_0 = __this->___m_Allocator;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = UIRAtlasAllocator_get_physicalWidth_m0B06147154436A555CEABB9C9EB319D7D33A5398_inline(L_0, NULL);
		V_0 = L_1;
		UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* L_2 = __this->___m_Allocator;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = UIRAtlasAllocator_get_physicalHeight_m736C92B2C509CE66BAFFBA87110103BBC72DBD88_inline(L_2, NULL);
		V_1 = L_3;
		V_2 = (bool)0;
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_4 = __this->___m_Texture;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_5;
		L_5 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602((Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)L_4, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_4 = L_5;
		bool L_6 = V_4;
		if (!L_6)
		{
			goto IL_005b;
		}
	}
	{
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_7 = __this->___m_Texture;
		NullCheck((Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_7);
		int32_t L_8;
		L_8 = VirtualFuncInvoker0< int32_t >::Invoke(4, (Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_7);
		int32_t L_9 = V_0;
		if ((!(((uint32_t)L_8) == ((uint32_t)L_9))))
		{
			goto IL_004c;
		}
	}
	{
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_10 = __this->___m_Texture;
		NullCheck((Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_10);
		int32_t L_11;
		L_11 = VirtualFuncInvoker0< int32_t >::Invoke(6, (Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_10);
		int32_t L_12 = V_1;
		G_B4_0 = ((((int32_t)L_11) == ((int32_t)L_12))? 1 : 0);
		goto IL_004d;
	}

IL_004c:
	{
		G_B4_0 = 0;
	}

IL_004d:
	{
		V_5 = (bool)G_B4_0;
		bool L_13 = V_5;
		if (!L_13)
		{
			goto IL_0058;
		}
	}
	{
		goto IL_0154;
	}

IL_0058:
	{
		V_2 = (bool)1;
	}

IL_005b:
	{
		UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* L_14 = __this->___m_Allocator;
		NullCheck(L_14);
		int32_t L_15;
		L_15 = UIRAtlasAllocator_get_physicalWidth_m0B06147154436A555CEABB9C9EB319D7D33A5398_inline(L_14, NULL);
		UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* L_16 = __this->___m_Allocator;
		NullCheck(L_16);
		int32_t L_17;
		L_17 = UIRAtlasAllocator_get_physicalHeight_m736C92B2C509CE66BAFFBA87110103BBC72DBD88_inline(L_16, NULL);
		int32_t L_18 = __this->___m_Format;
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_19 = (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4*)il2cpp_codegen_object_new(Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4_il2cpp_TypeInfo_var);
		Texture2D__ctor_mECF60A9EC0638EC353C02C8E99B6B465D23BE917(L_19, L_15, L_17, L_18, (bool)0, NULL);
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_20 = L_19;
		il2cpp_codegen_runtime_class_init_inline(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var);
		int32_t L_21 = ((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_StaticFields*)il2cpp_codegen_static_fields_for(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var))->___s_TextureCounter;
		int32_t L_22 = L_21;
		((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_StaticFields*)il2cpp_codegen_static_fields_for(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var))->___s_TextureCounter = ((int32_t)il2cpp_codegen_add(L_22, 1));
		V_6 = L_22;
		String_t* L_23;
		L_23 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_6), NULL);
		String_t* L_24;
		L_24 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral358A3678217D3CE720F0C294149170B975E33338, L_23, NULL);
		NullCheck((Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)L_20);
		Object_set_name_mC79E6DC8FFD72479C90F0C4CC7F42A0FEAF5AE47((Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)L_20, L_24, NULL);
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_25 = L_20;
		NullCheck((Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)L_25);
		Object_set_hideFlags_mACB8BFC903FB3B01BBD427753E791BF28B5E33D4((Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)L_25, (int32_t)((int32_t)61), NULL);
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_26 = L_25;
		NullCheck((Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_26);
		Texture_set_filterMode_mE423E58C0C16D059EA62BA87AD70F44AEA50CCC9((Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_26, (int32_t)0, NULL);
		V_3 = L_26;
		bool L_27 = V_2;
		V_7 = L_27;
		bool L_28 = V_7;
		if (!L_28)
		{
			goto IL_0135;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var);
		ProfilerMarker_Begin_mD07DB736ADA7D8BAF9D969CC7F3C55848A218C6E_inline((&((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_StaticFields*)il2cpp_codegen_static_fields_for(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var))->___s_MarkerCopyTexture), NULL);
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_29 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Texels);
		bool L_30;
		L_30 = ((  bool (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 4)))(L_29, il2cpp_rgctx_method(method->klass->rgctx_data, 4));
		if (L_30)
		{
			goto IL_00e3;
		}
	}
	{
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_31 = __this->___m_Texture;
		NullCheck(L_31);
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_32;
		L_32 = ((  NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 (*) (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 6)))(L_31, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		G_B11_0 = L_32;
		goto IL_00e9;
	}

IL_00e3:
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_33 = __this->___m_Texels;
		G_B11_0 = L_33;
	}

IL_00e9:
	{
		V_8 = G_B11_0;
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_34 = V_3;
		NullCheck(L_34);
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_35;
		L_35 = ((  NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 (*) (Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 6)))(L_34, il2cpp_rgctx_method(method->klass->rgctx_data, 6));
		V_9 = L_35;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_36 = V_8;
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_37 = __this->___m_Texture;
		NullCheck((Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_37);
		int32_t L_38;
		L_38 = VirtualFuncInvoker0< int32_t >::Invoke(4, (Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_37);
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_39 = __this->___m_Texture;
		NullCheck((Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_39);
		int32_t L_40;
		L_40 = VirtualFuncInvoker0< int32_t >::Invoke(6, (Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_39);
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_41 = V_9;
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_42 = V_3;
		NullCheck((Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_42);
		int32_t L_43;
		L_43 = VirtualFuncInvoker0< int32_t >::Invoke(4, (Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_42);
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_44 = V_3;
		NullCheck((Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_44);
		int32_t L_45;
		L_45 = VirtualFuncInvoker0< int32_t >::Invoke(6, (Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700*)L_44);
		((  void (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, int32_t, int32_t, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 10)))(L_36, L_38, L_40, L_41, L_43, L_45, il2cpp_rgctx_method(method->klass->rgctx_data, 10));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_46 = V_9;
		__this->___m_Texels = L_46;
		il2cpp_codegen_runtime_class_init_inline(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var);
		ProfilerMarker_End_m025AE3EF0F96F6DADC53489A53FC6EE65073DE60_inline((&((BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_StaticFields*)il2cpp_codegen_static_fields_for(BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2_il2cpp_TypeInfo_var))->___s_MarkerCopyTexture), NULL);
		goto IL_0141;
	}

IL_0135:
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_47 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Texels);
		il2cpp_codegen_initobj(L_47, sizeof(NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18));
	}

IL_0141:
	{
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_48 = __this->___m_Texture;
		il2cpp_codegen_runtime_class_init_inline(UIRUtility_tBBCA94052EAE57F0A59876553C582FFCF52E706C_il2cpp_TypeInfo_var);
		UIRUtility_Destroy_m9E925E79E7B4A4853B47C1EFACEF2ED0A7844A23((Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)L_48, NULL);
		Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* L_49 = V_3;
		__this->___m_Texture = L_49;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Texture), (void*)L_49);
	}

IL_0154:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ShaderInfoStorage_1_CpuBlit_m0E45789132A1E82D5777E6170B1D9470441F21BD_gshared (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_src, int32_t ___1_srcWidth, int32_t ___2_srcHeight, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___3_dst, int32_t ___4_dstWidth, int32_t ___5_dstHeight, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_T_tDC969906238A4B266B1EEEE339C754265058C711 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(InitializedTypeInfo(method->klass)->rgctx_data, 8));
	const Il2CppFullySharedGenericStruct L_13 = alloca(SizeOf_T_tDC969906238A4B266B1EEEE339C754265058C711);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	bool V_6 = false;
	bool V_7 = false;
	int32_t G_B3_0 = 0;
	{
		int32_t L_0 = ___4_dstWidth;
		int32_t L_1 = ___1_srcWidth;
		if ((((int32_t)L_0) < ((int32_t)L_1)))
		{
			goto IL_0010;
		}
	}
	{
		int32_t L_2 = ___5_dstHeight;
		int32_t L_3 = ___2_srcHeight;
		G_B3_0 = ((((int32_t)((((int32_t)L_2) < ((int32_t)L_3))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		goto IL_0011;
	}

IL_0010:
	{
		G_B3_0 = 0;
	}

IL_0011:
	{
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Assert_m6E778CACD0F440E2DEA9ACDD9330A22DAF16E96D((bool)G_B3_0, NULL);
		int32_t L_4 = ___4_dstWidth;
		int32_t L_5 = ___1_srcWidth;
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_4, L_5));
		int32_t L_6 = ___5_dstHeight;
		int32_t L_7 = ___2_srcHeight;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_6, L_7));
		int32_t L_8 = ___1_srcWidth;
		int32_t L_9 = ___2_srcHeight;
		V_2 = ((int32_t)il2cpp_codegen_multiply(L_8, L_9));
		V_3 = 0;
		V_4 = 0;
		int32_t L_10 = ___1_srcWidth;
		V_5 = L_10;
		goto IL_0068;
	}

IL_002f:
	{
		goto IL_0050;
	}

IL_0032:
	{
		int32_t L_11 = V_4;
		int32_t L_12 = V_3;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 12)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 12), (&___0_src), L_12, (Il2CppFullySharedGenericStruct*)L_13);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 9)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 9), (&___3_dst), L_11, L_13);
		int32_t L_14 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_14, 1));
		int32_t L_15 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_15, 1));
	}

IL_0050:
	{
		int32_t L_16 = V_3;
		int32_t L_17 = V_5;
		V_6 = (bool)((((int32_t)L_16) < ((int32_t)L_17))? 1 : 0);
		bool L_18 = V_6;
		if (L_18)
		{
			goto IL_0032;
		}
	}
	{
		int32_t L_19 = V_5;
		int32_t L_20 = ___1_srcWidth;
		V_5 = ((int32_t)il2cpp_codegen_add(L_19, L_20));
		int32_t L_21 = V_4;
		int32_t L_22 = V_0;
		V_4 = ((int32_t)il2cpp_codegen_add(L_21, L_22));
	}

IL_0068:
	{
		int32_t L_23 = V_3;
		int32_t L_24 = V_2;
		V_7 = (bool)((((int32_t)L_23) < ((int32_t)L_24))? 1 : 0);
		bool L_25 = V_7;
		if (L_25)
		{
			goto IL_002f;
		}
	}
	{
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SharedStatic_1__ctor_mF83D06637E10F1C230BA4F1A841E742F6A5ED399_gshared (SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0* __this, void* ___0_buffer, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_buffer;
		__this->____buffer = L_0;
		return;
	}
}
IL2CPP_EXTERN_C  void SharedStatic_1__ctor_mF83D06637E10F1C230BA4F1A841E742F6A5ED399_AdjustorThunk (RuntimeObject* __this, void* ___0_buffer, const RuntimeMethod* method)
{
	SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0*>(__this + _offset);
	SharedStatic_1__ctor_mF83D06637E10F1C230BA4F1A841E742F6A5ED399_inline(_thisAdjusted, ___0_buffer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t* SharedStatic_1_get_Data_m42DD928B26C146E0D920D5348F2CEBC3C7F21C3D_gshared (SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0* __this, const RuntimeMethod* method) 
{
	{
		void* L_0 = __this->____buffer;
		intptr_t* L_1;
		L_1 = UnsafeUtility_AsRef_TisIntPtr_t_m5E80CE586FADFB0EE0E808A1A736F9BF28C2B28B_inline(L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 1));
		return L_1;
	}
}
IL2CPP_EXTERN_C  intptr_t* SharedStatic_1_get_Data_m42DD928B26C146E0D920D5348F2CEBC3C7F21C3D_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0*>(__this + _offset);
	intptr_t* _returnValue;
	_returnValue = SharedStatic_1_get_Data_m42DD928B26C146E0D920D5348F2CEBC3C7F21C3D(_thisAdjusted, method);
	return _returnValue;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SharedStatic_1__ctor_m467F9A64986F442AA4853C5C314D0A54D887CDDC_gshared (SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08* __this, void* ___0_buffer, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_buffer;
		__this->____buffer = L_0;
		return;
	}
}
IL2CPP_EXTERN_C  void SharedStatic_1__ctor_m467F9A64986F442AA4853C5C314D0A54D887CDDC_AdjustorThunk (RuntimeObject* __this, void* ___0_buffer, const RuntimeMethod* method)
{
	SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08*>(__this + _offset);
	SharedStatic_1__ctor_m467F9A64986F442AA4853C5C314D0A54D887CDDC_inline(_thisAdjusted, ___0_buffer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* SharedStatic_1_get_Data_m679BD82198B4EC1D89F2EDE946A60F4DEE8E47E2_gshared (SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08* __this, const RuntimeMethod* method) 
{
	{
		void* L_0 = __this->____buffer;
		Il2CppFullySharedGenericStruct* L_1;
		L_1 = ((  Il2CppFullySharedGenericStruct* (*) (void*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 1)))(L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 1));
		return L_1;
	}
}
IL2CPP_EXTERN_C  Il2CppFullySharedGenericStruct* SharedStatic_1_get_Data_m679BD82198B4EC1D89F2EDE946A60F4DEE8E47E2_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08*>(__this + _offset);
	Il2CppFullySharedGenericStruct* _returnValue;
	_returnValue = SharedStatic_1_get_Data_m679BD82198B4EC1D89F2EDE946A60F4DEE8E47E2(_thisAdjusted, method);
	return _returnValue;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ShortEnumEqualityComparer_1__ctor_mDF4021A13BC967B8F2160B8A016872E7025447E9_gshared (ShortEnumEqualityComparer_1_t93E714E73A6CDB76D15D51942E3800AB3E57DFF6* __this, const RuntimeMethod* method) 
{
	{
		((  void (*) (EnumEqualityComparer_1_tBE0A26FDB9917D9CB482A0E2018093AB3394FC1A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((EnumEqualityComparer_1_tBE0A26FDB9917D9CB482A0E2018093AB3394FC1A*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ShortEnumEqualityComparer_1__ctor_m61792EA8BEDC5EB839C9BE5113E73DE5E2C17C91_gshared (ShortEnumEqualityComparer_1_t93E714E73A6CDB76D15D51942E3800AB3E57DFF6* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_information, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	{
		((  void (*) (EnumEqualityComparer_1_tBE0A26FDB9917D9CB482A0E2018093AB3394FC1A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 0)))((EnumEqualityComparer_1_tBE0A26FDB9917D9CB482A0E2018093AB3394FC1A*)__this, il2cpp_rgctx_method(method->klass->rgctx_data, 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ShortEnumEqualityComparer_1_GetHashCode_m3DD7EC97F7CC8C9A3747EFB17278B3B4AF22E8E9_gshared (ShortEnumEqualityComparer_1_t93E714E73A6CDB76D15D51942E3800AB3E57DFF6* __this, Il2CppFullySharedGenericStruct ___0_obj, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_tF891361FC715BBD984F1037039A2A971DE20FE75 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->klass->rgctx_data, 3));
	const Il2CppFullySharedGenericStruct L_0 = alloca(SizeOf_T_tF891361FC715BBD984F1037039A2A971DE20FE75);
	int16_t V_0 = 0;
	{
		il2cpp_codegen_memcpy(L_0, ___0_obj, SizeOf_T_tF891361FC715BBD984F1037039A2A971DE20FE75);
		int32_t L_1;
		L_1 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 4)), il2cpp_rgctx_method(method->klass->rgctx_data, 4), NULL, L_0);
		V_0 = ((int16_t)L_1);
		int32_t L_2;
		L_2 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1((&V_0), NULL);
		return L_2;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void SpanAction_2_Invoke_m761FF4012DB09668C6A5AA76774E9F04199D212E_Multicast(SpanAction_2_t65B015FEFE1F64814AC2EFA0E19A38B1CFC53178* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, ValueTuple_3_tFD2ADB3DA89E958885034AAFEF1ABDA8C814D987 ___1_arg, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		SpanAction_2_t65B015FEFE1F64814AC2EFA0E19A38B1CFC53178* currentDelegate = reinterpret_cast<SpanAction_2_t65B015FEFE1F64814AC2EFA0E19A38B1CFC53178*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, ValueTuple_3_tFD2ADB3DA89E958885034AAFEF1ABDA8C814D987, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_span, ___1_arg, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void SpanAction_2_Invoke_m761FF4012DB09668C6A5AA76774E9F04199D212E_OpenInst(SpanAction_2_t65B015FEFE1F64814AC2EFA0E19A38B1CFC53178* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, ValueTuple_3_tFD2ADB3DA89E958885034AAFEF1ABDA8C814D987 ___1_arg, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, ValueTuple_3_tFD2ADB3DA89E958885034AAFEF1ABDA8C814D987, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_span, ___1_arg, method);
}
void SpanAction_2_Invoke_m761FF4012DB09668C6A5AA76774E9F04199D212E_OpenStatic(SpanAction_2_t65B015FEFE1F64814AC2EFA0E19A38B1CFC53178* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, ValueTuple_3_tFD2ADB3DA89E958885034AAFEF1ABDA8C814D987 ___1_arg, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, ValueTuple_3_tFD2ADB3DA89E958885034AAFEF1ABDA8C814D987, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_span, ___1_arg, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpanAction_2__ctor_m4BBCE8F9C0E8FCC935E1765742799AEAD48606AE_gshared (SpanAction_2_t65B015FEFE1F64814AC2EFA0E19A38B1CFC53178* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&SpanAction_2_Invoke_m761FF4012DB09668C6A5AA76774E9F04199D212E_OpenStatic;
		else
			{
				__this->___invoke_impl = __this->___method_ptr;
				__this->___method_code = (intptr_t)__this->___m_target;
			}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl = __this->___method_ptr;
		__this->___method_code = (intptr_t)__this->___m_target;
	}
	__this->___extra_arg = (intptr_t)&SpanAction_2_Invoke_m761FF4012DB09668C6A5AA76774E9F04199D212E_Multicast;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpanAction_2_Invoke_m761FF4012DB09668C6A5AA76774E9F04199D212E_gshared (SpanAction_2_t65B015FEFE1F64814AC2EFA0E19A38B1CFC53178* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, ValueTuple_3_tFD2ADB3DA89E958885034AAFEF1ABDA8C814D987 ___1_arg, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, ValueTuple_3_tFD2ADB3DA89E958885034AAFEF1ABDA8C814D987, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_span, ___1_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void SpanAction_2_Invoke_m65D110A8BF9027F070FA8CF53AF75D47A98C6E2A_Multicast(SpanAction_2_t84FDFFEECCC96A9A407DCB490E60340E38185947* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, ValueTuple_5_t558B9F95CA55DE5694FC58A3BEAE441BF728FB57 ___1_arg, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		SpanAction_2_t84FDFFEECCC96A9A407DCB490E60340E38185947* currentDelegate = reinterpret_cast<SpanAction_2_t84FDFFEECCC96A9A407DCB490E60340E38185947*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, ValueTuple_5_t558B9F95CA55DE5694FC58A3BEAE441BF728FB57, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_span, ___1_arg, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void SpanAction_2_Invoke_m65D110A8BF9027F070FA8CF53AF75D47A98C6E2A_OpenInst(SpanAction_2_t84FDFFEECCC96A9A407DCB490E60340E38185947* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, ValueTuple_5_t558B9F95CA55DE5694FC58A3BEAE441BF728FB57 ___1_arg, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, ValueTuple_5_t558B9F95CA55DE5694FC58A3BEAE441BF728FB57, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_span, ___1_arg, method);
}
void SpanAction_2_Invoke_m65D110A8BF9027F070FA8CF53AF75D47A98C6E2A_OpenStatic(SpanAction_2_t84FDFFEECCC96A9A407DCB490E60340E38185947* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, ValueTuple_5_t558B9F95CA55DE5694FC58A3BEAE441BF728FB57 ___1_arg, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, ValueTuple_5_t558B9F95CA55DE5694FC58A3BEAE441BF728FB57, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_span, ___1_arg, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpanAction_2__ctor_m52B80F2401AFC1EDA0C92BDEC3320FB33A9FEB85_gshared (SpanAction_2_t84FDFFEECCC96A9A407DCB490E60340E38185947* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&SpanAction_2_Invoke_m65D110A8BF9027F070FA8CF53AF75D47A98C6E2A_OpenStatic;
		else
			{
				__this->___invoke_impl = __this->___method_ptr;
				__this->___method_code = (intptr_t)__this->___m_target;
			}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl = __this->___method_ptr;
		__this->___method_code = (intptr_t)__this->___m_target;
	}
	__this->___extra_arg = (intptr_t)&SpanAction_2_Invoke_m65D110A8BF9027F070FA8CF53AF75D47A98C6E2A_Multicast;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpanAction_2_Invoke_m65D110A8BF9027F070FA8CF53AF75D47A98C6E2A_gshared (SpanAction_2_t84FDFFEECCC96A9A407DCB490E60340E38185947* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, ValueTuple_5_t558B9F95CA55DE5694FC58A3BEAE441BF728FB57 ___1_arg, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, ValueTuple_5_t558B9F95CA55DE5694FC58A3BEAE441BF728FB57, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_span, ___1_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void SpanAction_2_Invoke_m494D48610BBC75F2900F6C061FDD40B45EB91C47_Multicast(SpanAction_2_t02885A83F58261D2CFDC8FFBBCD7C8ECAF105A7B* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, ValueTuple_8_t9B4E1B0569C36F02E150189D05FFCC0A69667F85 ___1_arg, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		SpanAction_2_t02885A83F58261D2CFDC8FFBBCD7C8ECAF105A7B* currentDelegate = reinterpret_cast<SpanAction_2_t02885A83F58261D2CFDC8FFBBCD7C8ECAF105A7B*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, ValueTuple_8_t9B4E1B0569C36F02E150189D05FFCC0A69667F85, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_span, ___1_arg, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void SpanAction_2_Invoke_m494D48610BBC75F2900F6C061FDD40B45EB91C47_OpenInst(SpanAction_2_t02885A83F58261D2CFDC8FFBBCD7C8ECAF105A7B* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, ValueTuple_8_t9B4E1B0569C36F02E150189D05FFCC0A69667F85 ___1_arg, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, ValueTuple_8_t9B4E1B0569C36F02E150189D05FFCC0A69667F85, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_span, ___1_arg, method);
}
void SpanAction_2_Invoke_m494D48610BBC75F2900F6C061FDD40B45EB91C47_OpenStatic(SpanAction_2_t02885A83F58261D2CFDC8FFBBCD7C8ECAF105A7B* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, ValueTuple_8_t9B4E1B0569C36F02E150189D05FFCC0A69667F85 ___1_arg, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, ValueTuple_8_t9B4E1B0569C36F02E150189D05FFCC0A69667F85, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_span, ___1_arg, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpanAction_2__ctor_m779B33E518F02340D4E655DDF668877EE565FE88_gshared (SpanAction_2_t02885A83F58261D2CFDC8FFBBCD7C8ECAF105A7B* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&SpanAction_2_Invoke_m494D48610BBC75F2900F6C061FDD40B45EB91C47_OpenStatic;
		else
			{
				__this->___invoke_impl = __this->___method_ptr;
				__this->___method_code = (intptr_t)__this->___m_target;
			}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl = __this->___method_ptr;
		__this->___method_code = (intptr_t)__this->___m_target;
	}
	__this->___extra_arg = (intptr_t)&SpanAction_2_Invoke_m494D48610BBC75F2900F6C061FDD40B45EB91C47_Multicast;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpanAction_2_Invoke_m494D48610BBC75F2900F6C061FDD40B45EB91C47_gshared (SpanAction_2_t02885A83F58261D2CFDC8FFBBCD7C8ECAF105A7B* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, ValueTuple_8_t9B4E1B0569C36F02E150189D05FFCC0A69667F85 ___1_arg, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D, ValueTuple_8_t9B4E1B0569C36F02E150189D05FFCC0A69667F85, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_span, ___1_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void SpanAction_2_Invoke_m4E51CE671BDBB67F3A2E93DA5AA706A80D9F166C_Multicast(SpanAction_2_t5907E59A3FE410EE3FC9FC29F5E9418DF5894C8B* __this, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 ___0_span, Il2CppFullySharedGenericAny ___1_arg, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		SpanAction_2_t5907E59A3FE410EE3FC9FC29F5E9418DF5894C8B* currentDelegate = reinterpret_cast<SpanAction_2_t5907E59A3FE410EE3FC9FC29F5E9418DF5894C8B*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54, Il2CppFullySharedGenericAny, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_span, ___1_arg, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void SpanAction_2_Invoke_m4E51CE671BDBB67F3A2E93DA5AA706A80D9F166C_OpenStaticInvoker(SpanAction_2_t5907E59A3FE410EE3FC9FC29F5E9418DF5894C8B* __this, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 ___0_span, Il2CppFullySharedGenericAny ___1_arg, const RuntimeMethod* method)
{
	InvokerActionInvoker2< Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54, Il2CppFullySharedGenericAny >::Invoke((Il2CppMethodPointer)__this->___method_ptr, method, NULL, ___0_span, ___1_arg);
}
void SpanAction_2_Invoke_m4E51CE671BDBB67F3A2E93DA5AA706A80D9F166C_ClosedStaticInvoker(SpanAction_2_t5907E59A3FE410EE3FC9FC29F5E9418DF5894C8B* __this, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 ___0_span, Il2CppFullySharedGenericAny ___1_arg, const RuntimeMethod* method)
{
	InvokerActionInvoker3< RuntimeObject*, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54, Il2CppFullySharedGenericAny >::Invoke((Il2CppMethodPointer)__this->___method_ptr, method, NULL, __this->___m_target, ___0_span, ___1_arg);
}
void SpanAction_2_Invoke_m4E51CE671BDBB67F3A2E93DA5AA706A80D9F166C_ClosedInstInvoker(SpanAction_2_t5907E59A3FE410EE3FC9FC29F5E9418DF5894C8B* __this, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 ___0_span, Il2CppFullySharedGenericAny ___1_arg, const RuntimeMethod* method)
{
	InvokerActionInvoker2< Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54, Il2CppFullySharedGenericAny >::Invoke((Il2CppMethodPointer)__this->___method_ptr, method, __this->___m_target, ___0_span, ___1_arg);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpanAction_2__ctor_mDA3D51C491A1F13D8CC15EB34D552737FFAE68E4_gshared (SpanAction_2_t5907E59A3FE410EE3FC9FC29F5E9418DF5894C8B* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&SpanAction_2_Invoke_m4E51CE671BDBB67F3A2E93DA5AA706A80D9F166C_OpenStaticInvoker;
		else
			__this->___invoke_impl = (intptr_t)&SpanAction_2_Invoke_m4E51CE671BDBB67F3A2E93DA5AA706A80D9F166C_ClosedStaticInvoker;
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl = (intptr_t)&SpanAction_2_Invoke_m4E51CE671BDBB67F3A2E93DA5AA706A80D9F166C_ClosedInstInvoker;
	}
	__this->___extra_arg = (intptr_t)&SpanAction_2_Invoke_m4E51CE671BDBB67F3A2E93DA5AA706A80D9F166C_Multicast;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpanAction_2_Invoke_m4E51CE671BDBB67F3A2E93DA5AA706A80D9F166C_gshared (SpanAction_2_t5907E59A3FE410EE3FC9FC29F5E9418DF5894C8B* __this, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54 ___0_span, Il2CppFullySharedGenericAny ___1_arg, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Span_1_tDEB40BEFA77B5E4BB49B058CD3050EEA4DD36C54, Il2CppFullySharedGenericAny, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_span, ___1_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m7126F92024E73EE43580A7A9D64C39CD973406CC_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* ___0_array, const RuntimeMethod* method) 
{
	BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D));
		goto IL_0037;
	}

IL_0037:
	{
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_4;
		L_4 = il2cpp_unsafe_as_ref<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D>(L_3);
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m6AD4D32958406E99771BD80D95955B6C1C1D8C7E_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_11;
		L_11 = il2cpp_unsafe_as_ref<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D>(L_10);
		int32_t L_12 = ___1_start;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_13;
		L_13 = il2cpp_unsafe_add<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,int32_t>(L_11, L_12);
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mF21BAD08783861F66A5DC64B2008B831D4E70ECD_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_2;
		L_2 = il2cpp_unsafe_as_ref<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D>((uint8_t*)L_1);
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mB2713B2424259A6D18038A2E29BD96DA081378D6_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_0 = ___0_ptr;
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* Span_1_get_Item_m8F05BEF265BF6D467B7F3EC7E0FC6144A17514B9_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_2 = __this->____pointer;
		V_0 = L_2;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_5;
		L_5 = il2cpp_unsafe_add<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m1B718013A2B8F944A651556CC5C238834972E189_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, const RuntimeMethod* method) 
{
	ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_0 = __this->____pointer;
		V_0 = L_0;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_mCFE2C408BFC0620F17CED47CB3A5E4E9097A2A2C_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_4 = __this->____pointer;
		V_2 = L_4;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_12 = __this->____pointer;
		V_2 = L_12;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_19 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_18 = L_19;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_24 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_23 = L_24;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_29 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_28 = L_29;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_34 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_33 = L_34;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_39 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_38 = L_39;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_44 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_43 = L_44;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_49 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_48 = L_49;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_54 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_64 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_63 = L_64;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_69 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_68 = L_69;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_74 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_73 = L_74;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_79 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_85 = ___0_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_mDCB97095A5B438EEDD243FF0924E8AFE4D0F040F_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m739A39BB426B19B7583557F308B2BDA52E2C3DD9_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 L_2 = ___0_destination;
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_3 = L_2.____pointer;
		V_0 = L_3;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_0));
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_5 = __this->____pointer;
		V_0 = L_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m9074142CF2F0828232AFEBB926F490D33E285B9B(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_mE4C5E1C41D72D994C9A4EAA1714F82F57ACB3D1D_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m739A39BB426B19B7583557F308B2BDA52E2C3DD9_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 L_2 = ___0_destination;
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_3 = L_2.____pointer;
		V_1 = L_3;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_1));
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_5 = __this->____pointer;
		V_1 = L_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m9074142CF2F0828232AFEBB926F490D33E285B9B(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tE73282FE39C46EDD2EE2F61A9E3E69BE943784B7 Span_1_op_Implicit_m55793F89576C91F51F84FEE419581F8B4B5F38C5_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 L_0 = ___0_span;
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_1 = L_0.____pointer;
		V_0 = L_1;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_0));
		Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_tE73282FE39C46EDD2EE2F61A9E3E69BE943784B7 L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_m729E93C65964D6955F3A0794056B0A8FA3E1FB44_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_m6103F745B1C7B9A9BD3A3116AF5F988065C25AF4_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_5 = __this->____pointer;
		V_1 = L_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 Span_1_Slice_m755E9ED71968348BB9C4E8463E30DE839E3FEFD0_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_2 = __this->____pointer;
		V_0 = L_2;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_5;
		L_5 = il2cpp_unsafe_add<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_mB2713B2424259A6D18038A2E29BD96DA081378D6_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 Span_1_Slice_mA98F6A471377545511DC5E22FD4DF75F4E10F707_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_5 = __this->____pointer;
		V_0 = L_5;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_8;
		L_8 = il2cpp_unsafe_add<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_mB2713B2424259A6D18038A2E29BD96DA081378D6_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* Span_1_ToArray_m33F9F235649E5BECFA4795C77789731BF922CFC7_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, const RuntimeMethod* method) 
{
	ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_1;
		L_1 = Array_Empty_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m652D1F78F0DEF31A60A1D09589A89DE06F12C3E4_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_3 = (BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80*)(BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_6;
		L_6 = il2cpp_unsafe_as_ref<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D>(L_5);
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_7 = __this->____pointer;
		V_0 = L_7;
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m9074142CF2F0828232AFEBB926F490D33E285B9B(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m739A39BB426B19B7583557F308B2BDA52E2C3DD9_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m31F00188DB58D0A6AC422C1110FE121512B83A8B_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_mB00CEDEC6497D53AB78D6B46111F2695915CF97A_gshared (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 Span_1_op_Implicit_m94CCC4AEF130B0783BEB1BFB5ACB39512FB9EF03_gshared (BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* ___0_array, const RuntimeMethod* method) 
{
	{
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_0 = ___0_array;
		Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428 L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_m7126F92024E73EE43580A7A9D64C39CD973406CC_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mCA3E1FB18A1006842617ABD22464535398F4655D_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* ___0_array, const RuntimeMethod* method) 
{
	BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF));
		goto IL_0037;
	}

IL_0037:
	{
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_4;
		L_4 = il2cpp_unsafe_as_ref<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF>(L_3);
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mFD33CF6810B10785B067103EEB5A566765495456_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_11;
		L_11 = il2cpp_unsafe_as_ref<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF>(L_10);
		int32_t L_12 = ___1_start;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_13;
		L_13 = il2cpp_unsafe_add<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,int32_t>(L_11, L_12);
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m5DFA597BC248F8415E6290DEE630D9DEE6910CE5_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_2;
		L_2 = il2cpp_unsafe_as_ref<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF>((uint8_t*)L_1);
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m4F32D7D5653D612D237DDFD35C9850E16CA11C18_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_0 = ___0_ptr;
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* Span_1_get_Item_mD533811FA5C4B53120E3936C9C8195AA9D4AFA96_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_2 = __this->____pointer;
		V_0 = L_2;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_5;
		L_5 = il2cpp_unsafe_add<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m59D227BCE295AE51C5DFF32C371E947DE9502428_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, const RuntimeMethod* method) 
{
	ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_0 = __this->____pointer;
		V_0 = L_0;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m59389A1C14E13B1AC0A9863ADC8C86F469146CA3_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_4 = __this->____pointer;
		V_2 = L_4;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_12 = __this->____pointer;
		V_2 = L_12;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_19 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_18 = L_19;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_24 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_23 = L_24;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_29 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_28 = L_29;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_34 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_33 = L_34;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_39 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_38 = L_39;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_44 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_43 = L_44;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_49 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_48 = L_49;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_54 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_64 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_63 = L_64;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_69 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_68 = L_69;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_74 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_73 = L_74;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_79 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF L_85 = ___0_value;
		*(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_mDB36175473DF442B57F349C488305879B0CB7255_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_mF5DDBBF4783D0A55C88BFD79E1A1F8B5DDCF60C5_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 L_2 = ___0_destination;
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_3 = L_2.____pointer;
		V_0 = L_3;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_0));
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_5 = __this->____pointer;
		V_0 = L_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF_m3ED952566857853E08E1F43BA48367A61065281A(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m6AD1D8620133D11250A9BA747F911F499F41A35B_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_mF5DDBBF4783D0A55C88BFD79E1A1F8B5DDCF60C5_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 L_2 = ___0_destination;
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_3 = L_2.____pointer;
		V_1 = L_3;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_1));
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_5 = __this->____pointer;
		V_1 = L_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF_m3ED952566857853E08E1F43BA48367A61065281A(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t3D251E6627DBB106D7D34F8DC234D102B691FD49 Span_1_op_Implicit_m2220F921A4A87212DB830E9F53F707FDD56C1C96_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 L_0 = ___0_span;
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_1 = L_0.____pointer;
		V_0 = L_1;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_0));
		Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t3D251E6627DBB106D7D34F8DC234D102B691FD49 L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_m1C72072A1F9FFD48A21C4C5F2A81954708D29495_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_m61DA7965FCDF9AEAB712B342C74927827FE9DBE1_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_5 = __this->____pointer;
		V_1 = L_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 Span_1_Slice_m741EAC6D068EC4FEFDF5A59805E791BC7F5A4046_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_2 = __this->____pointer;
		V_0 = L_2;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_5;
		L_5 = il2cpp_unsafe_add<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m4F32D7D5653D612D237DDFD35C9850E16CA11C18_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 Span_1_Slice_mE29D916E1DACE071E402F8EB19D17EB3E109DCB4_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_5 = __this->____pointer;
		V_0 = L_5;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_8;
		L_8 = il2cpp_unsafe_add<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m4F32D7D5653D612D237DDFD35C9850E16CA11C18_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* Span_1_ToArray_m8F1E0A08EFD1747DD532F65A14686F0783BDF711_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, const RuntimeMethod* method) 
{
	ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_1;
		L_1 = Array_Empty_TisBlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF_mCD144DB8231D7EA3AF1DB4FEB94681C9E580CA9D_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_3 = (BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B*)(BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_6;
		L_6 = il2cpp_unsafe_as_ref<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF>(L_5);
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_7 = __this->____pointer;
		V_0 = L_7;
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisBlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF_m3ED952566857853E08E1F43BA48367A61065281A(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mF5DDBBF4783D0A55C88BFD79E1A1F8B5DDCF60C5_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m821BBBACF2E09DB186D7EF0FBC7056846FD3DFC2_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_m9FCC61383FE9C38A07042FAA217F7FB5712DD8AF_gshared (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 Span_1_op_Implicit_m6D770C0E8BB6F22DB2D3418BC64730EB2A4F116F_gshared (BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* ___0_array, const RuntimeMethod* method) 
{
	{
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_0 = ___0_array;
		Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671 L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_mCA3E1FB18A1006842617ABD22464535398F4655D_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mF80BBD6B1E4103830CA7E538A9EE8ABA983D97EC_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* ___0_array, const RuntimeMethod* method) 
{
	BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6));
		goto IL_0037;
	}

IL_0037:
	{
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_4;
		L_4 = il2cpp_unsafe_as_ref<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6>(L_3);
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m4773E314A1E2A0CD2AC8579DB2E03903AE598691_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_11;
		L_11 = il2cpp_unsafe_as_ref<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6>(L_10);
		int32_t L_12 = ___1_start;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_13;
		L_13 = il2cpp_unsafe_add<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,int32_t>(L_11, L_12);
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m9D758D2C22722BA0C966A2EFEC231CF327AE27CA_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_2;
		L_2 = il2cpp_unsafe_as_ref<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6>((uint8_t*)L_1);
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m6C9685057F182B8896BBE6B894974625E6DA4221_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_0 = ___0_ptr;
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* Span_1_get_Item_m867435369EE8AA05643B069D12342448A6C0D8B8_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_2 = __this->____pointer;
		V_0 = L_2;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_5;
		L_5 = il2cpp_unsafe_add<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_mE28AB7ECD35A2F4A732DB2EC43C3CDE81813BBDD_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, const RuntimeMethod* method) 
{
	ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_0 = __this->____pointer;
		V_0 = L_0;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_mE47EFB4483702E1A60F8602814B99229737F7808_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_4 = __this->____pointer;
		V_2 = L_4;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_12 = __this->____pointer;
		V_2 = L_12;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_19 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_18 = L_19;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_24 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_23 = L_24;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_29 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_28 = L_29;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_34 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_33 = L_34;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_39 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_38 = L_39;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_44 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_43 = L_44;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_49 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_48 = L_49;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_54 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_64 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_63 = L_64;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_69 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_68 = L_69;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_74 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_73 = L_74;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_79 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 L_85 = ___0_value;
		*(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_mADE83344EFC15B4FE8899F6415FD1D573DDAAF14_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m0A22C7814AA57E51DE4EDC241010E81DA05627F9_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C L_2 = ___0_destination;
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_3 = L_2.____pointer;
		V_0 = L_3;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_0));
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_5 = __this->____pointer;
		V_0 = L_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6_mE178FB3796A6A1A4F519A7BA46829D3A14F94CBD(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m8B960FE0CC0868A5B0A65937DAFCB2929F7E625A_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m0A22C7814AA57E51DE4EDC241010E81DA05627F9_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C L_2 = ___0_destination;
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_3 = L_2.____pointer;
		V_1 = L_3;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_1));
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_5 = __this->____pointer;
		V_1 = L_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6_mE178FB3796A6A1A4F519A7BA46829D3A14F94CBD(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tD81D75B0E0400301DC302920BCCBB9FBD97CA2A8 Span_1_op_Implicit_m695E0E4F838DCFF3945ED16D10D75517964045EF_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C L_0 = ___0_span;
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_1 = L_0.____pointer;
		V_0 = L_1;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_0));
		Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_tD81D75B0E0400301DC302920BCCBB9FBD97CA2A8 L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_m143F99ABFB2902F2BE3AB6725D5F8AEAECDEC5F4_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_m26793FC09A6CDDCD4538326D81253A0527CE98E3_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_5 = __this->____pointer;
		V_1 = L_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C Span_1_Slice_m995A6B6EED381840AD58F75CE7DCCF6FADD18220_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_2 = __this->____pointer;
		V_0 = L_2;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_5;
		L_5 = il2cpp_unsafe_add<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m6C9685057F182B8896BBE6B894974625E6DA4221_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C Span_1_Slice_m24491E84690B3EDABF70EAD4DC1120D3E74439F7_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_5 = __this->____pointer;
		V_0 = L_5;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_8;
		L_8 = il2cpp_unsafe_add<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m6C9685057F182B8896BBE6B894974625E6DA4221_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* Span_1_ToArray_m49DE62393086FAB33829C8DEDBDC26A04FAB9A18_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, const RuntimeMethod* method) 
{
	ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_1;
		L_1 = Array_Empty_TisBlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6_m7D78EA1928C7379C27FE7337353FB51BEFD7476E_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_3 = (BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515*)(BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_6;
		L_6 = il2cpp_unsafe_as_ref<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6>(L_5);
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_7 = __this->____pointer;
		V_0 = L_7;
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisBlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6_mE178FB3796A6A1A4F519A7BA46829D3A14F94CBD(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m0A22C7814AA57E51DE4EDC241010E81DA05627F9_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m7E559DAFF58ED501B6B868B7FEA6A39292BEDB6D_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_m62B31265609A664C77B9CE4C34AC241A0BE8CA50_gshared (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C Span_1_op_Implicit_m8E913E79442066F7AA96DCD667A45B556E649EDF_gshared (BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* ___0_array, const RuntimeMethod* method) 
{
	{
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_0 = ___0_array;
		Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_mF80BBD6B1E4103830CA7E538A9EE8ABA983D97EC_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mB392265B6A34EA59542E156547D1143AC4B0EBD4_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* ___0_array, const RuntimeMethod* method) 
{
	BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C));
		goto IL_0037;
	}

IL_0037:
	{
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_4;
		L_4 = il2cpp_unsafe_as_ref<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C>(L_3);
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m0006DE3E774E4B0884E9F594FA2D00D8C2831FE8_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_11;
		L_11 = il2cpp_unsafe_as_ref<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C>(L_10);
		int32_t L_12 = ___1_start;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_13;
		L_13 = il2cpp_unsafe_add<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,int32_t>(L_11, L_12);
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mFAC1E53095EFC84F292BA7916C6D66DC5FCA690A_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_2;
		L_2 = il2cpp_unsafe_as_ref<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C>((uint8_t*)L_1);
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m773D9E2695DC1A1EAF17FDC94204CB7B1DE21582_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_0 = ___0_ptr;
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* Span_1_get_Item_m73DC27BE948BD550479732B2640E4B90268CFFC2_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_2 = __this->____pointer;
		V_0 = L_2;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_5;
		L_5 = il2cpp_unsafe_add<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m215020869659531B11EF5609CE326BBC038E0960_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, const RuntimeMethod* method) 
{
	ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_0 = __this->____pointer;
		V_0 = L_0;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_mE0AAF30EB7691430DF93CE9A8E65AF914A3EE3E8_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_4 = __this->____pointer;
		V_2 = L_4;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_12 = __this->____pointer;
		V_2 = L_12;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_19 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_18 = L_19;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_24 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_23 = L_24;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_29 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_28 = L_29;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_34 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_33 = L_34;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_39 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_38 = L_39;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_44 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_43 = L_44;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_49 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_48 = L_49;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_54 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_64 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_63 = L_64;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_69 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_68 = L_69;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_74 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_73 = L_74;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_79 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C L_85 = ___0_value;
		*(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m8CA473CD54839470D79A0455ED2999F0FF929628_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m3C5D2034819739D3DDB78A3D890CEE1C94529B01_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B L_2 = ___0_destination;
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_3 = L_2.____pointer;
		V_0 = L_3;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_0));
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_5 = __this->____pointer;
		V_0 = L_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C_m107660B4F4107562042A7A5BD0F5123732E1C1BF(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m46A2F70C0DD837E75E7C7652F56BC2B9B05645E5_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m3C5D2034819739D3DDB78A3D890CEE1C94529B01_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B L_2 = ___0_destination;
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_3 = L_2.____pointer;
		V_1 = L_3;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_1));
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_5 = __this->____pointer;
		V_1 = L_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C_m107660B4F4107562042A7A5BD0F5123732E1C1BF(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t70882B83461088DC23C3DB9AF59753CF91E1F3AA Span_1_op_Implicit_mC5272E30538A158484CA1730BDCA1538E7BD51AC_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B L_0 = ___0_span;
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_1 = L_0.____pointer;
		V_0 = L_1;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_0));
		Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t70882B83461088DC23C3DB9AF59753CF91E1F3AA L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_mD794B63B35B4B58E5337728A24E1998CFDD74810_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_m5621A583EECF457226E66278C9423C8245424F1F_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_5 = __this->____pointer;
		V_1 = L_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B Span_1_Slice_mD85CEAFA2B78E02E3C8B9BAF64AC60C4E3906A73_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_2 = __this->____pointer;
		V_0 = L_2;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_5;
		L_5 = il2cpp_unsafe_add<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m773D9E2695DC1A1EAF17FDC94204CB7B1DE21582_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B Span_1_Slice_mBD4E1573A35C00A8E62AAFA830F787B6BE280218_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_5 = __this->____pointer;
		V_0 = L_5;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_8;
		L_8 = il2cpp_unsafe_add<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m773D9E2695DC1A1EAF17FDC94204CB7B1DE21582_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* Span_1_ToArray_mC1AAAD0C3E2277B241A4F22D46825855DBC3F604_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, const RuntimeMethod* method) 
{
	ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_1;
		L_1 = Array_Empty_TisBlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C_m48CDEF41C2F032666E4312F197041C0757708AE3_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_3 = (BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A*)(BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_6;
		L_6 = il2cpp_unsafe_as_ref<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C>(L_5);
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_7 = __this->____pointer;
		V_0 = L_7;
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisBlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C_m107660B4F4107562042A7A5BD0F5123732E1C1BF(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m3C5D2034819739D3DDB78A3D890CEE1C94529B01_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m7F55EE83B9319F0B5E39F494B4DA746792AC439C_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_m96F76176FF5D31065703741A33020AF9ECE32C02_gshared (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B Span_1_op_Implicit_m2243A55C41D8CCFC201C16BDEBC0B1714C358D15_gshared (BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* ___0_array, const RuntimeMethod* method) 
{
	{
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_0 = ___0_array;
		Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_mB392265B6A34EA59542E156547D1143AC4B0EBD4_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mD521304CD3352077C22527BDFF5A3A6F5BBA2345_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* ___0_array, const RuntimeMethod* method) 
{
	BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54));
		goto IL_0037;
	}

IL_0037:
	{
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_4;
		L_4 = il2cpp_unsafe_as_ref<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54>(L_3);
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m41CBBD9269174D34492096CD4FE4DA748D886A09_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_11;
		L_11 = il2cpp_unsafe_as_ref<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54>(L_10);
		int32_t L_12 = ___1_start;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_13;
		L_13 = il2cpp_unsafe_add<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,int32_t>(L_11, L_12);
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m415AB8FC86987A725E297624EA832A8629B5B779_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_2;
		L_2 = il2cpp_unsafe_as_ref<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54>((uint8_t*)L_1);
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mEA9008985414217BB660044157B6458716A8AB1D_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_0 = ___0_ptr;
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* Span_1_get_Item_m23A57CB949BBEC9D8010B089E2E6B43494174E09_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_2 = __this->____pointer;
		V_0 = L_2;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_5;
		L_5 = il2cpp_unsafe_add<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m502AF1500ABCD70D8636A712FF6D9FEA464C1FEC_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, const RuntimeMethod* method) 
{
	ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_0 = __this->____pointer;
		V_0 = L_0;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m2A8A33FC58264C3934935F879D3969D9C2830D08_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_4 = __this->____pointer;
		V_2 = L_4;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_12 = __this->____pointer;
		V_2 = L_12;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_19 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_18 = L_19;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_24 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_23 = L_24;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_29 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_28 = L_29;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_34 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_33 = L_34;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_39 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_38 = L_39;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_44 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_43 = L_44;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_49 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_48 = L_49;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_54 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_64 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_63 = L_64;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_69 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_68 = L_69;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_74 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_73 = L_74;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_79 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 L_85 = ___0_value;
		*(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m1F71FDF9D53AA00318AEF9A12BD3F7E76BB919F2_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m088CD07D38433F7795ED549A2139E5D41EA16706_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF L_2 = ___0_destination;
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_3 = L_2.____pointer;
		V_0 = L_3;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_0));
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_5 = __this->____pointer;
		V_0 = L_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54_m812A4F9C363B5C0D2AAE7D5E5D180DB7F7FEF824(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m6347DEEACEE3DBB225BB9E1092C91DC98F1607E2_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m088CD07D38433F7795ED549A2139E5D41EA16706_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF L_2 = ___0_destination;
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_3 = L_2.____pointer;
		V_1 = L_3;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_1));
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_5 = __this->____pointer;
		V_1 = L_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54_m812A4F9C363B5C0D2AAE7D5E5D180DB7F7FEF824(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t2EFE9320FC985EB4C740E0FD04D094F25024C51D Span_1_op_Implicit_mCAAAC696B8FF40FBD4FB29F5211AEE52CA73CF23_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF L_0 = ___0_span;
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_1 = L_0.____pointer;
		V_0 = L_1;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_0));
		Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t2EFE9320FC985EB4C740E0FD04D094F25024C51D L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_m1A260D918B5EB96D17E965BA7BA73DA0C3493361_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_mA2E385C3E0316C161BC28C926653EF778ECE79E1_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_5 = __this->____pointer;
		V_1 = L_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF Span_1_Slice_m6962B0CB13D72D7E3E7AAD0BE78BAC704D9D1A65_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_2 = __this->____pointer;
		V_0 = L_2;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_5;
		L_5 = il2cpp_unsafe_add<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_mEA9008985414217BB660044157B6458716A8AB1D_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF Span_1_Slice_mBF42D1CB4DA7CB00F31CE101028189D40DDB6D0E_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_5 = __this->____pointer;
		V_0 = L_5;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_8;
		L_8 = il2cpp_unsafe_add<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_mEA9008985414217BB660044157B6458716A8AB1D_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* Span_1_ToArray_m18CFC6E2E78D646FBC99E9618523907D6175B35F_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, const RuntimeMethod* method) 
{
	ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_1;
		L_1 = Array_Empty_TisBlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54_mDE388119C5F2CA6DED1F8895551BEDC81C379FF9_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_3 = (BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8*)(BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_6;
		L_6 = il2cpp_unsafe_as_ref<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54>(L_5);
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_7 = __this->____pointer;
		V_0 = L_7;
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisBlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54_m812A4F9C363B5C0D2AAE7D5E5D180DB7F7FEF824(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m088CD07D38433F7795ED549A2139E5D41EA16706_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_mDC3980F146F1709A06CFD47462C731521041564E_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_mF9BE77DD75BEE69AED1F0174C1B2840AB086AC8F_gshared (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF Span_1_op_Implicit_m51E3482670B614CF227480786743D43FA79A43CF_gshared (BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* ___0_array, const RuntimeMethod* method) 
{
	{
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_0 = ___0_array;
		Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_mD521304CD3352077C22527BDFF5A3A6F5BBA2345_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mBC0A2A6F732CAD76B8E0B559AAF16DDDC7DA95FB_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* ___0_array, const RuntimeMethod* method) 
{
	BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901));
		goto IL_0037;
	}

IL_0037:
	{
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_4;
		L_4 = il2cpp_unsafe_as_ref<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901>(L_3);
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m9AC220B55F05A0DD7ED573ED8CCEF000E8F602D4_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_11;
		L_11 = il2cpp_unsafe_as_ref<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901>(L_10);
		int32_t L_12 = ___1_start;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_13;
		L_13 = il2cpp_unsafe_add<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,int32_t>(L_11, L_12);
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mCB1BDC0140A269D70097CECEA774740C2E9ED9BB_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_2;
		L_2 = il2cpp_unsafe_as_ref<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901>((uint8_t*)L_1);
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m18D55B2B52C0EE4D379FCBBC6EE16E72CE2928E1_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_0 = ___0_ptr;
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* Span_1_get_Item_mED589783F666A14BC3384697EE8953A268DAC552_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_2 = __this->____pointer;
		V_0 = L_2;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_5;
		L_5 = il2cpp_unsafe_add<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m5F018E655533AAE5C4C0FDA67BF4D0CE72801F54_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, const RuntimeMethod* method) 
{
	ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_0 = __this->____pointer;
		V_0 = L_0;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m851D68A2707CEF09B28EA66EC891E95FDF520B19_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_4 = __this->____pointer;
		V_2 = L_4;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_12 = __this->____pointer;
		V_2 = L_12;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_19 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_18 = L_19;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_24 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_23 = L_24;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_29 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_28 = L_29;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_34 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_33 = L_34;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_39 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_38 = L_39;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_44 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_43 = L_44;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_49 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_48 = L_49;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_54 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_64 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_63 = L_64;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_69 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_68 = L_69;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_74 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_73 = L_74;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_79 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 L_85 = ___0_value;
		*(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_mA6197925F333B9CA7CD79D142B48B2AFFE3BA054_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_mE19749B8DE0A55279184BDD9C3F394605245F91A_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C L_2 = ___0_destination;
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_3 = L_2.____pointer;
		V_0 = L_3;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_0));
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_5 = __this->____pointer;
		V_0 = L_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901_mCB357A3CD61F6C424F89F1F9C63A4446F5B9C57E(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m3BD50024911118C0EA67643284B5E3F30A2E751E_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_mE19749B8DE0A55279184BDD9C3F394605245F91A_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C L_2 = ___0_destination;
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_3 = L_2.____pointer;
		V_1 = L_3;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_1));
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_5 = __this->____pointer;
		V_1 = L_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901_mCB357A3CD61F6C424F89F1F9C63A4446F5B9C57E(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t5EE3C4B6EA25BB8F3F956DFD28820F5666342758 Span_1_op_Implicit_m662C4CEB116C78B10DD4EE858321A28889BE5D75_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C L_0 = ___0_span;
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_1 = L_0.____pointer;
		V_0 = L_1;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_0));
		Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t5EE3C4B6EA25BB8F3F956DFD28820F5666342758 L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_mE88D51223E12D11DE487A5E2C7AF2013C6413887_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_mF7CDCB76F95F17951B41C8361D88A4C607623C9D_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_5 = __this->____pointer;
		V_1 = L_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C Span_1_Slice_m7D030DFE43949C2F889BEC9EE19A956D17AD18D6_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_2 = __this->____pointer;
		V_0 = L_2;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_5;
		L_5 = il2cpp_unsafe_add<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m18D55B2B52C0EE4D379FCBBC6EE16E72CE2928E1_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C Span_1_Slice_mB0A6A6166F66C1F9D0E75DA7DE7E2BBF9C9DF407_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_5 = __this->____pointer;
		V_0 = L_5;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_8;
		L_8 = il2cpp_unsafe_add<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m18D55B2B52C0EE4D379FCBBC6EE16E72CE2928E1_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* Span_1_ToArray_mCBC8716EE478F83E4ABB7D8938950301365A1CDB_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, const RuntimeMethod* method) 
{
	ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_1;
		L_1 = Array_Empty_TisBlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901_m75A4A4FD904386887E2E78BA168595529AF13939_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_3 = (BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F*)(BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_6;
		L_6 = il2cpp_unsafe_as_ref<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901>(L_5);
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_7 = __this->____pointer;
		V_0 = L_7;
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisBlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901_mCB357A3CD61F6C424F89F1F9C63A4446F5B9C57E(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mE19749B8DE0A55279184BDD9C3F394605245F91A_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m84D15037DB9F6AABA69DF8C1CB3272B04111DBA5_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_m523F849869E2B077A52585FA1285BAEDAEBEA16A_gshared (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C Span_1_op_Implicit_mDAE46617FD1B6A54D23C0FA963B13ED070D78FCB_gshared (BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* ___0_array, const RuntimeMethod* method) 
{
	{
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_0 = ___0_array;
		Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_mBC0A2A6F732CAD76B8E0B559AAF16DDDC7DA95FB_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mDAF271BFB6432EB8FCE7E7E95BB3A4918F1BCC92_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* ___0_array, const RuntimeMethod* method) 
{
	BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472));
		goto IL_0037;
	}

IL_0037:
	{
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_4;
		L_4 = il2cpp_unsafe_as_ref<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472>(L_3);
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m4E7CB32DEDC997853314441ED9792FE2F7456408_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_11;
		L_11 = il2cpp_unsafe_as_ref<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472>(L_10);
		int32_t L_12 = ___1_start;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_13;
		L_13 = il2cpp_unsafe_add<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,int32_t>(L_11, L_12);
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mB96BFEADE40B6C5385D0CCDFF43B912A9626BD62_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_2;
		L_2 = il2cpp_unsafe_as_ref<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472>((uint8_t*)L_1);
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m0635E38BE51343FEA108E4BAC304A66703B9E727_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_0 = ___0_ptr;
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* Span_1_get_Item_m2DFFF9D32428AC30D43B49BC0582280578A318ED_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_2 = __this->____pointer;
		V_0 = L_2;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_5;
		L_5 = il2cpp_unsafe_add<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m7D41CF15708F6683DE64F64915FC677CD55B49E4_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, const RuntimeMethod* method) 
{
	ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_0 = __this->____pointer;
		V_0 = L_0;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m00345EB8321F450EF4C70CF4C913BDADAFAAFC1C_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_4 = __this->____pointer;
		V_2 = L_4;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_12 = __this->____pointer;
		V_2 = L_12;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_19 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_18 = L_19;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_24 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_23 = L_24;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_29 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_28 = L_29;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_34 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_33 = L_34;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_39 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_38 = L_39;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_44 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_43 = L_44;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_49 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_48 = L_49;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_54 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_64 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_63 = L_64;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_69 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_68 = L_69;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_74 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_73 = L_74;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_79 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 L_85 = ___0_value;
		*(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m65B2B88743ED3F2CE0FFC99806BA5F564C5728F6_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m27BEF44B2CCD3948DC00D344142E534E36BA7524_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 L_2 = ___0_destination;
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_3 = L_2.____pointer;
		V_0 = L_3;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_0));
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_5 = __this->____pointer;
		V_0 = L_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472_mDE86D51ADDC3C7F13B214DA755964EA5014FC510(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_mCA31070D238448C938A75D7AEAF7DD5395E4311E_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m27BEF44B2CCD3948DC00D344142E534E36BA7524_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 L_2 = ___0_destination;
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_3 = L_2.____pointer;
		V_1 = L_3;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_1));
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_5 = __this->____pointer;
		V_1 = L_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisBlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472_mDE86D51ADDC3C7F13B214DA755964EA5014FC510(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t9DCA2EC81EE91A02D7C140CF3376183B663C483A Span_1_op_Implicit_m4FF45CC64927A10C4A6D08D16601C0D064F4027B_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 L_0 = ___0_span;
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_1 = L_0.____pointer;
		V_0 = L_1;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_0));
		Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t9DCA2EC81EE91A02D7C140CF3376183B663C483A L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_m83EAE3C4FCB23391B66637D0580733B85E12B21A_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_mAB40E4EBF8AF405E3616017EB247A7D6FB8759FC_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_5 = __this->____pointer;
		V_1 = L_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 Span_1_Slice_mA539BFA2F5AE80D6E5A2D15ACE42AD96D5713B43_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_2 = __this->____pointer;
		V_0 = L_2;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_5;
		L_5 = il2cpp_unsafe_add<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m0635E38BE51343FEA108E4BAC304A66703B9E727_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 Span_1_Slice_m87BB31DB04EA06FD32B688FFEC55BA2DD7D22EC7_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_5 = __this->____pointer;
		V_0 = L_5;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_8;
		L_8 = il2cpp_unsafe_add<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m0635E38BE51343FEA108E4BAC304A66703B9E727_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* Span_1_ToArray_mA99E0B42161B83D5EEA26FF188911FAD68CF9319_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, const RuntimeMethod* method) 
{
	ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_1;
		L_1 = Array_Empty_TisBlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472_m6A8620E16588CCAE8CBA423DCB92B7E1D919A942_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_3 = (BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A*)(BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_6;
		L_6 = il2cpp_unsafe_as_ref<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472>(L_5);
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_7 = __this->____pointer;
		V_0 = L_7;
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisBlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472_mDE86D51ADDC3C7F13B214DA755964EA5014FC510(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m27BEF44B2CCD3948DC00D344142E534E36BA7524_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m7782E9755EFA7AD283C813BB5168DE8E182E2FA5_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_m53F7F5E368908672150DBC5DC8768E9C3058CE36_gshared (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 Span_1_op_Implicit_mC6B1ACEF0A6B0F9CEF18D5F0A25623C9760FDEA2_gshared (BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* ___0_array, const RuntimeMethod* method) 
{
	{
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_0 = ___0_array;
		Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1 L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_mDAF271BFB6432EB8FCE7E7E95BB3A4918F1BCC92_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m513968BDBFF3CFCE89F3F77FE44CAB22CA474EF9_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, const RuntimeMethod* method) 
{
	uint8_t V_0 = 0x0;
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(uint8_t));
		goto IL_0037;
	}

IL_0037:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		uint8_t* L_4;
		L_4 = il2cpp_unsafe_as_ref<uint8_t>(L_3);
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m698EC79E2E44AFF16BA096D0861CFB129FBF8218_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	uint8_t V_0 = 0x0;
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(uint8_t));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		uint8_t* L_11;
		L_11 = il2cpp_unsafe_as_ref<uint8_t>(L_10);
		int32_t L_12 = ___1_start;
		uint8_t* L_13;
		L_13 = il2cpp_unsafe_add<uint8_t,int32_t>(L_11, L_12);
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mE18EBB601FBFA01BA29FE353364700952A9091FE_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>((uint8_t*)L_1);
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, uint8_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		uint8_t* L_0 = ___0_ptr;
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Span_1_get_Item_mA500F3AC2BE20A39F8425A1CCA39B704F44DC0E1_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_2 = __this->____pointer;
		V_0 = L_2;
		uint8_t* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		uint8_t* L_5;
		L_5 = il2cpp_unsafe_add<uint8_t,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m95E8A4114E1E52B458C21B864A802C4A07A96F15_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, const RuntimeMethod* method) 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_0 = __this->____pointer;
		V_0 = L_0;
		uint8_t* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<uint8_t>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m5C8306E094A7E370D52DE264ED5D3743FC7A51A8_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, uint8_t ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	uint8_t V_1 = 0x0;
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	uint8_t* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<uint8_t>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		uint8_t L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_4 = __this->____pointer;
		V_2 = L_4;
		uint8_t* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_12 = __this->____pointer;
		V_2 = L_12;
		uint8_t* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<uint8_t>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		uint8_t* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		uint8_t* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		uint8_t L_19 = ___0_value;
		*(uint8_t*)L_18 = L_19;
		uint8_t* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		uint8_t* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		uint8_t L_24 = ___0_value;
		*(uint8_t*)L_23 = L_24;
		uint8_t* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		uint8_t* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		uint8_t L_29 = ___0_value;
		*(uint8_t*)L_28 = L_29;
		uint8_t* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		uint8_t* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		uint8_t L_34 = ___0_value;
		*(uint8_t*)L_33 = L_34;
		uint8_t* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		uint8_t* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		uint8_t L_39 = ___0_value;
		*(uint8_t*)L_38 = L_39;
		uint8_t* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		uint8_t* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		uint8_t L_44 = ___0_value;
		*(uint8_t*)L_43 = L_44;
		uint8_t* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		uint8_t* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		uint8_t L_49 = ___0_value;
		*(uint8_t*)L_48 = L_49;
		uint8_t* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		uint8_t* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		uint8_t L_54 = ___0_value;
		*(uint8_t*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		uint8_t* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		uint8_t* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		uint8_t L_64 = ___0_value;
		*(uint8_t*)L_63 = L_64;
		uint8_t* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		uint8_t* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		uint8_t L_69 = ___0_value;
		*(uint8_t*)L_68 = L_69;
		uint8_t* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		uint8_t* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		uint8_t L_74 = ___0_value;
		*(uint8_t*)L_73 = L_74;
		uint8_t* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		uint8_t* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		uint8_t L_79 = ___0_value;
		*(uint8_t*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		uint8_t* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		uint8_t* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<uint8_t,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		uint8_t L_85 = ___0_value;
		*(uint8_t*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m7A06ABD95EC3209F4FC307CAB38FD87202A88542_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m8E944E4954E037877A25B9FF6B901F1F901D4769_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_2 = ___0_destination;
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_3 = L_2.____pointer;
		V_0 = L_3;
		uint8_t* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_0));
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_5 = __this->____pointer;
		V_0 = L_5;
		uint8_t* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB1465EEEBE0A608FA51B29BC3F145F287AD04190(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_mFD99196C62E0CE029A2E64ED0B0F4FEC623B9F56_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m8E944E4954E037877A25B9FF6B901F1F901D4769_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_2 = ___0_destination;
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_3 = L_2.____pointer;
		V_1 = L_3;
		uint8_t* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_1));
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_5 = __this->____pointer;
		V_1 = L_5;
		uint8_t* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB1465EEEBE0A608FA51B29BC3F145F287AD04190(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D Span_1_op_Implicit_mD249188242C0C9D3192A31E9F7FA74C683F05B84_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_0 = ___0_span;
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_1 = L_0.____pointer;
		V_0 = L_1;
		uint8_t* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_0));
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_m0FC0B92549C2968E80B5F75A85F28B96DBFCFD63_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_m94E8AC193D974B79432BD6D8CC8AE7E7832AC6A4_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_5 = __this->____pointer;
		V_1 = L_5;
		uint8_t* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Span_1_Slice_m720734AA48ECB663CAA0594530927B9015A64341_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_2 = __this->____pointer;
		V_0 = L_2;
		uint8_t* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		uint8_t* L_5;
		L_5 = il2cpp_unsafe_add<uint8_t,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Span_1_Slice_m9D8BA8245B8DC9BFB4A4164759CBAAEAD1318CD6_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_5 = __this->____pointer;
		V_0 = L_5;
		uint8_t* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		uint8_t* L_8;
		L_8 = il2cpp_unsafe_add<uint8_t,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* Span_1_ToArray_mF415F39478D842BDA5A27003F3B9D3903DCE24BF_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, const RuntimeMethod* method) 
{
	ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1;
		L_1 = Array_Empty_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m6080CA526758F4FA182A066B2780D1761CD36ED5_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_7 = __this->____pointer;
		V_0 = L_7;
		uint8_t* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(uint8_t, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB1465EEEBE0A608FA51B29BC3F145F287AD04190(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m8E944E4954E037877A25B9FF6B901F1F901D4769_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m7F08055851C835FE3E76471A6015683E6CCBD980_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_mAB5C55282F13372D4B32AFA20E3E2618CE417F61_gshared (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 Span_1_op_Implicit_m8619157C8809464A173FF531960A75A0ACE2CE91_gshared (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, const RuntimeMethod* method) 
{
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_array;
		Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305 L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_m513968BDBFF3CFCE89F3F77FE44CAB22CA474EF9_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m9C0B3F87D446842B5C4638690ED90478A5B5073C_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* ___0_array, const RuntimeMethod* method) 
{
	Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87));
		goto IL_0037;
	}

IL_0037:
	{
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_4;
		L_4 = il2cpp_unsafe_as_ref<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87>(L_3);
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mD8BC434A2E1EA30367054FBA21C2D159395AD757_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_11;
		L_11 = il2cpp_unsafe_as_ref<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87>(L_10);
		int32_t L_12 = ___1_start;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_13;
		L_13 = il2cpp_unsafe_add<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,int32_t>(L_11, L_12);
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mCC4ED005E0023405480C9F83B0F13E39A16B3BA3_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_2;
		L_2 = il2cpp_unsafe_as_ref<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87>((uint8_t*)L_1);
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m31A2EA269EF672A7C251B615BA32E9B3B264E225_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_0 = ___0_ptr;
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* Span_1_get_Item_m2299742BA852C41228C3B88D323E3D72340348B4_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_2 = __this->____pointer;
		V_0 = L_2;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_5;
		L_5 = il2cpp_unsafe_add<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_mDB170CD06C3DD5594C4BC9DDBBE524C6F7A3BD7C_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, const RuntimeMethod* method) 
{
	ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_0 = __this->____pointer;
		V_0 = L_0;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m24197F31A25C76AE546856B40C1CE528B09461DB_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_4 = __this->____pointer;
		V_2 = L_4;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_12 = __this->____pointer;
		V_2 = L_12;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_19 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_18 = L_19;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_24 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_23 = L_24;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_29 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_28 = L_29;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_34 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_33 = L_34;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_39 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_38 = L_39;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_44 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_43 = L_44;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_49 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_48 = L_49;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_54 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_64 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_63 = L_64;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_69 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_68 = L_69;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_74 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_73 = L_74;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_79 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 L_85 = ___0_value;
		*(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m41ABE0322BD8C1C816266209CEB21400B3B702C7_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m6C31F03BA2113C74E17C5CDEEEB6F3127EED655F_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E L_2 = ___0_destination;
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_3 = L_2.____pointer;
		V_0 = L_3;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_0));
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_5 = __this->____pointer;
		V_0 = L_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisByte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87_mE057DC9F2C913014D2F0DA1582E3652DA81D4108(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_mEA74F58CE04359A9163563E36B39586E39C4F711_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m6C31F03BA2113C74E17C5CDEEEB6F3127EED655F_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E L_2 = ___0_destination;
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_3 = L_2.____pointer;
		V_1 = L_3;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_1));
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_5 = __this->____pointer;
		V_1 = L_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisByte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87_mE057DC9F2C913014D2F0DA1582E3652DA81D4108(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t2AC1F24E0EEA27708EE5E3315C5E8A149DA4AC1B Span_1_op_Implicit_m4328ED9CB019512D8ABAEDFCF3D56FCB9E5B829F_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E L_0 = ___0_span;
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_1 = L_0.____pointer;
		V_0 = L_1;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_0));
		Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t2AC1F24E0EEA27708EE5E3315C5E8A149DA4AC1B L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_mB2EBAFF15789F2361DDAE7F848E175DB33845102_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_m1F612BF6B088A12F79A59E3CB53DA321F89812B2_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_5 = __this->____pointer;
		V_1 = L_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E Span_1_Slice_m5E882862D8F160D04D7B49E46FE18132DB053FF0_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_2 = __this->____pointer;
		V_0 = L_2;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_5;
		L_5 = il2cpp_unsafe_add<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m31A2EA269EF672A7C251B615BA32E9B3B264E225_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E Span_1_Slice_m81DFF4DB69C83C6157E83EF0E5FF305BFE954DE3_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_5 = __this->____pointer;
		V_0 = L_5;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_8;
		L_8 = il2cpp_unsafe_add<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m31A2EA269EF672A7C251B615BA32E9B3B264E225_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* Span_1_ToArray_m9399DB15500A44E4DE581E9849916DC1CA05A1DD_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, const RuntimeMethod* method) 
{
	ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_1;
		L_1 = Array_Empty_TisByte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87_m05CA261BA6F06533AB2F5C75B5B0CB6F63DEC412_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_3 = (Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A*)(Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_6;
		L_6 = il2cpp_unsafe_as_ref<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87>(L_5);
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_7 = __this->____pointer;
		V_0 = L_7;
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisByte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87_mE057DC9F2C913014D2F0DA1582E3652DA81D4108(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m6C31F03BA2113C74E17C5CDEEEB6F3127EED655F_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_mFF40CCCD6CC0F2772B1ED6D0FE87A6B7FD5DFAD3_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_mEFCBDF7677F0AAE5ADB7D46F5C698D3B1C5707AC_gshared (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E Span_1_op_Implicit_m77AF3020FAEC50FFC706CC8EBC15C10A43DEFD22_gshared (Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* ___0_array, const RuntimeMethod* method) 
{
	{
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_0 = ___0_array;
		Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_m9C0B3F87D446842B5C4638690ED90478A5B5073C_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mB15C95C53B11DF662E871E2732D51D09DBDB299E_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* ___0_array, const RuntimeMethod* method) 
{
	Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tCD30211080708598A3F07B04B84E8A37702B198C));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B));
		goto IL_0037;
	}

IL_0037:
	{
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_4;
		L_4 = il2cpp_unsafe_as_ref<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B>(L_3);
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mEFCB13AC0C0970F5A8D3DA6FBB90DE2CA82E0B4A_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tCD30211080708598A3F07B04B84E8A37702B198C));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_11;
		L_11 = il2cpp_unsafe_as_ref<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B>(L_10);
		int32_t L_12 = ___1_start;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_13;
		L_13 = il2cpp_unsafe_add<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,int32_t>(L_11, L_12);
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mAEEACE0001CF1B70BA858131A0A080A74B695E96_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_2;
		L_2 = il2cpp_unsafe_as_ref<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B>((uint8_t*)L_1);
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m29EE9A42F0B8B3317F565CF7FAAB5E0567DC495B_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_0 = ___0_ptr;
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* Span_1_get_Item_mD0C2A9DC58E8312E6E352D83049D8C1A675F6552_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_2 = __this->____pointer;
		V_0 = L_2;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_5;
		L_5 = il2cpp_unsafe_add<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_mDD61566F943288E7236A011CE0741F4D82D9F7AD_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, const RuntimeMethod* method) 
{
	ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_0 = __this->____pointer;
		V_0 = L_0;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m0E1FCD8BDCECA53A81B3D2F28DA849F1A6745C61_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_4 = __this->____pointer;
		V_2 = L_4;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_12 = __this->____pointer;
		V_2 = L_12;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_19 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_18 = L_19;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_24 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_23 = L_24;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_29 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_28 = L_29;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_34 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_33 = L_34;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_39 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_38 = L_39;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_44 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_43 = L_44;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_49 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_48 = L_49;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_54 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_64 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_63 = L_64;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_69 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_68 = L_69;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_74 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_73 = L_74;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_79 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B L_85 = ___0_value;
		*(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_mEECCC113349066AE8D320441A5305A0C289B24C6_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, Span_1_tCD30211080708598A3F07B04B84E8A37702B198C ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_mF218AEBAC87C5B982A156B8286EF27B501363D4C_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_tCD30211080708598A3F07B04B84E8A37702B198C L_2 = ___0_destination;
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_3 = L_2.____pointer;
		V_0 = L_3;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_0));
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_5 = __this->____pointer;
		V_0 = L_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisByte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B_m321993B9B1BFF1674C614D34E70D2E0B23FA0B4B(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_mDEEB4C983A9367B4B55B8C18CE20020EB8965BD5_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, Span_1_tCD30211080708598A3F07B04B84E8A37702B198C ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_mF218AEBAC87C5B982A156B8286EF27B501363D4C_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_tCD30211080708598A3F07B04B84E8A37702B198C L_2 = ___0_destination;
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_3 = L_2.____pointer;
		V_1 = L_3;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_1));
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_5 = __this->____pointer;
		V_1 = L_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisByte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B_m321993B9B1BFF1674C614D34E70D2E0B23FA0B4B(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t45FE292A8BF877FADC6630D8A86BD5BFDDC70267 Span_1_op_Implicit_m6821C6AF98D7178BC180DBD02F4372989B84DD6C_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_tCD30211080708598A3F07B04B84E8A37702B198C L_0 = ___0_span;
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_1 = L_0.____pointer;
		V_0 = L_1;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_0));
		Span_1_tCD30211080708598A3F07B04B84E8A37702B198C L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t45FE292A8BF877FADC6630D8A86BD5BFDDC70267 L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_mF698E5C91A39EE4E9A4143E3EECCE2A9078FD390_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_m332F8BE62F9A5DC5A89A0725DC762EB9E855BB61_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_5 = __this->____pointer;
		V_1 = L_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tCD30211080708598A3F07B04B84E8A37702B198C Span_1_Slice_m57F79BBBF7DAAEA8AF6C49FB3A4FBE3C3D1DC8EC_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_2 = __this->____pointer;
		V_0 = L_2;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_5;
		L_5 = il2cpp_unsafe_add<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_tCD30211080708598A3F07B04B84E8A37702B198C L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m29EE9A42F0B8B3317F565CF7FAAB5E0567DC495B_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tCD30211080708598A3F07B04B84E8A37702B198C Span_1_Slice_mC1A3AD27A10A7F3795EE9BCE028B3F080363A82E_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_5 = __this->____pointer;
		V_0 = L_5;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_8;
		L_8 = il2cpp_unsafe_add<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_tCD30211080708598A3F07B04B84E8A37702B198C L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m29EE9A42F0B8B3317F565CF7FAAB5E0567DC495B_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* Span_1_ToArray_m2720459C6107BC22C1D6E86840E94C3B3D51D428_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, const RuntimeMethod* method) 
{
	ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_1;
		L_1 = Array_Empty_TisByte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B_m6D7C0121F09237151D13126E696B9A3344E0F93A_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_3 = (Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348*)(Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_6;
		L_6 = il2cpp_unsafe_as_ref<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B>(L_5);
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_7 = __this->____pointer;
		V_0 = L_7;
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisByte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B_m321993B9B1BFF1674C614D34E70D2E0B23FA0B4B(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mF218AEBAC87C5B982A156B8286EF27B501363D4C_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m4D0AF55386061E72400E957EA95629090569CA91_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_mEE5D02E3AC520988801B71C2199964420B5EB0A8_gshared (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tCD30211080708598A3F07B04B84E8A37702B198C Span_1_op_Implicit_m59C0725AA5AA3CA8C7F641509EF16808D727CF90_gshared (Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* ___0_array, const RuntimeMethod* method) 
{
	{
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_0 = ___0_array;
		Span_1_tCD30211080708598A3F07B04B84E8A37702B198C L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_mB15C95C53B11DF662E871E2732D51D09DBDB299E_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m23CBCD46AD762681A232C97FE90B3A9EDD4991E5_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, const RuntimeMethod* method) 
{
	Il2CppChar V_0 = 0x0;
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Il2CppChar));
		goto IL_0037;
	}

IL_0037:
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		Il2CppChar* L_4;
		L_4 = il2cpp_unsafe_as_ref<Il2CppChar>(L_3);
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m5BFF79141064122141ED34283347A634B9DF577D_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	Il2CppChar V_0 = 0x0;
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Il2CppChar));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		Il2CppChar* L_11;
		L_11 = il2cpp_unsafe_as_ref<Il2CppChar>(L_10);
		int32_t L_12 = ___1_start;
		Il2CppChar* L_13;
		L_13 = il2cpp_unsafe_add<Il2CppChar,int32_t>(L_11, L_12);
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m835590E344B05AF6AF00A78E92C4175BD781A3D2_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		Il2CppChar* L_2;
		L_2 = il2cpp_unsafe_as_ref<Il2CppChar>((uint8_t*)L_1);
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mC9BE2938B716B46BB6B9070B94DBE5CE814BC0E2_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, Il2CppChar* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Il2CppChar* L_0 = ___0_ptr;
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar* Span_1_get_Item_mF2BC8531357665CFAEC613B2AE68EB588ED973E5_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_2 = __this->____pointer;
		V_0 = L_2;
		Il2CppChar* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		Il2CppChar* L_5;
		L_5 = il2cpp_unsafe_add<Il2CppChar,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m1D40175F89C9D3C30CE2E42C986374C1A4B8DB75_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, const RuntimeMethod* method) 
{
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_0 = __this->____pointer;
		V_0 = L_0;
		Il2CppChar* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<Il2CppChar>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m13ADB57BBCF7684FF92630FACC729B10B9B6B254_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, Il2CppChar ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	Il2CppChar V_1 = 0x0;
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	Il2CppChar* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<Il2CppChar>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		Il2CppChar L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_4 = __this->____pointer;
		V_2 = L_4;
		Il2CppChar* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_12 = __this->____pointer;
		V_2 = L_12;
		Il2CppChar* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<Il2CppChar>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		Il2CppChar* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		Il2CppChar* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		Il2CppChar L_19 = ___0_value;
		*(Il2CppChar*)L_18 = L_19;
		Il2CppChar* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		Il2CppChar* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		Il2CppChar L_24 = ___0_value;
		*(Il2CppChar*)L_23 = L_24;
		Il2CppChar* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		Il2CppChar* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		Il2CppChar L_29 = ___0_value;
		*(Il2CppChar*)L_28 = L_29;
		Il2CppChar* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		Il2CppChar* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		Il2CppChar L_34 = ___0_value;
		*(Il2CppChar*)L_33 = L_34;
		Il2CppChar* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		Il2CppChar* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		Il2CppChar L_39 = ___0_value;
		*(Il2CppChar*)L_38 = L_39;
		Il2CppChar* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		Il2CppChar* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		Il2CppChar L_44 = ___0_value;
		*(Il2CppChar*)L_43 = L_44;
		Il2CppChar* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		Il2CppChar* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		Il2CppChar L_49 = ___0_value;
		*(Il2CppChar*)L_48 = L_49;
		Il2CppChar* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		Il2CppChar* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		Il2CppChar L_54 = ___0_value;
		*(Il2CppChar*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		Il2CppChar* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		Il2CppChar* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		Il2CppChar L_64 = ___0_value;
		*(Il2CppChar*)L_63 = L_64;
		Il2CppChar* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		Il2CppChar* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		Il2CppChar L_69 = ___0_value;
		*(Il2CppChar*)L_68 = L_69;
		Il2CppChar* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		Il2CppChar* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		Il2CppChar L_74 = ___0_value;
		*(Il2CppChar*)L_73 = L_74;
		Il2CppChar* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		Il2CppChar* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		Il2CppChar L_79 = ___0_value;
		*(Il2CppChar*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		Il2CppChar* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		Il2CppChar* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<Il2CppChar,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		Il2CppChar L_85 = ___0_value;
		*(Il2CppChar*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m7BB0A9984004C444974C7F111CCAD6D85325A15E_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_mB79622153F80AD55A805C005842AF045F4FCF992_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_2 = ___0_destination;
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_3 = L_2.____pointer;
		V_0 = L_3;
		Il2CppChar* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_0));
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_5 = __this->____pointer;
		V_0 = L_5;
		Il2CppChar* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisChar_t521A6F19B456D956AF452D926C32709DC03D6B17_m62AF071D7F91DFC9A4D8B847D6A4472B820B5446(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m25ED56B31CC4F4DBC734E898741037AADC8806F8_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_mB79622153F80AD55A805C005842AF045F4FCF992_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_2 = ___0_destination;
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_3 = L_2.____pointer;
		V_1 = L_3;
		Il2CppChar* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_1));
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_5 = __this->____pointer;
		V_1 = L_5;
		Il2CppChar* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisChar_t521A6F19B456D956AF452D926C32709DC03D6B17_m62AF071D7F91DFC9A4D8B847D6A4472B820B5446(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 Span_1_op_Implicit_m03D0CEDC1BC95844236105D1DE24A702B956BFE4_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_0 = ___0_span;
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_1 = L_0.____pointer;
		V_0 = L_1;
		Il2CppChar* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_0));
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1 L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_m0152E50B40750679B83FF9F30CA539FFBB98EEE8_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_m12316C6CDC05E2F49EA4BDAD78FD7F1718E6E980_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_5 = __this->____pointer;
		V_1 = L_5;
		Il2CppChar* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D Span_1_Slice_mDC9AA64B960B9BB8357655827A8202DF83443068_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_2 = __this->____pointer;
		V_0 = L_2;
		Il2CppChar* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		Il2CppChar* L_5;
		L_5 = il2cpp_unsafe_add<Il2CppChar,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_mC9BE2938B716B46BB6B9070B94DBE5CE814BC0E2_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D Span_1_Slice_mEFBC3C78FD443FFE23F9E841D43B7B0271622843_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_5 = __this->____pointer;
		V_0 = L_5;
		Il2CppChar* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		Il2CppChar* L_8;
		L_8 = il2cpp_unsafe_add<Il2CppChar,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_mC9BE2938B716B46BB6B9070B94DBE5CE814BC0E2_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* Span_1_ToArray_m3403E698018738391BF349D71C3B53A6942E53DC_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, const RuntimeMethod* method) 
{
	ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_1;
		L_1 = Array_Empty_TisChar_t521A6F19B456D956AF452D926C32709DC03D6B17_mD1C1362CB74B91496D984B006ADC79B688D9B50D_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_3 = (CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		Il2CppChar* L_6;
		L_6 = il2cpp_unsafe_as_ref<Il2CppChar>(L_5);
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_7 = __this->____pointer;
		V_0 = L_7;
		Il2CppChar* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(Il2CppChar, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisChar_t521A6F19B456D956AF452D926C32709DC03D6B17_m62AF071D7F91DFC9A4D8B847D6A4472B820B5446(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mB79622153F80AD55A805C005842AF045F4FCF992_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_mC3849E0C0D3F56F6E60A6CF94A829B5671286935_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_m3EC9972281C0F59EB1D5E884FA5BD061EEE5298B_gshared (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D Span_1_op_Implicit_mA0E9FDCF2C5113BA9F9C4964D17D8BDFBD6F3C98_gshared (CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, const RuntimeMethod* method) 
{
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_0 = ___0_array;
		Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_m23CBCD46AD762681A232C97FE90B3A9EDD4991E5_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mD8CCC80CA9129EEAC13B40BA31C6C577BDF46ECD_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* ___0_array, const RuntimeMethod* method) 
{
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F));
		goto IL_0037;
	}

IL_0037:
	{
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_4;
		L_4 = il2cpp_unsafe_as_ref<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F>(L_3);
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m61CB4E239F4B8535AE2EB854BD18DDFC1142FD07_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_11;
		L_11 = il2cpp_unsafe_as_ref<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F>(L_10);
		int32_t L_12 = ___1_start;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_13;
		L_13 = il2cpp_unsafe_add<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,int32_t>(L_11, L_12);
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m03647096ABFA9C361BD608B88E888E6D24BD45B6_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_2;
		L_2 = il2cpp_unsafe_as_ref<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F>((uint8_t*)L_1);
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m48419159317F9826172EDEA69FDB0598B87B34D2_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_0 = ___0_ptr;
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* Span_1_get_Item_m52CBA5BCE5D91D266DC53BC8CAA58B6B838758C9_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_2 = __this->____pointer;
		V_0 = L_2;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_5;
		L_5 = il2cpp_unsafe_add<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_mCB7BFD6347A5FC9F5C98881FBB6EED05DC7CEAFB_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, const RuntimeMethod* method) 
{
	ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_0 = __this->____pointer;
		V_0 = L_0;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m179EE62D8B2DFC60ADF134F7DF0633D7949836EE_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_4 = __this->____pointer;
		V_2 = L_4;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_12 = __this->____pointer;
		V_2 = L_12;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_19 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_18 = L_19;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_24 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_23 = L_24;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_29 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_28 = L_29;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_34 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_33 = L_34;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_39 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_38 = L_39;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_44 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_43 = L_44;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_49 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_48 = L_49;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_54 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_64 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_63 = L_64;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_69 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_68 = L_69;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_74 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_73 = L_74;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_79 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_85 = ___0_value;
		*(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m312B7E6091A77C90731BB4B3B0F9013A0380E8FE_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m83147EFB62B7FFBA49EEBEBE975F7348D665BAD0_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 L_2 = ___0_destination;
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_3 = L_2.____pointer;
		V_0 = L_3;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_0));
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_5 = __this->____pointer;
		V_0 = L_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_m3B15D4D61932A340BAAA5BE6E8D419605D3692E6(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m222A33CADBBA4AE2718BA2E3FB364B9595A83E5E_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m83147EFB62B7FFBA49EEBEBE975F7348D665BAD0_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 L_2 = ___0_destination;
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_3 = L_2.____pointer;
		V_1 = L_3;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_1));
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_5 = __this->____pointer;
		V_1 = L_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_m3B15D4D61932A340BAAA5BE6E8D419605D3692E6(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t7EE9E7096EE52CA433AA61A9353AD90B29B2C816 Span_1_op_Implicit_m37C59BB49FE22493B2449536D2487DC02E45B376_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 L_0 = ___0_span;
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_1 = L_0.____pointer;
		V_0 = L_1;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_0));
		Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t7EE9E7096EE52CA433AA61A9353AD90B29B2C816 L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_mD46BD07C5320D1B1A225E53FAF466E153FFC1679_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_mAF2DA66DEE0290DEFDE874C1F418EF5AEB17E8E2_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_5 = __this->____pointer;
		V_1 = L_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 Span_1_Slice_m0348A44E5418C052C9535570A1DE71BB4AE61E71_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_2 = __this->____pointer;
		V_0 = L_2;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_5;
		L_5 = il2cpp_unsafe_add<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m48419159317F9826172EDEA69FDB0598B87B34D2_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 Span_1_Slice_mE5AD8E826B11284EBF2D856E2D337D31DE34D25B_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_5 = __this->____pointer;
		V_0 = L_5;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_8;
		L_8 = il2cpp_unsafe_add<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m48419159317F9826172EDEA69FDB0598B87B34D2_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* Span_1_ToArray_m6F8FFA52461A0D5172130CD6B6AF02461326AF5C_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, const RuntimeMethod* method) 
{
	ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_1;
		L_1 = Array_Empty_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_m7E922E24AAEBD664256383832D53DDF17E1F3052_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_3 = (ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389*)(ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_6;
		L_6 = il2cpp_unsafe_as_ref<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F>(L_5);
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_7 = __this->____pointer;
		V_0 = L_7;
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_m3B15D4D61932A340BAAA5BE6E8D419605D3692E6(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m83147EFB62B7FFBA49EEBEBE975F7348D665BAD0_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_mB55BD6134EA35A11485DCF408D6D5FFC0BD3F533_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_m6962C2A5B1AD4080D5573C23E91A19EB6D728CF7_gshared (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 Span_1_op_Implicit_m9C1413FB618ED0B2E091F5EF63CE03A4C0AEC1A2_gshared (ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* ___0_array, const RuntimeMethod* method) 
{
	{
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_0 = ___0_array;
		Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018 L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_mD8CCC80CA9129EEAC13B40BA31C6C577BDF46ECD_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mDE7408B1AC4D3DDE1E8EB6C1A8AE8244CAB0BBB1_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* ___0_array, const RuntimeMethod* method) 
{
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B));
		goto IL_0037;
	}

IL_0037:
	{
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_4;
		L_4 = il2cpp_unsafe_as_ref<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B>(L_3);
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m7F27D45B1D68DA5173A121174DC1B8EEF1D43D5E_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_11;
		L_11 = il2cpp_unsafe_as_ref<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B>(L_10);
		int32_t L_12 = ___1_start;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_13;
		L_13 = il2cpp_unsafe_add<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,int32_t>(L_11, L_12);
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m3F2D12A6DE9449A7F172A8190B51721D3533512A_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_2;
		L_2 = il2cpp_unsafe_as_ref<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B>((uint8_t*)L_1);
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mD16E04B2ED38420390E0DE1D6E01DE23C583B434_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_0 = ___0_ptr;
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* Span_1_get_Item_mCE0F47FEF30AFC052EE646724CF0CCA095E61295_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_2 = __this->____pointer;
		V_0 = L_2;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_5;
		L_5 = il2cpp_unsafe_add<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m44937991C3C572BAA1C7D8B220198A6D73296EFD_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, const RuntimeMethod* method) 
{
	ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_0 = __this->____pointer;
		V_0 = L_0;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_mC1DCF00C88E61AB4C769979DAB36C6AC2FD7AC8F_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_4 = __this->____pointer;
		V_2 = L_4;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_12 = __this->____pointer;
		V_2 = L_12;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_19 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_18 = L_19;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_24 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_23 = L_24;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_29 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_28 = L_29;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_34 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_33 = L_34;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_39 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_38 = L_39;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_44 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_43 = L_44;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_49 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_48 = L_49;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_54 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_64 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_63 = L_64;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_69 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_68 = L_69;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_74 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_73 = L_74;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_79 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B L_85 = ___0_value;
		*(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m9D9E0B986FEB6121776F6E72762BFA348872D32D_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m413F20ECFE3F523163B62ED5BAB7DFA22F2FCCD4_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D L_2 = ___0_destination;
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_3 = L_2.____pointer;
		V_0 = L_3;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_0));
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_5 = __this->____pointer;
		V_0 = L_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_mA65CAF282F03FD4DB46666E2C44C22E3D0035A68(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m5751351E4F7B9348F5F42D82F5219BC76C16AEAF_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m413F20ECFE3F523163B62ED5BAB7DFA22F2FCCD4_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D L_2 = ___0_destination;
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_3 = L_2.____pointer;
		V_1 = L_3;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_1));
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_5 = __this->____pointer;
		V_1 = L_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_mA65CAF282F03FD4DB46666E2C44C22E3D0035A68(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t2E193A80641154947640E9A71614019D7A8F3DFC Span_1_op_Implicit_mF3E148EA33236C003117DE38E62DE33D938EC163_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D L_0 = ___0_span;
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_1 = L_0.____pointer;
		V_0 = L_1;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_0));
		Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t2E193A80641154947640E9A71614019D7A8F3DFC L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_m841651F5E0DEC77984A109EF01090F3F776571FB_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_mECADFF7BF87B76EA399CEE34F582D9F58876B9C6_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_5 = __this->____pointer;
		V_1 = L_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D Span_1_Slice_m7D6809980EE719FEF240C5A1F91ED1F8A49438D6_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_2 = __this->____pointer;
		V_0 = L_2;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_5;
		L_5 = il2cpp_unsafe_add<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_mD16E04B2ED38420390E0DE1D6E01DE23C583B434_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D Span_1_Slice_mC32C0950E410BE1C194BBA46C50AD868A23A25B8_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_5 = __this->____pointer;
		V_0 = L_5;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_8;
		L_8 = il2cpp_unsafe_add<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_mD16E04B2ED38420390E0DE1D6E01DE23C583B434_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* Span_1_ToArray_mC46741F43EE2A7AF5495CB3595312D25F9E437E5_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, const RuntimeMethod* method) 
{
	ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_1;
		L_1 = Array_Empty_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m5B415C4745E47108DD9258EBCCB422EFD6B8A0EB_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_3 = (Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259*)(Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_6;
		L_6 = il2cpp_unsafe_as_ref<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B>(L_5);
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_7 = __this->____pointer;
		V_0 = L_7;
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_mA65CAF282F03FD4DB46666E2C44C22E3D0035A68(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m413F20ECFE3F523163B62ED5BAB7DFA22F2FCCD4_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m1BC77A3C37539F0BD54EC0D5E1062B0612D351CA_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_mE5B1E8B27CA89868BA83DBD5092B62AB77DF4565_gshared (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D Span_1_op_Implicit_m8E6421CEC98AFF0BFB7F1C0A6796C55428A58195_gshared (Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* ___0_array, const RuntimeMethod* method) 
{
	{
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_0 = ___0_array;
		Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_mDE7408B1AC4D3DDE1E8EB6C1A8AE8244CAB0BBB1_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mE396EB49F11B34D41818F29E84D8865E2003B251_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* ___0_array, const RuntimeMethod* method) 
{
	ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1));
		goto IL_0037;
	}

IL_0037:
	{
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_4;
		L_4 = il2cpp_unsafe_as_ref<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1>(L_3);
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mBE8FABAA24DF826BE1E82A4AB4423495327BCB0A_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_11;
		L_11 = il2cpp_unsafe_as_ref<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1>(L_10);
		int32_t L_12 = ___1_start;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_13;
		L_13 = il2cpp_unsafe_add<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,int32_t>(L_11, L_12);
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m08D63DAF47E1B9EAF1763F6F0014D3DB2520FAA6_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_2;
		L_2 = il2cpp_unsafe_as_ref<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1>((uint8_t*)L_1);
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m1910D0E44CCD92AD908E1D5F61FFF27ADFE1EFAD_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_0 = ___0_ptr;
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* Span_1_get_Item_mB28D2A5E8933AF3C4FBD8A9A71922A169C115575_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_2 = __this->____pointer;
		V_0 = L_2;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_5;
		L_5 = il2cpp_unsafe_add<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m6FB345A0D9938AE254BE078AB5674E14B35BA2B0_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, const RuntimeMethod* method) 
{
	ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_0 = __this->____pointer;
		V_0 = L_0;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m693268106C25B6C11C5114CA1B213FCC66383737_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_4 = __this->____pointer;
		V_2 = L_4;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_12 = __this->____pointer;
		V_2 = L_12;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_19 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_18 = L_19;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_24 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_23 = L_24;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_29 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_28 = L_29;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_34 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_33 = L_34;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_39 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_38 = L_39;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_44 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_43 = L_44;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_49 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_48 = L_49;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_54 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_64 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_63 = L_64;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_69 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_68 = L_69;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_74 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_73 = L_74;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_79 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 L_85 = ___0_value;
		*(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m9F453E565E11AE491CA47DC1FC6166FCA11A0BA9_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m3B50FB2CF29A0E7C0C8B69E4E5A72D75883EBC4B_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 L_2 = ___0_destination;
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_3 = L_2.____pointer;
		V_0 = L_3;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_0));
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_5 = __this->____pointer;
		V_0 = L_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1_m747B7D7DC0AA466783F69D3676EC5EE854D08D52(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m7FE4C465E3CD79439D013535C7654D757BF138FC_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m3B50FB2CF29A0E7C0C8B69E4E5A72D75883EBC4B_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 L_2 = ___0_destination;
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_3 = L_2.____pointer;
		V_1 = L_3;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_1));
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_5 = __this->____pointer;
		V_1 = L_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1_m747B7D7DC0AA466783F69D3676EC5EE854D08D52(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t1CFFA3B34C09F05622921AC4014011D43A25715A Span_1_op_Implicit_mE518F0B4D759B13BED4E77F67B8A84AE65EE3A55_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 L_0 = ___0_span;
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_1 = L_0.____pointer;
		V_0 = L_1;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_0));
		Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t1CFFA3B34C09F05622921AC4014011D43A25715A L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_mDB9E4DFF0687E0A5405FF4F6387379524B1B07AB_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_m4B7F2DF1F6F7198DDFDEB08A1EA7555F079D706D_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_5 = __this->____pointer;
		V_1 = L_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 Span_1_Slice_m453B02BE47BECE17D1067E062DB0CF528C86058D_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_2 = __this->____pointer;
		V_0 = L_2;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_5;
		L_5 = il2cpp_unsafe_add<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m1910D0E44CCD92AD908E1D5F61FFF27ADFE1EFAD_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 Span_1_Slice_m8FA4A766C94410882272AD62143536F8CFD55DFB_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_5 = __this->____pointer;
		V_0 = L_5;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_8;
		L_8 = il2cpp_unsafe_add<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m1910D0E44CCD92AD908E1D5F61FFF27ADFE1EFAD_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* Span_1_ToArray_mCFA7DC986EFD8E702DBF3D8E14C955ED5B3D18EF_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, const RuntimeMethod* method) 
{
	ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_1;
		L_1 = Array_Empty_TisConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1_m164EDF2519D24430C10F8BB106ADB252BF225C26_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_3 = (ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2*)(ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_6;
		L_6 = il2cpp_unsafe_as_ref<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1>(L_5);
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_7 = __this->____pointer;
		V_0 = L_7;
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1_m747B7D7DC0AA466783F69D3676EC5EE854D08D52(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m3B50FB2CF29A0E7C0C8B69E4E5A72D75883EBC4B_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m3F0D2AD3665B8971808A96CAEC224BCCF9B01C36_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_m4E876D3B694C51A92940AB4174BDA10EAF3FBB1E_gshared (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 Span_1_op_Implicit_mD040C04412B7ECE954FC223604A61BBEA4E46BD6_gshared (ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* ___0_array, const RuntimeMethod* method) 
{
	{
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_0 = ___0_array;
		Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48 L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_mE396EB49F11B34D41818F29E84D8865E2003B251_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m2817AF8060669CE2B4F3418E7732492AE1043541_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* ___0_array, const RuntimeMethod* method) 
{
	CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044));
		goto IL_0037;
	}

IL_0037:
	{
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_4;
		L_4 = il2cpp_unsafe_as_ref<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044>(L_3);
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mB1D2E0A7358970D3E348EA59CEA0BB859C5BEE98_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_11;
		L_11 = il2cpp_unsafe_as_ref<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044>(L_10);
		int32_t L_12 = ___1_start;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_13;
		L_13 = il2cpp_unsafe_add<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,int32_t>(L_11, L_12);
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m22EB61195E8AD0900782D8ECD9B389A66E8058B9_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_2;
		L_2 = il2cpp_unsafe_as_ref<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044>((uint8_t*)L_1);
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mCD3AE57570C815AC4046DA4D9E7C0A9E2BBEB547_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_0 = ___0_ptr;
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* Span_1_get_Item_m94FA4691A509C5A984F5222219661935AFC2FD3E_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_2 = __this->____pointer;
		V_0 = L_2;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_5;
		L_5 = il2cpp_unsafe_add<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_mCC7BD219642056D8E8D42942F5AE57A726A62C81_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, const RuntimeMethod* method) 
{
	ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_0 = __this->____pointer;
		V_0 = L_0;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m1C15D3E3713BB8E857EDA412D2A871F19938FC8D_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_4 = __this->____pointer;
		V_2 = L_4;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_12 = __this->____pointer;
		V_2 = L_12;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_19 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_18 = L_19;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_24 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_23 = L_24;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_29 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_28 = L_29;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_34 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_33 = L_34;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_39 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_38 = L_39;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_44 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_43 = L_44;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_49 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_48 = L_49;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_54 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_64 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_63 = L_64;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_69 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_68 = L_69;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_74 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_73 = L_74;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_79 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 L_85 = ___0_value;
		*(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m1B261FC781B5AA89B6D5E94D4E2D293A1221350E_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_mEC383018256E25827F3B339475CABFC2C2237A88_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE L_2 = ___0_destination;
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_3 = L_2.____pointer;
		V_0 = L_3;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_0));
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_5 = __this->____pointer;
		V_0 = L_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisCopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044_m49C533FCD49E82DED6CE9BFF4EE71DBC632E91A0(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m7929B6D702D27A6E9D1579F463F967C887916A6E_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_mEC383018256E25827F3B339475CABFC2C2237A88_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE L_2 = ___0_destination;
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_3 = L_2.____pointer;
		V_1 = L_3;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_1));
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_5 = __this->____pointer;
		V_1 = L_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisCopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044_m49C533FCD49E82DED6CE9BFF4EE71DBC632E91A0(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t65511D2895327A8ECE2BF5A34FDD23AE34C83122 Span_1_op_Implicit_m44CC00E6EF8E15E00025A8CCBE6E21AF87606B2D_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE L_0 = ___0_span;
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_1 = L_0.____pointer;
		V_0 = L_1;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_0));
		Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t65511D2895327A8ECE2BF5A34FDD23AE34C83122 L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_m4D4193A630867D8532F94829D1B330477153F6F5_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_mDF30F734A6CB97C05992644BAEAD98700DEBA561_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_5 = __this->____pointer;
		V_1 = L_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE Span_1_Slice_mD759BBB5224546D40F87110A5B82CEC67AEBAE79_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_2 = __this->____pointer;
		V_0 = L_2;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_5;
		L_5 = il2cpp_unsafe_add<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_mCD3AE57570C815AC4046DA4D9E7C0A9E2BBEB547_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE Span_1_Slice_m8D7D1B9DD8DB83AB2381032519BC6DD8EACB9F39_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_5 = __this->____pointer;
		V_0 = L_5;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_8;
		L_8 = il2cpp_unsafe_add<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_mCD3AE57570C815AC4046DA4D9E7C0A9E2BBEB547_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* Span_1_ToArray_m91AE194DAB85E4947637106217B696BE3E5833B2_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, const RuntimeMethod* method) 
{
	ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_1;
		L_1 = Array_Empty_TisCopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044_mE213035FEF51FB6A504BDD242F0307E9FE074829_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_3 = (CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57*)(CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_6;
		L_6 = il2cpp_unsafe_as_ref<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044>(L_5);
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_7 = __this->____pointer;
		V_0 = L_7;
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisCopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044_m49C533FCD49E82DED6CE9BFF4EE71DBC632E91A0(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mEC383018256E25827F3B339475CABFC2C2237A88_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m61A2B014BA19D944D333E322CBC5DC0AEE711C0D_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_mBE529327378BD62EBF68ED2B5BE39886411B98DE_gshared (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE Span_1_op_Implicit_mE543261C3A4DA085677350E3366A664EFAF28EFF_gshared (CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* ___0_array, const RuntimeMethod* method) 
{
	{
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_0 = ___0_array;
		Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_m2817AF8060669CE2B4F3418E7732492AE1043541_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m59E7D308EB85B51BA4162E76EE21E5568E986970_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* ___0_array, const RuntimeMethod* method) 
{
	CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0));
		goto IL_0037;
	}

IL_0037:
	{
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_4;
		L_4 = il2cpp_unsafe_as_ref<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0>(L_3);
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m606517B73FE4D624EC119A86BE3E06F24C19893E_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_11;
		L_11 = il2cpp_unsafe_as_ref<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0>(L_10);
		int32_t L_12 = ___1_start;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_13;
		L_13 = il2cpp_unsafe_add<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,int32_t>(L_11, L_12);
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mE2FA83FC81F71DF9F7FF270D9B9F0BA6E9682CC6_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_2;
		L_2 = il2cpp_unsafe_as_ref<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0>((uint8_t*)L_1);
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m938DD54F3773C27DD1393A85BB94346047AD1DA5_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_0 = ___0_ptr;
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* Span_1_get_Item_m0DD0A598D8E775F0F40CA173448E867F3C4D7184_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_2 = __this->____pointer;
		V_0 = L_2;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_5;
		L_5 = il2cpp_unsafe_add<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m36960EB93F65E71DED9E56FBCCD6DE03D299B416_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, const RuntimeMethod* method) 
{
	ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_0 = __this->____pointer;
		V_0 = L_0;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_mADB4236876AE9BE883BE402317D8B5A6D2FDB581_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_4 = __this->____pointer;
		V_2 = L_4;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_12 = __this->____pointer;
		V_2 = L_12;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_19 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_18 = L_19;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_24 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_23 = L_24;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_29 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_28 = L_29;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_34 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_33 = L_34;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_39 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_38 = L_39;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_44 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_43 = L_44;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_49 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_48 = L_49;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_54 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_64 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_63 = L_64;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_69 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_68 = L_69;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_74 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_73 = L_74;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_79 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_85 = ___0_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m80A1636F770BC85161F858E9C9CB7D9E3CD10285_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m385F87A001B432F97C5381EF1F01B485642ED27D_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 L_2 = ___0_destination;
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_3 = L_2.____pointer;
		V_0 = L_3;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_0));
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_5 = __this->____pointer;
		V_0 = L_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m9A4B5780CB8BC1ACD63C193EC68D5E217CDBAC80(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_mECF82110A92F5DE6D13C143A65D6479EF6EB3E9B_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m385F87A001B432F97C5381EF1F01B485642ED27D_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 L_2 = ___0_destination;
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_3 = L_2.____pointer;
		V_1 = L_3;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_1));
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_5 = __this->____pointer;
		V_1 = L_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m9A4B5780CB8BC1ACD63C193EC68D5E217CDBAC80(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t7918A88B9E042EA0B873C90C85D2A8B97CB11BDF Span_1_op_Implicit_m50C31B4C2B83D2776A89C2431F1B8CA12A87B786_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 L_0 = ___0_span;
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_1 = L_0.____pointer;
		V_0 = L_1;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_0));
		Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t7918A88B9E042EA0B873C90C85D2A8B97CB11BDF L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_m7515BCC9EAB305B335A968E684B597A1FC9A5F24_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_m58DBA8626A402C6462C2DAC716BBE2A0D7132E27_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_5 = __this->____pointer;
		V_1 = L_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 Span_1_Slice_m63DB5DCB9F9F920F70F16F0D2BF971E736B91419_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_2 = __this->____pointer;
		V_0 = L_2;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_5;
		L_5 = il2cpp_unsafe_add<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m938DD54F3773C27DD1393A85BB94346047AD1DA5_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 Span_1_Slice_mFBBEF6E4AC4F1A5960049A4F244F9FF9D85F7767_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_5 = __this->____pointer;
		V_0 = L_5;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_8;
		L_8 = il2cpp_unsafe_add<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m938DD54F3773C27DD1393A85BB94346047AD1DA5_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* Span_1_ToArray_mA2628E72CF7312719A67C20F19743C12093A3454_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, const RuntimeMethod* method) 
{
	ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_1;
		L_1 = Array_Empty_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m46787E1D6E481E4790F1F9E63000A067C9AF33CD_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_3 = (CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61*)(CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_6;
		L_6 = il2cpp_unsafe_as_ref<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0>(L_5);
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_7 = __this->____pointer;
		V_0 = L_7;
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m9A4B5780CB8BC1ACD63C193EC68D5E217CDBAC80(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m385F87A001B432F97C5381EF1F01B485642ED27D_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m81034FE9CEB9BF65700774B1C6670020FF2F1E91_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_m224B624467E11482C2F71CD49F9A224DFDF521E6_gshared (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 Span_1_op_Implicit_mEE5E639E63941E7CD6CF6C70F043A3D749BBF49E_gshared (CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* ___0_array, const RuntimeMethod* method) 
{
	{
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_0 = ___0_array;
		Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116 L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_m59E7D308EB85B51BA4162E76EE21E5568E986970_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m7F574E10BF82902E6DFCF264F060076901BC34C0_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* ___0_array, const RuntimeMethod* method) 
{
	DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5));
		goto IL_0037;
	}

IL_0037:
	{
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_4;
		L_4 = il2cpp_unsafe_as_ref<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5>(L_3);
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mF67C4C6EFA782F05C69F6BB6A886AB9C9C10BDC7_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_11;
		L_11 = il2cpp_unsafe_as_ref<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5>(L_10);
		int32_t L_12 = ___1_start;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_13;
		L_13 = il2cpp_unsafe_add<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,int32_t>(L_11, L_12);
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m228D147D941B814F1329A67DDFDE2EEB431FB518_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_2;
		L_2 = il2cpp_unsafe_as_ref<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5>((uint8_t*)L_1);
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m52DDC62CEE4B57B1A97604C59D91F867D9C9472B_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_0 = ___0_ptr;
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* Span_1_get_Item_m11AE8F8BE99DFC276141A8E87744C2BA1D969DEE_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_2 = __this->____pointer;
		V_0 = L_2;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_5;
		L_5 = il2cpp_unsafe_add<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m8D5E95ECEAAA5A95DA84A54805C724EC84151053_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, const RuntimeMethod* method) 
{
	ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_0 = __this->____pointer;
		V_0 = L_0;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m45952C7D9651153521D16CAAF7F702BE54191BD3_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_4 = __this->____pointer;
		V_2 = L_4;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_12 = __this->____pointer;
		V_2 = L_12;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_19 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_18 = L_19;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_24 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_23 = L_24;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_29 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_28 = L_29;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_34 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_33 = L_34;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_39 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_38 = L_39;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_44 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_43 = L_44;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_49 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_48 = L_49;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_54 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_64 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_63 = L_64;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_69 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_68 = L_69;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_74 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_73 = L_74;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_79 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 L_85 = ___0_value;
		*(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m816C9F3553EB12A6072B1A1D2593A6D01330556C_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_mFF4419EF107B2F1CD3364357F9723EAC96433F03_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 L_2 = ___0_destination;
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_3 = L_2.____pointer;
		V_0 = L_3;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_0));
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_5 = __this->____pointer;
		V_0 = L_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisDrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5_mDF1CDB2973A50B932ED2E72CC7A57E75C7FCAB54(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_mADD62B12032BFD1A15E6D36DA8A3F1AE31C2D126_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_mFF4419EF107B2F1CD3364357F9723EAC96433F03_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 L_2 = ___0_destination;
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_3 = L_2.____pointer;
		V_1 = L_3;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_1));
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_5 = __this->____pointer;
		V_1 = L_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisDrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5_mDF1CDB2973A50B932ED2E72CC7A57E75C7FCAB54(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tB185515663CA8B149175531C2C9804EB48DDEC9B Span_1_op_Implicit_m5C75F80A5B0F30B448701B42F47880BE6B13AA49_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 L_0 = ___0_span;
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_1 = L_0.____pointer;
		V_0 = L_1;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_0));
		Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_tB185515663CA8B149175531C2C9804EB48DDEC9B L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_mB6153B16E29314D6497048CA9F509CF21C277F71_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_m2923E7AA319022EBFDDC405189D77B50BBE47C9C_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_5 = __this->____pointer;
		V_1 = L_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 Span_1_Slice_m4D9B63EFD3EDBBCDDC506B2A4EE7255AE98E716E_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_2 = __this->____pointer;
		V_0 = L_2;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_5;
		L_5 = il2cpp_unsafe_add<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m52DDC62CEE4B57B1A97604C59D91F867D9C9472B_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 Span_1_Slice_m572F7CB4090B053E5DB995EE2207BD30E316B1DB_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_5 = __this->____pointer;
		V_0 = L_5;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_8;
		L_8 = il2cpp_unsafe_add<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m52DDC62CEE4B57B1A97604C59D91F867D9C9472B_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* Span_1_ToArray_m65E63225ABF6D547FE1422B368B4137536104EC3_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, const RuntimeMethod* method) 
{
	ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_1;
		L_1 = Array_Empty_TisDrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5_m05A4DA3A4ACD6D784909779870EE466DF7778EC7_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_3 = (DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB*)(DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_6;
		L_6 = il2cpp_unsafe_as_ref<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5>(L_5);
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_7 = __this->____pointer;
		V_0 = L_7;
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisDrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5_mDF1CDB2973A50B932ED2E72CC7A57E75C7FCAB54(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mFF4419EF107B2F1CD3364357F9723EAC96433F03_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m9D8B811F0101BC86E8D92ADD191281F338CD607B_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_mB74E5CF070738CD4752565624A8C10667F0B8781_gshared (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 Span_1_op_Implicit_m0118B6AB1BE7F6DDBA033389286B1B23268ED8CC_gshared (DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* ___0_array, const RuntimeMethod* method) 
{
	{
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_0 = ___0_array;
		Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73 L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_m7F574E10BF82902E6DFCF264F060076901BC34C0_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mEAFD68654E9CB51239357C3D94CDB5056137D70B_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* ___0_array, const RuntimeMethod* method) 
{
	GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C));
		goto IL_0037;
	}

IL_0037:
	{
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_4;
		L_4 = il2cpp_unsafe_as_ref<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C>(L_3);
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mD858C96433D0CCF6401FD0BD9AE5439983EB1C7F_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_11;
		L_11 = il2cpp_unsafe_as_ref<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C>(L_10);
		int32_t L_12 = ___1_start;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_13;
		L_13 = il2cpp_unsafe_add<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,int32_t>(L_11, L_12);
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m52435B19F7206FF9ACDF935B21B58EC14F9C1A01_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_2;
		L_2 = il2cpp_unsafe_as_ref<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C>((uint8_t*)L_1);
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mABCC2BDB018D99B11CE82B53D6EDE75D4455193F_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_0 = ___0_ptr;
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* Span_1_get_Item_mF313949AE59C17459B3DE2377B1F60DB1B3FC582_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_2 = __this->____pointer;
		V_0 = L_2;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_5;
		L_5 = il2cpp_unsafe_add<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m067127B31C1843993F46EAEC7619679D1AF41B6A_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, const RuntimeMethod* method) 
{
	ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_0 = __this->____pointer;
		V_0 = L_0;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m3DD12317CD4A8F1B9E3130C5F072990B53888C79_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_4 = __this->____pointer;
		V_2 = L_4;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_12 = __this->____pointer;
		V_2 = L_12;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_19 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_18 = L_19;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_24 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_23 = L_24;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_29 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_28 = L_29;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_34 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_33 = L_34;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_39 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_38 = L_39;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_44 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_43 = L_44;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_49 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_48 = L_49;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_54 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_64 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_63 = L_64;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_69 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_68 = L_69;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_74 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_73 = L_74;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_79 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C L_85 = ___0_value;
		*(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_mE256DB1817DCD1C184771B4C2D6C4CD823262B0F_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m4AFBDAB740A9ECD13948F54329A3D84FD198CB73_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 L_2 = ___0_destination;
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_3 = L_2.____pointer;
		V_0 = L_3;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_0));
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_5 = __this->____pointer;
		V_0 = L_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisGfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C_m2CA00C03921B3C30B95A8129FDEA92912124ED5E(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m93EAB9F31B6E3CB33155F09836C4701B9F5D778F_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m4AFBDAB740A9ECD13948F54329A3D84FD198CB73_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 L_2 = ___0_destination;
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_3 = L_2.____pointer;
		V_1 = L_3;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_1));
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_5 = __this->____pointer;
		V_1 = L_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisGfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C_m2CA00C03921B3C30B95A8129FDEA92912124ED5E(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_tBE8F7CF96CF1493E2EA4ED19616DF91D5FF56E7C Span_1_op_Implicit_m2A2F3018EAA6BD8AA0CE21F352F8B9EB4413DB74_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 L_0 = ___0_span;
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_1 = L_0.____pointer;
		V_0 = L_1;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_0));
		Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_tBE8F7CF96CF1493E2EA4ED19616DF91D5FF56E7C L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_m8560DF2D26A1CC196BDE7BB7DFC896FB3D65EA16_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_mDFF9ACEC9E1CDDDE4EBD4774C4DE9ADD0CD07873_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_5 = __this->____pointer;
		V_1 = L_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 Span_1_Slice_mD7BBF3C840B3443C3E819F2A5A812136610371A0_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_2 = __this->____pointer;
		V_0 = L_2;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_5;
		L_5 = il2cpp_unsafe_add<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_mABCC2BDB018D99B11CE82B53D6EDE75D4455193F_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 Span_1_Slice_m6D8E13B2EEEB8638FC07B582EC183E26A438DD43_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_5 = __this->____pointer;
		V_0 = L_5;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_8;
		L_8 = il2cpp_unsafe_add<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_mABCC2BDB018D99B11CE82B53D6EDE75D4455193F_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* Span_1_ToArray_m6A163D57DA041C95CD27FB3518A5753ECFF9CB6B_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, const RuntimeMethod* method) 
{
	ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_1;
		L_1 = Array_Empty_TisGfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C_mC6C376B567AC6FA4773E73349EE73E984E47852B_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_3 = (GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30*)(GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_6;
		L_6 = il2cpp_unsafe_as_ref<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C>(L_5);
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_7 = __this->____pointer;
		V_0 = L_7;
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisGfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C_m2CA00C03921B3C30B95A8129FDEA92912124ED5E(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m4AFBDAB740A9ECD13948F54329A3D84FD198CB73_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m23F0171CFED0530FBFDD3400216E71CEC64157C6_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_m22FBF5AA1590F902B9D41BBA1FFA6EA66F71C49F_gshared (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 Span_1_op_Implicit_mCEB395506E09ADA9DD31C610F5E204B327BEB785_gshared (GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* ___0_array, const RuntimeMethod* method) 
{
	{
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_0 = ___0_array;
		Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68 L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_mEAFD68654E9CB51239357C3D94CDB5056137D70B_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m176441CFA181B7C6097611CC13C24C5ED7F14CFF_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(int32_t));
		goto IL_0037;
	}

IL_0037:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		int32_t* L_4;
		L_4 = il2cpp_unsafe_as_ref<int32_t>(L_3);
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_mE5D19FF7B2CED496CE41333FF842F490D1F14C03_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(int32_t));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		int32_t* L_11;
		L_11 = il2cpp_unsafe_as_ref<int32_t>(L_10);
		int32_t L_12 = ___1_start;
		int32_t* L_13;
		L_13 = il2cpp_unsafe_add<int32_t,int32_t>(L_11, L_12);
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m31EE4A5510B5C504DB26DB281BC7D4179B859F2B_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		int32_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<int32_t>((uint8_t*)L_1);
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m89B8042F831A4ACF35D15B29B8141AE29CFFDF84_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, int32_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		int32_t* L_0 = ___0_ptr;
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* Span_1_get_Item_m9272911ACF4FC0A82F6053A0DE22CEBC8C10D4E0_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_2 = __this->____pointer;
		V_0 = L_2;
		int32_t* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		int32_t* L_5;
		L_5 = il2cpp_unsafe_add<int32_t,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m36EEDEB219123208E625AC1446BC03AB5A21A001_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, const RuntimeMethod* method) 
{
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_0 = __this->____pointer;
		V_0 = L_0;
		int32_t* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<int32_t>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_m0911D9EBB79D74E3F1442C095DEDB346CBE87340_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	int32_t V_1 = 0;
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	int32_t* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<int32_t>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		int32_t L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_4 = __this->____pointer;
		V_2 = L_4;
		int32_t* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_12 = __this->____pointer;
		V_2 = L_12;
		int32_t* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<int32_t>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		int32_t* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		int32_t* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		int32_t L_19 = ___0_value;
		*(int32_t*)L_18 = L_19;
		int32_t* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		int32_t* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		int32_t L_24 = ___0_value;
		*(int32_t*)L_23 = L_24;
		int32_t* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		int32_t* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		int32_t L_29 = ___0_value;
		*(int32_t*)L_28 = L_29;
		int32_t* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		int32_t* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		int32_t L_34 = ___0_value;
		*(int32_t*)L_33 = L_34;
		int32_t* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		int32_t* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		int32_t L_39 = ___0_value;
		*(int32_t*)L_38 = L_39;
		int32_t* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		int32_t* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		int32_t L_44 = ___0_value;
		*(int32_t*)L_43 = L_44;
		int32_t* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		int32_t* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		int32_t L_49 = ___0_value;
		*(int32_t*)L_48 = L_49;
		int32_t* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		int32_t* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		int32_t L_54 = ___0_value;
		*(int32_t*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		int32_t* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		int32_t* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		int32_t L_64 = ___0_value;
		*(int32_t*)L_63 = L_64;
		int32_t* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		int32_t* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		int32_t L_69 = ___0_value;
		*(int32_t*)L_68 = L_69;
		int32_t* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		int32_t* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		int32_t L_74 = ___0_value;
		*(int32_t*)L_73 = L_74;
		int32_t* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		int32_t* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		int32_t L_79 = ___0_value;
		*(int32_t*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		int32_t* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		int32_t* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<int32_t,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		int32_t L_85 = ___0_value;
		*(int32_t*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m197E47790117E2C925FE1A8E051A19AB9CF4260B_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m87AB3C694F2E4802F14D006F21C020816045285F_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_2 = ___0_destination;
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_3 = L_2.____pointer;
		V_0 = L_3;
		int32_t* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_0));
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_5 = __this->____pointer;
		V_0 = L_5;
		int32_t* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m1CD5B4A82FDDB0C96C8ABC21339D0339688CEEAB(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m33CBE4497D24B50852F8C5C0924DFF38724969BD_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m87AB3C694F2E4802F14D006F21C020816045285F_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_2 = ___0_destination;
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_3 = L_2.____pointer;
		V_1 = L_3;
		int32_t* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_1));
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_5 = __this->____pointer;
		V_1 = L_5;
		int32_t* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m1CD5B4A82FDDB0C96C8ABC21339D0339688CEEAB(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t6190994DF094ABDFA6908C2C3FB347457E8E4282 Span_1_op_Implicit_m2740023916201D5EB04C52CEB9FB3E175E79FE7A_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_0 = ___0_span;
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_1 = L_0.____pointer;
		V_0 = L_1;
		int32_t* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_0));
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t6190994DF094ABDFA6908C2C3FB347457E8E4282 L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_mA0D85386F3D3AAF59FC429C4A2A9E7CD6B7DCF2A_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_m71CB64722D92C563993B18D00317C1A3929D259B_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_5 = __this->____pointer;
		V_1 = L_5;
		int32_t* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 Span_1_Slice_mEE3E0DF3B0F4D4D2A6CE3587C2919CD859EF4973_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_2 = __this->____pointer;
		V_0 = L_2;
		int32_t* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		int32_t* L_5;
		L_5 = il2cpp_unsafe_add<int32_t,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m89B8042F831A4ACF35D15B29B8141AE29CFFDF84_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 Span_1_Slice_m7586DA899BDF88591C3546C39E571CE889D6C098_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_5 = __this->____pointer;
		V_0 = L_5;
		int32_t* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		int32_t* L_8;
		L_8 = il2cpp_unsafe_add<int32_t,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m89B8042F831A4ACF35D15B29B8141AE29CFFDF84_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* Span_1_ToArray_m45051661AD085CCC9DDBA0E5926090B360668450_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, const RuntimeMethod* method) 
{
	ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1;
		L_1 = Array_Empty_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m4D53E0E0F90F37AD5DBFD2DC75E52406F90C7ABC_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		int32_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<int32_t>(L_5);
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_7 = __this->____pointer;
		V_0 = L_7;
		int32_t* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(int32_t, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m1CD5B4A82FDDB0C96C8ABC21339D0339688CEEAB(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m87AB3C694F2E4802F14D006F21C020816045285F_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m1756B3F9D59F21477044E6EE24B20B51BB216F31_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_mBB9141DEAC1EA44851C84E0A12B1A3136460B0D4_gshared (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 Span_1_op_Implicit_m75103E0CA16D9EEB5414F2FA9611149122CF23CC_gshared (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, const RuntimeMethod* method) 
{
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_array;
		Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316 L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_m176441CFA181B7C6097611CC13C24C5ED7F14CFF_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m639F3CC8B14984E278FC347886BA5C0D86C7A4B9_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, const RuntimeMethod* method) 
{
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		goto IL_0037;
	}

IL_0037:
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_4;
		L_4 = il2cpp_unsafe_as_ref<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08>(L_3);
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m9B69139F2AA96589DD533B9347BEF2E2B79927CA_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) 
{
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___1_start;
		if (L_1)
		{
			goto IL_0009;
		}
	}
	{
		int32_t L_2 = ___2_length;
		if (!L_2)
		{
			goto IL_000e;
		}
	}

IL_0009:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211));
		return;
	}

IL_0016:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		goto IL_0042;
	}

IL_0042:
	{
		int32_t L_4 = ___1_start;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_5 = ___0_array;
		NullCheck(L_5);
		if ((!(((uint32_t)L_4) <= ((uint32_t)((int32_t)(((RuntimeArray*)L_5)->max_length))))))
		{
			goto IL_0050;
		}
	}
	{
		int32_t L_6 = ___2_length;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_7 = ___0_array;
		NullCheck(L_7);
		int32_t L_8 = ___1_start;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(((int32_t)(((RuntimeArray*)L_7)->max_length)), L_8))))))
		{
			goto IL_0055;
		}
	}

IL_0050:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0055:
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_9 = ___0_array;
		NullCheck((RuntimeArray*)L_9);
		uint8_t* L_10;
		L_10 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_9, NULL);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_11;
		L_11 = il2cpp_unsafe_as_ref<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08>(L_10);
		int32_t L_12 = ___1_start;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_13;
		L_13 = il2cpp_unsafe_add<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,int32_t>(L_11, L_12);
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_14;
		memset((&L_14), 0, sizeof(L_14));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_14), L_13);
		__this->____pointer = L_14;
		int32_t L_15 = ___2_length;
		__this->____length = L_15;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m2763F49482AE3C8E6D3E8A8F30C188BA458479EF_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, void* ___0_pointer, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		goto IL_0016;
	}

IL_0016:
	{
		int32_t L_0 = ___1_length;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_001f;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_001f:
	{
		void* L_1 = ___0_pointer;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_2;
		L_2 = il2cpp_unsafe_as_ref<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08>((uint8_t*)L_1);
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_3;
		memset((&L_3), 0, sizeof(L_3));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_3), L_2);
		__this->____pointer = L_3;
		int32_t L_4 = ___1_length;
		__this->____length = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1__ctor_m495B7963DA5CE2A2F3D69EAEBDD7BF73A1B34A31_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_0 = ___0_ptr;
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* Span_1_get_Item_m2DBE972264EB94BB8678D76C73C5A5163BC55CDA_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowIndexOutOfRangeException_m86F753A24E2765A35546BA6352A7E4F0BB8A66B5(NULL);
	}

IL_000e:
	{
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_2 = __this->____pointer;
		V_0 = L_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_index;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_5;
		L_5 = il2cpp_unsafe_add<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,int32_t>(L_3, L_4);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Clear_m57866DA65846B03A091F29CA32A03E38784A99DD_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, const RuntimeMethod* method) 
{
	ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		goto IL_0034;
	}

IL_0034:
	{
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_0 = __this->____pointer;
		V_0 = L_0;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_1;
		L_1 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_0));
		uint8_t* L_2;
		L_2 = il2cpp_unsafe_as_ref<uint8_t>(L_1);
		int32_t L_3 = __this->____length;
		int32_t L_4;
		L_4 = il2cpp_unsafe_sizeof<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08>();
		SpanHelpers_ClearWithoutReferences_m65DB2925AE7A5FF88BB3EA1BF90513C9ADF0653D(L_2, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)L_3), ((int64_t)L_4))), NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_Fill_mDE58570B73BCCE323E5AD7C9196685FD2EE9572B_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_value, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_1;
	memset((&V_1), 0, sizeof(V_1));
	ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 V_2;
	memset((&V_2), 0, sizeof(V_2));
	uint64_t V_3 = 0;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* V_4 = NULL;
	uint64_t V_5 = 0;
	uint64_t V_6 = 0;
	{
		int32_t L_0;
		L_0 = il2cpp_unsafe_sizeof<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08>();
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0037;
		}
	}
	{
		int32_t L_1 = __this->____length;
		V_0 = (uint32_t)L_1;
		uint32_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0013;
		}
	}
	{
		return;
	}

IL_0013:
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_3 = ___0_value;
		V_1 = L_3;
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_4 = __this->____pointer;
		V_2 = L_4;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_5;
		L_5 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_2));
		uint8_t* L_6;
		L_6 = il2cpp_unsafe_as_ref<uint8_t>(L_5);
		uint8_t* L_7;
		L_7 = il2cpp_unsafe_as_ref<uint8_t>((&V_1));
		int32_t L_8 = *((uint8_t*)L_7);
		uint32_t L_9 = V_0;
		Unsafe_InitBlockUnaligned_m6F2353EB9ABC9320E61629FAEE23948C80BFF03A(L_6, (uint8_t)L_8, L_9, NULL);
		return;
	}

IL_0037:
	{
		int32_t L_10 = __this->____length;
		V_3 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_10));
		uint64_t L_11 = V_3;
		if (L_11)
		{
			goto IL_0043;
		}
	}
	{
		return;
	}

IL_0043:
	{
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_12 = __this->____pointer;
		V_2 = L_12;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_13;
		L_13 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_2));
		V_4 = L_13;
		int32_t L_14;
		L_14 = il2cpp_unsafe_sizeof<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08>();
		V_5 = (uint64_t)((int64_t)(uint64_t)((uint32_t)L_14));
		V_6 = (uint64_t)((int64_t)0);
		goto IL_0110;
	}

IL_0064:
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_15 = V_4;
		uint64_t L_16 = V_6;
		uint64_t L_17 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_18;
		L_18 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_15, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_16, (int64_t)L_17)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_19 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_18 = L_19;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_20 = V_4;
		uint64_t L_21 = V_6;
		uint64_t L_22 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_23;
		L_23 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_20, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_21, ((int64_t)1))), (int64_t)L_22)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_24 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_23 = L_24;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_25 = V_4;
		uint64_t L_26 = V_6;
		uint64_t L_27 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_28;
		L_28 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_25, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_26, ((int64_t)2))), (int64_t)L_27)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_29 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_28 = L_29;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_30 = V_4;
		uint64_t L_31 = V_6;
		uint64_t L_32 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_33;
		L_33 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_30, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_31, ((int64_t)3))), (int64_t)L_32)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_34 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_33 = L_34;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_35 = V_4;
		uint64_t L_36 = V_6;
		uint64_t L_37 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_38;
		L_38 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_35, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_36, ((int64_t)4))), (int64_t)L_37)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_39 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_38 = L_39;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_40 = V_4;
		uint64_t L_41 = V_6;
		uint64_t L_42 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_43;
		L_43 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_40, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_41, ((int64_t)5))), (int64_t)L_42)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_44 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_43 = L_44;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_45 = V_4;
		uint64_t L_46 = V_6;
		uint64_t L_47 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_48;
		L_48 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_45, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_46, ((int64_t)6))), (int64_t)L_47)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_49 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_48 = L_49;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_50 = V_4;
		uint64_t L_51 = V_6;
		uint64_t L_52 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_53;
		L_53 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_50, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_51, ((int64_t)7))), (int64_t)L_52)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_54 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_53 = L_54;
		uint64_t L_55 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_55, ((int64_t)8)));
	}

IL_0110:
	{
		uint64_t L_56 = V_6;
		uint64_t L_57 = V_3;
		if ((!(((uint64_t)L_56) >= ((uint64_t)((int64_t)((int64_t)L_57&((int64_t)((int32_t)-8))))))))
		{
			goto IL_0064;
		}
	}
	{
		uint64_t L_58 = V_6;
		uint64_t L_59 = V_3;
		if ((!(((uint64_t)L_58) < ((uint64_t)((int64_t)((int64_t)L_59&((int64_t)((int32_t)-4))))))))
		{
			goto IL_0198;
		}
	}
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_60 = V_4;
		uint64_t L_61 = V_6;
		uint64_t L_62 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_63;
		L_63 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_60, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_61, (int64_t)L_62)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_64 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_63 = L_64;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_65 = V_4;
		uint64_t L_66 = V_6;
		uint64_t L_67 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_68;
		L_68 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_65, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_66, ((int64_t)1))), (int64_t)L_67)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_69 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_68 = L_69;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_70 = V_4;
		uint64_t L_71 = V_6;
		uint64_t L_72 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_73;
		L_73 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_70, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_71, ((int64_t)2))), (int64_t)L_72)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_74 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_73 = L_74;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_75 = V_4;
		uint64_t L_76 = V_6;
		uint64_t L_77 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_78;
		L_78 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_75, (uint64_t)((int64_t)il2cpp_codegen_multiply(((int64_t)il2cpp_codegen_add((int64_t)L_76, ((int64_t)3))), (int64_t)L_77)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_79 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_78 = L_79;
		uint64_t L_80 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_80, ((int64_t)4)));
		goto IL_0198;
	}

IL_017f:
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_81 = V_4;
		uint64_t L_82 = V_6;
		uint64_t L_83 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_84;
		L_84 = il2cpp_unsafe_add_byte_offset<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,uint64_t>(L_81, (uint64_t)((int64_t)il2cpp_codegen_multiply((int64_t)L_82, (int64_t)L_83)));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_85 = ___0_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_84 = L_85;
		uint64_t L_86 = V_6;
		V_6 = (uint64_t)((int64_t)il2cpp_codegen_add((int64_t)L_86, ((int64_t)1)));
	}

IL_0198:
	{
		uint64_t L_87 = V_6;
		uint64_t L_88 = V_3;
		if ((!(((uint64_t)L_87) >= ((uint64_t)L_88))))
		{
			goto IL_017f;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Span_1_CopyTo_m19596686257476852589E2B2DCEC6AA451DFE0C6_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 ___0_destination, const RuntimeMethod* method) 
{
	ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m0BE6EA932B404A54A3AF19C9654ED2611196FAE5_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0038;
		}
	}
	{
		Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 L_2 = ___0_destination;
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_3 = L_2.____pointer;
		V_0 = L_3;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_0));
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_5 = __this->____pointer;
		V_0 = L_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_0));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m4DF13B5C2D27E38BFD7112649345659B81B99988(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return;
	}

IL_0038:
	{
		ThrowHelper_ThrowArgumentException_DestinationTooShort_m6468934A3BBB67DBC5BAEF7A64D91BD5BBBB3D4D(NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_TryCopyTo_m7E9A424718E91F91E565E7ECBDF59027E71270E5_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 ___0_destination, const RuntimeMethod* method) 
{
	bool V_0 = false;
	ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = (bool)0;
		int32_t L_0 = __this->____length;
		int32_t L_1;
		L_1 = Span_1_get_Length_m0BE6EA932B404A54A3AF19C9654ED2611196FAE5_inline((&___0_destination), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 13));
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_003b;
		}
	}
	{
		Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 L_2 = ___0_destination;
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_3 = L_2.____pointer;
		V_1 = L_3;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_4;
		L_4 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_1));
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_5 = __this->____pointer;
		V_1 = L_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_1));
		int32_t L_7 = __this->____length;
		Buffer_Memmove_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m4DF13B5C2D27E38BFD7112649345659B81B99988(L_4, L_6, (uint64_t)((int64_t)L_7), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		V_0 = (bool)1;
	}

IL_003b:
	{
		bool L_8 = V_0;
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlySpan_1_t09FC5325A7B15784D246B5B71F829AB1C98B41DB Span_1_op_Implicit_mDE9258F71F661B25988E11D8971B042982F305F8_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 ___0_span, const RuntimeMethod* method) 
{
	ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 L_0 = ___0_span;
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_1 = L_0.____pointer;
		V_0 = L_1;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_2;
		L_2 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_0));
		Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 L_3 = ___0_span;
		int32_t L_4 = L_3.____length;
		ReadOnlySpan_1_t09FC5325A7B15784D246B5B71F829AB1C98B41DB L_5;
		memset((&L_5), 0, sizeof(L_5));
		ReadOnlySpan_1__ctor_m5146D98DC32810D3BC61D690968758CF2711417A_inline((&L_5), L_2, L_4, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 17));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Span_1_ToString_mB669A15536A62320F2162D422ACE9AF8B760C008_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Type_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DB46164953228904843938099AF66650313FEE5);
		s_Il2CppMethodInitialized = true;
	}
	Il2CppChar* V_0 = NULL;
	ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (Char_t521A6F19B456D956AF452D926C32709DC03D6B17_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_003e;
		}
	}
	{
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_5 = __this->____pointer;
		V_1 = L_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_1));
		Il2CppChar* L_7;
		L_7 = il2cpp_unsafe_as_ref<Il2CppChar>(L_6);
		V_0 = L_7;
		Il2CppChar* L_8 = V_0;
		int32_t L_9 = __this->____length;
		String_t* L_10;
		L_10 = String_CreateString_m3F8794FEB452558B8A68C65E1F0B603B3D94E0E2(NULL, (Il2CppChar*)((uintptr_t)L_8), 0, L_9, NULL);
		return L_10;
	}

IL_003e:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(InitializedTypeInfo(method->klass)->rgctx_data, 9)) };
		il2cpp_codegen_runtime_class_init_inline(Type_t_il2cpp_TypeInfo_var);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		NullCheck((MemberInfo_t*)L_12);
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(7, (MemberInfo_t*)L_12);
		int32_t L_14 = __this->____length;
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_15);
		String_t* L_17;
		L_17 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0DB46164953228904843938099AF66650313FEE5, (RuntimeObject*)L_13, L_16, NULL);
		return L_17;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 Span_1_Slice_mC59838AA19F35B1A65FCD3FB141788ACCBA3D0FE_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, int32_t ___0_start, const RuntimeMethod* method) 
{
	ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_000e:
	{
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_2 = __this->____pointer;
		V_0 = L_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_3;
		L_3 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_0));
		int32_t L_4 = ___0_start;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_5;
		L_5 = il2cpp_unsafe_add<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,int32_t>(L_3, L_4);
		int32_t L_6 = __this->____length;
		int32_t L_7 = ___0_start;
		Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 L_8;
		memset((&L_8), 0, sizeof(L_8));
		Span_1__ctor_m495B7963DA5CE2A2F3D69EAEBDD7BF73A1B34A31_inline((&L_8), L_5, ((int32_t)il2cpp_codegen_subtract(L_6, L_7)), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 Span_1_Slice_m09896097F411041376DFF01E5B219E667D8B5E6B_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) 
{
	ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_start;
		int32_t L_1 = __this->____length;
		if ((!(((uint32_t)L_0) <= ((uint32_t)L_1))))
		{
			goto IL_0014;
		}
	}
	{
		int32_t L_2 = ___1_length;
		int32_t L_3 = __this->____length;
		int32_t L_4 = ___0_start;
		if ((!(((uint32_t)L_2) > ((uint32_t)((int32_t)il2cpp_codegen_subtract(L_3, L_4))))))
		{
			goto IL_0019;
		}
	}

IL_0014:
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_mD7D90276EDCDF9394A8EA635923E3B48BB71BD56(NULL);
	}

IL_0019:
	{
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_5 = __this->____pointer;
		V_0 = L_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_6;
		L_6 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_0));
		int32_t L_7 = ___0_start;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_8;
		L_8 = il2cpp_unsafe_add<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08,int32_t>(L_6, L_7);
		int32_t L_9 = ___1_length;
		Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 L_10;
		memset((&L_10), 0, sizeof(L_10));
		Span_1__ctor_m495B7963DA5CE2A2F3D69EAEBDD7BF73A1B34A31_inline((&L_10), L_8, L_9, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 18));
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* Span_1_ToArray_mF4721672D36FD9E8507DAFE70234016604B649D4_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, const RuntimeMethod* method) 
{
	ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = __this->____length;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_1;
		L_1 = Array_Empty_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m65AF0C73C7E00505BCE35B9CC15EE8C8F6F0A01E_inline(il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 19));
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____length;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_3 = (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*)(JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*)SZArrayNew(il2cpp_rgctx_data(InitializedTypeInfo(method->klass)->rgctx_data, 20), (uint32_t)L_2);
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_4 = L_3;
		NullCheck((RuntimeArray*)L_4);
		uint8_t* L_5;
		L_5 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_4, NULL);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_6;
		L_6 = il2cpp_unsafe_as_ref<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08>(L_5);
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_7 = __this->____pointer;
		V_0 = L_7;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_8;
		L_8 = IL2CPP_BY_REFERENCE_GET_VALUE(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, (Il2CppByReference*)(&V_0));
		int32_t L_9 = __this->____length;
		Buffer_Memmove_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m4DF13B5C2D27E38BFD7112649345659B81B99988(L_6, L_8, (uint64_t)((int64_t)L_9), il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 15));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m0BE6EA932B404A54A3AF19C9654ED2611196FAE5_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Span_1_Equals_m4C53EB5B2A406FC3E2DE28D1280852BEC74F579E_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral69508A540AFD085A745316DD7D6345B1C8CC662D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Span_1_GetHashCode_mAC8BFDF0E30684ECCD4735F1017009B2D7EC1363_gshared (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralECE618215BAC99C6FD12D8A273CC2118945EDCC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 Span_1_op_Implicit_m17A008F01B642720D89B2987F2D3C18863EE3286_gshared (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, const RuntimeMethod* method) 
{
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_0 = ___0_array;
		Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211 L_1;
		memset((&L_1), 0, sizeof(L_1));
		Span_1__ctor_m639F3CC8B14984E278FC347886BA5C0D86C7A4B9_inline((&L_1), L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 21));
		return L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool BaseShaderInfoStorage_get_disposed_mAF7F54A791E6AF75BF1AD71B1DDA85099BFCE1EF_inline (BaseShaderInfoStorage_tA4E5F167749C2492F7933E0B660BF9CF8F6716A2* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = __this->___U3CdisposedU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RectInt_get_x_mA1E7EF6DEAD2E900D7D56B7A3957C05081EBA9CA_inline (RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->___m_XMin;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		int32_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t RectInt_get_y_m440422264E6FCAA91E01F81486A78037AC29D878_inline (RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->___m_YMin;
		V_0 = L_0;
		goto IL_000a;
	}

IL_000a:
	{
		int32_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RectInt__ctor_m6E8B3A6C7EE11257A6B438E36274116FE39B5B42_inline (RectInt_t1744D10E1063135DA9D574F95205B98DAC600CB8* __this, int32_t ___0_xMin, int32_t ___1_yMin, int32_t ___2_width, int32_t ___3_height, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_xMin;
		__this->___m_XMin = L_0;
		int32_t L_1 = ___1_yMin;
		__this->___m_YMin = L_1;
		int32_t L_2 = ___2_width;
		__this->___m_Width = L_2;
		int32_t L_3 = ___3_height;
		__this->___m_Height = L_3;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ProfilerMarker_Begin_mD07DB736ADA7D8BAF9D969CC7F3C55848A218C6E_inline (ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD* __this, const RuntimeMethod* method) 
{
	{
		intptr_t L_0 = __this->___m_Ptr;
		ProfilerUnsafeUtility_BeginSample_mB5106F4E7ECEF54906545665ED23928D14F5FCA7(L_0, NULL);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ProfilerMarker_End_m025AE3EF0F96F6DADC53489A53FC6EE65073DE60_inline (ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD* __this, const RuntimeMethod* method) 
{
	{
		intptr_t L_0 = __this->___m_Ptr;
		ProfilerUnsafeUtility_EndSample_mFDB4EFB160A9CB817D2F8ED21B88693616B27409(L_0, NULL);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UIRAtlasAllocator_get_physicalWidth_m0B06147154436A555CEABB9C9EB319D7D33A5398_inline (UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CphysicalWidthU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UIRAtlasAllocator_get_physicalHeight_m736C92B2C509CE66BAFFBA87110103BBC72DBD88_inline (UIRAtlasAllocator_t70FA0F3477E077A18096F66B51F6A2B205825BD7* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CphysicalHeightU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t* Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline (RuntimeArray* __this, const RuntimeMethod* method) 
{
	{
		RawData_t37CAF2D3F74B7723974ED7CEEE9B297D8FA64ED0* L_0;
		L_0 = il2cpp_unsafe_as<RawData_t37CAF2D3F74B7723974ED7CEEE9B297D8FA64ED0*>(__this);
		NullCheck(L_0);
		uint8_t* L_1 = (uint8_t*)(&L_0->___Data);
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SharedStatic_1__ctor_mF83D06637E10F1C230BA4F1A841E742F6A5ED399_gshared_inline (SharedStatic_1_t33583FDAFE4C36D5BA68FE6F5444170BB42F98C0* __this, void* ___0_buffer, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_buffer;
		__this->____buffer = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR intptr_t* UnsafeUtility_AsRef_TisIntPtr_t_m5E80CE586FADFB0EE0E808A1A736F9BF28C2B28B_gshared_inline (void* ___0_ptr, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_ptr;
		return (intptr_t*)(L_0);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SharedStatic_1__ctor_m467F9A64986F442AA4853C5C314D0A54D887CDDC_gshared_inline (SharedStatic_1_t965CBE4F8A30F785649BF3D97C277D0927858D08* __this, void* ___0_buffer, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_buffer;
		__this->____buffer = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m739A39BB426B19B7583557F308B2BDA52E2C3DD9_gshared_inline (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m729E93C65964D6955F3A0794056B0A8FA3E1FB44_gshared_inline (ReadOnlySpan_1_tE73282FE39C46EDD2EE2F61A9E3E69BE943784B7* __this, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_0 = ___0_ptr;
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mB2713B2424259A6D18038A2E29BD96DA081378D6_gshared_inline (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_0 = ___0_ptr;
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* Array_Empty_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m652D1F78F0DEF31A60A1D09589A89DE06F12C3E4_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_0 = ((EmptyArray_1_tA6E339CF983886C190886835190061C2E3B679F2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m7126F92024E73EE43580A7A9D64C39CD973406CC_gshared_inline (Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428* __this, BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* ___0_array, const RuntimeMethod* method) 
{
	BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t36B7E942A80FDA89A0043D5EDED0559212667428));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D));
		goto IL_0037;
	}

IL_0037:
	{
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D* L_4;
		L_4 = il2cpp_unsafe_as_ref<BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D>(L_3);
		ByReference_1_t6B219462DA620514530122E206E21B814BB5AE56 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BatchCullingOutputDrawCommandsU5BU5D_t74BE7663EB19A8F858498AE303D905FBCCF54F80* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mF5DDBBF4783D0A55C88BFD79E1A1F8B5DDCF60C5_gshared_inline (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m1C72072A1F9FFD48A21C4C5F2A81954708D29495_gshared_inline (ReadOnlySpan_1_t3D251E6627DBB106D7D34F8DC234D102B691FD49* __this, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_0 = ___0_ptr;
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m4F32D7D5653D612D237DDFD35C9850E16CA11C18_gshared_inline (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_0 = ___0_ptr;
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* Array_Empty_TisBlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF_mCD144DB8231D7EA3AF1DB4FEB94681C9E580CA9D_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_0 = ((EmptyArray_1_tD61E793B4EDBEE4AA2790494DEAA1AFF267A1F35_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mCA3E1FB18A1006842617ABD22464535398F4655D_gshared_inline (Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671* __this, BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* ___0_array, const RuntimeMethod* method) 
{
	BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t7C5A19CE460E0E7CEF37F40BFC0A2EF653B13671));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF));
		goto IL_0037;
	}

IL_0037:
	{
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF* L_4;
		L_4 = il2cpp_unsafe_as_ref<BlittableCollider_tAC3A9ECD36B3C3C09DF00CB9E459790F774887CF>(L_3);
		ByReference_1_t0D4A129F50D2A249B4A6A7FA4B4A023FDCD5801F L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BlittableColliderU5BU5D_t3708611FCB7A23589D4E4BCFB767C7116D14CC6B* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m0A22C7814AA57E51DE4EDC241010E81DA05627F9_gshared_inline (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m143F99ABFB2902F2BE3AB6725D5F8AEAECDEC5F4_gshared_inline (ReadOnlySpan_1_tD81D75B0E0400301DC302920BCCBB9FBD97CA2A8* __this, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_0 = ___0_ptr;
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m6C9685057F182B8896BBE6B894974625E6DA4221_gshared_inline (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_0 = ___0_ptr;
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* Array_Empty_TisBlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6_m7D78EA1928C7379C27FE7337353FB51BEFD7476E_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_0 = ((EmptyArray_1_t080248E0CE94C9EDF86D6BBE84F395794E5E43C3_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mF80BBD6B1E4103830CA7E538A9EE8ABA983D97EC_gshared_inline (Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C* __this, BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* ___0_array, const RuntimeMethod* method) 
{
	BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tC0FB6C8C1E516492E0FD9D0020AC47EFED4E3B1C));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6));
		goto IL_0037;
	}

IL_0037:
	{
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6* L_4;
		L_4 = il2cpp_unsafe_as_ref<BlittableJointImmutable_tD735AA7841E92D5AC537D3C3D1CB2CB544094EB6>(L_3);
		ByReference_1_t67265AE71FAD8A73FA3DD219D07BDC558B2C20B7 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BlittableJointImmutableU5BU5D_t8BAA773AB20A42CC92A9CE0F12BBF7C12DB24515* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m3C5D2034819739D3DDB78A3D890CEE1C94529B01_gshared_inline (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mD794B63B35B4B58E5337728A24E1998CFDD74810_gshared_inline (ReadOnlySpan_1_t70882B83461088DC23C3DB9AF59753CF91E1F3AA* __this, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_0 = ___0_ptr;
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m773D9E2695DC1A1EAF17FDC94204CB7B1DE21582_gshared_inline (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_0 = ___0_ptr;
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* Array_Empty_TisBlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C_m48CDEF41C2F032666E4312F197041C0757708AE3_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_0 = ((EmptyArray_1_tA290AEF3927090408C0E0B2EC14CB3DB2C5163A6_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mB392265B6A34EA59542E156547D1143AC4B0EBD4_gshared_inline (Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B* __this, BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* ___0_array, const RuntimeMethod* method) 
{
	BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t3AAB8E3BD6C3080DEC6B11819836A7F2E4CF575B));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C));
		goto IL_0037;
	}

IL_0037:
	{
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C* L_4;
		L_4 = il2cpp_unsafe_as_ref<BlittableJointMutable_t9FC7CE827D9553E7ED07375E079CCB1C9384E42C>(L_3);
		ByReference_1_t05F40BEA5BF1226828D26FE67C525849A48D27DF L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BlittableJointMutableU5BU5D_t82AA653AC7F7D3384D3500EE6EAC91CCED86B57A* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m088CD07D38433F7795ED549A2139E5D41EA16706_gshared_inline (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m1A260D918B5EB96D17E965BA7BA73DA0C3493361_gshared_inline (ReadOnlySpan_1_t2EFE9320FC985EB4C740E0FD04D094F25024C51D* __this, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_0 = ___0_ptr;
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mEA9008985414217BB660044157B6458716A8AB1D_gshared_inline (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_0 = ___0_ptr;
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* Array_Empty_TisBlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54_mDE388119C5F2CA6DED1F8895551BEDC81C379FF9_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_0 = ((EmptyArray_1_t353CE6E273731A6220E1AD1A702E6AF00E235055_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mD521304CD3352077C22527BDFF5A3A6F5BBA2345_gshared_inline (Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF* __this, BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* ___0_array, const RuntimeMethod* method) 
{
	BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tD7465B7D52CA8A22E738742BC2A7F541938D94BF));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54));
		goto IL_0037;
	}

IL_0037:
	{
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54* L_4;
		L_4 = il2cpp_unsafe_as_ref<BlittableModelLevel_tA45F5F4A1ADAE0096ED4024725478A0960A2EB54>(L_3);
		ByReference_1_t0FBB72B56E4E4D978AA3A8F0918F1F557401D833 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BlittableModelLevelU5BU5D_t9C38F6C16D611A297E63A24AA21097A661A5F2C8* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mE19749B8DE0A55279184BDD9C3F394605245F91A_gshared_inline (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mE88D51223E12D11DE487A5E2C7AF2013C6413887_gshared_inline (ReadOnlySpan_1_t5EE3C4B6EA25BB8F3F956DFD28820F5666342758* __this, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_0 = ___0_ptr;
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m18D55B2B52C0EE4D379FCBBC6EE16E72CE2928E1_gshared_inline (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_0 = ___0_ptr;
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* Array_Empty_TisBlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901_m75A4A4FD904386887E2E78BA168595529AF13939_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_0 = ((EmptyArray_1_tF2E6E6E2B72D0BF7ECB89ECF4FD5717E4EDE97BF_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mBC0A2A6F732CAD76B8E0B559AAF16DDDC7DA95FB_gshared_inline (Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C* __this, BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* ___0_array, const RuntimeMethod* method) 
{
	BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t38ECE5022A30EC648B9E50357894011F14BC634C));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901));
		goto IL_0037;
	}

IL_0037:
	{
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901* L_4;
		L_4 = il2cpp_unsafe_as_ref<BlittableSpring_t649D9EB5E13BBB41790E0E576C46541596777901>(L_3);
		ByReference_1_tCED3D6988C1C98E3F3870586F43060298B8A60E8 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BlittableSpringU5BU5D_t056F49A354355447C3DDABF11B429183CFEBD22F* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m27BEF44B2CCD3948DC00D344142E534E36BA7524_gshared_inline (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m83EAE3C4FCB23391B66637D0580733B85E12B21A_gshared_inline (ReadOnlySpan_1_t9DCA2EC81EE91A02D7C140CF3376183B663C483A* __this, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_0 = ___0_ptr;
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m0635E38BE51343FEA108E4BAC304A66703B9E727_gshared_inline (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_0 = ___0_ptr;
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* Array_Empty_TisBlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472_m6A8620E16588CCAE8CBA423DCB92B7E1D919A942_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_0 = ((EmptyArray_1_tA656C73B1CB77366F398AB7451929D79699A6181_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mDAF271BFB6432EB8FCE7E7E95BB3A4918F1BCC92_gshared_inline (Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1* __this, BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* ___0_array, const RuntimeMethod* method) 
{
	BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t8379C8AC81E90862037D484486A34DF4CA4A49D1));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472));
		goto IL_0037;
	}

IL_0037:
	{
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472* L_4;
		L_4 = il2cpp_unsafe_as_ref<BlittableTransform_t57879CB8848C36D08222D38699C09295D32C6472>(L_3);
		ByReference_1_tBA1F106ABCF90AFEC223DE139D1A742F122C03A0 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		BlittableTransformU5BU5D_t2DF3579998B5E3ACEA63BBFA1ECD473E7D28E35A* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m8E944E4954E037877A25B9FF6B901F1F901D4769_gshared_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m0FC0B92549C2968E80B5F75A85F28B96DBFCFD63_gshared_inline (ReadOnlySpan_1_tA850A6C0E88ABBA37646A078ACBC24D6D5FD9B4D* __this, uint8_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		uint8_t* L_0 = ___0_ptr;
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m947BF95D54571BF3897F96822B7A8FDA5853497B_gshared_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, uint8_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		uint8_t* L_0 = ___0_ptr;
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* Array_Empty_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m6080CA526758F4FA182A066B2780D1761CD36ED5_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ((EmptyArray_1_t7187E746F328254739F076CFBCAABB28D4B4554C_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m513968BDBFF3CFCE89F3F77FE44CAB22CA474EF9_gshared_inline (Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_array, const RuntimeMethod* method) 
{
	uint8_t V_0 = 0x0;
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tDADAC65069DFE6B57C458109115ECD795ED39305));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(uint8_t));
		goto IL_0037;
	}

IL_0037:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		uint8_t* L_4;
		L_4 = il2cpp_unsafe_as_ref<uint8_t>(L_3);
		ByReference_1_t9C85BCCAAF8C525B6C06B07E922D8D217BE8D6FC L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m6C31F03BA2113C74E17C5CDEEEB6F3127EED655F_gshared_inline (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mB2EBAFF15789F2361DDAE7F848E175DB33845102_gshared_inline (ReadOnlySpan_1_t2AC1F24E0EEA27708EE5E3315C5E8A149DA4AC1B* __this, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_0 = ___0_ptr;
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m31A2EA269EF672A7C251B615BA32E9B3B264E225_gshared_inline (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_0 = ___0_ptr;
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* Array_Empty_TisByte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87_m05CA261BA6F06533AB2F5C75B5B0CB6F63DEC412_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_0 = ((EmptyArray_1_t47661D704C83AA21034108CB0B840DB306FC3905_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m9C0B3F87D446842B5C4638690ED90478A5B5073C_gshared_inline (Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E* __this, Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* ___0_array, const RuntimeMethod* method) 
{
	Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t35F4533D9645A41B01C5BEF1B278832AC34C3E0E));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87));
		goto IL_0037;
	}

IL_0037:
	{
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87* L_4;
		L_4 = il2cpp_unsafe_as_ref<Byte3_t895169CA1C79C4F3A79E7EA1AFD0F023C6D56A87>(L_3);
		ByReference_1_t8BE200CD464DAC2189A5ACB2C61A81E6CF071B19 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		Byte3U5BU5D_t86DDE2BD9D81B7656DF7C3BC23C7E0BD8E29A28A* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mF218AEBAC87C5B982A156B8286EF27B501363D4C_gshared_inline (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mF698E5C91A39EE4E9A4143E3EECCE2A9078FD390_gshared_inline (ReadOnlySpan_1_t45FE292A8BF877FADC6630D8A86BD5BFDDC70267* __this, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_0 = ___0_ptr;
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m29EE9A42F0B8B3317F565CF7FAAB5E0567DC495B_gshared_inline (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_0 = ___0_ptr;
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* Array_Empty_TisByte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B_m6D7C0121F09237151D13126E696B9A3344E0F93A_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_0 = ((EmptyArray_1_t6FD6A997ADBD66902EAF4E27C5C77F3F67BD253E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mB15C95C53B11DF662E871E2732D51D09DBDB299E_gshared_inline (Span_1_tCD30211080708598A3F07B04B84E8A37702B198C* __this, Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* ___0_array, const RuntimeMethod* method) 
{
	Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tCD30211080708598A3F07B04B84E8A37702B198C));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B));
		goto IL_0037;
	}

IL_0037:
	{
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B* L_4;
		L_4 = il2cpp_unsafe_as_ref<Byte4_tFA32F6B216D425FEEC1BAD0B827028028BDDB79B>(L_3);
		ByReference_1_t0FF4E8E9950C6A1CB0DBEEFDB5847C7BF376B267 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		Byte4U5BU5D_t9FD542FE05F8EDAAFEF3C5A0B19C58AC7E207348* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mB79622153F80AD55A805C005842AF045F4FCF992_gshared_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m0152E50B40750679B83FF9F30CA539FFBB98EEE8_gshared_inline (ReadOnlySpan_1_t59614EA6E51A945A32B02AB17FBCBDF9A5C419C1* __this, Il2CppChar* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Il2CppChar* L_0 = ___0_ptr;
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mC9BE2938B716B46BB6B9070B94DBE5CE814BC0E2_gshared_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, Il2CppChar* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Il2CppChar* L_0 = ___0_ptr;
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* Array_Empty_TisChar_t521A6F19B456D956AF452D926C32709DC03D6B17_mD1C1362CB74B91496D984B006ADC79B688D9B50D_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_0 = ((EmptyArray_1_t7BBC8CED754F364A777871A238BBBE3F94FFDDE1_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m23CBCD46AD762681A232C97FE90B3A9EDD4991E5_gshared_inline (Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_array, const RuntimeMethod* method) 
{
	Il2CppChar V_0 = 0x0;
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tEDDF15FCF9EC6DEBA0F696BAACDDBAB9D92C252D));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Il2CppChar));
		goto IL_0037;
	}

IL_0037:
	{
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		Il2CppChar* L_4;
		L_4 = il2cpp_unsafe_as_ref<Il2CppChar>(L_3);
		ByReference_1_t7BA5A6CA164F770BC688F21C5978D368716465F5 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m83147EFB62B7FFBA49EEBEBE975F7348D665BAD0_gshared_inline (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mD46BD07C5320D1B1A225E53FAF466E153FFC1679_gshared_inline (ReadOnlySpan_1_t7EE9E7096EE52CA433AA61A9353AD90B29B2C816* __this, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_0 = ___0_ptr;
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m48419159317F9826172EDEA69FDB0598B87B34D2_gshared_inline (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_0 = ___0_ptr;
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* Array_Empty_TisColor_tD001788D726C3A7F1379BEED0260B9591F440C1F_m7E922E24AAEBD664256383832D53DDF17E1F3052_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_0 = ((EmptyArray_1_t9FC4EAC7DDBFA164B697CFEBFF39A52B321CC8C9_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mD8CCC80CA9129EEAC13B40BA31C6C577BDF46ECD_gshared_inline (Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018* __this, ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* ___0_array, const RuntimeMethod* method) 
{
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t162CEB1BEB175B131BEFB9D4647CEB2D48558018));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Color_tD001788D726C3A7F1379BEED0260B9591F440C1F));
		goto IL_0037;
	}

IL_0037:
	{
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* L_4;
		L_4 = il2cpp_unsafe_as_ref<Color_tD001788D726C3A7F1379BEED0260B9591F440C1F>(L_3);
		ByReference_1_t9B1B5AE3B920C99C8F3511B46F258F98CCFD0836 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		ColorU5BU5D_t612261CF293F6FFC3D80AB52259FF0DC2B2CC389* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m413F20ECFE3F523163B62ED5BAB7DFA22F2FCCD4_gshared_inline (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m841651F5E0DEC77984A109EF01090F3F776571FB_gshared_inline (ReadOnlySpan_1_t2E193A80641154947640E9A71614019D7A8F3DFC* __this, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_0 = ___0_ptr;
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mD16E04B2ED38420390E0DE1D6E01DE23C583B434_gshared_inline (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_0 = ___0_ptr;
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* Array_Empty_TisColor32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B_m5B415C4745E47108DD9258EBCCB422EFD6B8A0EB_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_0 = ((EmptyArray_1_tC72AE83DCB4E240E4B2AC2595448148BB03F9498_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mDE7408B1AC4D3DDE1E8EB6C1A8AE8244CAB0BBB1_gshared_inline (Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D* __this, Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* ___0_array, const RuntimeMethod* method) 
{
	Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tCF27B3DC55C4AD13268A1F154352D6782B237F7D));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B));
		goto IL_0037;
	}

IL_0037:
	{
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B* L_4;
		L_4 = il2cpp_unsafe_as_ref<Color32_t73C5004937BF5BB8AD55323D51AAA40A898EF48B>(L_3);
		ByReference_1_t2F6DD447F09BA6643D703E03C0CB184F51C4BC97 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		Color32U5BU5D_t38116C3E91765C4C5726CE12C77FAD7F9F737259* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m3B50FB2CF29A0E7C0C8B69E4E5A72D75883EBC4B_gshared_inline (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mDB9E4DFF0687E0A5405FF4F6387379524B1B07AB_gshared_inline (ReadOnlySpan_1_t1CFFA3B34C09F05622921AC4014011D43A25715A* __this, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_0 = ___0_ptr;
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m1910D0E44CCD92AD908E1D5F61FFF27ADFE1EFAD_gshared_inline (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_0 = ___0_ptr;
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* Array_Empty_TisConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1_m164EDF2519D24430C10F8BB106ADB252BF225C26_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_0 = ((EmptyArray_1_tB029523A05EA2FFE1EB90490D66A384F7A0D4574_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mE396EB49F11B34D41818F29E84D8865E2003B251_gshared_inline (Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48* __this, ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* ___0_array, const RuntimeMethod* method) 
{
	ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tA69488C008961B8AE09141F37FDAE8A0F575CE48));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1));
		goto IL_0037;
	}

IL_0037:
	{
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1* L_4;
		L_4 = il2cpp_unsafe_as_ref<ConvertMeshJobData_t35F3B601671C4880929BC30A858410B14459E3B1>(L_3);
		ByReference_1_tF22763B5EFC788349C264CA03884C061A3FD8051 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		ConvertMeshJobDataU5BU5D_tB2771774E6E94A75BA5D65C7D84F0B7F3AD6D9E2* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mEC383018256E25827F3B339475CABFC2C2237A88_gshared_inline (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m4D4193A630867D8532F94829D1B330477153F6F5_gshared_inline (ReadOnlySpan_1_t65511D2895327A8ECE2BF5A34FDD23AE34C83122* __this, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_0 = ___0_ptr;
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mCD3AE57570C815AC4046DA4D9E7C0A9E2BBEB547_gshared_inline (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_0 = ___0_ptr;
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* Array_Empty_TisCopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044_mE213035FEF51FB6A504BDD242F0307E9FE074829_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_0 = ((EmptyArray_1_tA096FF5ABA9BBA8015C9E8E28FACB937691BFA36_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m2817AF8060669CE2B4F3418E7732492AE1043541_gshared_inline (Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE* __this, CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* ___0_array, const RuntimeMethod* method) 
{
	CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tD2CB759F9E30C3D5ABD48138E22576CCC8C570DE));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044));
		goto IL_0037;
	}

IL_0037:
	{
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044* L_4;
		L_4 = il2cpp_unsafe_as_ref<CopyClosingMeshJobData_t92845C1341A518A8D05CD9DCE53496BD70CF2044>(L_3);
		ByReference_1_t8F2B91815487096EDD5FC079D4B80CB31BE14972 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		CopyClosingMeshJobDataU5BU5D_tC12848324EE49ED0545B86D2A0C46030B81AEC57* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m385F87A001B432F97C5381EF1F01B485642ED27D_gshared_inline (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m7515BCC9EAB305B335A968E684B597A1FC9A5F24_gshared_inline (ReadOnlySpan_1_t7918A88B9E042EA0B873C90C85D2A8B97CB11BDF* __this, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_0 = ___0_ptr;
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m938DD54F3773C27DD1393A85BB94346047AD1DA5_gshared_inline (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_0 = ___0_ptr;
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* Array_Empty_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m46787E1D6E481E4790F1F9E63000A067C9AF33CD_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_0 = ((EmptyArray_1_t27401338DAB1F4C8F9B8E695AB18ABBBF6573E17_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m59E7D308EB85B51BA4162E76EE21E5568E986970_gshared_inline (Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116* __this, CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* ___0_array, const RuntimeMethod* method) 
{
	CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tC85B5D30CDD48BE32D9DF528934ED5AEC5BFC116));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0));
		goto IL_0037;
	}

IL_0037:
	{
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0* L_4;
		L_4 = il2cpp_unsafe_as_ref<CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0>(L_3);
		ByReference_1_t81CF4D69552C11045F619B7C65392B2FB3646E25 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		CullingSplitU5BU5D_tE7E4F4841F80A466E7A6149F61460774D8813F61* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_mFF4419EF107B2F1CD3364357F9723EAC96433F03_gshared_inline (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mB6153B16E29314D6497048CA9F509CF21C277F71_gshared_inline (ReadOnlySpan_1_tB185515663CA8B149175531C2C9804EB48DDEC9B* __this, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_0 = ___0_ptr;
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m52DDC62CEE4B57B1A97604C59D91F867D9C9472B_gshared_inline (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_0 = ___0_ptr;
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* Array_Empty_TisDrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5_m05A4DA3A4ACD6D784909779870EE466DF7778EC7_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_0 = ((EmptyArray_1_t640F34C5C1351444FCE089711FFEF74161372D64_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m7F574E10BF82902E6DFCF264F060076901BC34C0_gshared_inline (Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73* __this, DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* ___0_array, const RuntimeMethod* method) 
{
	DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tFCA7D5D0BF7401ABF1CDA871A9259927808E7F73));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5));
		goto IL_0037;
	}

IL_0037:
	{
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5* L_4;
		L_4 = il2cpp_unsafe_as_ref<DrawBufferRange_t289089F19A7539FDA77D3E63416BAFBA0955E2D5>(L_3);
		ByReference_1_t4E075C50F1605FECDAC4938F5DEBE21F2A040718 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		DrawBufferRangeU5BU5D_t6B42ADE630C5C9FFF52E20462A038BB9696764DB* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m4AFBDAB740A9ECD13948F54329A3D84FD198CB73_gshared_inline (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m8560DF2D26A1CC196BDE7BB7DFC896FB3D65EA16_gshared_inline (ReadOnlySpan_1_tBE8F7CF96CF1493E2EA4ED19616DF91D5FF56E7C* __this, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_0 = ___0_ptr;
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mABCC2BDB018D99B11CE82B53D6EDE75D4455193F_gshared_inline (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_0 = ___0_ptr;
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* Array_Empty_TisGfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C_mC6C376B567AC6FA4773E73349EE73E984E47852B_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_0 = ((EmptyArray_1_tFF976FF929BF18504D078013AD3BE659BC52BBEF_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_mEAFD68654E9CB51239357C3D94CDB5056137D70B_gshared_inline (Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68* __this, GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* ___0_array, const RuntimeMethod* method) 
{
	GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_tB93B3BC3E7EA509CCF751F8460FFA592FF1D1A68));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C));
		goto IL_0037;
	}

IL_0037:
	{
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C* L_4;
		L_4 = il2cpp_unsafe_as_ref<GfxUpdateBufferRange_t2991435FD0E056C19D7E3D4E524C13493F244B4C>(L_3);
		ByReference_1_tE9792401E28CE6CB45136FFF6CFB63E2B0BFEB93 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		GfxUpdateBufferRangeU5BU5D_tE41D12E7B85611267BA408D468B0F0422B7D1F30* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m87AB3C694F2E4802F14D006F21C020816045285F_gshared_inline (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_mA0D85386F3D3AAF59FC429C4A2A9E7CD6B7DCF2A_gshared_inline (ReadOnlySpan_1_t6190994DF094ABDFA6908C2C3FB347457E8E4282* __this, int32_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		int32_t* L_0 = ___0_ptr;
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m89B8042F831A4ACF35D15B29B8141AE29CFFDF84_gshared_inline (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, int32_t* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		int32_t* L_0 = ___0_ptr;
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* Array_Empty_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m4D53E0E0F90F37AD5DBFD2DC75E52406F90C7ABC_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ((EmptyArray_1_tE700FA647008891EF64C31436B092B253493667F_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m176441CFA181B7C6097611CC13C24C5ED7F14CFF_gshared_inline (Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_array, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t3C5DB525B005B1AC5A1F3BDD528900C5C7C7D316));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(int32_t));
		goto IL_0037;
	}

IL_0037:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		int32_t* L_4;
		L_4 = il2cpp_unsafe_as_ref<int32_t>(L_3);
		ByReference_1_tDDF129F0BC02430629D5CD253C681112F166BAD4 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Span_1_get_Length_m0BE6EA932B404A54A3AF19C9654ED2611196FAE5_gshared_inline (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____length;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ReadOnlySpan_1__ctor_m5146D98DC32810D3BC61D690968758CF2711417A_gshared_inline (ReadOnlySpan_1_t09FC5325A7B15784D246B5B71F829AB1C98B41DB* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_0 = ___0_ptr;
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m495B7963DA5CE2A2F3D69EAEBDD7BF73A1B34A31_gshared_inline (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___0_ptr, int32_t ___1_length, const RuntimeMethod* method) 
{
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_0 = ___0_ptr;
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_1;
		memset((&L_1), 0, sizeof(L_1));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_1), L_0);
		__this->____pointer = L_1;
		int32_t L_2 = ___1_length;
		__this->____length = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* Array_Empty_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m65AF0C73C7E00505BCE35B9CC15EE8C8F6F0A01E_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 2));
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_0 = ((EmptyArray_1_t0D07744D06CBE1D5EFB0F376FCD9DE664680DB24_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 2)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Span_1__ctor_m639F3CC8B14984E278FC347886BA5C0D86C7A4B9_gshared_inline (Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211* __this, JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, const RuntimeMethod* method) 
{
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		il2cpp_codegen_initobj(__this, sizeof(Span_1_t8206B553B7E881F7BC4BEA2B12509D008E524211));
		return;
	}

IL_000b:
	{
		il2cpp_codegen_initobj((&V_0), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		goto IL_0037;
	}

IL_0037:
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_2 = ___0_array;
		NullCheck((RuntimeArray*)L_2);
		uint8_t* L_3;
		L_3 = Array_GetRawSzArrayData_m2F8F5B2A381AEF971F12866D9C0A6C4FBA59F6BB_inline((RuntimeArray*)L_2, NULL);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_4;
		L_4 = il2cpp_unsafe_as_ref<JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08>(L_3);
		ByReference_1_tBB6AAE59AAE4993D4FA874B4F58E0E2C22E6CE90 L_5;
		memset((&L_5), 0, sizeof(L_5));
		il2cpp_codegen_by_reference_constructor((Il2CppByReference*)(&L_5), L_4);
		__this->____pointer = L_5;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_6 = ___0_array;
		NullCheck(L_6);
		__this->____length = ((int32_t)(((RuntimeArray*)L_6)->max_length));
		return;
	}
}
