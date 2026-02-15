%top{
    #include "parser.tab.hh"
    #define YY_DECL yy::parser::symbol_type yylex()
    #include "Node.h"
    int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 

%%

    /* KEYWORDS */
"return"            {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_RETURN(yytext);}}
"class"             {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_CLASS(yytext);}}
"main"              {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_MAIN(yytext);}}
"int"               {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_INT_TYPE(yytext);}}
"int[]"             {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_INT_ARRAY_TYPE(yytext);}}
"float"             {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_FLOAT_TYPE(yytext);}}
"float[]"           {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_FLOAT_ARRAY_TYPE(yytext);}}
"boolean"           {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"void"              {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_VOID_TYPE(yytext);}}
"volatile"          {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_VOLATILE(yytext);}}
"if"                {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_IF(yytext);}}
"else"              {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_ELSE(yytext);}}
"for"               {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_FOR(yytext);}}
"print"             {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_PRINT(yytext);}}
"read"              {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_READ(yytext);}}
"break"             {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"continue"          {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"true"              {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_TRUE(yytext);}}
"false"             {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_FALSE(yytext);}}
"length"            {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {return yy::parser::make_LENGTH(yytext);}}

    /* OPERATORS */
"+"                 {if(USE_LEX_ONLY) {printf("PLUSOP\n");} else {return yy::parser::make_PLUSOP(yytext);}}
"-"                 {if(USE_LEX_ONLY) {printf("SUBOP\n");} else {return yy::parser::make_MINUSOP(yytext);}}
"*"                 {if(USE_LEX_ONLY) {printf("MULTOP\n");} else {return yy::parser::make_MULTOP(yytext);}}
"/"                 {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {return yy::parser::make_DIVOP(yytext);}}
"^"                 {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {return yy::parser::make_POWER(yytext);}}   
"&"                 {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {return yy::parser::make_AND(yytext);}}
"|"                 {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {return yy::parser::make_OR(yytext);}}
"="                 {if(USE_LEX_ONLY) { printf("EQOP\n"); }   else { return yy::parser::make_EQTO(yytext); } }
"!="                {if(USE_LEX_ONLY) { printf("NEQOP\n"); }   else { return yy::parser::make_NEQ(yytext); } }
"<="                {if(USE_LEX_ONLY) { printf("LEOP\n"); }    else { return yy::parser::make_LE(yytext); } }
">="                {if(USE_LEX_ONLY) { printf("GEOP\n"); }    else { return yy::parser::make_GE(yytext); } }
"<"                 {if(USE_LEX_ONLY) { printf("LTOP\n"); }    else { return yy::parser::make_LT(yytext); } }
">"                 {if(USE_LEX_ONLY) { printf("GTOP\n"); }    else { return yy::parser::make_GT(yytext); } }
":="  { if(USE_LEX_ONLY) { printf("ASSIGNOP\n"); } else { return yy::parser::make_ASSIGN(yytext); } }

    /* SYMBOLS */
"("                 {if(USE_LEX_ONLY) {printf("LP\n");} else {return yy::parser::make_LP(yytext);}}
")"                 {if(USE_LEX_ONLY) {printf("RP\n");} else {return yy::parser::make_RP(yytext);}}
"["                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {return yy::parser::make_SLB(yytext);}}
"]"                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {return yy::parser::make_SRB(yytext);}}
"{"                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {return yy::parser::make_LCB(yytext);}}
"}"                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {return yy::parser::make_RCB(yytext);}}
"."                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {return yy::parser::make_DOT(yytext);}}
","                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {return yy::parser::make_COMMA(yytext);}}
":"                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {return yy::parser::make_COLON(yytext);}}
    /* NEWLINE */
[\t\n\r]+              {}
0|[1-9][0-9]*          {if(USE_LEX_ONLY) {printf("INT\n");} else {return yy::parser::make_INT(yytext);}}
([0-9]*[.])?[0-9]+     {if(USE_LEX_ONLY) {printf("FLOAT\n");} else {return yy::parser::make_FLOAT(yytext);}}
    /* ID */
\/\/[^\n]* {if(USE_LEX_ONLY) {printf("FLOAT\n");} else {return yy::parser::make_COMMENT(yytext);}}

[a-zA-Z_][a-zA-Z0-9_]* {if(USE_LEX_ONLY) {printf("FLOAT\n");} else {return yy::parser::make_ID(yytext);}}

    /* skip whitespace & comments*/
[\t\r ]                 {if(USE_LEX_ONLY) {printf("SPACE\n");} else {}}

    /*EOF & errors*/
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); fprintf(stderr,"\t@error at line %d. Character %s is not recognized\n", yylineno, yytext); lexical_errors = 1;}
<<EOF>>                  {return yy::parser::make_END();}
%%