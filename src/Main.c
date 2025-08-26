#include "/home/codeleaded/System/Static/Library/IRRuntime.h"

int main(int argc,char** argv){
    if(argc < 2){
        printf("[IRRuntime]: Arguments -> Usage: irr <.iralx>\n");
        return 0;
    }

    IRRuntime irr = IRRuntime_New(argv[1],"./bin");
    IRRuntime_Print(&irr);
    IRRuntime_Free(&irr);

    return 0;
}