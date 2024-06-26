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

#line 76 "syntax.tab.c"

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
#line 6 "syntax.y"

    node type_node;

#line 165 "syntax.tab.c"

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
#define YYLAST   542

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

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
       0,    34,    34,    36,    37,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    49,    50,    51,    53,    54,    56,
      57,    58,    59,    61,    62,    64,    66,    67,    68,    69,
      70,    72,    73,    74,    75,    76,    78,    79,    81,    83,
      84,    86,    87,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   103,   104,   106,   107,
     108,   110,   111,   113,   114,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   148,   149
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

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-58)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   134,  -127,   108,    23,  -127,     6,    15,  -127,     4,
      54,  -127,  -127,  -127,    70,    37,    24,    46,    86,   121,
    -127,  -127,  -127,   142,    65,  -127,   170,   109,    24,  -127,
      32,   161,    28,  -127,    31,   159,    64,  -127,  -127,    31,
    -127,  -127,  -127,   102,   102,   177,  -127,   191,   102,   174,
     188,  -127,    83,  -127,   190,   110,   147,   189,    64,  -127,
      94,   196,   192,  -127,  -127,  -127,   207,    56,   209,  -127,
      32,  -127,  -127,    86,    53,   206,   226,   140,   228,  -127,
    -127,    95,  -127,  -127,   216,  -127,  -127,  -127,   421,   421,
     421,   221,     9,   141,  -127,   213,    94,   157,  -127,  -127,
     225,  -127,  -127,   421,  -127,   102,  -127,  -127,  -127,   198,
     215,    -2,   463,   242,   176,   222,   421,   118,   421,  -127,
    -127,   243,  -127,   241,   261,   281,   301,   321,   341,   361,
     381,   249,   401,  -127,   505,  -127,   247,  -127,   434,   234,
    -127,  -127,  -127,  -127,   124,   477,  -127,  -127,   491,  -127,
     250,   505,   251,   398,   262,   215,   263,   215,   264,    -2,
     265,    -2,   267,   195,   268,   518,  -127,   233,   448,  -127,
     421,  -127,  -127,   124,   124,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,   239,  -127,   124,  -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    17,     0,     0,     2,     0,     0,    18,    24,
       0,     9,    10,    11,     0,     0,     0,     0,    25,     0,
      20,     1,     3,     0,     0,     7,     0,     0,     0,    23,
       0,     0,     0,    13,     0,     0,     0,     8,    21,     0,
      12,    30,     6,     0,     0,     0,     5,    24,     0,     0,
      37,    34,    24,    32,     0,     0,     0,     0,     0,    40,
       0,     0,     0,    26,    16,    15,     0,     0,    38,    35,
       0,    33,    31,    26,    63,     0,    61,     0,     0,    22,
      56,     0,    81,    82,    80,    84,    83,    85,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,    19,    29,
       0,    27,    36,     0,    60,     0,    59,    58,    52,     0,
      74,    75,     0,     0,     0,     0,     0,     0,     0,    39,
      41,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    64,    62,     0,    77,    97,     0,
      73,    55,    54,    45,     0,     0,    50,    51,     0,    53,
       0,    65,     0,    68,     0,    69,     0,    70,     0,    71,
       0,    72,     0,    66,     0,    67,    79,     0,     0,    94,
       0,    76,    49,     0,     0,    86,    89,    90,    91,    92,
      93,    87,    88,    95,    78,    96,    46,    48,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,   272,  -127,   139,    13,  -127,   276,  -127,   -44,
     273,   -24,  -127,    89,   194,  -126,   101,  -127,   -51,  -127,
     -88,   122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    26,    56,     8,    15,    20,    27,
      16,    49,    50,    94,    95,    96,    57,    58,    75,    76,
      97,   139
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     110,   111,   112,   114,    68,    78,    -4,     1,    54,    29,
     115,    74,    74,     7,    14,   134,    23,   131,   172,     7,
      24,   138,   132,    21,    25,    35,    30,     2,   145,    52,
     148,   116,    55,    47,     3,   151,   153,   155,   157,   159,
     161,   163,   165,    48,   168,    48,   102,   186,   187,     2,
      36,    53,     2,     2,   135,    31,     3,   100,   -57,     3,
       3,    74,   189,    34,   103,    55,    31,   -57,   -57,   -57,
     -57,   -57,   -57,    38,   -26,   -26,    32,    45,   -57,    33,
     -23,   101,   138,    48,   -57,     2,   -57,    32,    29,   -26,
     -57,   -57,     3,   -57,   -57,    81,   -57,    82,    83,    84,
      85,    86,    87,    62,   108,    37,    71,    63,    88,    17,
      43,    62,   -23,    18,    89,    73,    90,    46,   -14,    44,
      36,   -42,    59,    91,    92,    81,    93,    82,    83,    84,
      85,    86,    87,    45,   -24,     9,   -24,    60,    88,    10,
      61,   146,   117,    11,    89,   147,    90,    39,    77,   106,
      36,    40,    63,    91,    92,     2,    93,    12,   121,    80,
     -24,    13,     3,   118,    30,    41,   122,    41,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   142,    66,    42,
      67,   132,    64,    65,    51,   143,    59,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    29,    69,    70,   136,
     132,    82,    83,    84,    85,    86,    87,   124,   125,   126,
     127,   128,    88,    72,   131,   104,    79,    41,    89,   132,
      90,   137,   113,    98,    82,    83,    84,    85,    86,    87,
     127,   128,    99,    45,   131,    88,   105,   107,   109,   132,
     119,    89,   150,    90,    82,    83,    84,    85,    86,    87,
     133,   141,   149,   144,   166,    88,   169,   171,   183,   175,
     176,    89,   152,    90,    82,    83,    84,    85,    86,    87,
     188,   177,   178,   179,   180,    88,   181,   182,    22,    19,
      28,    89,   154,    90,    82,    83,    84,    85,    86,    87,
     120,     0,   185,     0,     0,    88,     0,     0,     0,     0,
       0,    89,   156,    90,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,    89,   158,    90,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,    89,   160,    90,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,    89,   162,    90,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,    89,   164,    90,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,    89,   167,    90,    82,    83,    84,    85,    86,    87,
       0,   125,   126,   127,   128,    88,     0,   131,     0,     0,
       0,    89,   132,    90,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,    89,     0,    90,   170,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,     0,     0,     0,   132,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,     0,
       0,     0,   132,   184,   123,   124,   125,   126,   127,   128,
     129,   130,   131,     0,     0,     0,   140,   132,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,     0,
     173,   132,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,     0,   174,   132,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,     0,     0,   132,
     124,   125,   126,   127,   128,   129,     0,   131,     0,     0,
       0,     0,   132
};

static const yytype_int16 yycheck[] =
{
      88,    89,    90,    91,    48,    56,     0,     1,    32,     5,
       1,    55,    56,     0,     1,   103,     1,    19,   144,     6,
       5,   109,    24,     0,     9,     1,    22,    21,   116,     1,
     118,    22,     1,     1,    28,   123,   124,   125,   126,   127,
     128,   129,   130,    30,   132,    32,    70,   173,   174,    21,
      26,    23,    21,    21,   105,     1,    28,     1,    27,    28,
      28,   105,   188,    26,    11,     1,     1,     3,     4,     5,
       6,     7,     8,    27,     9,    10,    22,    24,    14,     9,
      26,    25,   170,    70,    20,    21,    22,    22,     5,    24,
      26,    27,    28,    29,    30,     1,    32,     3,     4,     5,
       6,     7,     8,     1,     9,    16,    23,     5,    14,     1,
       1,     1,    26,     5,    20,     5,    22,    28,     9,    10,
      26,    27,    27,    29,    30,     1,    32,     3,     4,     5,
       6,     7,     8,    24,    26,     1,    26,    36,    14,     5,
      39,    23,     1,     9,    20,    27,    22,    26,     1,     9,
      26,     9,     5,    29,    30,    21,    32,    23,     1,    58,
      26,    27,    28,    22,    22,    25,     9,    25,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     1,     1,     9,
       3,    24,    43,    44,    23,     9,    27,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     5,    23,    10,     1,
      24,     3,     4,     5,     6,     7,     8,    12,    13,    14,
      15,    16,    14,    23,    19,     9,    27,    25,    20,    24,
      22,    23,     1,    27,     3,     4,     5,     6,     7,     8,
      15,    16,    25,    24,    19,    14,    10,     9,    22,    24,
      27,    20,     1,    22,     3,     4,     5,     6,     7,     8,
      25,     9,     9,    31,     5,    14,     9,    23,    25,     9,
       9,    20,     1,    22,     3,     4,     5,     6,     7,     8,
      31,     9,     9,     9,     9,    14,     9,     9,     6,     3,
       7,    20,     1,    22,     3,     4,     5,     6,     7,     8,
      96,    -1,   170,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    20,     1,    22,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    20,     1,    22,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    20,     1,    22,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    20,     1,    22,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    20,     1,    22,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    20,     1,    22,     3,     4,     5,     6,     7,     8,
      -1,    13,    14,    15,    16,    14,    -1,    19,    -1,    -1,
      -1,    20,    24,    22,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    22,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    23,    24,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      23,    24,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    23,    24,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,
      12,    13,    14,    15,    16,    17,    -1,    19,    -1,    -1,
      -1,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    21,    28,    34,    35,    36,    38,    39,     1,
       5,     9,    23,    27,    38,    40,    43,     1,     5,    40,
      41,     0,    35,     1,     5,     9,    37,    42,    43,     5,
      22,     1,    22,     9,    26,     1,    26,    46,    27,    26,
       9,    25,     9,     1,    10,    24,    46,     1,    38,    44,
      45,    23,     1,    23,    44,     1,    38,    49,    50,    27,
      49,    49,     1,     5,    37,    37,     1,     3,    42,    23,
      10,    23,    23,     5,    42,    51,    52,     1,    51,    27,
      49,     1,     3,     4,     5,     6,     7,     8,    14,    20,
      22,    29,    30,    32,    46,    47,    48,    53,    27,    25,
       1,    25,    44,    11,     9,    10,     9,     9,     9,    22,
      53,    53,    53,     1,    53,     1,    22,     1,    22,    27,
      47,     1,     9,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    24,    25,    53,    51,     1,    23,    53,    54,
      23,     9,     1,     9,    31,    53,    23,    27,    53,     9,
       1,    53,     1,    53,     1,    53,     1,    53,     1,    53,
       1,    53,     1,    53,     1,    53,     5,     1,    53,     9,
      10,    23,    48,    23,    23,     9,     9,     9,     9,     9,
       9,     9,     9,    25,    25,    54,    48,    48,    31,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    37,    37,    37,    38,    38,    39,
      39,    39,    39,    40,    40,    41,    42,    42,    42,    42,
      42,    43,    43,    43,    43,    43,    44,    44,    45,    46,
      46,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    49,    49,    50,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     2,     3,     2,
       2,     2,     3,     3,     1,     3,     3,     1,     1,     5,
       2,     3,     5,     1,     0,     1,     1,     4,     5,     4,
       2,     4,     3,     4,     3,     4,     3,     1,     2,     4,
       2,     2,     0,     2,     1,     3,     5,     7,     5,     4,
       3,     3,     2,     3,     3,     3,     2,     0,     3,     3,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     3,     4,     3,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     1
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
#line 34 "syntax.y"
                     { (yyval.type_node)= create_node("Program", 0, 1, create_child_list(1,(node []){(yyvsp[0].type_node)}));print_tree((yyval.type_node),0);}
#line 1532 "syntax.tab.c"
    break;

  case 3:
#line 36 "syntax.y"
                               { (yyval.type_node) = create_node("ExtDefList", 0,2,create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1538 "syntax.tab.c"
    break;

  case 4:
#line 37 "syntax.y"
                      { (yyval.type_node) = create_node("NULL",-1,0,NULL);}
#line 1544 "syntax.tab.c"
    break;

  case 5:
#line 39 "syntax.y"
                                 { (yyval.type_node)= create_node("ExtDef", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1550 "syntax.tab.c"
    break;

  case 6:
#line 40 "syntax.y"
                                { (yyval.type_node)= create_node("ExtDef", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1556 "syntax.tab.c"
    break;

  case 7:
#line 41 "syntax.y"
                     { (yyval.type_node)= create_node("ExtDef", 0, 2, create_child_list(2,(node[]){(yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1562 "syntax.tab.c"
    break;

  case 8:
#line 42 "syntax.y"
                          {}
#line 1568 "syntax.tab.c"
    break;

  case 9:
#line 43 "syntax.y"
                 {}
#line 1574 "syntax.tab.c"
    break;

  case 10:
#line 44 "syntax.y"
               {}
#line 1580 "syntax.tab.c"
    break;

  case 11:
#line 45 "syntax.y"
                {}
#line 1586 "syntax.tab.c"
    break;

  case 12:
#line 46 "syntax.y"
                           {}
#line 1592 "syntax.tab.c"
    break;

  case 13:
#line 47 "syntax.y"
                           {}
#line 1598 "syntax.tab.c"
    break;

  case 14:
#line 49 "syntax.y"
                    { (yyval.type_node)= create_node("ExtDecList", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1604 "syntax.tab.c"
    break;

  case 15:
#line 50 "syntax.y"
                              { (yyval.type_node)= create_node("ExtDecList", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1610 "syntax.tab.c"
    break;

  case 16:
#line 51 "syntax.y"
                              {}
#line 1616 "syntax.tab.c"
    break;

  case 17:
#line 53 "syntax.y"
                 { (yyval.type_node)= create_node("Specifier", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1622 "syntax.tab.c"
    break;

  case 18:
#line 54 "syntax.y"
                      { (yyval.type_node)= create_node("Specifier", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1628 "syntax.tab.c"
    break;

  case 19:
#line 56 "syntax.y"
                                              { (yyval.type_node)= create_node("StructSpecifier", 0, 5, create_child_list(5, (node[]){(yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1634 "syntax.tab.c"
    break;

  case 20:
#line 57 "syntax.y"
                 { (yyval.type_node)= create_node("StructSpecifier", 0, 2, create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1640 "syntax.tab.c"
    break;

  case 21:
#line 58 "syntax.y"
                       {}
#line 1646 "syntax.tab.c"
    break;

  case 22:
#line 59 "syntax.y"
                                 {}
#line 1652 "syntax.tab.c"
    break;

  case 23:
#line 61 "syntax.y"
            { (yyval.type_node)= create_node("OptTag", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1658 "syntax.tab.c"
    break;

  case 24:
#line 62 "syntax.y"
                      { (yyval.type_node) = create_node("NULL",-1,0,NULL);; }
#line 1664 "syntax.tab.c"
    break;

  case 25:
#line 64 "syntax.y"
         { (yyval.type_node)= create_node("Tag", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1670 "syntax.tab.c"
    break;

  case 26:
#line 66 "syntax.y"
            { (yyval.type_node)= create_node("VarDec", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1676 "syntax.tab.c"
    break;

  case 27:
#line 67 "syntax.y"
                       { (yyval.type_node)= create_node("VarDec", 0, 4, create_child_list(4, (node[]){(yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1682 "syntax.tab.c"
    break;

  case 28:
#line 68 "syntax.y"
                             {}
#line 1688 "syntax.tab.c"
    break;

  case 29:
#line 69 "syntax.y"
                         {}
#line 1694 "syntax.tab.c"
    break;

  case 30:
#line 70 "syntax.y"
               {}
#line 1700 "syntax.tab.c"
    break;

  case 31:
#line 72 "syntax.y"
                         { (yyval.type_node)= create_node("FunDec", 0, 4, create_child_list(4, (node[]){(yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1706 "syntax.tab.c"
    break;

  case 32:
#line 73 "syntax.y"
               { (yyval.type_node)= create_node("FunDec", 0, 3, create_child_list(3,(node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1712 "syntax.tab.c"
    break;

  case 33:
#line 74 "syntax.y"
                     {}
#line 1718 "syntax.tab.c"
    break;

  case 34:
#line 75 "syntax.y"
                  {}
#line 1724 "syntax.tab.c"
    break;

  case 35:
#line 76 "syntax.y"
                          {}
#line 1730 "syntax.tab.c"
    break;

  case 36:
#line 78 "syntax.y"
                                 { (yyval.type_node)= create_node("VarList", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1736 "syntax.tab.c"
    break;

  case 37:
#line 79 "syntax.y"
               { (yyval.type_node)= create_node("VarList", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1742 "syntax.tab.c"
    break;

  case 38:
#line 81 "syntax.y"
                            { (yyval.type_node)= create_node("ParamDec", 0, 2, create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1748 "syntax.tab.c"
    break;

  case 39:
#line 83 "syntax.y"
                                { (yyval.type_node)= create_node("CompSt", 0, 4, create_child_list(4, (node[]){(yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1754 "syntax.tab.c"
    break;

  case 40:
#line 84 "syntax.y"
               {}
#line 1760 "syntax.tab.c"
    break;

  case 41:
#line 86 "syntax.y"
                         { (yyval.type_node)= create_node("StmtList", 0, 2, create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1766 "syntax.tab.c"
    break;

  case 42:
#line 87 "syntax.y"
                      { (yyval.type_node) = create_node("NULL",-1,0,NULL);; }
#line 1772 "syntax.tab.c"
    break;

  case 43:
#line 89 "syntax.y"
                { (yyval.type_node)= create_node("Stmt", 0, 2, create_child_list(2,(node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1778 "syntax.tab.c"
    break;

  case 44:
#line 90 "syntax.y"
             { (yyval.type_node)= create_node("Stmt", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)}));  }
#line 1784 "syntax.tab.c"
    break;

  case 45:
#line 91 "syntax.y"
                      { (yyval.type_node)= create_node("Stmt", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1790 "syntax.tab.c"
    break;

  case 46:
#line 92 "syntax.y"
                        { (yyval.type_node)= create_node("Stmt", 0, 5, create_child_list(5, (node[]){(yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1796 "syntax.tab.c"
    break;

  case 47:
#line 93 "syntax.y"
                                  { (yyval.type_node)= create_node("Stmt", 0, 7, create_child_list(7, (node[]){(yyvsp[-6].type_node), (yyvsp[-5].type_node), (yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node),(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1802 "syntax.tab.c"
    break;

  case 48:
#line 94 "syntax.y"
                           { (yyval.type_node)= create_node("Stmt", 0, 5, create_child_list(5, (node[]){(yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1808 "syntax.tab.c"
    break;

  case 49:
#line 95 "syntax.y"
                           {}
#line 1814 "syntax.tab.c"
    break;

  case 50:
#line 96 "syntax.y"
                     {}
#line 1820 "syntax.tab.c"
    break;

  case 51:
#line 97 "syntax.y"
                     {}
#line 1826 "syntax.tab.c"
    break;

  case 52:
#line 98 "syntax.y"
                 {}
#line 1832 "syntax.tab.c"
    break;

  case 53:
#line 99 "syntax.y"
                     {}
#line 1838 "syntax.tab.c"
    break;

  case 54:
#line 100 "syntax.y"
                      {}
#line 1844 "syntax.tab.c"
    break;

  case 55:
#line 101 "syntax.y"
                        {}
#line 1850 "syntax.tab.c"
    break;

  case 56:
#line 103 "syntax.y"
                      { (yyval.type_node)= create_node("DefList", 0, 2, create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1856 "syntax.tab.c"
    break;

  case 57:
#line 104 "syntax.y"
                      { (yyval.type_node) = create_node("NULL",-1,0,NULL);; }
#line 1862 "syntax.tab.c"
    break;

  case 58:
#line 106 "syntax.y"
                             { (yyval.type_node)= create_node("Def", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1868 "syntax.tab.c"
    break;

  case 59:
#line 107 "syntax.y"
                          {}
#line 1874 "syntax.tab.c"
    break;

  case 60:
#line 108 "syntax.y"
                         {}
#line 1880 "syntax.tab.c"
    break;

  case 61:
#line 110 "syntax.y"
              { (yyval.type_node)= create_node("DecList", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1886 "syntax.tab.c"
    break;

  case 62:
#line 111 "syntax.y"
                        { (yyval.type_node)= create_node("DecList", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1892 "syntax.tab.c"
    break;

  case 63:
#line 113 "syntax.y"
             { (yyval.type_node)= create_node("Dec", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 1898 "syntax.tab.c"
    break;

  case 64:
#line 114 "syntax.y"
                          { (yyval.type_node)= create_node("Dec", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1904 "syntax.tab.c"
    break;

  case 65:
#line 116 "syntax.y"
                       { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1910 "syntax.tab.c"
    break;

  case 66:
#line 117 "syntax.y"
                  { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1916 "syntax.tab.c"
    break;

  case 67:
#line 118 "syntax.y"
                 { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1922 "syntax.tab.c"
    break;

  case 68:
#line 119 "syntax.y"
                    { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1928 "syntax.tab.c"
    break;

  case 69:
#line 120 "syntax.y"
                   { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1934 "syntax.tab.c"
    break;

  case 70:
#line 121 "syntax.y"
                    { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1940 "syntax.tab.c"
    break;

  case 71:
#line 122 "syntax.y"
                   { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1946 "syntax.tab.c"
    break;

  case 72:
#line 123 "syntax.y"
                  { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1952 "syntax.tab.c"
    break;

  case 73:
#line 124 "syntax.y"
                { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1958 "syntax.tab.c"
    break;

  case 74:
#line 125 "syntax.y"
                { (yyval.type_node)= create_node("Exp", 0, 2, create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1964 "syntax.tab.c"
    break;

  case 75:
#line 126 "syntax.y"
              { (yyval.type_node)= create_node("Exp", 0, 2, create_child_list(2, (node[]){(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1970 "syntax.tab.c"
    break;

  case 76:
#line 127 "syntax.y"
                    { (yyval.type_node)= create_node("Exp", 0, 4, create_child_list(4, (node[]){(yyvsp[-3].type_node),(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1976 "syntax.tab.c"
    break;

  case 77:
#line 128 "syntax.y"
               { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node),(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1982 "syntax.tab.c"
    break;

  case 78:
#line 129 "syntax.y"
                    { (yyval.type_node)= create_node("Exp", 0, 4, create_child_list(4, (node[]){(yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 1988 "syntax.tab.c"
    break;

  case 79:
#line 130 "syntax.y"
                 { (yyval.type_node)= create_node("Exp", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node)})); }
#line 1994 "syntax.tab.c"
    break;

  case 80:
#line 131 "syntax.y"
         { (yyval.type_node)= create_node("Exp", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 2000 "syntax.tab.c"
    break;

  case 81:
#line 132 "syntax.y"
          { (yyval.type_node)= create_node("Exp", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 2006 "syntax.tab.c"
    break;

  case 82:
#line 133 "syntax.y"
            { (yyval.type_node)= create_node("Exp", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 2012 "syntax.tab.c"
    break;

  case 83:
#line 134 "syntax.y"
                  {}
#line 2018 "syntax.tab.c"
    break;

  case 84:
#line 135 "syntax.y"
                 {}
#line 2024 "syntax.tab.c"
    break;

  case 85:
#line 136 "syntax.y"
                  {}
#line 2030 "syntax.tab.c"
    break;

  case 86:
#line 137 "syntax.y"
                              {}
#line 2036 "syntax.tab.c"
    break;

  case 87:
#line 138 "syntax.y"
                         {}
#line 2042 "syntax.tab.c"
    break;

  case 88:
#line 139 "syntax.y"
                        {}
#line 2048 "syntax.tab.c"
    break;

  case 89:
#line 140 "syntax.y"
                           {}
#line 2054 "syntax.tab.c"
    break;

  case 90:
#line 141 "syntax.y"
                          {}
#line 2060 "syntax.tab.c"
    break;

  case 91:
#line 142 "syntax.y"
                           {}
#line 2066 "syntax.tab.c"
    break;

  case 92:
#line 143 "syntax.y"
                          {}
#line 2072 "syntax.tab.c"
    break;

  case 93:
#line 144 "syntax.y"
                          {}
#line 2078 "syntax.tab.c"
    break;

  case 94:
#line 145 "syntax.y"
                         {}
#line 2084 "syntax.tab.c"
    break;

  case 95:
#line 146 "syntax.y"
                       {}
#line 2090 "syntax.tab.c"
    break;

  case 96:
#line 148 "syntax.y"
                      { (yyval.type_node)= create_node("Args", 0, 3, create_child_list(3, (node[]){(yyvsp[-2].type_node),(yyvsp[-1].type_node), (yyvsp[0].type_node)})); }
#line 2096 "syntax.tab.c"
    break;

  case 97:
#line 149 "syntax.y"
          { (yyval.type_node)= create_node("Args", 0, 1, create_child_list(1,(node[]){(yyvsp[0].type_node)})); }
#line 2102 "syntax.tab.c"
    break;


#line 2106 "syntax.tab.c"

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
#line 152 "syntax.y"

