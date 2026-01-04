#include "/home/codeleaded/System/Static/Library/AlxCallStack.h"
#include "/home/codeleaded/System/Static/Library/AlxExternFunctions.h"
#include "/home/codeleaded/System/Static/Library/IRVM_Comp.h"

void Ex_Packer(ExternFunctionMap* Extern_Functions,Vector* funcs,IRVM* ir){//Vector<CStr>
    TypeMap_PushContained(&ir->types,funcs,
        Type_New("void",sizeof(void*),OperatorInterationMap_Make((OperatorInterater[]){
            OperatorInterater_Make((CStr[]){ NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_INIT,     NULL),
                OperatorDefiner_New(TOKEN_DESTROY,  NULL),
                OPERATORDEFINER_END
            })),
            OPERATORINTERATER_END
        }),NULL,NULL)
    );
}