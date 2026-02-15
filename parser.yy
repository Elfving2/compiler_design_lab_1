/* Skeleton and definitions for generating a LALR(1) parser in C++ */
%skeleton "lalr1.cc" 
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


%token <std::string> PLUSOP MINUSOP MULTOP INT LP RP FLOAT DIVOP POWER FLOAT_TYPE INT_TYPE VOLATILE ID COLON ASSIGN RETURN PRINT LCB RCB MAIN FOR COMMA AND OR EQTO NEQ LE GE LT GT IF SLB SRB COMMENT CLASS READ DOT LENGTH ELSE TRUE FALSE INT_ARRAY_TYPE FLOAT_ARRAY_TYPE VOID_TYPE

%token END 0 "end of file"

/* Operator precedence and associativity rules */
/* Used to resolve ambiguities in parsing expressions See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl */ 
%left PLUSOP MINUSOP
%left MULTOP DIVOP
%right POWER

/* Specify types for non-terminals in the grammar */
/* The type specifies the data type of the values associated with these non-terminals */
%type <Node *> root statements expression arithmetic_operators math_expression variable type return print block main for_statement relational_operators if_statement number_array array_call array_decl comment class function_decl function_call parameters read


/* Grammar rules section */ 
/* This section defines the production rules for the language being parsed */
%%
root:       
  statements {
    root = $1;
};

statements :
  %empty {
      $$ = new Node("Statements", "", yylineno);
    }
  | 
  statements expression {
      $$ = $1;
      $$->children.push_back($2);
    }
  ; 

expression:
  variable {
    $$ = $1;
  }
  |
  read {
    $$ = $1; 
  }
  |
  print {
    $$ = $1;
  }
  |
  block {
    $$ = $1;
  }
  |
  main {
    $$ = $1;
  }
  |
  for_statement {
    $$ = $1;
  }
  |
  if_statement {
    $$ = $1;
  }
  |
  array_decl {
    $$ = $1;
  }
  |
  comment {
    $$ = $1;
  }
  |
  return {
    $$ = $1;
  }
  |
  class {
    $$ = $1;
  }
  |
  function_decl {
    $$ = $1;
  }
  |
  function_call {
    $$ = $1;
  }
  ;

math_expression:
    math_expression PLUSOP math_expression {
        $$ = new Node("Add", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | 
    math_expression MINUSOP math_expression {
        $$ = new Node("Sub", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | 
    math_expression MULTOP math_expression {
        $$ = new Node("Mul", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | 
    math_expression DIVOP math_expression {
        $$ = new Node("Div", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | 
    math_expression POWER math_expression {
        $$ = new Node("Pow", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    |
    arithmetic_operators {
        $$ = $1;
  }
  ;


arithmetic_operators:
  ID {
    $$ = new Node("Id", "", yylineno);
  }
  | 
  INT {
    $$ = new Node("Int", "", yylineno);
  }
  |
  FLOAT {
    $$ = new Node("Float", "", yylineno);
  }
  |
  LP math_expression RP {
    $$ = $2;
  }
  |
  function_call {
    $$ = $1;
  }
  |
  TRUE {
    $$ = new Node("True", "", yylineno);
  }
  |
  FALSE {
    $$= new Node("False", "", yylineno);
  }
  ;

type: 
  INT_TYPE {
    $$ = new Node("Int_type", "", yylineno);
  }
  |
  FLOAT_TYPE {
    $$ = new Node("Float_type", "", yylineno);
  }
  |
  INT_ARRAY_TYPE {
    $$ = new Node("Int_array", "", yylineno);
  }
  |
  FLOAT_ARRAY_TYPE {
    $$ = new Node("Float_array", "", yylineno);
  }
  |
  VOID_TYPE {
    $$ = new Node("Void", "", yylineno);
  }

  ;

variable:
  VOLATILE ID COLON type ASSIGN math_expression {
        $$ = new Node("Variable", "", yylineno);
        $$->children.push_back(new Node("Volatile", "", yylineno));
        $$->children.push_back(new Node("Id", "", yylineno)); /*Change text?*/
        $$->children.push_back($4);
        $$->children.push_back($6);
  }
  |
  VOLATILE ID COLON type ASSIGN ID DOT LENGTH {
        $$ = new Node("Variable", "", yylineno);
        $$->children.push_back(new Node("Volatile", "", yylineno));
        $$->children.push_back(new Node("Id", "", yylineno)); /*Change text?*/
        $$->children.push_back($4);
  }
  |
  VOLATILE ID COLON type {
        $$ = new Node("Variable", "", yylineno);
        $$->children.push_back(new Node("Volatile", "", yylineno));
        $$->children.push_back(new Node("Id", "", yylineno)); /*Change text?*/
        $$->children.push_back(new Node("Type", "", yylineno));
  }
  |
  ID ASSIGN math_expression {
    $$ = new Node("reassign", "", yylineno);
    $$->children.push_back(new Node("Id", "", yylineno));
    $$->children.push_back($3);
  }
  ;


read:
  READ LP ID RP {
    $$ = new Node("Read", "", yylineno);
    $$->children.push_back(new Node("Id", "", yylineno)); 
  }
  ;

print:
  PRINT LP ID RP {
        $$ = new Node("Print", "", yylineno);
        $$->children.push_back(new Node("Id", "", yylineno));
  }
  |
  PRINT LP array_call RP {
    $$ = new Node("Print", "", yylineno);
    $$->children.push_back($3);
  }
  |
  PRINT LP ID DOT function_call RP {
    $$ = new Node("Print", "", yylineno);
    $$->children.push_back($5);
  }
  ;

return:
  RETURN math_expression {
    $$ = new Node("Return", "", yylineno);
    $$->children.push_back($2);
  }
  ;

block:
  LCB statements RCB {
    $$ = new Node("Block", "", yylineno);
    $$->children.push_back($2);
  }
  ;

main:
  MAIN LP RP COLON type block {
    $$ = new Node("main", "", yylineno);
    $$->children.push_back($5);
    $$->children.push_back($6);
  }
  ;

for_statement:
  FOR LP ID ASSIGN INT COMMA ID relational_operators math_expression COMMA ID ASSIGN math_expression RP block {
    $$ = new Node("for_loop", "", yylineno);
    
    Node * init = new Node("Int", "", yylineno);
    init->children.push_back(new Node("Id", "", yylineno));

    Node * rel_operator = $8;

    rel_operator->children.push_back(init);
    rel_operator->children.push_back($9);

    Node * assign = new Node("Assign", "", yylineno);
    
    assign->children.push_back(new Node("Id", "", yylineno));
    assign->children.push_back($13);

    $$->children.push_back(rel_operator);
    $$->children.push_back($15);
  }
  |
  FOR LP ID ASSIGN INT COMMA ID relational_operators ID DOT LENGTH COMMA ID ASSIGN math_expression RP block {
    $$ = new Node("for_loop", "", yylineno);
    $$->children.push_back(new Node("Id", "", yylineno));
    /*Continue here*/
  }
  ;

relational_operators:
  EQTO {
    $$ = new Node("Equal_To", "", yylineno);
  }
  |
  NEQ {
    $$ = new Node("Not_equal_to", "", yylineno);
  }
  |
  LE {
    $$ = new Node("Less_than_or_equal to", "", yylineno);
  }
  |
  GE {
    $$ = new Node("Greater_than_or_equal_To", "", yylineno);
  }
  |
  LT {
    $$ = new Node("Less_than", "", yylineno);
  }
  |
  GT {
    $$ = new Node("Greater_than", "", yylineno);
  }
  ;


  if_statement:
    IF LP math_expression relational_operators math_expression RP block {
      $$ = new Node("If", "", yylineno);
      
      Node * rel_operator = $4;

      rel_operator->children.push_back($3);
      rel_operator->children.push_back($5);

      $$->children.push_back(rel_operator);
      $$->children.push_back($7);
    }
  |
  
  IF LP array_call relational_operators array_call RP block {
    $$ = new Node("If", "", yylineno);
    
    Node * rel_operator = $4;

    rel_operator->children.push_back($3);
    rel_operator->children.push_back($5);

    $$->children.push_back(rel_operator);
    $$->children.push_back($7);
  }
  |
  IF LP math_expression relational_operators math_expression RP block ELSE block {
    $$ = new Node("If", "", yylineno);
    
    Node * rel_operator = $4;

    rel_operator->children.push_back($3);
    rel_operator->children.push_back($5);

    Node * el = new Node("else", "", yylineno);
    el->children.push_back($9);

    $$->children.push_back(rel_operator);
    $$->children.push_back($7);
  }
  ;

number_array:
  arithmetic_operators {
    $$ =$1;
  }
  |
  number_array COMMA arithmetic_operators {
    $$ = $3;
  }
  ;

array_decl:
  VOLATILE ID COLON type ASSIGN type SLB number_array SRB {
    $$ = new Node("Array", "", yylineno);

    Node * assign = new Node("Assign", "", yylineno);

    assign->children.push_back(new Node("Volatile", "", yylineno));
    assign->children.push_back(new Node("Id", "", yylineno));
    assign->children.push_back($4);

    Node * type_one = new Node("Type", "", yylineno);
    type_one->children.push_back($6);

    assign->children.push_back(type_one);

    $$->children.push_back(assign);
  }
  |
  ID COLON ID ASSIGN function_call {
    $$ = new Node("variable", "", yylineno);
    $$->children.push_back(new Node("Id", "", yylineno));
    $$->children.push_back(new Node("Id", "", yylineno));
    $$->children.push_back($5);
  }
  |
  ID ASSIGN ID SLB math_expression SRB {
    $$ = new Node("Assign", "", yylineno);
    $$->children.push_back(new Node("Id", "", yylineno));
    $$->children.push_back($5);
  }
  |
  ID SLB math_expression SRB ASSIGN ID SLB math_expression SRB {
    Node * listOne = new Node("Id", "", yylineno);
    listOne->children.push_back($3);
  
    Node * listTwo = new Node("Id", "", yylineno);  
    listTwo->children.push_back($8);

    $$ = new Node("Assign", "", yylineno);
    $$->children.push_back(listOne);
    $$->children.push_back(listTwo);
  }
  |
    ID SLB math_expression SRB ASSIGN ID {
    Node * list = new Node("Id", "", yylineno);
    list->children.push_back($3);
  
    $$ = new Node("Assign", "", yylineno);
    $$->children.push_back(list);
    $$->children.push_back(new Node("Id", "", yylineno));
  }

array_call:
  ID SLB math_expression SRB {
    $$ = new Node("Array", "", yylineno);
    $$->children.push_back(new Node("Id", "", yylineno));
    $$->children.push_back($3);
  }
  ;

comment:
  COMMENT {
    $$ = new Node("Comment", "", yylineno);
  }
  ;

class:
  CLASS ID block {
    $$ = new Node("Class", "", yylineno);
    $$->children.push_back(new Node("Id", "", yylineno));
    $$->children.push_back($3);
  }
  ;

function_decl:
  ID LP parameters RP COLON type block {
    $$ = new Node("function_Decl", "", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($6);
    $$->children.push_back($7);
  }
  |
  ID LP RP COLON type block {
    $$ = new Node("function_Decl", "", yylineno);
    $$->children.push_back($5);
    $$->children.push_back($6); 
  }
  ;

function_call:
  ID LP math_expression RP {
    $$ = new Node("get_function", "", yylineno);
    $$->children.push_back($3);
  }
  |
  ID LP RP {
    $$ = new Node("get_function", "", yylineno);
  }
;

parameters: 
  ID COLON type {
    $$ = new Node("parameters", "", yylineno);
    Node * t = $3;
    t->children.push_back(new Node("Id", "", yylineno));

    $$->children.push_back(t);
  }
  |
  parameters COMMA ID COLON type {
    $$ = $1;

    Node * t = $5;
    t->children.push_back(new Node("Id", "", yylineno));

    $$->children.push_back(t);
  }
  ;
    

/* ./compiler < test_files/valid/test1.cpm */

