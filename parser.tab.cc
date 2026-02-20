// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 16 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;

#line 54 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 127 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_relation: // relation
      case symbol_kind::S_math_expression: // math_expression
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_type: // type
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_read: // read
      case symbol_kind::S_print: // print
      case symbol_kind::S_return: // return
      case symbol_kind::S_block: // block
      case symbol_kind::S_main: // main
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_relational_operators: // relational_operators
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_else_statement: // else_statement
      case symbol_kind::S_number_array: // number_array
      case symbol_kind::S_array_decl: // array_decl
      case symbol_kind::S_array_call: // array_call
      case symbol_kind::S_comment: // comment
      case symbol_kind::S_class: // class
      case symbol_kind::S_function_decl: // function_decl
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_arguments: // arguments
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWER: // POWER
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQTO: // EQTO
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_SLB: // SLB
      case symbol_kind::S_SRB: // SRB
      case symbol_kind::S_COMMENT: // COMMENT
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_INT_ARRAY_TYPE: // INT_ARRAY_TYPE
      case symbol_kind::S_FLOAT_ARRAY_TYPE: // FLOAT_ARRAY_TYPE
      case symbol_kind::S_VOID_TYPE: // VOID_TYPE
      case symbol_kind::S_BOOLEAN_TYPE: // BOOLEAN_TYPE
      case symbol_kind::S_EXCLAMATION_MARK: // EXCLAMATION_MARK
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_relation: // relation
      case symbol_kind::S_math_expression: // math_expression
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_type: // type
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_read: // read
      case symbol_kind::S_print: // print
      case symbol_kind::S_return: // return
      case symbol_kind::S_block: // block
      case symbol_kind::S_main: // main
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_relational_operators: // relational_operators
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_else_statement: // else_statement
      case symbol_kind::S_number_array: // number_array
      case symbol_kind::S_array_decl: // array_decl
      case symbol_kind::S_array_call: // array_call
      case symbol_kind::S_comment: // comment
      case symbol_kind::S_class: // class
      case symbol_kind::S_function_decl: // function_decl
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_arguments: // arguments
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWER: // POWER
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQTO: // EQTO
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_SLB: // SLB
      case symbol_kind::S_SRB: // SRB
      case symbol_kind::S_COMMENT: // COMMENT
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_INT_ARRAY_TYPE: // INT_ARRAY_TYPE
      case symbol_kind::S_FLOAT_ARRAY_TYPE: // FLOAT_ARRAY_TYPE
      case symbol_kind::S_VOID_TYPE: // VOID_TYPE
      case symbol_kind::S_BOOLEAN_TYPE: // BOOLEAN_TYPE
      case symbol_kind::S_EXCLAMATION_MARK: // EXCLAMATION_MARK
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_relation: // relation
      case symbol_kind::S_math_expression: // math_expression
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_type: // type
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_read: // read
      case symbol_kind::S_print: // print
      case symbol_kind::S_return: // return
      case symbol_kind::S_block: // block
      case symbol_kind::S_main: // main
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_relational_operators: // relational_operators
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_else_statement: // else_statement
      case symbol_kind::S_number_array: // number_array
      case symbol_kind::S_array_decl: // array_decl
      case symbol_kind::S_array_call: // array_call
      case symbol_kind::S_comment: // comment
      case symbol_kind::S_class: // class
      case symbol_kind::S_function_decl: // function_decl
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_arguments: // arguments
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWER: // POWER
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQTO: // EQTO
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_SLB: // SLB
      case symbol_kind::S_SRB: // SRB
      case symbol_kind::S_COMMENT: // COMMENT
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_INT_ARRAY_TYPE: // INT_ARRAY_TYPE
      case symbol_kind::S_FLOAT_ARRAY_TYPE: // FLOAT_ARRAY_TYPE
      case symbol_kind::S_VOID_TYPE: // VOID_TYPE
      case symbol_kind::S_BOOLEAN_TYPE: // BOOLEAN_TYPE
      case symbol_kind::S_EXCLAMATION_MARK: // EXCLAMATION_MARK
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_relation: // relation
      case symbol_kind::S_math_expression: // math_expression
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_type: // type
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_read: // read
      case symbol_kind::S_print: // print
      case symbol_kind::S_return: // return
      case symbol_kind::S_block: // block
      case symbol_kind::S_main: // main
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_relational_operators: // relational_operators
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_else_statement: // else_statement
      case symbol_kind::S_number_array: // number_array
      case symbol_kind::S_array_decl: // array_decl
      case symbol_kind::S_array_call: // array_call
      case symbol_kind::S_comment: // comment
      case symbol_kind::S_class: // class
      case symbol_kind::S_function_decl: // function_decl
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_arguments: // arguments
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWER: // POWER
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQTO: // EQTO
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_SLB: // SLB
      case symbol_kind::S_SRB: // SRB
      case symbol_kind::S_COMMENT: // COMMENT
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_INT_ARRAY_TYPE: // INT_ARRAY_TYPE
      case symbol_kind::S_FLOAT_ARRAY_TYPE: // FLOAT_ARRAY_TYPE
      case symbol_kind::S_VOID_TYPE: // VOID_TYPE
      case symbol_kind::S_BOOLEAN_TYPE: // BOOLEAN_TYPE
      case symbol_kind::S_EXCLAMATION_MARK: // EXCLAMATION_MARK
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_relation: // relation
      case symbol_kind::S_math_expression: // math_expression
      case symbol_kind::S_term: // term
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_unary: // unary
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_type: // type
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_read: // read
      case symbol_kind::S_print: // print
      case symbol_kind::S_return: // return
      case symbol_kind::S_block: // block
      case symbol_kind::S_main: // main
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_relational_operators: // relational_operators
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_else_statement: // else_statement
      case symbol_kind::S_number_array: // number_array
      case symbol_kind::S_array_decl: // array_decl
      case symbol_kind::S_array_call: // array_call
      case symbol_kind::S_comment: // comment
      case symbol_kind::S_class: // class
      case symbol_kind::S_function_decl: // function_decl
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_arguments: // arguments
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_POWER: // POWER
      case symbol_kind::S_FLOAT_TYPE: // FLOAT_TYPE
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_VOLATILE: // VOLATILE
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQTO: // EQTO
      case symbol_kind::S_NEQ: // NEQ
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_SLB: // SLB
      case symbol_kind::S_SRB: // SRB
      case symbol_kind::S_COMMENT: // COMMENT
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_INT_ARRAY_TYPE: // INT_ARRAY_TYPE
      case symbol_kind::S_FLOAT_ARRAY_TYPE: // FLOAT_ARRAY_TYPE
      case symbol_kind::S_VOID_TYPE: // VOID_TYPE
      case symbol_kind::S_BOOLEAN_TYPE: // BOOLEAN_TYPE
      case symbol_kind::S_EXCLAMATION_MARK: // EXCLAMATION_MARK
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: statements
#line 51 "parser.yy"
             {
    root = yystack_[0].value.as < Node * > ();
}
#line 930 "parser.tab.cc"
    break;

  case 3: // statements: %empty
#line 56 "parser.yy"
         {
      yylhs.value.as < Node * > () = new Node("Statements", "", yylineno);
    }
#line 938 "parser.tab.cc"
    break;

  case 4: // statements: statements expression
#line 60 "parser.yy"
                        {
      yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 947 "parser.tab.cc"
    break;

  case 5: // expression: variable
#line 67 "parser.yy"
           {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 955 "parser.tab.cc"
    break;

  case 6: // expression: read
#line 71 "parser.yy"
       {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); 
  }
#line 963 "parser.tab.cc"
    break;

  case 7: // expression: print
#line 75 "parser.yy"
        {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 971 "parser.tab.cc"
    break;

  case 8: // expression: block
#line 79 "parser.yy"
        {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 979 "parser.tab.cc"
    break;

  case 9: // expression: main
#line 83 "parser.yy"
       {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 987 "parser.tab.cc"
    break;

  case 10: // expression: for_statement
#line 87 "parser.yy"
                {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 995 "parser.tab.cc"
    break;

  case 11: // expression: if_statement
#line 91 "parser.yy"
               {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1003 "parser.tab.cc"
    break;

  case 12: // expression: array_decl
#line 95 "parser.yy"
             {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1011 "parser.tab.cc"
    break;

  case 13: // expression: comment
#line 99 "parser.yy"
          {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1019 "parser.tab.cc"
    break;

  case 14: // expression: return
#line 103 "parser.yy"
         {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1027 "parser.tab.cc"
    break;

  case 15: // expression: class
#line 107 "parser.yy"
        {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1035 "parser.tab.cc"
    break;

  case 16: // expression: function_decl
#line 111 "parser.yy"
                {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1043 "parser.tab.cc"
    break;

  case 17: // expression: function_call
#line 115 "parser.yy"
                {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1051 "parser.tab.cc"
    break;

  case 18: // expression: else_statement
#line 119 "parser.yy"
                 {
    yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
  }
#line 1059 "parser.tab.cc"
    break;

  case 19: // condition: condition OR condition
#line 124 "parser.yy"
                           {
      yylhs.value.as < Node * > () = new Node("Or", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1069 "parser.tab.cc"
    break;

  case 20: // condition: condition AND condition
#line 129 "parser.yy"
                            {
      yylhs.value.as < Node * > () = new Node("And", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1079 "parser.tab.cc"
    break;

  case 21: // condition: EXCLAMATION_MARK condition
#line 134 "parser.yy"
                               {
      yylhs.value.as < Node * > () = new Node("Not", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1088 "parser.tab.cc"
    break;

  case 22: // condition: LP condition RP
#line 138 "parser.yy"
                    {
      yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    }
#line 1096 "parser.tab.cc"
    break;

  case 23: // condition: relation
#line 141 "parser.yy"
             {
      yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
    }
#line 1104 "parser.tab.cc"
    break;

  case 24: // condition: TRUE
#line 144 "parser.yy"
         {
      yylhs.value.as < Node * > () = new Node("Boolean", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(new Node("", yystack_[0].value.as < std::string > (), yylineno));
    }
#line 1113 "parser.tab.cc"
    break;

  case 25: // condition: FALSE
#line 148 "parser.yy"
          {
      yylhs.value.as < Node * > () = new Node("Boolean", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(new Node("", yystack_[0].value.as < std::string > (), yylineno));
    }
#line 1122 "parser.tab.cc"
    break;

  case 26: // relation: math_expression relational_operators math_expression
#line 155 "parser.yy"
                                                         {
      Node *op = yystack_[1].value.as < Node * > ();
      op->children.push_back(yystack_[2].value.as < Node * > ());
      op->children.push_back(yystack_[0].value.as < Node * > ());
      yylhs.value.as < Node * > () = op;
    }
#line 1133 "parser.tab.cc"
    break;

  case 27: // math_expression: math_expression PLUSOP term
#line 164 "parser.yy"
                                  {
          yylhs.value.as < Node * > () = new Node("Add","",yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1143 "parser.tab.cc"
    break;

  case 28: // math_expression: math_expression MINUSOP term
#line 169 "parser.yy"
                                   {
          yylhs.value.as < Node * > () = new Node("Sub","",yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1153 "parser.tab.cc"
    break;

  case 29: // math_expression: term
#line 174 "parser.yy"
           {
          yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
      }
#line 1161 "parser.tab.cc"
    break;

  case 30: // term: term MULTOP factor
#line 180 "parser.yy"
                         {
          yylhs.value.as < Node * > () = new Node("Multiplication", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1171 "parser.tab.cc"
    break;

  case 31: // term: term DIVOP factor
#line 185 "parser.yy"
                        {
          yylhs.value.as < Node * > () = new Node("Division","",yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1181 "parser.tab.cc"
    break;

  case 32: // term: factor
#line 190 "parser.yy"
             {
          yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
      }
#line 1189 "parser.tab.cc"
    break;

  case 33: // factor: unary
#line 196 "parser.yy"
            {
          yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
      }
#line 1197 "parser.tab.cc"
    break;

  case 34: // factor: unary POWER factor
#line 199 "parser.yy"
                         {
          yylhs.value.as < Node * > () = new Node("Pow","",yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1207 "parser.tab.cc"
    break;

  case 35: // unary: MINUSOP unary
#line 207 "parser.yy"
                    {
          yylhs.value.as < Node * > () = new Node("Negate", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1216 "parser.tab.cc"
    break;

  case 36: // unary: primary
#line 211 "parser.yy"
              {
          yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
      }
#line 1224 "parser.tab.cc"
    break;

  case 37: // primary: ID
#line 218 "parser.yy"
         {
          Node * identifier = new Node("Identifier", "", yylineno);
          identifier->children.push_back(new Node("", yystack_[0].value.as < std::string > (), yylineno));
          yylhs.value.as < Node * > () = identifier;
      }
#line 1234 "parser.tab.cc"
    break;

  case 38: // primary: INT
#line 223 "parser.yy"
          {
          yylhs.value.as < Node * > () = new Node("Integer", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(new Node("", yystack_[0].value.as < std::string > (), yylineno));
      }
#line 1243 "parser.tab.cc"
    break;

  case 39: // primary: FLOAT
#line 227 "parser.yy"
            {
          yylhs.value.as < Node * > () = new Node("Float", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(new Node("", yystack_[0].value.as < std::string > (), yylineno));
      }
#line 1252 "parser.tab.cc"
    break;

  case 40: // primary: function_call
#line 231 "parser.yy"
                    {
          yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
      }
#line 1260 "parser.tab.cc"
    break;

  case 41: // primary: array_call
#line 234 "parser.yy"
                 {
          yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
      }
#line 1268 "parser.tab.cc"
    break;

  case 42: // primary: LP math_expression RP
#line 237 "parser.yy"
                            {
          yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
      }
#line 1276 "parser.tab.cc"
    break;

  case 43: // type: INT_TYPE
#line 245 "parser.yy"
           {
    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("Integer", "", yylineno));
    yylhs.value.as < Node * > () = type;
  }
#line 1286 "parser.tab.cc"
    break;

  case 44: // type: FLOAT_TYPE
#line 251 "parser.yy"
             {
    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("Float", "", yylineno));
    yylhs.value.as < Node * > () = type;
  }
#line 1296 "parser.tab.cc"
    break;

  case 45: // type: INT_ARRAY_TYPE
#line 257 "parser.yy"
                 {
    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("Integer_array", "", yylineno));
    yylhs.value.as < Node * > () = type;
  }
#line 1306 "parser.tab.cc"
    break;

  case 46: // type: FLOAT_ARRAY_TYPE
#line 263 "parser.yy"
                   {
    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("Float_array", "", yylineno));
    yylhs.value.as < Node * > () = type;
  }
#line 1316 "parser.tab.cc"
    break;

  case 47: // type: VOID_TYPE
#line 269 "parser.yy"
            {
    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("Void", "", yylineno));
    yylhs.value.as < Node * > () = type;
  }
#line 1326 "parser.tab.cc"
    break;

  case 48: // type: BOOLEAN_TYPE
#line 275 "parser.yy"
               {
    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("Boolean", "", yylineno));
    yylhs.value.as < Node * > () = type;
  }
#line 1336 "parser.tab.cc"
    break;

  case 49: // variable: VOLATILE ID COLON type ASSIGN math_expression
#line 283 "parser.yy"
                                                {
    yylhs.value.as < Node * > () = new Node("VarDecl", "", yylineno);

    Node * modifier = new Node("Modifier", "", yylineno);
    modifier->children.push_back(new Node("Volatile", "", yylineno));


    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[4].value.as < std::string > (), yylineno));
    
     yylhs.value.as < Node * > ()->children.push_back(modifier);
     yylhs.value.as < Node * > ()->children.push_back(identifier);
     yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
     yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    
  }
#line 1357 "parser.tab.cc"
    break;

  case 50: // variable: VOLATILE ID COLON type
#line 300 "parser.yy"
                         {

    yylhs.value.as < Node * > () = new Node("VarDecl", "", yylineno);

    Node * modifier = new Node("Modifier", "", yylineno);
    modifier->children.push_back(new Node("Volatile", "", yylineno));

    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[2].value.as < std::string > (), yylineno));

     yylhs.value.as < Node * > ()->children.push_back(modifier);
     yylhs.value.as < Node * > ()->children.push_back(identifier);
     yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

  }
#line 1377 "parser.tab.cc"
    break;

  case 51: // variable: VOLATILE ID COLON type ASSIGN ID LP RP DOT function_call
#line 316 "parser.yy"
                                                           {
    yylhs.value.as < Node * > () = new Node("Variable", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Volatile", "", yylineno));
    yylhs.value.as < Node * > ()->children.push_back(new Node("Id", "", yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1389 "parser.tab.cc"
    break;

  case 52: // variable: VOLATILE ID COLON ID ASSIGN function_call
#line 324 "parser.yy"
                                            {
    yylhs.value.as < Node * > () = new Node("Variaasasdasdble", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Volatile", "", yylineno));
    yylhs.value.as < Node * > ()->children.push_back(new Node("Id", "", yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1400 "parser.tab.cc"
    break;

  case 53: // variable: ID DOT function_call
#line 331 "parser.yy"
                       {
    yylhs.value.as < Node * > () = new Node("Id", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1409 "parser.tab.cc"
    break;

  case 54: // variable: ID ASSIGN math_expression
#line 336 "parser.yy"
                            {
    yylhs.value.as < Node * > () = new Node("Re_assign", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[2].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(identifier);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1421 "parser.tab.cc"
    break;

  case 55: // variable: VOLATILE ID COLON type ASSIGN ID DOT function_call
#line 344 "parser.yy"
                                                     {
    yylhs.value.as < Node * > () = new Node("Variable", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Id", "", yylineno));
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
  }
#line 1431 "parser.tab.cc"
    break;

  case 56: // variable: ID ASSIGN condition
#line 350 "parser.yy"
                      {
    yylhs.value.as < Node * > () = new Node("Re_assign", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[2].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(identifier);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1443 "parser.tab.cc"
    break;

  case 57: // read: READ LP ID RP
#line 360 "parser.yy"
                {
    yylhs.value.as < Node * > () = new Node("Read", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Id", "", yylineno)); 
  }
#line 1452 "parser.tab.cc"
    break;

  case 58: // print: PRINT LP math_expression RP
#line 367 "parser.yy"
                              {
    yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1461 "parser.tab.cc"
    break;

  case 59: // print: PRINT LP ID DOT function_call RP
#line 372 "parser.yy"
                                   {
    yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1470 "parser.tab.cc"
    break;

  case 60: // print: PRINT LP ID LP RP DOT function_call RP
#line 377 "parser.yy"
                                         {
    yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
    Node * class_func_call = new Node("Id", "", yylineno);
    class_func_call->children.push_back(new Node("Dot", "", yylineno));
    class_func_call->children.push_back(yystack_[1].value.as < Node * > ());

    yylhs.value.as < Node * > ()->children.push_back(class_func_call);
    
  }
#line 1484 "parser.tab.cc"
    break;

  case 61: // return: RETURN math_expression
#line 389 "parser.yy"
                         {
    yylhs.value.as < Node * > () = new Node("Return", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1493 "parser.tab.cc"
    break;

  case 62: // block: LCB statements RCB
#line 396 "parser.yy"
                     {
    yylhs.value.as < Node * > () = new Node("Block", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1502 "parser.tab.cc"
    break;

  case 63: // block: BREAK
#line 401 "parser.yy"
        {
    yylhs.value.as < Node * > () = new Node("Break", "", yylineno); 
  }
#line 1510 "parser.tab.cc"
    break;

  case 64: // block: CONTINUE
#line 405 "parser.yy"
           {
    yylhs.value.as < Node * > () = new Node("Continue", "", yylineno);
  }
#line 1518 "parser.tab.cc"
    break;

  case 65: // main: MAIN LP RP COLON type block
#line 411 "parser.yy"
                              {
    yylhs.value.as < Node * > () = new Node("main_function", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1528 "parser.tab.cc"
    break;

  case 66: // for_statement: FOR LP COMMA condition COMMA ID ASSIGN math_expression RP block
#line 419 "parser.yy"
                                                                  {
    yylhs.value.as < Node * > () = new Node("for_loop", "", yylineno);

    // init (tom)
    Node * init = new Node("Init", "", yylineno);
    init->children.push_back(new Node("(Empty)", "", yylineno));

    // condition
    Node * cond = yystack_[6].value.as < Node * > ();

    // update
    Node * update = new Node("Update", "", yylineno);
    Node * id = new Node("Identifier", "", yylineno);
    id->children.push_back(new Node("", yystack_[4].value.as < std::string > (), yylineno));
    update->children.push_back(id);
    update->children.push_back(yystack_[2].value.as < Node * > ());

    // body
    Node * body = yystack_[0].value.as < Node * > ();

    yylhs.value.as < Node * > ()->children.push_back(init);
    yylhs.value.as < Node * > ()->children.push_back(cond);
    yylhs.value.as < Node * > ()->children.push_back(update);
    yylhs.value.as < Node * > ()->children.push_back(body);
  }
#line 1558 "parser.tab.cc"
    break;

  case 67: // for_statement: FOR LP COMMA math_expression COMMA ID ASSIGN math_expression RP block
#line 445 "parser.yy"
                                                                        {
    yylhs.value.as < Node * > () = new Node("for_loop", "", yylineno);

    // init (tom)
    Node * init = new Node("Init", "", yylineno);
    init->children.push_back(new Node("(Empty)", "", yylineno));

    // condition
    Node * cond = yystack_[6].value.as < Node * > ();

    // update
    Node * update = new Node("Update", "", yylineno);
    Node * id = new Node("Identifier", "", yylineno);
    id->children.push_back(new Node("", yystack_[4].value.as < std::string > (), yylineno));
    update->children.push_back(id);
    update->children.push_back(yystack_[2].value.as < Node * > ());

    // body
    Node * body = yystack_[0].value.as < Node * > ();

    yylhs.value.as < Node * > ()->children.push_back(init);
    yylhs.value.as < Node * > ()->children.push_back(cond);
    yylhs.value.as < Node * > ()->children.push_back(update);
    yylhs.value.as < Node * > ()->children.push_back(body);
  }
#line 1588 "parser.tab.cc"
    break;

  case 68: // for_statement: FOR LP ID ASSIGN math_expression COMMA condition relational_operators math_expression COMMA ID ASSIGN math_expression RP block
#line 471 "parser.yy"
                                                                                                                                 {
    yylhs.value.as < Node * > () = new Node("for_loop", "", yylineno);

    Node * variable = new Node("VarDecl", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[12].value.as < std::string > (), yylineno));
    variable->children.push_back(identifier);
    variable->children.push_back(yystack_[10].value.as < Node * > ());


    Node * logicalCondition = new Node("Logical_condition", "", yylineno);
    Node * condition = yystack_[7].value.as < Node * > ();

    condition->children.push_back(yystack_[8].value.as < Node * > ());
    condition->children.push_back(yystack_[6].value.as < Node * > ());
    logicalCondition->children.push_back(condition);


    Node * variableTwo = new Node("Expression", "", yylineno);
    variableTwo->children.push_back(yystack_[2].value.as < Node * > ());



    yylhs.value.as < Node * > ()->children.push_back(variable);
    yylhs.value.as < Node * > ()->children.push_back(logicalCondition);
    yylhs.value.as < Node * > ()->children.push_back(variableTwo);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1621 "parser.tab.cc"
    break;

  case 69: // relational_operators: EQTO
#line 502 "parser.yy"
       {
    yylhs.value.as < Node * > () = new Node("", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1629 "parser.tab.cc"
    break;

  case 70: // relational_operators: NEQ
#line 506 "parser.yy"
      {
    yylhs.value.as < Node * > () = new Node("", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1637 "parser.tab.cc"
    break;

  case 71: // relational_operators: LE
#line 510 "parser.yy"
     {
    yylhs.value.as < Node * > () = new Node("", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1645 "parser.tab.cc"
    break;

  case 72: // relational_operators: GE
#line 514 "parser.yy"
     {
    yylhs.value.as < Node * > () = new Node("", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1653 "parser.tab.cc"
    break;

  case 73: // relational_operators: LT
#line 518 "parser.yy"
     {
    yylhs.value.as < Node * > () = new Node("", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1661 "parser.tab.cc"
    break;

  case 74: // relational_operators: GT
#line 522 "parser.yy"
     {
    yylhs.value.as < Node * > () = new Node("", yystack_[0].value.as < std::string > (), yylineno);
  }
#line 1669 "parser.tab.cc"
    break;

  case 75: // if_statement: IF LP condition RP block
#line 528 "parser.yy"
                             {
      yylhs.value.as < Node * > () = new Node("If_statement", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1679 "parser.tab.cc"
    break;

  case 76: // if_statement: IF LP condition relational_operators condition RP block
#line 534 "parser.yy"
                                                            {
      yylhs.value.as < Node * > () = new Node("If_statement", "", yylineno);

      Node * logicalCondition = new Node("Logical_condition", "", yylineno);
      Node * condition = yystack_[3].value.as < Node * > ();

      condition->children.push_back(yystack_[4].value.as < Node * > ());
      condition->children.push_back(yystack_[2].value.as < Node * > ());
      logicalCondition->children.push_back(condition);

      yylhs.value.as < Node * > ()->children.push_back(logicalCondition);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      
    }
#line 1698 "parser.tab.cc"
    break;

  case 77: // else_statement: ELSE block
#line 552 "parser.yy"
               {
      yylhs.value.as < Node * > () = new Node("Else_statement", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1707 "parser.tab.cc"
    break;

  case 78: // else_statement: ELSE variable
#line 557 "parser.yy"
                  {
      yylhs.value.as < Node * > () = new Node("Else", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1716 "parser.tab.cc"
    break;

  case 79: // number_array: primary
#line 564 "parser.yy"
          {
    Node * arrayLiteral = new Node("Array_literal", "", yylineno);
    yylhs.value.as < Node * > () = arrayLiteral;
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1726 "parser.tab.cc"
    break;

  case 80: // number_array: number_array COMMA primary
#line 570 "parser.yy"
                             {
    yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1735 "parser.tab.cc"
    break;

  case 81: // array_decl: VOLATILE ID COLON type ASSIGN type SLB number_array SRB
#line 577 "parser.yy"
                                                          {

    yylhs.value.as < Node * > () = new Node("ArrayDecl", "", yylineno);

    Node * modifier = new Node("Modifier", "", yylineno);
    modifier->children.push_back(new Node("Volatile", "", yylineno));

    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[7].value.as < std::string > (), yylineno));    

    yylhs.value.as < Node * > ()->children.push_back(modifier);
    yylhs.value.as < Node * > ()->children.push_back(identifier);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1755 "parser.tab.cc"
    break;

  case 82: // array_decl: ID ASSIGN type SLB number_array SRB
#line 593 "parser.yy"
                                      {
    yylhs.value.as < Node * > () = new Node("Assgin", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(new Node("Id", "", yylineno));
    Node * array = yystack_[3].value.as < Node * > ();
    array->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(array);
  }
#line 1767 "parser.tab.cc"
    break;

  case 83: // array_decl: ID SLB math_expression SRB ASSIGN ID SLB math_expression SRB
#line 601 "parser.yy"
                                                               {
    yylhs.value.as < Node * > () = new Node("Re_assign", "", yylineno);
    
    Node * arrayOne = new Node("Array", "", yylineno);
    Node * identifierOne = new Node("Identifier", "", yylineno);
    Node * idOne = new Node("", yystack_[8].value.as < std::string > (), yylineno);
    identifierOne->children.push_back(idOne);
    Node * indexOne = new Node("index", "", yylineno);
    indexOne->children.push_back(yystack_[6].value.as < Node * > ());

    arrayOne->children.push_back(identifierOne);
    arrayOne->children.push_back(indexOne);


    Node * arrayTwo = new Node("Array", "", yylineno);

    Node * identifierTwo = new Node("Identifier", "", yylineno);
    Node * idTwo = new Node("", yystack_[3].value.as < std::string > (), yylineno);
    identifierTwo->children.push_back(idTwo);
    Node * indexTwo = new Node("index", "", yylineno);
    indexTwo->children.push_back(yystack_[1].value.as < Node * > ());

    arrayTwo->children.push_back(identifierTwo);
    arrayTwo->children.push_back(indexTwo);

    yylhs.value.as < Node * > ()->children.push_back(arrayOne);
    yylhs.value.as < Node * > ()->children.push_back(arrayTwo);
  }
#line 1800 "parser.tab.cc"
    break;

  case 84: // array_decl: ID SLB math_expression SRB ASSIGN ID
#line 630 "parser.yy"
                                       {
    yylhs.value.as < Node * > () = new Node("Re_assign", "", yylineno);
    
    Node * arrayOne = new Node("Array", "", yylineno);
    Node * identifierOne = new Node("Identifier", "", yylineno);
    Node * idOne = new Node("", yystack_[5].value.as < std::string > (), yylineno);
    identifierOne->children.push_back(idOne);
    Node * indexOne = new Node("index", "", yylineno);
    indexOne->children.push_back(yystack_[3].value.as < Node * > ());

    arrayOne->children.push_back(identifierOne);
    arrayOne->children.push_back(indexOne);


    Node * identifierTwo = new Node("Identifier", "", yylineno);
    Node * idTwo = new Node("", yystack_[0].value.as < std::string > (), yylineno);

    identifierTwo->children.push_back(idTwo);

    yylhs.value.as < Node * > ()->children.push_back(arrayOne);
    yylhs.value.as < Node * > ()->children.push_back(identifierTwo);
  }
#line 1827 "parser.tab.cc"
    break;

  case 85: // array_call: ID SLB math_expression SRB
#line 654 "parser.yy"
                             {
    yylhs.value.as < Node * > () = new Node("Array", "", yylineno);
    
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[3].value.as < std::string > (), yylineno));

    Node * index = new Node("Index", "", yylineno);
    index->children.push_back(yystack_[1].value.as < Node * > ());

    yylhs.value.as < Node * > ()->children.push_back(identifier);
    yylhs.value.as < Node * > ()->children.push_back(index);
  }
#line 1844 "parser.tab.cc"
    break;

  case 86: // array_call: ID DOT LENGTH
#line 667 "parser.yy"
                {
    yylhs.value.as < Node * > () = new Node("Array", "", yylineno);
    Node * member_access = new Node("Member_access", "", yylineno);

    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[2].value.as < std::string > (), yylineno));

    member_access->children.push_back(identifier);
    member_access->children.push_back(new Node("Length", "", yylineno));

    yylhs.value.as < Node * > ()->children.push_back(member_access);
  }
#line 1861 "parser.tab.cc"
    break;

  case 87: // comment: COMMENT
#line 682 "parser.yy"
          {
    yylhs.value.as < Node * > () = new Node("Comment", "", yylineno);
  }
#line 1869 "parser.tab.cc"
    break;

  case 88: // class: CLASS ID block
#line 688 "parser.yy"
                 {
    yylhs.value.as < Node * > () = new Node("Class", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[1].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(identifier);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1881 "parser.tab.cc"
    break;

  case 89: // class: ID COLON ID ASSIGN ID LP RP
#line 696 "parser.yy"
                              {
    yylhs.value.as < Node * > () = new Node("VarDec", "", yylineno);

    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[6].value.as < std::string > (), yylineno));

    Node * type = new Node("Type", "", yylineno);
    type->children.push_back(new Node("", yystack_[4].value.as < std::string > (), yylineno));

    Node * classs = new Node("Class", "", yylineno);
    classs->children.push_back(new Node("", yystack_[2].value.as < std::string > (), yylineno));

    yylhs.value.as < Node * > ()->children.push_back(identifier);
    yylhs.value.as < Node * > ()->children.push_back(type);
    yylhs.value.as < Node * > ()->children.push_back(classs);
  
  }
#line 1903 "parser.tab.cc"
    break;

  case 90: // function_decl: ID LP parameters RP COLON type block
#line 716 "parser.yy"
                                       {
    yylhs.value.as < Node * > () = new Node("function_Decl", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[6].value.as < std::string > (), yylineno));

    Node * returnType = new Node("Return_type", "", yylineno);
    returnType->children.push_back(yystack_[1].value.as < Node * > ());


    yylhs.value.as < Node * > ()->children.push_back(identifier);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(returnType);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1922 "parser.tab.cc"
    break;

  case 91: // function_decl: ID LP RP COLON type block
#line 731 "parser.yy"
                            {
    yylhs.value.as < Node * > () = new Node("function_Decl", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
  }
#line 1932 "parser.tab.cc"
    break;

  case 92: // function_call: ID LP arguments RP
#line 739 "parser.yy"
                     {
    yylhs.value.as < Node * > () = new Node("function_call", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[3].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(identifier);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1944 "parser.tab.cc"
    break;

  case 93: // function_call: ID LP RP
#line 747 "parser.yy"
           {
    yylhs.value.as < Node * > () = new Node("function_call", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[2].value.as < std::string > (), yylineno));
    yylhs.value.as < Node * > ()->children.push_back(identifier);
  }
#line 1955 "parser.tab.cc"
    break;

  case 94: // parameters: ID COLON type
#line 756 "parser.yy"
                {
    yylhs.value.as < Node * > () = new Node("parameters", "", yylineno);

    Node * parameter = new Node("Parameter", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[2].value.as < std::string > (), yylineno));

    parameter->children.push_back(identifier);
    parameter->children.push_back(yystack_[0].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(parameter);
  }
#line 1971 "parser.tab.cc"
    break;

  case 95: // parameters: parameters COMMA ID COLON type
#line 768 "parser.yy"
                                 {

    yylhs.value.as < Node * > () = yystack_[4].value.as < Node * > ();

    Node * parameter = new Node("Parameter", "", yylineno);
    Node * identifier = new Node("Identifier", "", yylineno);
    identifier->children.push_back(new Node("", yystack_[2].value.as < std::string > (), yylineno));

    parameter->children.push_back(identifier);
    parameter->children.push_back(yystack_[0].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(parameter);
  }
#line 1988 "parser.tab.cc"
    break;

  case 96: // arguments: math_expression
#line 783 "parser.yy"
                    {
      yylhs.value.as < Node * > () = new Node("Arguments", "", yylineno);

      Node * argument = new Node("argument", "", yylineno);
      argument->children.push_back(yystack_[0].value.as < Node * > ());   
      yylhs.value.as < Node * > ()->children.push_back(argument);
    }
#line 2000 "parser.tab.cc"
    break;

  case 97: // arguments: arguments COMMA math_expression
#line 791 "parser.yy"
                                    {
      yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();

      Node * argument = new Node("argument", "", yylineno);
      argument->children.push_back(yystack_[0].value.as < Node * > ());   
      yylhs.value.as < Node * > ()->children.push_back(argument);
    }
#line 2012 "parser.tab.cc"
    break;


#line 2016 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -125;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
    -125,    49,   248,  -125,    41,    64,   323,    15,  -125,    57,
     112,   149,  -125,   136,   151,     9,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,    -2,   284,   152,   207,   323,   155,   323,
    -125,   323,  -125,    14,    86,     7,  -125,   148,  -125,  -125,
    -125,   330,   223,   171,   118,     4,   -11,   170,   197,    68,
    -125,  -125,    21,   208,    72,    86,    76,    84,   201,     4,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,     4,   168,
    -125,   133,   153,    22,   216,  -125,  -125,    12,   296,   323,
     185,   323,   323,   323,   323,   323,    71,   232,  -125,   210,
     222,     4,   202,   133,  -125,   239,   241,     4,   231,   252,
      30,    30,   242,   250,  -125,   323,   261,   158,   174,  -125,
       4,     4,  -125,  -125,  -125,  -125,  -125,  -125,   323,   268,
     262,  -125,  -125,    37,  -125,     7,     7,  -125,  -125,  -125,
     306,    -8,  -125,    30,   323,   106,   144,   -11,     4,  -125,
      21,   155,   108,   -11,  -125,    30,   264,    86,   271,  -125,
    -125,   257,    86,  -125,    67,   272,  -125,   255,   287,   -11,
     121,   281,   286,  -125,   172,   289,  -125,    79,    86,   273,
    -125,   -11,    30,   300,   268,  -125,   275,   155,  -125,  -125,
       4,   299,   301,   -11,   337,   316,    -8,   268,  -125,  -125,
    -125,  -125,   323,   309,   328,   323,   323,  -125,   280,  -125,
      92,    58,  -125,   323,   358,   360,   155,  -125,  -125,   125,
     -11,   -11,  -125,   311,  -125,  -125,   318,   323,   366,   -11,
    -125
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,     2,     1,     0,     0,     0,     0,     3,     0,
       0,     0,    87,     0,     0,     0,    63,    64,     4,     5,
       6,     7,    14,     8,     9,    10,    11,    18,    12,    13,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
      38,     0,    39,    37,    61,    29,    32,    33,    36,    41,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    77,     0,    93,    37,    96,     0,     0,     0,     0,
      44,    43,    24,    25,    45,    46,    47,    48,     0,    56,
      23,    54,     0,     0,     0,    53,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,    62,     0,
       0,     0,     0,     0,    88,     0,     0,     0,     0,    50,
       0,     0,     0,     0,    92,     0,     0,     0,     0,    21,
       0,     0,    69,    70,    71,    72,    73,    74,     0,     0,
       0,    42,    93,     0,    86,    27,    28,    30,    31,    34,
       0,     0,    58,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,    94,     0,     0,    97,     0,    22,
      20,    19,    26,    79,     0,     0,    85,    93,     0,     0,
       0,     0,     0,    75,     0,    50,    52,    37,    49,     0,
      91,     0,     0,     0,     0,    82,    84,     0,    59,    65,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    95,
      89,    80,     0,     0,     0,     0,     0,    76,    93,    55,
       0,     0,    60,     0,     0,     0,     0,    81,    83,     0,
       0,     0,    51,     0,    66,    67,     0,     0,     0,     0,
      68
  };

  const short
  parser::yypgoto_[] =
  {
    -125,  -125,   320,  -125,   -51,  -125,    -6,    52,    97,   294,
    -124,   -56,   325,  -125,  -125,  -125,   -12,  -125,  -125,  -100,
    -125,  -125,   145,  -125,  -125,  -125,  -125,  -125,    -1,  -125,
    -125
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     1,     2,    18,    79,    80,   103,    45,    46,    47,
      48,    82,    19,    20,    21,    22,    23,    24,    25,   128,
      26,    27,   164,    28,    49,    29,    30,    31,    50,    66,
      67
  };

  const unsigned char
  parser::yytable_[] =
  {
      44,    32,   148,    61,   102,   163,   109,    84,    39,     8,
      40,    69,    93,    42,    62,    91,    92,    94,   117,    43,
     131,    88,    51,    58,    59,    91,    92,   119,    65,     8,
      81,    83,   134,    70,    71,    87,   108,    85,    16,    17,
      91,    92,    70,    71,   104,    97,    72,    73,    89,     3,
     145,    32,    78,    90,   153,   154,    33,   130,    16,    17,
     201,    91,    92,   118,    53,    74,    75,    76,    77,   160,
     161,    34,   166,   163,    74,    75,    76,    77,   140,    88,
      35,    36,    65,   133,   112,   107,   195,   169,   111,    91,
      92,   184,   114,   218,   175,   146,   179,   174,    37,   181,
     113,    81,   185,    38,   213,    89,    89,    38,   115,   157,
     141,    90,    39,    89,    40,    41,   184,    42,   196,    54,
      70,    71,   162,   177,    91,    92,   199,   217,    91,    92,
     171,   120,   121,   100,    65,   173,    91,    92,   170,   204,
     168,   180,   101,   135,   136,   190,   178,    91,    92,   223,
     176,    56,    74,    75,    76,    77,    55,   189,    57,    95,
     122,   123,   124,   125,   126,   127,   159,    68,   172,   198,
      84,   122,   123,   124,   125,   126,   127,    91,    92,    99,
     193,   207,   131,   120,   121,   105,   203,   129,   178,    65,
     137,   138,   139,   120,   121,   209,   211,   120,   121,   214,
     215,   122,   123,   124,   125,   126,   127,   219,   224,   225,
     147,    39,   106,    40,    69,   222,    42,   230,   116,    70,
      71,   228,    43,    88,   110,   134,   143,   120,   121,   122,
     123,   124,   125,   126,   127,    91,    92,     4,     5,   144,
     142,     6,     7,     8,    98,     9,    10,   149,   151,    72,
      73,    74,    75,    76,    77,    78,    11,   150,   155,    12,
      13,    14,     4,     5,    15,   156,     6,     7,     8,   152,
       9,    10,    16,    17,    40,    41,   158,    42,   183,   165,
     182,    11,   120,    43,    12,    13,    14,   186,    39,    15,
      40,    41,    63,    42,   187,   188,   191,    16,    17,    64,
      39,   192,    40,    41,   132,    42,   194,   197,   200,   202,
      39,    43,    40,    41,   167,    42,   205,   212,   206,   216,
      39,    43,    40,    41,   208,    42,   226,    39,    52,    40,
      41,    43,    42,    86,    39,   227,    40,    41,    43,    42,
      60,    39,   210,    40,    41,    96,    42,     0,     0,     0,
       0,     0,   177,   120,   121,   122,   123,   124,   125,   126,
     127,    91,    92,    91,    92,     0,   220,     0,   221,    91,
      92,     0,     0,     0,   229
  };

  const short
  parser::yycheck_[] =
  {
       6,     2,   102,    15,    55,   129,    62,    15,     4,    20,
       6,     7,     5,     9,    16,     3,     4,    10,    69,    15,
       8,     7,     7,    14,    15,     3,     4,    78,    34,    20,
      36,    37,    40,    12,    13,    41,    15,    38,    49,    50,
       3,     4,    12,    13,    56,    51,    42,    43,    34,     0,
     101,    52,    48,    39,   110,   111,    15,    35,    49,    50,
     184,     3,     4,    69,     7,    44,    45,    46,    47,   120,
     121,     7,    35,   197,    44,    45,    46,    47,     7,     7,
      16,    17,    88,    89,     8,    17,     7,   143,    16,     3,
       4,    24,     8,    35,   150,   101,   152,   148,    34,   155,
      24,   107,    35,    39,   204,    34,    34,    39,    24,   115,
      39,    39,     4,    34,     6,     7,    24,     9,    39,     7,
      12,    13,   128,    15,     3,     4,   182,    35,     3,     4,
      24,    25,    26,    15,   140,   147,     3,     4,   144,   190,
     141,   153,    24,    91,    92,    24,   152,     3,     4,    24,
     151,    15,    44,    45,    46,    47,     7,   169,     7,    11,
      27,    28,    29,    30,    31,    32,     8,    15,    24,   181,
      15,    27,    28,    29,    30,    31,    32,     3,     4,     8,
       8,   193,     8,    25,    26,    15,   187,    34,   194,   195,
      93,    94,    95,    25,    26,   196,   202,    25,    26,   205,
     206,    27,    28,    29,    30,    31,    32,   213,   220,   221,
       8,     4,    15,     6,     7,   216,     9,   229,    17,    12,
      13,   227,    15,     7,    16,    40,    16,    25,    26,    27,
      28,    29,    30,    31,    32,     3,     4,    14,    15,    17,
       8,    18,    19,    20,    21,    22,    23,     8,    17,    42,
      43,    44,    45,    46,    47,    48,    33,    16,    16,    36,
      37,    38,    14,    15,    41,    15,    18,    19,    20,    17,
      22,    23,    49,    50,     6,     7,    15,     9,     7,    17,
      16,    33,    25,    15,    36,    37,    38,    15,     4,    41,
       6,     7,     8,     9,    39,     8,    15,    49,    50,    15,
       4,    15,     6,     7,     8,     9,    17,    34,     8,    34,
       4,    15,     6,     7,     8,     9,    17,     8,    17,    39,
       4,    15,     6,     7,     8,     9,    15,     4,     8,     6,
       7,    15,     9,    39,     4,    17,     6,     7,    15,     9,
      15,     4,   197,     6,     7,    15,     9,    -1,    -1,    -1,
      -1,    -1,    15,    25,    26,    27,    28,    29,    30,    31,
      32,     3,     4,     3,     4,    -1,     8,    -1,     8,     3,
       4,    -1,    -1,    -1,     8
  };

  const signed char
  parser::yystos_[] =
  {
       0,    52,    53,     0,    14,    15,    18,    19,    20,    22,
      23,    33,    36,    37,    38,    41,    49,    50,    54,    63,
      64,    65,    66,    67,    68,    69,    71,    72,    74,    76,
      77,    78,    79,    15,     7,    16,    17,    34,    39,     4,
       6,     7,     9,    15,    57,    58,    59,    60,    61,    75,
      79,     7,    53,     7,     7,     7,    15,     7,    14,    15,
      63,    67,    16,     8,    15,    57,    80,    81,    15,     7,
      12,    13,    42,    43,    44,    45,    46,    47,    48,    55,
      56,    57,    62,    57,    15,    79,    60,    57,     7,    34,
      39,     3,     4,     5,    10,    11,    15,    57,    21,     8,
      15,    24,    55,    57,    67,    15,    15,    17,    15,    62,
      16,    16,     8,    24,     8,    24,    17,    55,    57,    55,
      25,    26,    27,    28,    29,    30,    31,    32,    70,    34,
      35,     8,     8,    57,    40,    58,    58,    59,    59,    59,
       7,    39,     8,    16,    17,    55,    57,     8,    70,     8,
      16,    17,    17,    62,    62,    16,    15,    57,    15,     8,
      55,    55,    57,    61,    73,    17,    35,     8,    79,    62,
      57,    24,    24,    67,    55,    62,    79,    15,    57,    62,
      67,    62,    16,     7,    24,    35,    15,    39,     8,    67,
      24,    15,    15,     8,    17,     7,    39,    34,    67,    62,
       8,    61,    34,    79,    55,    17,    17,    67,     8,    79,
      73,    57,     8,    70,    57,    57,    39,    35,    35,    57,
       8,     8,    79,    24,    67,    67,    15,    17,    57,     8,
      67
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    56,    57,    57,    57,
      58,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    65,    65,
      65,    66,    67,    67,    67,    68,    69,    69,    69,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    74,    74,    75,    75,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     2,     3,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     6,
       4,    10,     6,     3,     3,     8,     3,     4,     4,     6,
       8,     2,     3,     1,     1,     6,    10,    10,    15,     1,
       1,     1,     1,     1,     1,     5,     7,     2,     2,     1,
       3,     9,     6,     9,     6,     4,     3,     1,     3,     7,
       7,     6,     4,     3,     3,     5,     1,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PLUSOP", "MINUSOP",
  "MULTOP", "INT", "LP", "RP", "FLOAT", "DIVOP", "POWER", "FLOAT_TYPE",
  "INT_TYPE", "VOLATILE", "ID", "COLON", "ASSIGN", "RETURN", "PRINT",
  "LCB", "RCB", "MAIN", "FOR", "COMMA", "AND", "OR", "EQTO", "NEQ", "LE",
  "GE", "LT", "GT", "IF", "SLB", "SRB", "COMMENT", "CLASS", "READ", "DOT",
  "LENGTH", "ELSE", "TRUE", "FALSE", "INT_ARRAY_TYPE", "FLOAT_ARRAY_TYPE",
  "VOID_TYPE", "BOOLEAN_TYPE", "EXCLAMATION_MARK", "BREAK", "CONTINUE",
  "$accept", "root", "statements", "expression", "condition", "relation",
  "math_expression", "term", "factor", "unary", "primary", "type",
  "variable", "read", "print", "return", "block", "main", "for_statement",
  "relational_operators", "if_statement", "else_statement", "number_array",
  "array_decl", "array_call", "comment", "class", "function_decl",
  "function_call", "parameters", "arguments", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    51,    51,    56,    60,    67,    71,    75,    79,    83,
      87,    91,    95,    99,   103,   107,   111,   115,   119,   124,
     129,   134,   138,   141,   144,   148,   155,   164,   169,   174,
     180,   185,   190,   196,   199,   207,   211,   218,   223,   227,
     231,   234,   237,   245,   251,   257,   263,   269,   275,   283,
     300,   316,   324,   331,   336,   344,   350,   360,   367,   372,
     377,   389,   396,   401,   405,   411,   419,   445,   471,   502,
     506,   510,   514,   518,   522,   528,   534,   552,   557,   564,
     570,   577,   593,   601,   630,   654,   667,   682,   688,   696,
     716,   731,   739,   747,   756,   768,   783,   791
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2658 "parser.tab.cc"

