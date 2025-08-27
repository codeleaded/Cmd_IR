#include "/home/codeleaded/System/Static/Library/IRRuntime.h"

int main(int argc,char** argv){
    if(argc < 2){
        printf("[IRRuntime]: Arguments -> Usage: irr <.iralx>\n");
        return 0;
    }

    IRRuntime irr = IRRuntime_New(argv[1],"./bin");
    IRRuntime_Print(&irr);

    Variable params[] = {
        Variable_Make(".RETURN","int",(Number[]){ 0LL },sizeof(Number),-1,NULL,NULL),
        VARIABLE_END
    };
    IRRuntime_Function(&irr,"main",params);

    //IRRuntime_PrintVariable(&irr,params + 0);

    for(int i = 0;i<sizeof(params) / sizeof(Variable) - 1;i++){
        Variable_Free(params + i);
    }

    IRRuntime_Free(&irr);

    return 0;
}