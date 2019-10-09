/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>

#line 70 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    LESS_OR_EQ = 259,
    MORE_OR_EQ = 260,
    NOT_EQ = 261,
    FALLEN_COLON = 262,
    TERMINAL = 263,
    COLON = 264,
    COMMA = 265,
    LBRACKET = 266,
    RBRACKET = 267,
    LPAREN = 268,
    RPAREN = 269,
    MULTIPLY = 270,
    DIVIDE = 271,
    MOD = 272,
    PLUS = 273,
    MINUS = 274,
    POINT = 275,
    LESS = 276,
    MORE = 277,
    EQ = 278,
    VAR_TOKEN = 279,
    IS_TOKEN = 280,
    TYPE_TOKEN = 281,
    ROUTINE_TOKEN = 282,
    END_TOKEN = 283,
    INT_TOKEN = 284,
    REAL_TOKEN = 285,
    BOOL_TOKEN = 286,
    REC_TOKEN = 287,
    ARRAY_TOKEN = 288,
    WHILE_TOKEN = 289,
    LOOP_TOKEN = 290,
    FOR_TOKEN = 291,
    IN_TOKEN = 292,
    REVERSE_TOKEN = 293,
    IF_TOKEN = 294,
    THEN_TOKEN = 295,
    ELSE_TOKEN = 296,
    AND_TOKEN = 297,
    OR_TOKEN = 298,
    XOR_TOKEN = 299,
    TRUE_TOKEN = 300,
    FALSE_TOKEN = 301,
    IDENT = 302,
    INT_LITERAL = 303,
    REAL_LITERAL = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 171 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   284

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,     7,     7,     8,    10,    11,    12,    13,    15,    16,
      18,    19,    20,    22,    23,    25,    27,    28,    29,    30,
      32,    33,    34,    36,    37,    39,    40,    41,    43,    44,
      46,    47,    48,    50,    51,    53,    54,    55,    56,    57,
      58,    60,    61,    63,    64,    65,    67,    68,    70,    71,
      73,    74,    76,    77,    78,    79,    80,    81,    83,    84,
      86,    87,    88,    89,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   108,   111,   112,   114,   115,   117,   118,   119,
     120,   122,   123,   124,   125,   126,   128,   130,   131,   133,
     134,   136,   137,   139,   140,   142,   143,   145,   146,   147,
     148,   149,   150
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "LESS_OR_EQ", "MORE_OR_EQ",
  "NOT_EQ", "FALLEN_COLON", "TERMINAL", "COLON", "COMMA", "LBRACKET",
  "RBRACKET", "LPAREN", "RPAREN", "MULTIPLY", "DIVIDE", "MOD", "PLUS",
  "MINUS", "POINT", "LESS", "MORE", "EQ", "VAR_TOKEN", "IS_TOKEN",
  "TYPE_TOKEN", "ROUTINE_TOKEN", "END_TOKEN", "INT_TOKEN", "REAL_TOKEN",
  "BOOL_TOKEN", "REC_TOKEN", "ARRAY_TOKEN", "WHILE_TOKEN", "LOOP_TOKEN",
  "FOR_TOKEN", "IN_TOKEN", "REVERSE_TOKEN", "IF_TOKEN", "THEN_TOKEN",
  "ELSE_TOKEN", "AND_TOKEN", "OR_TOKEN", "XOR_TOKEN", "TRUE_TOKEN",
  "FALSE_TOKEN", "IDENT", "INT_LITERAL", "REAL_LITERAL", "$accept",
  "Program", "ProgramFull", "SimpleDeclaration", "VariableDeclaration",
  "VariableDeclarations", "TypeDeclaration", "Type", "PrimitiveType",
  "RecordType", "ArrayType", "Expression", "Logical", "Relation",
  "Correlation", "Simple", "FactorSign", "Factor", "Sign", "Summand",
  "Primary", "ModifiablePrimary", "ModifiableSecondary",
  "RoutineDeclaration", "$@1", "ParameterDeclaration", "Parameters",
  "Body", "Statement", "Assignment", "RoutineCall", "Expressions",
  "WhileLoop", "ForLoop", "Range", "IfStatement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      48,   -36,     1,     5,    54,  -115,    65,  -115,  -115,    75,
      11,    31,    99,  -115,    48,    48,   236,   113,   236,   236,
      -5,   142,  -115,  -115,  -115,  -115,  -115,    22,     2,  -115,
      44,  -115,  -115,  -115,   113,  -115,  -115,   132,  -115,  -115,
    -115,    67,   127,   156,    61,  -115,  -115,  -115,  -115,    77,
      16,    81,   105,   107,  -115,   113,    83,   113,   117,   125,
     106,   133,  -115,  -115,  -115,  -115,  -115,  -115,   134,   123,
      15,  -115,   113,   160,   113,    52,   108,  -115,  -115,  -115,
    -115,   113,  -115,  -115,  -115,  -115,  -115,  -115,   113,  -115,
    -115,  -115,   113,  -115,  -115,   113,   159,   236,   166,    -8,
     109,    42,   144,   147,   146,   -10,   113,  -115,   -10,   167,
    -115,   236,   184,  -115,  -115,   192,  -115,   193,   194,    -1,
    -115,  -115,  -115,  -115,  -115,   182,   186,  -115,   195,  -115,
    -115,  -115,   236,   173,   190,    58,   187,   141,  -115,  -115,
    -115,  -115,  -115,   236,    -1,   113,  -115,  -115,  -115,   191,
    -115,   196,  -115,   200,  -115,   211,   113,   233,   207,  -115,
     208,    17,  -115,  -115,  -115,  -115,   217,   224,  -115,  -115,
     249,   113,  -115,   229,  -115,   234,  -115,   225,  -115,  -115,
     242,   113,  -115,  -115,  -115,  -115,   245,  -115,  -115,  -115,
    -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,     3,     0,     8,     9,     0,
       0,     0,    64,     1,     4,     6,     0,     0,     0,     0,
       0,     0,     5,     7,    20,    21,    22,     0,     0,    19,
      10,    16,    18,    17,     0,    54,    55,    58,    52,    53,
      12,    28,    33,    41,    46,    50,    56,    57,    15,    67,
      70,     0,    85,     0,    65,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,    95,    23,     0,     0,
       0,    27,     0,     0,     0,     0,     0,    59,    30,    31,
      32,     0,    36,    38,    40,    35,    37,    39,     0,    43,
      44,    45,     0,    48,    49,     0,     0,     0,     0,     0,
       0,    71,     0,     0,     0,    87,     0,    66,    88,    13,
      24,     0,     0,    11,    51,     0,    97,    99,     0,    60,
      29,    34,    42,    47,    68,     0,    76,    72,     0,    83,
      84,    86,     0,     0,     0,     0,     0,     0,    89,    96,
      90,    14,    26,     0,    61,     0,    98,    62,    69,     0,
      74,    77,    73,     0,   101,     0,     0,     0,     0,   108,
       0,     0,    25,    63,   100,    78,     0,     0,    75,   102,
       0,     0,   103,     0,   112,     0,   107,     0,    80,    79,
       0,     0,   105,   104,   110,   111,     0,    81,   106,   109,
      82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,    78,   122,   -23,   165,  -115,   -16,   176,  -115,
    -115,   -17,  -115,   197,  -115,   188,  -115,   185,  -115,   189,
    -115,   -20,  -114,  -115,  -115,  -115,   179,   -90,  -115,  -115,
     -14,   135,  -115,  -115,  -115,  -115
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    58,     7,    69,     8,    30,    31,    32,
      33,   117,    81,    41,    88,    42,    92,    43,    95,    44,
      45,    46,    77,     9,   190,    52,    53,    60,    61,    62,
      47,   118,    64,    65,   136,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    59,    48,    49,    68,   147,   125,    63,   128,    50,
      74,    10,    71,    70,     1,   138,     2,    73,   140,    76,
      16,    24,    25,    26,    55,    97,    56,   111,    34,    57,
     163,    24,    25,    26,    27,    28,    17,    37,   102,   129,
     104,    98,    51,   153,   155,   176,     1,   161,    11,    29,
      67,   132,    12,   112,    13,   113,    18,   115,   177,   166,
      35,    36,    37,    38,    39,    34,   116,   133,   173,    72,
     175,    34,     1,    14,     2,     3,    59,   180,    59,    93,
      94,   126,    63,    15,    63,    59,    68,   186,    59,   139,
      99,    63,    22,    23,    63,   142,   156,    35,    36,    37,
      38,    39,    96,    35,    36,    37,    38,    39,    19,    78,
      79,    80,    20,    59,    59,   100,   151,    59,   157,    63,
      63,   101,     6,    63,    21,   105,    34,   162,   106,    59,
     103,    82,    83,    84,   107,    63,     6,     6,    59,   170,
      59,   108,   109,    74,    63,    75,    63,    59,    85,    86,
      87,   110,    76,    63,   182,   119,    51,    59,    35,    36,
      37,    38,    39,    63,   188,     1,     1,     2,     2,   159,
      54,    89,    90,    91,   114,    55,    55,    56,    56,   134,
      57,    57,   160,     1,   135,     2,   137,   124,    37,    37,
       1,     1,     2,    55,   127,    56,   143,     1,    57,     2,
      55,   152,    56,   145,   144,    57,    37,    55,   146,    56,
     148,   149,    57,    37,     1,     1,     2,     2,   154,   165,
      37,   167,   158,   150,    55,    55,    56,    56,   168,    57,
      57,     1,     1,     2,     2,   172,   174,    37,    37,   169,
     171,    55,    55,    56,    56,   178,    57,    57,     1,     1,
       2,     2,   179,   185,    37,    37,   181,   183,    55,    55,
      56,    56,   184,    57,    57,    24,    25,    26,    27,    28,
     187,    37,    37,   189,   141,   130,   121,   122,   120,   131,
     164,     0,     0,    29,   123
};

static const yytype_int16 yycheck[] =
{
      17,    21,    18,    19,    27,   119,    96,    21,    98,    14,
      11,    47,    28,    11,    24,   105,    26,    34,   108,    20,
       9,    29,    30,    31,    34,     9,    36,    12,    13,    39,
     144,    29,    30,    31,    32,    33,    25,    47,    55,    47,
      57,    25,    47,   133,   134,    28,    24,   137,    47,    47,
      28,     9,    47,    70,     0,    72,    25,    74,    41,   149,
      45,    46,    47,    48,    49,    13,    14,    25,   158,    25,
     160,    13,    24,     8,    26,    27,    96,   167,    98,    18,
      19,    97,    96,     8,    98,   105,   109,   177,   108,   106,
       9,   105,    14,    15,   108,   111,    38,    45,    46,    47,
      48,    49,    25,    45,    46,    47,    48,    49,     9,    42,
      43,    44,    13,   133,   134,    10,   132,   137,   135,   133,
     134,    14,     0,   137,    25,     8,    13,   143,     3,   149,
      47,     4,     5,     6,    28,   149,    14,    15,   158,   156,
     160,     8,     8,    11,   158,    13,   160,   167,    21,    22,
      23,    28,    20,   167,   171,    47,    47,   177,    45,    46,
      47,    48,    49,   177,   181,    24,    24,    26,    26,    28,
      28,    15,    16,    17,    14,    34,    34,    36,    36,    35,
      39,    39,    41,    24,    37,    26,    40,    28,    47,    47,
      24,    24,    26,    34,    28,    36,    12,    24,    39,    26,
      34,    28,    36,    10,    12,    39,    47,    34,    14,    36,
      28,    25,    39,    47,    24,    24,    26,    26,    28,    28,
      47,    25,    35,    28,    34,    34,    36,    36,    28,    39,
      39,    24,    24,    26,    26,    28,    28,    47,    47,    28,
       7,    34,    34,    36,    36,    28,    39,    39,    24,    24,
      26,    26,    28,    28,    47,    47,     7,    28,    34,    34,
      36,    36,    28,    39,    39,    29,    30,    31,    32,    33,
      28,    47,    47,    28,   109,    99,    88,    92,    81,   100,
     145,    -1,    -1,    47,    95
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    26,    27,    51,    52,    53,    54,    56,    73,
      47,    47,    47,     0,     8,     8,     9,    25,    25,     9,
      13,    25,    52,    52,    29,    30,    31,    32,    33,    47,
      57,    58,    59,    60,    13,    45,    46,    47,    48,    49,
      61,    63,    65,    67,    69,    70,    71,    80,    57,    57,
      14,    47,    75,    76,    28,    34,    36,    39,    53,    71,
      77,    78,    79,    80,    82,    83,    85,    28,    54,    55,
      11,    57,    25,    61,    11,    13,    20,    72,    42,    43,
      44,    62,     4,     5,     6,    21,    22,    23,    64,    15,
      16,    17,    66,    18,    19,    68,    25,     9,    25,     9,
      10,    14,    61,    47,    61,     8,     3,    28,     8,     8,
      28,    12,    61,    61,    14,    61,    14,    61,    81,    47,
      63,    65,    67,    69,    28,    77,    57,    28,    77,    47,
      58,    76,     9,    25,    35,    37,    84,    40,    77,    61,
      77,    55,    57,    12,    12,    10,    14,    72,    28,    25,
      28,    57,    28,    77,    28,    77,    38,    61,    35,    28,
      41,    77,    57,    72,    81,    28,    77,    25,    28,    28,
      61,     7,    28,    77,    28,    77,    28,    41,    28,    28,
      77,     7,    61,    28,    28,    28,    77,    28,    61,    28,
      74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    52,    52,    53,    53,
      54,    54,    54,    55,    55,    56,    57,    57,    57,    57,
      58,    58,    58,    59,    59,    60,    60,    60,    61,    61,
      62,    62,    62,    63,    63,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    73,    75,    75,    76,    76,    77,    77,    77,
      77,    78,    78,    78,    78,    78,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85,    85,
      85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     2,     3,     2,     3,     1,     1,
       4,     6,     4,     2,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     5,     4,     2,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     3,     4,     2,     4,     5,     4,     6,     7,
       4,     5,     6,     7,     7,     8,     6,     7,     8,     9,
       9,     0,    11,     3,     3,     1,     3,     2,     2,     3,
       3,     1,     1,     1,     1,     1,     3,     3,     4,     1,
       3,     4,     5,     5,     6,     4,     5,     5,     4,     7,
       6,     6,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 7 "parser.y" /* yacc.c:1646  */
    {printf("<Program,0,Program : >+");}
#line 1412 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 8 "parser.y" /* yacc.c:1646  */
    {printf("<Program,1,		| ProgramFull>+");}
#line 1418 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 10 "parser.y" /* yacc.c:1646  */
    {printf("<ProgramFull,2,ProgramFull : SimpleDeclaration TERMINAL>+");}
#line 1424 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 11 "parser.y" /* yacc.c:1646  */
    {printf("<ProgramFull,3,			| SimpleDeclaration TERMINAL ProgramFull>+");}
#line 1430 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 12 "parser.y" /* yacc.c:1646  */
    {printf("<ProgramFull,2,			| RoutineDeclaration TERMINAL>+");}
#line 1436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 13 "parser.y" /* yacc.c:1646  */
    {printf("<ProgramFull,3,			| RoutineDeclaration TERMINAL ProgramFull>+");}
#line 1442 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 15 "parser.y" /* yacc.c:1646  */
    {printf("<SimpleDeclaration,1,SimpleDeclaration : VariableDeclaration>+");}
#line 1448 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 16 "parser.y" /* yacc.c:1646  */
    {printf("<SimpleDeclaration,1,				  | TypeDeclaration>+");}
#line 1454 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 18 "parser.y" /* yacc.c:1646  */
    {printf("<VariableDeclaration,4,VariableDeclaration : VAR_TOKEN IDENT COLON Type>+");}
#line 1460 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 19 "parser.y" /* yacc.c:1646  */
    {printf("<VariableDeclaration,6,                    | VAR_TOKEN IDENT COLON Type IS_TOKEN Expression>+");}
#line 1466 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 20 "parser.y" /* yacc.c:1646  */
    {printf("<VariableDeclaration,4,                    | VAR_TOKEN IDENT IS_TOKEN Expression>+");}
#line 1472 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 22 "parser.y" /* yacc.c:1646  */
    {printf("<VariableDeclarations,2,VariableDeclarations : VariableDeclaration TERMINAL>+");}
#line 1478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 23 "parser.y" /* yacc.c:1646  */
    {printf("<VariableDeclarations,3,					 | VariableDeclaration TERMINAL VariableDeclarations >+");}
#line 1484 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 25 "parser.y" /* yacc.c:1646  */
    {printf("<TypeDeclaration,4,TypeDeclaration : TYPE_TOKEN IDENT IS_TOKEN Type>+");}
#line 1490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 27 "parser.y" /* yacc.c:1646  */
    {printf("<Type,1,Type : PrimitiveType>+");}
#line 1496 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 28 "parser.y" /* yacc.c:1646  */
    {printf("<Type,1,	 | ArrayType>+");}
#line 1502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 29 "parser.y" /* yacc.c:1646  */
    {printf("<Type,1,	 | RecordType>+");}
#line 1508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 30 "parser.y" /* yacc.c:1646  */
    {printf("<Type,1,	 | IDENT >+");}
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 32 "parser.y" /* yacc.c:1646  */
    {printf("<PrimitiveType,1,PrimitiveType : INT_TOKEN>+");}
#line 1520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 33 "parser.y" /* yacc.c:1646  */
    {printf("<PrimitiveType,1,			  | REAL_TOKEN>+");}
#line 1526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 34 "parser.y" /* yacc.c:1646  */
    {printf("<PrimitiveType,1,			  | BOOL_TOKEN >+");}
#line 1532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 36 "parser.y" /* yacc.c:1646  */
    {printf("<RecordType,2,RecordType : REC_TOKEN END_TOKEN>+");}
#line 1538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 37 "parser.y" /* yacc.c:1646  */
    {printf("<RecordType,3,		   | REC_TOKEN VariableDeclarations END_TOKEN>+");}
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 39 "parser.y" /* yacc.c:1646  */
    {printf("<ArrayType,5,ArrayType : ARRAY_TOKEN LBRACKET Expression RBRACKET Type>+");}
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 40 "parser.y" /* yacc.c:1646  */
    {printf("<ArrayType,4,          | ARRAY_TOKEN LBRACKET RBRACKET Type>+");}
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 41 "parser.y" /* yacc.c:1646  */
    {printf("<ArrayType,2,          | ARRAY_TOKEN Type >+");}
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 43 "parser.y" /* yacc.c:1646  */
    {printf("<Expression,1,Expression : Relation>+");}
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 44 "parser.y" /* yacc.c:1646  */
    {printf("<Expression,3,		   | Relation Logical Relation >+");}
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 46 "parser.y" /* yacc.c:1646  */
    {printf("<Logical,1,Logical : AND_TOKEN>+");}
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 47 "parser.y" /* yacc.c:1646  */
    {printf("<Logical,1,		| OR_TOKEN>+");}
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 48 "parser.y" /* yacc.c:1646  */
    {printf("<Logical,1,		| XOR_TOKEN >+");}
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 50 "parser.y" /* yacc.c:1646  */
    {printf("<Relation,1,Relation : Simple>+");}
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 51 "parser.y" /* yacc.c:1646  */
    {printf("<Relation,3,		 | Simple Correlation Simple >+");}
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 53 "parser.y" /* yacc.c:1646  */
    {printf("<Correlation,1,Correlation : LESS>+");}
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 54 "parser.y" /* yacc.c:1646  */
    {printf("<Correlation,1,			| LESS_OR_EQ>+");}
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 55 "parser.y" /* yacc.c:1646  */
    {printf("<Correlation,1,			| MORE>+");}
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 56 "parser.y" /* yacc.c:1646  */
    {printf("<Correlation,1,			| MORE_OR_EQ>+");}
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 57 "parser.y" /* yacc.c:1646  */
    {printf("<Correlation,1,			| EQ>+");}
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 58 "parser.y" /* yacc.c:1646  */
    {printf("<Correlation,1,			| NOT_EQ >+");}
#line 1640 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 60 "parser.y" /* yacc.c:1646  */
    {printf("<Simple,1,Simple : Factor >+");}
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 61 "parser.y" /* yacc.c:1646  */
    {printf("<Simple,3,	   | Factor FactorSign Factor >+");}
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 63 "parser.y" /* yacc.c:1646  */
    {printf("<FactorSign,1,FactorSign : MULTIPLY >+");}
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 64 "parser.y" /* yacc.c:1646  */
    {printf("<FactorSign,1,		   | DIVIDE>+");}
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 65 "parser.y" /* yacc.c:1646  */
    {printf("<FactorSign,1,		   | MOD >+");}
#line 1670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 67 "parser.y" /* yacc.c:1646  */
    {printf("<Factor,1,Factor : Summand>+");}
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 68 "parser.y" /* yacc.c:1646  */
    {printf("<Factor,3,	   | Summand Sign Summand >+");}
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 70 "parser.y" /* yacc.c:1646  */
    {printf("<Sign,1,Sign : PLUS>+");}
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 71 "parser.y" /* yacc.c:1646  */
    {printf("<Sign,1,	 | MINUS >+");}
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 73 "parser.y" /* yacc.c:1646  */
    {printf("<Summand,1,Summand : Primary>+");}
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 74 "parser.y" /* yacc.c:1646  */
    {printf("<Summand,3,		| LPAREN Expression RPAREN >+");}
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 76 "parser.y" /* yacc.c:1646  */
    {printf("<Primary,1,Primary : INT_LITERAL>+");}
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 77 "parser.y" /* yacc.c:1646  */
    {printf("<Primary,1,		| REAL_LITERAL>+");}
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 78 "parser.y" /* yacc.c:1646  */
    {printf("<Primary,1,		| TRUE_TOKEN>+");}
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 79 "parser.y" /* yacc.c:1646  */
    {printf("<Primary,1,		| FALSE_TOKEN>+");}
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 80 "parser.y" /* yacc.c:1646  */
    {printf("<Primary,1,		| ModifiablePrimary>+");}
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 81 "parser.y" /* yacc.c:1646  */
    {printf("<Primary,1,		| RoutineCall>+");}
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 83 "parser.y" /* yacc.c:1646  */
    {printf("<ModifiablePrimary,1,ModifiablePrimary : IDENT>+");}
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 84 "parser.y" /* yacc.c:1646  */
    {printf("<ModifiablePrimary,2,                  | IDENT ModifiableSecondary>+");}
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 86 "parser.y" /* yacc.c:1646  */
    {printf("<ModifiableSecondary,2,ModifiableSecondary : POINT IDENT>+");}
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 87 "parser.y" /* yacc.c:1646  */
    {printf("<ModifiableSecondary,3,					| LBRACKET Expression RBRACKET>+");}
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 88 "parser.y" /* yacc.c:1646  */
    {printf("<ModifiableSecondary,3,					| POINT IDENT ModifiableSecondary>+");}
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 89 "parser.y" /* yacc.c:1646  */
    {printf("<ModifiableSecondary,4,					| LBRACKET Expression RBRACKET ModifiableSecondary>+");}
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 91 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,2,RoutineDeclaration : ROUTINE_TOKEN IDENT>+");}
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 92 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,4,                   | ROUTINE_TOKEN IDENT IS_TOKEN END_TOKEN>+");}
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 93 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,5,                   | ROUTINE_TOKEN IDENT IS_TOKEN Body END_TOKEN>+");}
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 94 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,4,                   | ROUTINE_TOKEN IDENT COLON Type>+");}
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 95 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,6,                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN END_TOKEN>+");}
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 96 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,7,                   | ROUTINE_TOKEN IDENT COLON Type IS_TOKEN Body END_TOKEN>+");}
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 97 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,4,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN>+");}
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 98 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,5,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN>+");}
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 99 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,6,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN END_TOKEN>+");}
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 100 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,7,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN END_TOKEN>+");}
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 101 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,7,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN IS_TOKEN Body END_TOKEN>+");}
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 102 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,8,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN IS_TOKEN Body END_TOKEN>+");}
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 103 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,6,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type>+");}
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 104 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,7,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type>+");}
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 105 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,8,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN END_TOKEN >+");}
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 106 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,9,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN END_TOKEN>+");}
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 107 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,9,                   | ROUTINE_TOKEN IDENT LPAREN RPAREN COLON Type IS_TOKEN Body END_TOKEN  >+");}
#line 1880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 108 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,10,                   | ROUTINE_TOKEN IDENT LPAREN Parameters RPAREN COLON Type IS_TOKEN Body END_TOKEN >+");}
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 109 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineDeclaration,0,                   >+");}
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 111 "parser.y" /* yacc.c:1646  */
    {printf("<ParameterDeclaration,3,ParameterDeclaration : IDENT COLON IDENT>+");}
#line 1898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 112 "parser.y" /* yacc.c:1646  */
    {printf("<ParameterDeclaration,3,					 | IDENT COLON PrimitiveType>+");}
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 114 "parser.y" /* yacc.c:1646  */
    {printf("<Parameters,1,Parameters : ParameterDeclaration>+");}
#line 1910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 115 "parser.y" /* yacc.c:1646  */
    {printf("<Parameters,3,		   | ParameterDeclaration COMMA Parameters>+");}
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 117 "parser.y" /* yacc.c:1646  */
    {printf("<Body,2,Body : SimpleDeclaration TERMINAL>+");}
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 118 "parser.y" /* yacc.c:1646  */
    {printf("<Body,2,     | Statement TERMINAL>+");}
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 119 "parser.y" /* yacc.c:1646  */
    {printf("<Body,3,     | SimpleDeclaration TERMINAL Body>+");}
#line 1934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 120 "parser.y" /* yacc.c:1646  */
    {printf("<Body,3,     | Statement TERMINAL Body >+");}
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 122 "parser.y" /* yacc.c:1646  */
    {printf("<Statement,1,Statement : Assignment>+");}
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 123 "parser.y" /* yacc.c:1646  */
    {printf("<Statement,1,		  | RoutineCall>+");}
#line 1952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 124 "parser.y" /* yacc.c:1646  */
    {printf("<Statement,1,		  | WhileLoop>+");}
#line 1958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 125 "parser.y" /* yacc.c:1646  */
    {printf("<Statement,1,		  | ForLoop>+");}
#line 1964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 126 "parser.y" /* yacc.c:1646  */
    {printf("<Statement,1,		  | IfStatement >+");}
#line 1970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 128 "parser.y" /* yacc.c:1646  */
    {printf("<Assignment,3,Assignment : ModifiablePrimary ASSIGN Expression >+");}
#line 1976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 130 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineCall,3,RoutineCall : IDENT LPAREN RPAREN >+");}
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 131 "parser.y" /* yacc.c:1646  */
    {printf("<RoutineCall,4,            | IDENT LPAREN Expressions RPAREN >+");}
#line 1988 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 133 "parser.y" /* yacc.c:1646  */
    {printf("<Expressions,1,Expressions : Expression>+");}
#line 1994 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 134 "parser.y" /* yacc.c:1646  */
    {printf("<Expressions,3,			| Expression COMMA Expressions>+");}
#line 2000 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 136 "parser.y" /* yacc.c:1646  */
    {printf("<WhileLoop,4,WhileLoop : WHILE_TOKEN Expression LOOP_TOKEN END_TOKEN>+");}
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 137 "parser.y" /* yacc.c:1646  */
    {printf("<WhileLoop,5,		  | WHILE_TOKEN Expression LOOP_TOKEN Body END_TOKEN>+");}
#line 2012 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 139 "parser.y" /* yacc.c:1646  */
    {printf("<ForLoop,5,ForLoop : FOR_TOKEN IDENT Range LOOP_TOKEN END_TOKEN >+");}
#line 2018 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 140 "parser.y" /* yacc.c:1646  */
    {printf("<ForLoop,6,		| FOR_TOKEN IDENT Range LOOP_TOKEN Body END_TOKEN>+");}
#line 2024 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 142 "parser.y" /* yacc.c:1646  */
    {printf("<Range,4,Range : IN_TOKEN Expression FALLEN_COLON Expression>+");}
#line 2030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 143 "parser.y" /* yacc.c:1646  */
    {printf("<Range,5,      | IN_TOKEN REVERSE_TOKEN Expression FALLEN_COLON Expression >+");}
#line 2036 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 145 "parser.y" /* yacc.c:1646  */
    {printf("<IfStatement,5,IfStatement : IF_TOKEN Expression THEN_TOKEN Body END_TOKEN>+");}
#line 2042 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 146 "parser.y" /* yacc.c:1646  */
    {printf("<IfStatement,4,			| IF_TOKEN Expression THEN_TOKEN END_TOKEN>+");}
#line 2048 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 147 "parser.y" /* yacc.c:1646  */
    {printf("<IfStatement,7,            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN Body END_TOKEN>+");}
#line 2054 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 148 "parser.y" /* yacc.c:1646  */
    {printf("<IfStatement,6,            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN Body END_TOKEN>+");}
#line 2060 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 149 "parser.y" /* yacc.c:1646  */
    {printf("<IfStatement,6,            | IF_TOKEN Expression THEN_TOKEN Body ELSE_TOKEN END_TOKEN>+");}
#line 2066 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 150 "parser.y" /* yacc.c:1646  */
    {printf("<IfStatement,5,            | IF_TOKEN Expression THEN_TOKEN ELSE_TOKEN END_TOKEN>+");}
#line 2072 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2076 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 152 "parser.y" /* yacc.c:1906  */

int main(int argc, char **argv){
	yyparse();
}
int yyerror(char *s){
	printf("\n\n-\nError: %s\n-\n", s);
}
