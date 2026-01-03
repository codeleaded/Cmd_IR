#include "/home/codeleaded/System/Static/Library/ASMRuntime.h"

int main(int argc,char** argv){
    //if(argc < 2){
    //    printf("[ASMRuntime]: Arguments -> Usage: irr <.asmalx>\n");
    //    return 0;
    //}

    ASMRuntime irr = ASMRuntime_New("./code/Main.asmalx","./bin");
    ASMRuntime_Print(&irr);

    Variable params[] = {
        Variable_Make("a","int",(Number[]){ 0LL },sizeof(Number),-1,NULL,NULL),
        VARIABLE_END
    };
    ASMRuntime_Function(&irr,"main",params);
    //ASMRuntime_PrintVariable(&irr,params + 0);

    ASMRuntime_Free(&irr);
    return 0;
}