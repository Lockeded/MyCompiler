/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

    #include <stdio.h>
    #include "Node.h"
    #include "lex.yy.c"
    #include "Semantic.h"
    #include "InterCode.h"

#line 78 "syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    ID = 260,
    ERROR_INT8 = 261,
    ERROR_INT16 = 262,
    ERROR_FLOAT = 263,
    SEMI = 264,
    COMMA = 265,
    ASSIGNOP = 266,
    RELOP = 267,
    PLUS = 268,
    MINUS = 269,
    STAR = 270,
    DIV = 271,
    AND = 272,
    OR = 273,
    DOT = 274,
    NOT = 275,
    TYPE = 276,
    LP = 277,
    RP = 278,
    LB = 279,
    RB = 280,
    LC = 281,
    RC = 282,
    STRUCT = 283,
    RETURN = 284,
    IF = 285,
    ELSE = 286,
    WHILE = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 8 "syntax.y"

    node type_node;

#line 167 "syntax.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   551

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

#define YYUNDEFTOK  2
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    36,    36,    38,    39,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    52,    53,    54,    56,    57,
      59,    60,    61,    62,    64,    65,    67,    69,    70,    71,
      72,    73,    75,    76,    77,    78,    79,    81,    82,    84,
      86,    87,    89,    90,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   106,   107,   109,
     110,   111,   113,   114,   116,   117,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   151,   152
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "ID", "ERROR_INT8",
  "ERROR_INT16", "ERROR_FLOAT", "SEMI", "COMMA", "ASSIGNOP", "RELOP",
  "PLUS", "MINUS", "STAR", "DIV", "AND", "OR", "DOT", "NOT", "TYPE", "LP",
  "RP", "LB", "RB", "LC", "RC", "STRUCT", "RETURN", "IF", "ELSE", "WHILE",
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

#define YYPACT_NINF (-128)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,   135,  -128,    52,    74,  -128,    31,   103,  -128,    53,
      54,  -128,  -128,  -128,    68,    80,    24,   111,    81,   122,
    -128,  -128,  -128,   143,   196,  -128,   132,   110,     8,  -128,
       5,   127,    28,  -128,    62,   137,    65,  -128,  -128,    62,
    -128,  -128,  -128,    15,    15,    64,  -128,  -128,   176,    15,
     160,   189,  -128,   100,  -128,   161,   109,    22,   173,    65,
    -128,    95,   175,   162,  -128,  -128,  -128,   178,    63,   180,
    -128,     5,  -128,  -128,    81,   174,   198,   199,    -1,   208,
    -128,  -128,   133,  -128,  -128,   194,  -128,  -128,  -128,   430,
     430,   430,   230,    59,   115,  -128,   192,    95,   158,  -128,
    -128,   197,  -128,  -128,   430,  -128,    15,  -128,  -128,  -128,
     207,   224,    94,   472,   214,   177,   193,   430,   126,   430,
    -128,  -128,   216,  -128,   250,   270,   290,   310,   330,   350,
     370,   390,   221,   410,  -128,   514,  -128,   219,  -128,   443,
     209,  -128,  -128,  -128,  -128,   125,   486,  -128,  -128,   500,
    -128,   232,   514,   233,   427,   236,   224,   237,   224,   238,
      94,   240,    94,   251,   407,   252,   527,  -128,   234,   457,
    -128,   430,  -128,  -128,   125,   125,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,   231,  -128,   125,
    -128
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    18,     0,     0,     2,     0,     0,    19,    25,
       0,    10,    11,    12,     0,     0,     0,     0,    26,     0,
      21,     1,     3,     0,     0,     8,     0,     0,     0,    24,
       0,     0,     0,    14,     0,     0,     0,     9,    22,     0,
      13,    31,     7,     0,     0,     0,     6,     5,    25,     0,
       0,    38,    35,    25,    33,     0,     0,     0,     0,     0,
      41,     0,     0,     0,    27,    17,    16,     0,     0,    39,
      36,     0,    34,    32,    27,    64,     0,    62,     0,     0,
      23,    57,     0,    82,    83,    81,    85,    84,    86,     0,
       0,     0,     0,     0,     0,    45,     0,     0,     0,    20,
      30,     0,    28,    37,     0,    61,     0,    60,    59,    53,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
      40,    42,     0,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    65,    63,     0,    78,    98,
       0,    74,    56,    55,    46,     0,     0,    51,    52,     0,
      54,     0,    66,     0,    69,     0,    70,     0,    71,     0,
      72,     0,    73,     0,    67,     0,    68,    80,     0,     0,
      95,     0,    77,    50,     0,     0,    87,    90,    91,    92,
      93,    94,    88,    89,    96,    79,    97,    47,    49,     0,
      48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,   257,  -128,   136,    13,  -128,   262,  -128,   -45,
     259,   -25,  -128,    -6,   170,  -127,   107,  -128,   -52,  -128,
     -89,    97
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    26,    57,     8,    15,    20,    27,
      16,    50,    51,    95,    96,    97,    58,    59,    76,    77,
      98,   140
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     111,   112,   113,   115,    69,    79,    48,    55,   107,    35,
      37,    75,    75,     7,    14,   135,    63,    46,   173,     7,
      64,   139,    47,    78,    41,    35,     2,    64,   146,    53,
     149,    -4,     1,     3,    36,   152,   154,   156,   158,   160,
     162,   164,   166,    49,   169,    49,   103,   187,   188,     2,
      36,    54,     2,    17,   136,    31,     3,    18,    29,     3,
     116,    75,   190,    56,   101,    67,    56,    68,   -58,   -58,
     -58,   -58,   -58,   -58,    21,    30,    32,    33,   -25,   -58,
     -24,   117,   139,     2,    49,   -58,     2,   -58,   102,   -58,
       3,   -58,   -58,     3,   -58,   -58,    82,   -58,    83,    84,
      85,    86,    87,    88,    23,    29,    34,   -24,    24,    89,
      63,    43,    25,   132,    74,    90,   118,    91,   133,   -15,
      44,    36,   -43,    72,    92,    93,    82,    94,    83,    84,
      85,    86,    87,    88,    45,   -25,     9,   119,    38,    89,
      10,    42,   109,    61,    11,    90,    62,    91,    39,   147,
      52,    36,    40,   148,    92,    93,     2,    94,    12,   122,
      60,   -25,    13,     3,    60,    30,    81,   123,    41,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   143,    65,
      66,    29,   133,    70,    73,   104,   144,    41,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    31,    45,    71,
      80,   133,    99,   100,    45,   -27,   -27,   105,   137,   106,
      83,    84,    85,    86,    87,    88,   110,   108,    32,   120,
     -27,    89,   134,   142,   145,   150,   167,    90,   170,    91,
     138,   114,   172,    83,    84,    85,    86,    87,    88,   128,
     129,   176,   177,   132,    89,   178,   179,   180,   133,   181,
      90,   151,    91,    83,    84,    85,    86,    87,    88,   184,
     182,   183,   189,    22,    89,    19,    28,   121,   186,     0,
      90,   153,    91,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
      90,   155,    91,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
      90,   157,    91,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
      90,   159,    91,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
      90,   161,    91,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
      90,   163,    91,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
      90,   165,    91,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
      90,   168,    91,    83,    84,    85,    86,    87,    88,   125,
     126,   127,   128,   129,    89,     0,   132,     0,     0,     0,
      90,   133,    91,    83,    84,    85,    86,    87,    88,     0,
     126,   127,   128,   129,    89,     0,   132,     0,     0,     0,
      90,   133,    91,   171,   124,   125,   126,   127,   128,   129,
     130,   131,   132,     0,     0,     0,     0,   133,   124,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,     0,
       0,   133,   185,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,     0,     0,   141,   133,   124,   125,   126,
     127,   128,   129,   130,   131,   132,     0,     0,     0,   174,
     133,   124,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,     0,   175,   133,   124,   125,   126,   127,   128,
     129,   130,   131,   132,     0,     0,     0,     0,   133,   125,
     126,   127,   128,   129,   130,     0,   132,     0,     0,     0,
       0,   133
};

static const yytype_int16 yycheck[] =
{
      89,    90,    91,    92,    49,    57,     1,    32,     9,     1,
      16,    56,    57,     0,     1,   104,     1,     9,   145,     6,
       5,   110,    28,     1,    25,     1,    21,     5,   117,     1,
     119,     0,     1,    28,    26,   124,   125,   126,   127,   128,
     129,   130,   131,    30,   133,    32,    71,   174,   175,    21,
      26,    23,    21,     1,   106,     1,    28,     5,     5,    28,
       1,   106,   189,     1,     1,     1,     1,     3,     3,     4,
       5,     6,     7,     8,     0,    22,    22,     9,    26,    14,
      26,    22,   171,    21,    71,    20,    21,    22,    25,    27,
      28,    26,    27,    28,    29,    30,     1,    32,     3,     4,
       5,     6,     7,     8,     1,     5,    26,    26,     5,    14,
       1,     1,     9,    19,     5,    20,     1,    22,    24,     9,
      10,    26,    27,    23,    29,    30,     1,    32,     3,     4,
       5,     6,     7,     8,    24,    26,     1,    22,    27,    14,
       5,     9,     9,    36,     9,    20,    39,    22,    26,    23,
      23,    26,     9,    27,    29,    30,    21,    32,    23,     1,
      27,    26,    27,    28,    27,    22,    59,     9,    25,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     1,    43,
      44,     5,    24,    23,    23,    11,     9,    25,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     1,    24,    10,
      27,    24,    27,    25,    24,     9,    10,     9,     1,    10,
       3,     4,     5,     6,     7,     8,    22,     9,    22,    27,
      24,    14,    25,     9,    31,     9,     5,    20,     9,    22,
      23,     1,    23,     3,     4,     5,     6,     7,     8,    15,
      16,     9,     9,    19,    14,     9,     9,     9,    24,     9,
      20,     1,    22,     3,     4,     5,     6,     7,     8,    25,
       9,     9,    31,     6,    14,     3,     7,    97,   171,    -1,
      20,     1,    22,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      20,     1,    22,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      20,     1,    22,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      20,     1,    22,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      20,     1,    22,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      20,     1,    22,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      20,     1,    22,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      20,     1,    22,     3,     4,     5,     6,     7,     8,    12,
      13,    14,    15,    16,    14,    -1,    19,    -1,    -1,    -1,
      20,    24,    22,     3,     4,     5,     6,     7,     8,    -1,
      13,    14,    15,    16,    14,    -1,    19,    -1,    -1,    -1,
      20,    24,    22,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    24,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    23,    24,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      24,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    23,    24,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,    12,
      13,    14,    15,    16,    17,    -1,    19,    -1,    -1,    -1,
      -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    21,    28,    34,    35,    36,    38,    39,     1,
       5,     9,    23,    27,    38,    40,    43,     1,     5,    40,
      41,     0,    35,     1,     5,     9,    37,    42,    43,     5,
      22,     1,    22,     9,    26,     1,    26,    46,    27,    26,
       9,    25,     9,     1,    10,    24,     9,    46,     1,    38,
      44,    45,    23,     1,    23,    44,     1,    38,    49,    50,
      27,    49,    49,     1,     5,    37,    37,     1,     3,    42,
      23,    10,    23,    23,     5,    42,    51,    52,     1,    51,
      27,    49,     1,     3,     4,     5,     6,     7,     8,    14,
      20,    22,    29,    30,    32,    46,    47,    48,    53,    27,
      25,     1,    25,    44,    11,     9,    10,     9,     9,     9,
      22,    53,    53,    53,     1,    53,     1,    22,     1,    22,
      27,    47,     1,     9,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    24,    25,    53,    51,     1,    23,    53,
      54,    23,     9,     1,     9,    31,    53,    23,    27,    53,
       9,     1,    53,     1,    53,     1,    53,     1,    53,     1,
      53,     1,    53,     1,    53,     1,    53,     5,     1,    53,
       9,    10,    23,    48,    23,    23,     9,     9,     9,     9,
       9,     9,     9,     9,    25,    25,    54,    48,    48,    31,
      48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    37,    37,    37,    38,    38,
      39,    39,    39,    39,    40,    40,    41,    42,    42,    42,
      42,    42,    43,    43,    43,    43,    43,    44,    44,    45,
      46,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    49,    49,    50,
      50,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     3,     2,     3,
       2,     2,     2,     3,     3,     1,     3,     3,     1,     1,
       5,     2,     3,     5,     1,     0,     1,     1,     4,     5,
       4,     2,     4,     3,     4,     3,     4,     3,     1,     2,
       4,     2,     2,     0,     2,     1,     3,     5,     7,     5,
       4,     3,     3,     2,     3,     3,     3,     2,     0,     3,
       3,     3,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     4,     3,     4,
       3,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 36 "syntax.y"
                     { (yyval.type_node)= create_node("Program", 0, 1, create_child_list(1,(node []){(yyvsp[0].type_node)}));semantic((yyval.type_node));translate_Program((yyval.type_node));}
#line 1539 "syntax.tab.c"
    break;

  case 3:
#line 38 "syntax.y"
                               { (yyval.type_node) = create_node("ExtDefList", 0,2,create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1545 "syntax.tab.c"
    break;

  case 4:
#line 39 "syntax.y"
                      { (yyval.type_node) = create_node("NULL",-1,0,NULL);}
#line 1551 "syntax.tab.c"
    break;

  case 5:
#line 41 "syntax.y"
                                 { (yyval.type_node)= create_node("ExtDef", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1557 "syntax.tab.c"
    break;

  case 6:
#line 42 "syntax.y"
                            {(yyval.type_node)= create_node("ExtDef", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1563 "syntax.tab.c"
    break;

  case 7:
#line 43 "syntax.y"
                                { (yyval.type_node)= create_node("ExtDef", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1569 "syntax.tab.c"
    break;

  case 8:
#line 44 "syntax.y"
                     { (yyval.type_node)= create_node("ExtDef", 0, 2, create_child_list(2,(node[]){(yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1575 "syntax.tab.c"
    break;

  case 9:
#line 45 "syntax.y"
                          {}
#line 1581 "syntax.tab.c"
    break;

  case 10:
#line 46 "syntax.y"
                 {}
#line 1587 "syntax.tab.c"
    break;

  case 11:
#line 47 "syntax.y"
               {}
#line 1593 "syntax.tab.c"
    break;

  case 12:
#line 48 "syntax.y"
                {}
#line 1599 "syntax.tab.c"
    break;

  case 13:
#line 49 "syntax.y"
                           {}
#line 1605 "syntax.tab.c"
    break;

  case 14:
#line 50 "syntax.y"
                           {}
#line 1611 "syntax.tab.c"
    break;

  case 15:
#line 52 "syntax.y"
                    { (yyval.type_node)= create_node("ExtDecList", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1617 "syntax.tab.c"
    break;

  case 16:
#line 53 "syntax.y"
                              { (yyval.type_node)= create_node("ExtDecList", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1623 "syntax.tab.c"
    break;

  case 17:
#line 54 "syntax.y"
                              {}
#line 1629 "syntax.tab.c"
    break;

  case 18:
#line 56 "syntax.y"
                 { (yyval.type_node)= create_node("Specifier", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1635 "syntax.tab.c"
    break;

  case 19:
#line 57 "syntax.y"
                      { (yyval.type_node)= create_node("Specifier", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1641 "syntax.tab.c"
    break;

  case 20:
#line 59 "syntax.y"
                                              { (yyval.type_node)= create_node("StructSpecifier", 0, 5, create_child_list(5, (node[]){(yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1647 "syntax.tab.c"
    break;

  case 21:
#line 60 "syntax.y"
                 { (yyval.type_node)= create_node("StructSpecifier", 0, 2, create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1653 "syntax.tab.c"
    break;

  case 22:
#line 61 "syntax.y"
                       {}
#line 1659 "syntax.tab.c"
    break;

  case 23:
#line 62 "syntax.y"
                                 {}
#line 1665 "syntax.tab.c"
    break;

  case 24:
#line 64 "syntax.y"
            { (yyval.type_node)= create_node("OptTag", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1671 "syntax.tab.c"
    break;

  case 25:
#line 65 "syntax.y"
                      { (yyval.type_node) = create_node("NULL",-1,0,NULL);; }
#line 1677 "syntax.tab.c"
    break;

  case 26:
#line 67 "syntax.y"
         { (yyval.type_node)= create_node("Tag", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1683 "syntax.tab.c"
    break;

  case 27:
#line 69 "syntax.y"
            { (yyval.type_node)= create_node("VarDec", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1689 "syntax.tab.c"
    break;

  case 28:
#line 70 "syntax.y"
                       { (yyval.type_node)= create_node("VarDec", 0, 4, create_child_list(4, (node[]){(yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1695 "syntax.tab.c"
    break;

  case 29:
#line 71 "syntax.y"
                             {}
#line 1701 "syntax.tab.c"
    break;

  case 30:
#line 72 "syntax.y"
                         {}
#line 1707 "syntax.tab.c"
    break;

  case 31:
#line 73 "syntax.y"
               {}
#line 1713 "syntax.tab.c"
    break;

  case 32:
#line 75 "syntax.y"
                         { (yyval.type_node)= create_node("FunDec", 0, 4, create_child_list(4, (node[]){(yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1719 "syntax.tab.c"
    break;

  case 33:
#line 76 "syntax.y"
               { (yyval.type_node)= create_node("FunDec", 0, 3, create_child_list(3,(node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1725 "syntax.tab.c"
    break;

  case 34:
#line 77 "syntax.y"
                     {}
#line 1731 "syntax.tab.c"
    break;

  case 35:
#line 78 "syntax.y"
                  {}
#line 1737 "syntax.tab.c"
    break;

  case 36:
#line 79 "syntax.y"
                          {}
#line 1743 "syntax.tab.c"
    break;

  case 37:
#line 81 "syntax.y"
                                 { (yyval.type_node)= create_node("VarList", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1749 "syntax.tab.c"
    break;

  case 38:
#line 82 "syntax.y"
               { (yyval.type_node)= create_node("VarList", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1755 "syntax.tab.c"
    break;

  case 39:
#line 84 "syntax.y"
                            { (yyval.type_node)= create_node("ParamDec", 0, 2, create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1761 "syntax.tab.c"
    break;

  case 40:
#line 86 "syntax.y"
                                { (yyval.type_node)= create_node("CompSt", 0, 4, create_child_list(4, (node[]){(yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1767 "syntax.tab.c"
    break;

  case 41:
#line 87 "syntax.y"
               {}
#line 1773 "syntax.tab.c"
    break;

  case 42:
#line 89 "syntax.y"
                         { (yyval.type_node)= create_node("StmtList", 0, 2, create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1779 "syntax.tab.c"
    break;

  case 43:
#line 90 "syntax.y"
                      { (yyval.type_node) = create_node("NULL",-1,0,NULL);; }
#line 1785 "syntax.tab.c"
    break;

  case 44:
#line 92 "syntax.y"
                { (yyval.type_node)= create_node("Stmt", 0, 2, create_child_list(2,(node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1791 "syntax.tab.c"
    break;

  case 45:
#line 93 "syntax.y"
             { (yyval.type_node)= create_node("Stmt", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)}));  }
#line 1797 "syntax.tab.c"
    break;

  case 46:
#line 94 "syntax.y"
                      { (yyval.type_node)= create_node("Stmt", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1803 "syntax.tab.c"
    break;

  case 47:
#line 95 "syntax.y"
                        { (yyval.type_node)= create_node("Stmt", 0, 5, create_child_list(5, (node[]){(yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1809 "syntax.tab.c"
    break;

  case 48:
#line 96 "syntax.y"
                                  { (yyval.type_node)= create_node("Stmt", 0, 7, create_child_list(7, (node[]){(yyvsp[-6].type_node), (yyvsp[-5].type_node), (yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node),(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1815 "syntax.tab.c"
    break;

  case 49:
#line 97 "syntax.y"
                           { (yyval.type_node)= create_node("Stmt", 0, 5, create_child_list(5, (node[]){(yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1821 "syntax.tab.c"
    break;

  case 50:
#line 98 "syntax.y"
                           {}
#line 1827 "syntax.tab.c"
    break;

  case 51:
#line 99 "syntax.y"
                     {}
#line 1833 "syntax.tab.c"
    break;

  case 52:
#line 100 "syntax.y"
                     {}
#line 1839 "syntax.tab.c"
    break;

  case 53:
#line 101 "syntax.y"
                 {}
#line 1845 "syntax.tab.c"
    break;

  case 54:
#line 102 "syntax.y"
                     {}
#line 1851 "syntax.tab.c"
    break;

  case 55:
#line 103 "syntax.y"
                      {}
#line 1857 "syntax.tab.c"
    break;

  case 56:
#line 104 "syntax.y"
                        {}
#line 1863 "syntax.tab.c"
    break;

  case 57:
#line 106 "syntax.y"
                      { (yyval.type_node)= create_node("DefList", 0, 2, create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1869 "syntax.tab.c"
    break;

  case 58:
#line 107 "syntax.y"
                      { (yyval.type_node) = create_node("NULL",-1,0,NULL);; }
#line 1875 "syntax.tab.c"
    break;

  case 59:
#line 109 "syntax.y"
                             { (yyval.type_node)= create_node("Def", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1881 "syntax.tab.c"
    break;

  case 60:
#line 110 "syntax.y"
                          {}
#line 1887 "syntax.tab.c"
    break;

  case 61:
#line 111 "syntax.y"
                         {}
#line 1893 "syntax.tab.c"
    break;

  case 62:
#line 113 "syntax.y"
              { (yyval.type_node)= create_node("DecList", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1899 "syntax.tab.c"
    break;

  case 63:
#line 114 "syntax.y"
                        { (yyval.type_node)= create_node("DecList", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1905 "syntax.tab.c"
    break;

  case 64:
#line 116 "syntax.y"
             { (yyval.type_node)= create_node("Dec", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1911 "syntax.tab.c"
    break;

  case 65:
#line 117 "syntax.y"
                          { (yyval.type_node)= create_node("Dec", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1917 "syntax.tab.c"
    break;

  case 66:
#line 119 "syntax.y"
                       { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1923 "syntax.tab.c"
    break;

  case 67:
#line 120 "syntax.y"
                  { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1929 "syntax.tab.c"
    break;

  case 68:
#line 121 "syntax.y"
                 { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1935 "syntax.tab.c"
    break;

  case 69:
#line 122 "syntax.y"
                    { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1941 "syntax.tab.c"
    break;

  case 70:
#line 123 "syntax.y"
                   { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1947 "syntax.tab.c"
    break;

  case 71:
#line 124 "syntax.y"
                    { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1953 "syntax.tab.c"
    break;

  case 72:
#line 125 "syntax.y"
                   { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1959 "syntax.tab.c"
    break;

  case 73:
#line 126 "syntax.y"
                  { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1965 "syntax.tab.c"
    break;

  case 74:
#line 127 "syntax.y"
                { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1971 "syntax.tab.c"
    break;

  case 75:
#line 128 "syntax.y"
                { (yyval.type_node)= create_node("Exp", 0, 2, create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1977 "syntax.tab.c"
    break;

  case 76:
#line 129 "syntax.y"
              { (yyval.type_node)= create_node("Exp", 0, 2, create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1983 "syntax.tab.c"
    break;

  case 77:
#line 130 "syntax.y"
                    { (yyval.type_node)= create_node("Exp", 0, 4, create_child_list(4, (node[]){(yyvsp[-3].type_node),(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1989 "syntax.tab.c"
    break;

  case 78:
#line 131 "syntax.y"
               { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node),(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1995 "syntax.tab.c"
    break;

  case 79:
#line 132 "syntax.y"
                    { (yyval.type_node)= create_node("Exp", 0, 4, create_child_list(4, (node[]){(yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 2001 "syntax.tab.c"
    break;

  case 80:
#line 133 "syntax.y"
                 { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 2007 "syntax.tab.c"
    break;

  case 81:
#line 134 "syntax.y"
         { (yyval.type_node)= create_node("Exp", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 2013 "syntax.tab.c"
    break;

  case 82:
#line 135 "syntax.y"
          { (yyval.type_node)= create_node("Exp", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 2019 "syntax.tab.c"
    break;

  case 83:
#line 136 "syntax.y"
            { (yyval.type_node)= create_node("Exp", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 2025 "syntax.tab.c"
    break;

  case 84:
#line 137 "syntax.y"
                  {}
#line 2031 "syntax.tab.c"
    break;

  case 85:
#line 138 "syntax.y"
                 {}
#line 2037 "syntax.tab.c"
    break;

  case 86:
#line 139 "syntax.y"
                  {}
#line 2043 "syntax.tab.c"
    break;

  case 87:
#line 140 "syntax.y"
                              {}
#line 2049 "syntax.tab.c"
    break;

  case 88:
#line 141 "syntax.y"
                         {}
#line 2055 "syntax.tab.c"
    break;

  case 89:
#line 142 "syntax.y"
                        {}
#line 2061 "syntax.tab.c"
    break;

  case 90:
#line 143 "syntax.y"
                           {}
#line 2067 "syntax.tab.c"
    break;

  case 91:
#line 144 "syntax.y"
                          {}
#line 2073 "syntax.tab.c"
    break;

  case 92:
#line 145 "syntax.y"
                           {}
#line 2079 "syntax.tab.c"
    break;

  case 93:
#line 146 "syntax.y"
                          {}
#line 2085 "syntax.tab.c"
    break;

  case 94:
#line 147 "syntax.y"
                          {}
#line 2091 "syntax.tab.c"
    break;

  case 95:
#line 148 "syntax.y"
                         {}
#line 2097 "syntax.tab.c"
    break;

  case 96:
#line 149 "syntax.y"
                       {}
#line 2103 "syntax.tab.c"
    break;

  case 97:
#line 151 "syntax.y"
                      { (yyval.type_node)= create_node("Args", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node),(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 2109 "syntax.tab.c"
    break;

  case 98:
#line 152 "syntax.y"
          { (yyval.type_node)= create_node("Args", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 2115 "syntax.tab.c"
    break;


#line 2119 "syntax.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 155 "syntax.y"

