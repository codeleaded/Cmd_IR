#include "/home/codeleaded/System/Static/Library/IRVM_Comp.h"

int main(int argc,char** argv){
    //if(argc < 2){
    //    printf("[IRVM]: Arguments -> Usage: irvm <.iralx>\n");
    //    return 0;
    //}

    IRVM irr = IRVM_New("./bin");
    IRVM_Script(&irr,"./code/Main." IRVM_TYPE);
    IRVM_Print(&irr);
    //IRVM_Build(&irr);
    //IRVM_Write(&irr,"./code/Main.asm");
    IRVM_Free(&irr);
    return 0;
}