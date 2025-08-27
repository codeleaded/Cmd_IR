#include "/home/codeleaded/System/Static/Library/AlxCallStack.h"
#include "/home/codeleaded/System/Static/Library/AlxExternFunctions.h"
#include "/home/codeleaded/System/Static/Library/IR.h"

Number Implementation_IntOf(IR* ir,Token* a){
    Number n = NUMBER_PARSE_ERROR;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            n = *(Number*)Variable_Data(a_var);
        }else{
            printf("[Int_Number]: 1. Arg: Variable %s doesn't exist!\n",a->str);
        }
    }else if(a->tt==TOKEN_NUMBER){
        n = Number_Parse(a->str);
    }else if(a->tt==TOKEN_FLOAT){
        n = (Number)Double_Parse(a->str,1);
    }else{
        printf("[Int_Number]: 1. Arg: %s is not a int type!\n",a->str);
    }
    return n;
}

Token Int_Int_Handler_Ass(IR* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("(int,int) ASS: %s = %s\n",a->str,b->str);

    Number n2 = Implementation_IntOf(ir,b);
    
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Number),"int",NULL,NULL);
            Variable_SetTo(a_var,(Number[]){ n2 });
        }else{
            //IR_BuildInitVariableRange(ir,a->str,"int",-1,(Number[]){ n2 });
        }
    }else{
        printf("[Int_Ass]: 1. Arg: %s is not a variable type!\n",a->str);
    }

    Number res = n2;

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Add(IR* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("ADD: %s + %s\n",a->str,b->str);

    Number n1 = Implementation_IntOf(ir,a);
    Number n2 = Implementation_IntOf(ir,b);
    Number res = n1 + n2;

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Sub(IR* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("SUB: %s - %s\n",a->str,b->str);

    Number n1 = Implementation_IntOf(ir,a);
    Number n2 = Implementation_IntOf(ir,b);
    Number res = n1 - n2;

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Mul(IR* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("MUL: %s * %s\n",a->str,b->str);

    Number n1 = Implementation_IntOf(ir,a);
    Number n2 = Implementation_IntOf(ir,b);
    Number res = n1 * n2;

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Div(IR* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("DIV: %s / %s\n",a->str,b->str);

    Number n1 = Implementation_IntOf(ir,a);
    Number n2 = Implementation_IntOf(ir,b);

    Number res = 0;
    if(n2!=0) res = n1 / n2;
    else{
        printf("[Enviroment]: Error: DIV by Zero\n");
    }

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Neg(IR* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);

    //printf("NEG: -%s\n",a->str);

    Number n1 = Implementation_IntOf(ir,a);
    Number res = -n1;

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Equ(IR* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("EQU: %s == %s\n",a->str,b->str);

    Number n1 = Implementation_IntOf(ir,a);
    Number n2 = Implementation_IntOf(ir,b);
    Boolean res = n1 == n2;

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Int_Handler_Les(IR* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("LES: %s < %s\n",a->str,b->str);

    Number n1 = Implementation_IntOf(ir,a);
    Number n2 = Implementation_IntOf(ir,b);
    Boolean res = n1 < n2;

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Int_Handler_Grt(IR* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("GRT: %s > %s\n",a->str,b->str);

    Number n1 = Implementation_IntOf(ir,a);
    Number n2 = Implementation_IntOf(ir,b);
    Boolean res = n1 > n2;

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Int_Handler_Leq(IR* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("LEQ: %s <= %s\n",a->str,b->str);

    Number n1 = Implementation_IntOf(ir,a);
    Number n2 = Implementation_IntOf(ir,b);
    Boolean res = n1 <= n2;

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Int_Handler_Grq(IR* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("GRQ: %s >= %s\n",a->str,b->str);

    Number n1 = Implementation_IntOf(ir,a);
    Number n2 = Implementation_IntOf(ir,b);
    Boolean res = n1 >= n2;

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Handler_Cast(IR* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);

    //printf("CAST: %s\n",a->str);

    Number res = Implementation_IntOf(ir,a);
    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_CONSTSTRING_DOUBLE,resstr);
}

void Ex_Packer(ExternFunctionMap* Extern_Functions,Vector* funcs,IR* ir){//Vector<CStr>
    TypeMap_PushContained(&ir->types,funcs,
        Type_New("int",8,OperatorInterationMap_Make((OperatorInterater[]){
            OperatorInterater_Make((CStr[]){ NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_IR_NEG,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Neg),
                OperatorDefiner_New(TOKEN_CAST,     (Token(*)(void*,Token*,Vector*))Int_Handler_Cast),
                OperatorDefiner_New(TOKEN_INIT,     NULL),
                OperatorDefiner_New(TOKEN_DESTROY,  NULL),
                OPERATORDEFINER_END
            })),
            OperatorInterater_Make((CStr[]){ "int",NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_IR_ASS,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Ass),
                OperatorDefiner_New(TOKEN_IR_ADD,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Add),
                OperatorDefiner_New(TOKEN_IR_SUB,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Sub),
                OperatorDefiner_New(TOKEN_IR_MUL,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Mul),
                OperatorDefiner_New(TOKEN_IR_DIV,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Div),
                OperatorDefiner_New(TOKEN_IR_EQU,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Equ),
                OperatorDefiner_New(TOKEN_IR_LES,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Les),
                OperatorDefiner_New(TOKEN_IR_GRT,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Grt),
                OperatorDefiner_New(TOKEN_IR_LEQ,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Leq),
                OperatorDefiner_New(TOKEN_IR_GRQ,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Grq),
                OPERATORDEFINER_END
            })),
            OPERATORINTERATER_END
        }),NULL,NULL)
    );
}