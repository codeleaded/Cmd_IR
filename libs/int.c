#include "/home/codeleaded/System/Static/Library/AlxCallStack.h"
#include "/home/codeleaded/System/Static/Library/AlxExternFunctions.h"
#include "/home/codeleaded/System/Static/Library/ASMRuntime.h"

Token Int_Int_Handler_Ass(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    ASM_InfoHandler(ir,"ass int %s %s",a->str,b->str);

    Number n2 = ASM_Impl_Int(ir,b);
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Number),"int",NULL,NULL);
            Variable_SetTo(a_var,(Number[]){ n2 });
        }else{
            ASM_ErrorHandler(ir,"Ass: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Ass: arg1 should be a variable, but is %s!",a->str);
    }

    Number res = n2;
    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}

Token Int_Int_Handler_Add2(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    ASM_InfoHandler(ir,"add int %s %s",a->str,b->str);

    Number n1 = ASM_Impl_Int(ir,a);
    Number n2 = ASM_Impl_Int(ir,b);
    Number res = n1 + n2;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Number),"int",NULL,NULL);
            Variable_SetTo(a_var,(Number[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Add: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Add: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Sub2(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    ASM_InfoHandler(ir,"sub int %s %s",a->str,b->str);

    Number n1 = ASM_Impl_Int(ir,a);
    Number n2 = ASM_Impl_Int(ir,b);
    Number res = n1 - n2;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Number),"int",NULL,NULL);
            Variable_SetTo(a_var,(Number[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Sub: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Sub: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Mul2(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    ASM_InfoHandler(ir,"mul int %s %s",a->str,b->str);

    Number n1 = ASM_Impl_Int(ir,a);
    Number n2 = ASM_Impl_Int(ir,b);
    Number res = n1 * n2;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Number),"int",NULL,NULL);
            Variable_SetTo(a_var,(Number[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Mul: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Mul: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Div2(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    ASM_InfoHandler(ir,"div int %s %s",a->str,b->str);

    Number n1 = ASM_Impl_Int(ir,a);
    Number n2 = ASM_Impl_Int(ir,b);
    Number res = n1 / n2;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            if(n2!=0){
                Variable_PrepairFor(a_var,sizeof(Number),"int",NULL,NULL);
                Variable_SetTo(a_var,(Number[]){ res });
            }else
                ASM_ErrorHandler(ir,"Div: division by 0, because %s is 0!",b->str);
        }else{
            ASM_ErrorHandler(ir,"Div: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Div: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Handler_Neg1(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);

    ASM_InfoHandler(ir,"neg int %s",a->str);

    Number n1 = ASM_Impl_Int(ir,a);
    Number res = -n1;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Number),"int",NULL,NULL);
            Variable_SetTo(a_var,(Number[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Div: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Div: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}

Token Int_Int_Handler_Add3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"add int %s %s %s",a->str,b->str,c->str);

    Number n2 = ASM_Impl_Int(ir,b);
    Number n3 = ASM_Impl_Int(ir,c);
    Number res = n2 + n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Number),"int",NULL,NULL);
            Variable_SetTo(a_var,(Number[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Add: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Add: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Sub3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"sub int %s %s %s",a->str,b->str,c->str);

    Number n2 = ASM_Impl_Int(ir,b);
    Number n3 = ASM_Impl_Int(ir,c);
    Number res = n2 + n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Number),"int",NULL,NULL);
            Variable_SetTo(a_var,(Number[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Sub: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Sub: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Mul3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"mul int %s %s %s",a->str,b->str,c->str);

    Number n2 = ASM_Impl_Int(ir,b);
    Number n3 = ASM_Impl_Int(ir,c);
    Number res = n2 * n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Number),"int",NULL,NULL);
            Variable_SetTo(a_var,(Number[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Mul: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Mul: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Div3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"div int %s %s %s",a->str,b->str,c->str);

    Number n2 = ASM_Impl_Int(ir,b);
    Number n3 = ASM_Impl_Int(ir,c);
    Number res = n2 / n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            if(n2!=0){
                Variable_PrepairFor(a_var,sizeof(Number),"int",NULL,NULL);
                Variable_SetTo(a_var,(Number[]){ res });
            }else
                ASM_ErrorHandler(ir,"Div: division by 0, because %s is 0!",c->str);
        }else{
            ASM_ErrorHandler(ir,"Div: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Div: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}
Token Int_Int_Handler_Neg2(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    ASM_InfoHandler(ir,"neg int %s %s",a->str,b->str);

    Number n2 = ASM_Impl_Int(ir,b);
    Number res = -n2;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Number),"int",NULL,NULL);
            Variable_SetTo(a_var,(Number[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Neg: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Neg: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_NUMBER,resstr);
}

Token Int_Int_Handler_Equ(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("EQU: %s == %s\n",a->str,b->str);

    Number n1 = ASM_Impl_Int(ir,a);
    Number n2 = ASM_Impl_Int(ir,b);
    Boolean res = n1 == n2;

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Int_Handler_Les(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("LES: %s < %s\n",a->str,b->str);

    Number n1 = ASM_Impl_Int(ir,a);
    Number n2 = ASM_Impl_Int(ir,b);
    Boolean res = n1 < n2;

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Int_Handler_Grt(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("GRT: %s > %s\n",a->str,b->str);

    Number n1 = ASM_Impl_Int(ir,a);
    Number n2 = ASM_Impl_Int(ir,b);
    Boolean res = n1 > n2;

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Int_Handler_Leq(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("LEQ: %s <= %s\n",a->str,b->str);

    Number n1 = ASM_Impl_Int(ir,a);
    Number n2 = ASM_Impl_Int(ir,b);
    Boolean res = n1 <= n2;

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Int_Handler_Grq(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    //printf("GRQ: %s >= %s\n",a->str,b->str);

    Number n1 = ASM_Impl_Int(ir,a);
    Number n2 = ASM_Impl_Int(ir,b);
    Boolean res = n1 >= n2;

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}

Token Int_Handler_Cast(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);

    //printf("CAST: %s\n",a->str);

    Number res = ASM_Impl_Int(ir,a);
    char* resstr = Number_Get(res);
    return Token_Move(TOKEN_CONSTSTRING_DOUBLE,resstr);
}

void Ex_Packer(ExternFunctionMap* Extern_Functions,Vector* funcs,ASM* ir){//Vector<CStr>
    TypeMap_PushContained(&ir->types,funcs,
        Type_New("int",sizeof(Number),OperatorInterationMap_Make((OperatorInterater[]){
            OperatorInterater_Make((CStr[]){ NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_ASM_NEG,   (Token(*)(void*,Token*,Vector*))Int_Handler_Neg1),
                OperatorDefiner_New(TOKEN_CAST,     (Token(*)(void*,Token*,Vector*))Int_Handler_Cast),
                OperatorDefiner_New(TOKEN_INIT,     NULL),
                OperatorDefiner_New(TOKEN_DESTROY,  NULL),
                OPERATORDEFINER_END
            })),
            OperatorInterater_Make((CStr[]){ "int",NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_ASM_ASS,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Ass),
                OperatorDefiner_New(TOKEN_ASM_ADD,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Add2),
                OperatorDefiner_New(TOKEN_ASM_SUB,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Sub2),
                OperatorDefiner_New(TOKEN_ASM_MUL,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Mul2),
                OperatorDefiner_New(TOKEN_ASM_DIV,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Div2),
                OperatorDefiner_New(TOKEN_ASM_NEG,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Neg2),
                OperatorDefiner_New(TOKEN_ASM_EQU,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Equ),
                OperatorDefiner_New(TOKEN_ASM_LES,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Les),
                OperatorDefiner_New(TOKEN_ASM_GRT,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Grt),
                OperatorDefiner_New(TOKEN_ASM_LEQ,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Leq),
                OperatorDefiner_New(TOKEN_ASM_GRQ,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Grq),
                OPERATORDEFINER_END
            })),
            OperatorInterater_Make((CStr[]){ "int","int",NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_ASM_ADD,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Add3),
                OperatorDefiner_New(TOKEN_ASM_SUB,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Sub3),
                OperatorDefiner_New(TOKEN_ASM_MUL,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Mul3),
                OperatorDefiner_New(TOKEN_ASM_DIV,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Div3),
                OPERATORDEFINER_END
            })),
            OPERATORINTERATER_END
        }),NULL,NULL)
    );
}
