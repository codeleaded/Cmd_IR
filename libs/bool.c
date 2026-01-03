#include "/home/codeleaded/System/Static/Library/AlxCallStack.h"
#include "/home/codeleaded/System/Static/Library/AlxExternFunctions.h"
#include "/home/codeleaded/System/Static/Library/ASMRuntime.h"

Token Boolean_Boolean_Handler_Ass(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    ASM_InfoHandler(ir,"ass bool %s %s",a->str,b->str);

    Boolean n2 = ASM_Impl_Boolean(ir,b);
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ n2 });
        }else{
            ASM_ErrorHandler(ir,"Ass: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Ass: arg1 should be a variable, but is %s!",a->str);
    }

    Boolean res = n2;
    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}

Token Boolean_Boolean_Handler_Equ2(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    ASM_InfoHandler(ir,"equ bool %s %s",a->str,b->str);

    Boolean n1 = ASM_Impl_Boolean(ir,a);
    Boolean n2 = ASM_Impl_Boolean(ir,b);
    Boolean res = n1 == n2;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Equ: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Equ: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Boolean_Boolean_Handler_Equ3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"equ bool %s %s %s",a->str,b->str,c->str);

    Boolean n2 = ASM_Impl_Boolean(ir,b);
    Boolean n3 = ASM_Impl_Boolean(ir,c);
    Boolean res = n2 + n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Equ: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Equ: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}

Token Boolean_Boolean_Handler_And2(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    ASM_InfoHandler(ir,"and bool %s %s",a->str,b->str);

    Boolean n1 = ASM_Impl_Boolean(ir,a);
    Boolean n2 = ASM_Impl_Boolean(ir,b);
    Boolean res = n1 && n2;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"And: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"And: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Boolean_Boolean_Handler_Or2(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    ASM_InfoHandler(ir,"or bool %s %s",a->str,b->str);

    Boolean n1 = ASM_Impl_Boolean(ir,a);
    Boolean n2 = ASM_Impl_Boolean(ir,b);
    Boolean res = n1 || n2;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Or: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Or: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Boolean_Handler_Not1(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);

    ASM_InfoHandler(ir,"not bool %s",a->str);

    Boolean n1 = ASM_Impl_Boolean(ir,a);
    Boolean res = !n1;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Not: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Not: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}

Token Boolean_Boolean_Handler_And3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"and bool %s %s %s",a->str,b->str,c->str);

    Boolean n2 = ASM_Impl_Boolean(ir,b);
    Boolean n3 = ASM_Impl_Boolean(ir,c);
    Boolean res = n2 && n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"And: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"And: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Boolean_Boolean_Handler_Or3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"or bool %s %s %s",a->str,b->str,c->str);

    Boolean n2 = ASM_Impl_Boolean(ir,b);
    Boolean n3 = ASM_Impl_Boolean(ir,c);
    Boolean res = n2 || n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Or: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Or: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Boolean_Boolean_Handler_Not2(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);

    ASM_InfoHandler(ir,"not bool %s %s",a->str,b->str);

    Boolean n2 = ASM_Impl_Boolean(ir,b);
    Boolean res = !n2;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Not: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Not: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}

Token Boolean_Handler_Cast(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);

    Boolean n1 = ASM_Impl_Boolean(ir,a);
    
    Boolean res = n1;
    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_CONSTSTRING_DOUBLE,resstr);
}


Token Int_Int_Handler_Equ3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"equ int %s %s %s",a->str,b->str,c->str);

    Number n2 = ASM_Impl_Int(ir,b);
    Number n3 = ASM_Impl_Int(ir,c);
    Boolean res = n2 == n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Equ: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Equ: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Int_Handler_Les3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"les int %s %s %s",a->str,b->str,c->str);

    Number n2 = ASM_Impl_Int(ir,b);
    Number n3 = ASM_Impl_Int(ir,c);
    Boolean res = n2 < n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Les: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Les: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Int_Handler_Grt3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"grt int %s %s %s",a->str,b->str,c->str);

    Number n2 = ASM_Impl_Int(ir,b);
    Number n3 = ASM_Impl_Int(ir,c);
    Boolean res = n2 > n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Grt: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Grt: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Int_Handler_Leq3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"leq int %s %s %s",a->str,b->str,c->str);

    Number n2 = ASM_Impl_Int(ir,b);
    Number n3 = ASM_Impl_Int(ir,c);
    Boolean res = n2 <= n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Leq: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Leq: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Int_Int_Handler_Grq3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"grq int %s %s %s",a->str,b->str,c->str);

    Number n2 = ASM_Impl_Int(ir,b);
    Number n3 = ASM_Impl_Int(ir,c);
    Boolean res = n2 >= n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Grq: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Grq: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}

Token Float_Float_Handler_Equ3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"equ float %s %s %s",a->str,b->str,c->str);

    Double n2 = ASM_Impl_Int(ir,b);
    Double n3 = ASM_Impl_Int(ir,c);
    Boolean res = n2 == n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Equ: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Equ: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Float_Float_Handler_Les3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"les float %s %s %s",a->str,b->str,c->str);

    Double n2 = ASM_Impl_Int(ir,b);
    Double n3 = ASM_Impl_Int(ir,c);
    Boolean res = n2 < n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Les: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Les: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Float_Float_Handler_Grt3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"grt float %s %s %s",a->str,b->str,c->str);

    Double n2 = ASM_Impl_Int(ir,b);
    Double n3 = ASM_Impl_Int(ir,c);
    Boolean res = n2 > n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Grt: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Grt: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Float_Float_Handler_Leq3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"leq float %s %s %s",a->str,b->str,c->str);

    Double n2 = ASM_Impl_Int(ir,b);
    Double n3 = ASM_Impl_Int(ir,c);
    Boolean res = n2 <= n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Leq: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Leq: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}
Token Float_Float_Handler_Grq3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"grq float %s %s %s",a->str,b->str,c->str);

    Double n2 = ASM_Impl_Int(ir,b);
    Double n3 = ASM_Impl_Int(ir,c);
    Boolean res = n2 >= n3;
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Grq: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Grq: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}

Token Str_Str_Handler_Equ3(ASM* ir,Token* op,Vector* args){
    Token* a = (Token*)Vector_Get(args,0);
    Token* b = (Token*)Vector_Get(args,1);
    Token* c = (Token*)Vector_Get(args,2);

    ASM_InfoHandler(ir,"equ str %s %s %s",a->str,b->str,c->str);

    CStr n2 = ASM_Impl_Str(ir,b);
    CStr n3 = ASM_Impl_Str(ir,c);
    Boolean res = CStr_Cmp(n2,n3);
    if(a->tt==TOKEN_STRING){
        Variable* a_var = VariableMap_Find(&ir->vars,a->str);
        if(a_var){
            Variable_PrepairFor(a_var,sizeof(Boolean),"bool",NULL,NULL);
            Variable_SetTo(a_var,(Boolean[]){ res });
        }else{
            ASM_ErrorHandler(ir,"Equ: variable %s doesn't exist!",a->str);
        }
    }else{
        ASM_ErrorHandler(ir,"Equ: arg1 should be a variable, but is %s!",a->str);
    }

    char* resstr = Boolean_Get(res);
    return Token_Move(TOKEN_BOOL,resstr);
}

void Ex_Packer(ExternFunctionMap* Extern_Functions,Vector* funcs,ASM* ir){//Vector<CStr>
    TypeMap_PushContained(&ir->types,funcs,
        Type_New("bool",sizeof(Boolean),OperatorInterationMap_Make((OperatorInterater[]){
            OperatorInterater_Make((CStr[]){ NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_ASM_NOT,   (Token(*)(void*,Token*,Vector*))Boolean_Handler_Not1),
                OperatorDefiner_New(TOKEN_CAST,     (Token(*)(void*,Token*,Vector*))Boolean_Handler_Cast),
                OperatorDefiner_New(TOKEN_INIT,     NULL),
                OperatorDefiner_New(TOKEN_DESTROY,  NULL),
                OPERATORDEFINER_END
            })),
            OperatorInterater_Make((CStr[]){ "bool",NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_ASM_ASS,   (Token(*)(void*,Token*,Vector*))Boolean_Boolean_Handler_Ass),
                OperatorDefiner_New(TOKEN_ASM_EQU,   (Token(*)(void*,Token*,Vector*))Boolean_Boolean_Handler_Equ2),
                OperatorDefiner_New(TOKEN_ASM_AND,   (Token(*)(void*,Token*,Vector*))Boolean_Boolean_Handler_And2),
                OperatorDefiner_New(TOKEN_ASM_OR,    (Token(*)(void*,Token*,Vector*))Boolean_Boolean_Handler_Or2),
                OperatorDefiner_New(TOKEN_ASM_NOT,   (Token(*)(void*,Token*,Vector*))Boolean_Boolean_Handler_Not2),
                OPERATORDEFINER_END
            })),
            OperatorInterater_Make((CStr[]){ "bool","bool",NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_ASM_AND,   (Token(*)(void*,Token*,Vector*))Boolean_Boolean_Handler_And3),
                OperatorDefiner_New(TOKEN_ASM_OR,    (Token(*)(void*,Token*,Vector*))Boolean_Boolean_Handler_Or3),
                OPERATORDEFINER_END
            })),
            OperatorInterater_Make((CStr[]){ "int","int",NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_ASM_EQU,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Equ3),
                OperatorDefiner_New(TOKEN_ASM_LES,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Les3),
                OperatorDefiner_New(TOKEN_ASM_GRT,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Grt3),
                OperatorDefiner_New(TOKEN_ASM_LEQ,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Leq3),
                OperatorDefiner_New(TOKEN_ASM_GRQ,   (Token(*)(void*,Token*,Vector*))Int_Int_Handler_Grq3),
                OPERATORDEFINER_END
            })),
            OperatorInterater_Make((CStr[]){ "float","float",NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_ASM_EQU,   (Token(*)(void*,Token*,Vector*))Float_Float_Handler_Equ3),
                OperatorDefiner_New(TOKEN_ASM_LES,   (Token(*)(void*,Token*,Vector*))Float_Float_Handler_Les3),
                OperatorDefiner_New(TOKEN_ASM_GRT,   (Token(*)(void*,Token*,Vector*))Float_Float_Handler_Grt3),
                OperatorDefiner_New(TOKEN_ASM_LEQ,   (Token(*)(void*,Token*,Vector*))Float_Float_Handler_Leq3),
                OperatorDefiner_New(TOKEN_ASM_GRQ,   (Token(*)(void*,Token*,Vector*))Float_Float_Handler_Grq3),
                OPERATORDEFINER_END
            })),OperatorInterater_Make((CStr[]){ "str","str",NULL },OperatorDefineMap_Make((OperatorDefiner[]){
                OperatorDefiner_New(TOKEN_ASM_EQU,   (Token(*)(void*,Token*,Vector*))Str_Str_Handler_Equ3),
                OPERATORDEFINER_END
            })),
            OPERATORINTERATER_END
        }),NULL,NULL)
    );
}