#include "/home/codeleaded/System/Static/Library/AlxCallStack.h"
#include "/home/codeleaded/System/Static/Library/AlxExternFunctions.h"
#include "/home/codeleaded/System/Static/Library/IRVM_Comp.h"

Token Pointer_Pointer_Handler_Ass(IRVM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    IRVM_InfoHandler(ir,"ass Pointer %s %s",a->str,b->str);

    return Token_Move(TOKEN_IRVM_SSA,NULL);
}
Token Pointer_Handler_Ret(IRVM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);

    IRVM_InfoHandler(ir,"ret Pointer %s",a->str);

    return Token_Move(TOKEN_IRVM_SSA,NULL);
}

Token Pointer_Handler_Cast(IRVM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);

    return Token_Move(TOKEN_CONSTSTRING_DOUBLE,NULL);
}

void Ex_Packer(ExternFunctionMap* Extern_Functions,Vector* funcs,IRVM* ir){//Vector<CStr>
    TypeMap_PushContained(&ir->types,funcs,
        Type_New("?*",sizeof(void*),OperatorInterationMap_Make((OperatorInterater[]){
            OperatorInterater_Make((CStr[]){ NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_IRVM_RET, (Token(*)(void*,Token*,Vector*))Pointer_Handler_Ret),
                OperatorDefiner_New(TOKEN_CAST,     (Token(*)(void*,Token*,Vector*))Pointer_Handler_Cast),
                OperatorDefiner_New(TOKEN_INIT,     NULL),
                OperatorDefiner_New(TOKEN_DESTROY,  NULL),
                OPERATORDEFINER_END
            })),
            OperatorInterater_Make((CStr[]){ "?*",NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_IRVM_ASS,   (Token(*)(void*,Token*,Vector*))Pointer_Pointer_Handler_Ass),
                OPERATORDEFINER_END
            })),
            OPERATORINTERATER_END
        }),NULL,NULL)
    );
}