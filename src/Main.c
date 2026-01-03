#include "/home/codeleaded/System/Static/Library/IRVM.h"

int main(int argc,char** argv){
    //if(argc < 2){
    //    printf("[ASMRuntime]: Arguments -> Usage: irr <.asmalx>\n");
    //    return 0;
    //}

    IRVM irr = IRVM_Make("./code/Main."  IRVM_TYPE,"./bin");
    IRVM_Print(&irr);
    IRVM_Free(&irr);
    return 0;
}