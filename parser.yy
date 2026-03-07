/* Skeleton and definitions for generating a LALR(1) parser in C++ */
%skeleton "lalr1.cc" 
%glr-parser 

/*
  Added grl-praser that fixes shift/reduce error in parser with ID LP RP and ID LP expression RP
  it dosent know if it should create a function or a math expression so i use glr-praser to look more
  one token ahead

*/

%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

/* Required code included before the parser definition begins */
%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
}

/* Code included in the parser implementation file */
%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}

/* Token definitions for the grammar */
/* Tokens represent the smallest units of the language, like operators and parentheses */



%token <std::string> PLUSOP MINUSOP MULTOP DIVOP POWER
%token <std::string> OR AND EXCLAMATION_MARK
%token <std::string> EQTO NEQ LE GE LT GT
%token <std::string> LP RP SLB SRB LCB RCB DOT COMMA COLON ASSIGN
%token <std::string> RETURN PRINT READ BREAK CONTINUE
%token <std::string> IF ELSE FOR MAIN CLASS LENGTH
%token <std::string> INT FLOAT TRUE FALSE
%token <std::string> ID COMMENT
%token <std::string> INT_TYPE FLOAT_TYPE BOOLEAN_TYPE VOID_TYPE VOLATILE
%token <std::string> INT_ARRAY_TYPE FLOAT_ARRAY_TYPE

%token END 0 "end of file"


/* Operator precedence and associativity rules */
/* Used to resolve ambiguities in parsing expressions See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl */ 


/* Specify types for non-terminals in the grammar */
/* The type specifies the data type of the values associated with these non-terminals */
%type <Node *> root block statements statement array_call class_call if_body
%type <Node *> expression logical_or logical_and equality relational additive multiplicative unary primary type values func_def main_def class_def
%type <Node *> assignment if_stmt for_stmt print_stmt read_stmt return_stmt break_stmt continue_stmt expr_stmt power comment parameters func_call arguments



/* Grammar rules section */ 
/* This section defines the production rules for the language being parsed */
%precedence IFX
%precedence ELSE

%%
root:
  statements END
  {
    root = $1;
  }
  | block END {
    root = $1;
  }
  ;

block: 
  LCB statements RCB {
    $$ = $2;
  }
  ;

statements:
  statement {
    $$ = new Node("Block", "Block", yylineno);
    $$->children.push_back($1);
  }
| statements statement {
  $$ = $1;
  $$->children.push_back($2);
}
;

statement: 
  main_def
  | class_def
  | func_def
  | assignment
  | if_stmt
  | for_stmt
  | print_stmt
  | read_stmt
  | return_stmt
  | break_stmt
  | continue_stmt
  | expr_stmt
  | type
  | comment
  ;


main_def:
  MAIN LP RP COLON INT_TYPE block {
    $$ = new Node("Main", $5, yylineno);
    $$->children.push_back($6);
  }


class_def:
  CLASS ID block {
    $$ = new Node("Class", $2, yylineno);
    $$->children.push_back($3);
  }
  ;

class_call:
  ID LP RP {
    $$ = new Node("Class", $1, yylineno);
  }
  ;

assignment:
  VOLATILE ID COLON type ASSIGN expression {
    $$ = new Node("varDecl", "", yylineno);
    $$->children.push_back(new Node("Modifier", $1, yylineno));
    $$->children.push_back(new Node("Identifier", $2, yylineno));
    $$->children.push_back($4);
    $$->children.push_back($6);
  }
  |
  ID COLON type ASSIGN expression {
    $$ = new Node("varDecl", "", yylineno);
    $$->children.push_back(new Node("Identifier", $1, yylineno));
    $$->children.push_back($3);
    $$->children.push_back($5);
  }
  |
  VOLATILE ID COLON type {
    $$ = new Node("varDecl", "", yylineno);
    $$->children.push_back(new Node("Modifier", $1, yylineno));
    $$->children.push_back(new Node("Identifier", $2, yylineno));
    $$->children.push_back($4);
  }
  | 
  VOLATILE ID COLON type ASSIGN type SLB values SRB {
    $$ = new Node("varDecl", "", yylineno);
    $$->children.push_back(new Node("Modifier", $1, yylineno));
    $$->children.push_back(new Node("Identifier", $2, yylineno));
    $$->children.push_back($4);
    $$->children.push_back($8);
  }
  |
  array_call ASSIGN array_call {
    $1->value = "1";
    $3->value = "2";
    $$ = new Node("Assign", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  |
  ID COLON ID ASSIGN class_call {
    $$ = new Node("Assign", "", yylineno);

    $$->children.push_back(new Node("Identifier", $1, yylineno));
    $$->children.push_back(new Node("Type", $3, yylineno));
    $$->children.push_back($5);
  }
  |
  VOLATILE ID COLON ID ASSIGN class_call {
    $$ = new Node("varDecl", "", yylineno);
    $$->children.push_back(new Node("Modifier", $1, yylineno));
    $$->children.push_back(new Node("Identifier", $2, yylineno));
    $$->children.push_back(new Node("Class", $4, yylineno));
    $$->children.push_back($6);
  }
  |
  VOLATILE ID COLON type ASSIGN class_call DOT func_call {
    $$ = new Node("varDecl", "", yylineno);
    $$->children.push_back(new Node("Modifier", $1, yylineno));
    $$->children.push_back(new Node("Identifier", $2, yylineno));
    $$->children.push_back($4);
    Node * c = $6;
    c->children.push_back($8);
    $$->children.push_back(c);
  }
  |
  VOLATILE ID COLON type ASSIGN ID DOT func_call {
    $$ = new Node("varDecl", "", yylineno);
    $$->children.push_back(new Node("Modifier", $1, yylineno));
    $$->children.push_back(new Node("Identifier", $2, yylineno));
    $$->children.push_back($4);
    Node * c = new Node("Class", $6, yylineno);
    c->children.push_back($8);
    $$->children.push_back(c);
  }
  |
  ID ASSIGN expression {
    $$ = new Node("Assign", "", yylineno);
    $$->children.push_back(new Node("Identifier", $1, yylineno));
    $$->children.push_back($3);
  }
  |
  array_call ASSIGN ID {
    $1->value = "1";
    $$ = new Node("Assign", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back(new Node("Value", $3, yylineno));
  }
  |
  ID ASSIGN type SLB values SRB {
    $$ = new Node("Assaign", "", yylineno);
    $$->children.push_back(new Node("Identifier", $1, yylineno));
    Node * array = new Node("Array", "", yylineno);
    array->children.push_back($3);
    array->children.push_back($5);
    $$->children.push_back(array);
  }
  |
  ID DOT func_call {
    $$ = new Node("Identifier", $1, yylineno);
    $$->children.push_back($3);
  }
  ;

parameters:
  ID COLON type {
    $$ = new Node("Parameters", "", yylineno);
    Node * parameter = new Node("Parameter", "", yylineno);
    parameter->children.push_back(new Node("Identifier", $1, yylineno));
    parameter->children.push_back($3);
    $$->children.push_back(parameter);
  }
  | 
  parameters COMMA ID COLON type  {
    $$ = $1;
    Node * parameter = new Node("Parameter", "", yylineno);
    parameter->children.push_back(new Node("Identifier", $3, yylineno));
    parameter->children.push_back($5);
    $$->children.push_back(parameter);
  }
  ;
func_def:
  ID LP parameters RP COLON type block {
    $$ = new Node("function_def", "", yylineno);
    $$->children.push_back(new Node("Identifier", $1, yylineno));
    $$->children.push_back($3);
    Node * return_type = new Node("Return_type", "", yylineno);
    return_type->children.push_back($6);
    $$->children.push_back(return_type);
    $$->children.push_back($7);
  }
  | 
  ID LP RP COLON type block {
    $$ = new Node("function_def", "", yylineno);
    $$->children.push_back(new Node("Identifier", $1, yylineno));
    Node * return_type = new Node("Return_type", "", yylineno);
    return_type->children.push_back($5);
    $$->children.push_back(return_type);
    $$->children.push_back($6);
  }
  |
  ID COLON type LP RP block {
    $$ = new Node("function_def", "", yylineno);
    $$->children.push_back(new Node("Identifier", $1, yylineno));
    Node * return_type = new Node("Return_type", "", yylineno);
    return_type->children.push_back($3);
    $$->children.push_back(return_type);
    $$->children.push_back($6);
  }
  ;

arguments:
  %empty{ 
    $$ = new Node("","", yylineno);
  }
  |
  expression {
    $$ = new Node("Arguments", "", yylineno);
    $$->children.push_back($1);
  }
  |
  arguments COMMA expression {
    $$ = $1;
    $$->children.push_back($3);
  }
  ;
func_call:
  ID LP arguments RP {
    $$ = new Node("function_call", $1, yylineno);
    $$->children.push_back($3);
  }
  ;


if_body
  : statement {
    $$ = new Node("Block", "", yylineno);
    $$->children.push_back($1);

  }
  | block
  ;

if_stmt:
   IF LP expression RP if_body %prec IFX
    {
      $$ = new Node("If_statement", "", yylineno);
      $$->children.push_back($3);
      $$->children.push_back($5);
    }
  | IF LP expression RP if_body ELSE if_body
    {
      $$ = new Node("If_statement", "", yylineno);
      $$->children.push_back($3);
      $$->children.push_back($5);
      Node * el = new Node("Else", "", yylineno);
      el->children.push_back($7);
      $$->children.push_back(el);
    }
  ;



for_stmt: 
  FOR LP ID ASSIGN expression COMMA relational COMMA ID ASSIGN expression RP block {
    $$ = new Node("For_loop", "", yylineno);
    Node * assign = new Node("Assign", "1", yylineno);
    assign->children.push_back(new Node("Identifier", $3, yylineno));
    assign->children.push_back($5);
    $$->children.push_back(assign);
    $$->children.push_back($7);
    
    Node * assign2 = new Node("Assign", "2", yylineno);
    assign2->children.push_back(new Node("Identifier", $9, yylineno));
    assign2->children.push_back($11);
    $$->children.push_back(assign2);
    $$->children.push_back($13);
  }
  |
  FOR LP COMMA primary COMMA primary ASSIGN primary RP block {
    $$ = new Node("For_loop", "", yylineno);
    $$->children.push_back($4);
    Node * assign = new Node("Assign", "2", yylineno);
    assign->children.push_back($6);
    assign->children.push_back($8);
    $$->children.push_back(assign);
    $$->children.push_back($10);
  }
  ;

print_stmt: 
  PRINT LP ID DOT func_call RP {
    $$ = new Node("Print", "", yylineno);
    Node * identifier = new Node("Identifier", $3, yylineno);
    identifier->children.push_back($5);
    $$->children.push_back(identifier);
  }
  |
  PRINT LP expression RP {
    $$ = new Node("Print", "", yylineno);
    $$->children.push_back($3);
  }
  |
  PRINT LP class_call DOT func_call RP {
    $$ = new Node("Print", "", yylineno);
    Node * c = $3;
    c->children.push_back($5);
    $$->children.push_back(c);
  }
  ;

read_stmt: 
  READ LP expression RP {
    $$ = new Node("Read", "", yylineno);
    $$->children.push_back($3);
  }
  ;

return_stmt: 
  RETURN expression {
    $$ = new Node("Return", "", yylineno);
    $$->children.push_back($2);
  }
  ;

break_stmt: 
  BREAK {
    $$ = new Node("Break", $1, yylineno);
  }
  ;

continue_stmt
  : CONTINUE {}
  ;

expr_stmt: 
  expression {
    $$ = $1;
  }
  ;

expression
  : logical_or {
    $$ = $1;
  }
  ;

logical_or: 
  logical_or OR logical_and {
    $$ = new Node("", $2, yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | logical_and {
    $$ = $1;
  }
  ;

logical_and:
 logical_and AND equality {
    $$ = new Node("", $2, yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    
  }
  | equality {
    $$ = $1;
  }
  ;

equality:
  equality EQTO relational {
    $$ = new Node("Equal_to", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | equality NEQ relational
  | relational {
    $$ = $1;
  }
  ;

relational
  : relational LT additive {
    $$ = new Node("Less_than", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | relational GT additive {
    $$ = new Node("Greater_than", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | relational LE additive {
    $$ = new Node("Less_than_or_equal_to", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | relational GE additive {
    $$ = new Node("Greater_than_or_equal_to", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | additive {
    $$ = $1;
  }
  ;

additive: 
  additive PLUSOP multiplicative {
    $$ = new Node("Add", "", yylineno); 
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | additive MINUSOP multiplicative {
    $$ = new Node("Minus", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);

  }
  | multiplicative {
    $$ = $1;
  }
  ;

power:
  unary POWER power {
      $$ = new Node("Power", "", yylineno);
      $$->children.push_back($1);
      $$->children.push_back($3);
  }
| unary {
      $$ = $1;
  }
;

multiplicative: 
  multiplicative MULTOP unary {
    $$ = new Node("Multiply", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | multiplicative DIVOP unary {
    $$ = new Node("Divide", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | power {
    $$ = $1;
  }
  ;

unary:
  EXCLAMATION_MARK unary
    {
      $$ = new Node("!", "", yylineno);
      $$->children.push_back($2);
    }
  | primary
    {
      $$ = $1;
    }
  ;

primary
  : INT {
    $$ = new Node("Value", $1, yylineno);
  }
  | FLOAT {
    $$ = new Node("Value", $1, yylineno);
  }
  | TRUE {
    $$ = new Node("Value", $1, yylineno);
  }
  | FALSE {
    $$ = new Node("Value", $1, yylineno);
  }
  | ID {
    $$ = new Node("Value", $1, yylineno);
  }
  | LP logical_or RP {
    $$ = $2;
  }
  |
  array_call {
    $$ = $1;
  }
  |
  func_call {
    $$ = $1;
  }
  ;

type:
  INT_TYPE {
    $$ = new Node("Type", $1, yylineno);
  }
  |
  FLOAT_TYPE {
    $$ = new Node("Type", $1, yylineno);
  } 
  | BOOLEAN_TYPE {
    $$ = new Node("Type", $1, yylineno);
  } 
  | 
  VOID_TYPE {
    $$ = new Node("Type", $1, yylineno);
  }
  |
  FLOAT_ARRAY_TYPE {
    $$ = new Node("Type", $1, yylineno);
  }
  |
  INT_ARRAY_TYPE {
    $$ = new Node("Type", $1, yylineno);
  }
  ;

comment:
  COMMENT {
    $$ = new Node("Comment", "", yylineno);
    $$->children.push_back(new Node("Value", $1, yylineno));
  }
  ;


values:
  primary {
    $$ = new Node("Array_literal", "", yylineno);
    $$->children.push_back($1);
  }
  |
  values COMMA primary {
    $$ = $1;
    $$->children.push_back($3);
  }


array_call:
  ID SLB expression SRB {
    $$ = new Node("Array", "", yylineno);
    $$->children.push_back(new Node("Identifier", $1, yylineno));
    Node * index = new Node("Index", "", yylineno);
    index->children.push_back($3);

    $$->children.push_back(index);
  }
  |
  ID DOT LENGTH {
    $$ = new Node("Array", "", yylineno);
    Node * identifier = new Node("Identifier", $1, yylineno);
    identifier->children.push_back(new Node("function_call", $3, yylineno));
    $$->children.push_back(identifier);

  }
%%



/* ./compiler < test_files/valid/test1.cpm */

