%top{
    #include "parser.tab.hh"
    #define YY_DECL yy::parser::symbol_type yylex()
    #include "Node.h"
    int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 

%%

    /* KEYWORDS */
"class"             {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"main"              {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"int"               {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"float"             {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"boolean"           {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"void"              {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"volatile"          {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"if"                {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"else"              {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"for"               {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"print"             {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"read"              {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"return"            {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"break"             {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"continue"          {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"true"              {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}
"false"             {if(USE_LEX_ONLY) {printf("KEYWORD\n");} else {}}

    /* OPERATORS */
"+"                 {if(USE_LEX_ONLY) {printf("PLUSOP\n");} else {return yy::parser::make_PLUSOP(yytext);}}
"-"                 {if(USE_LEX_ONLY) {printf("SUBOP\n");} else {return yy::parser::make_MINUSOP(yytext);}}
"*"                 {if(USE_LEX_ONLY) {printf("MULTOP\n");} else {return yy::parser::make_MULTOP(yytext);}}
"/"                 {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {}}
"^"                 {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {}}   
"&"                 {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {}}
"|"                 {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {}}
"="                 {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {}}
"!="                {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {}}
"<"                 {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {}}
">"                 {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {}}
"<="                {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {}}
">="                {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {}}
":="                {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {}}
"!"                 {if(USE_LEX_ONLY) {printf("OPERATOR\n");} else {}}

    /* SYMBOLS */
"("                 {if(USE_LEX_ONLY) {printf("LP\n");} else {return yy::parser::make_LP(yytext);}}
")"                 {if(USE_LEX_ONLY) {printf("RP\n");} else {return yy::parser::make_RP(yytext);}}
"["                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {}}
"]"                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {}}
"{"                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {}}
"}"                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {}}
"."                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {}}
","                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {}}
":"                 {if(USE_LEX_ONLY) {printf("SYMBOL\n");} else {}}




    /* NEWLINE */
[\t\n\r]+              {}

    /* NUMBERS */
0|[1-9][0-9]*          {if(USE_LEX_ONLY) {printf("INT\n");} else {return yy::parser::make_INT(yytext);}}


    /* ID */
[a-zA-Z_][a-zA-Z0-9_]* {if(USE_LEX_ONLY) {printf("ID\n");} else {}}

    /* IDENTIFIER DONT WORK WHEN I HAVE ID */
    /*
        [a-zA-Z]               {if(USE_LEX_ONLY) {printf("CHAR\n");} else {}}  
        [a-zA-Z]+              {if(USE_LEX_ONLY) {printf("STRING\n");} else {}}
    */


    /* skip whitespace & comments*/
[\t\r ]                       {if(USE_LEX_ONLY) {printf("SPACE\n");} else {}}

    /*EOF & errors*/
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); fprintf(stderr,"\t@error at line %d. Character %s is not recognized\n", yylineno, yytext); lexical_errors = 1;}
<<EOF>>                  {return yy::parser::make_END();}
%%