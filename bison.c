/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */

/*

    YABASIC  ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2022
    more info at www.yabasic.de

    BISON part
     
    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/


#ifndef YABASIC_INCLUDED
#include "yabasic.h"     /* definitions of yabasic */
#endif

#ifdef WINDOWS
#include <malloc.h>
#else
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif
#endif

#if HAVE_ALLOCA_H
#ifndef WINDOWS
#include <alloca.h>
#endif
#endif

void __yy_bcopy(char *,char *,int); /* prototype missing */

int tileol; /* true, read should go to eon of line */
int function_type=ftNONE; /* contains function type while parsing function */
char *current_function=NULL; /* name of currently parsed function */
int exported=FALSE; /* true, if function is exported */
int yylex(void);
extern struct library *current_library; /* defined in main.c: name of currently parsed library */
extern int yylineno; /* defined in flex */
int missing_endif=0;
int missing_endif_line=0;
int missing_endsub=0;
int missing_endsub_line=0;
int missing_next=0;
int missing_next_line=0;
int missing_wend=0;
int missing_wend_line=0;
int missing_until=0;
int missing_until_line=0;
int missing_loop=0;
int missing_loop_line=0;
int loop_nesting=0;
int switch_nesting=0;

void report_if_missing(char *text,int eof) {
  if (missing_loop || missing_endif || missing_next || missing_until || missing_wend) {
    if (eof) {
       error_without_position(sERROR,text);
    } else {
       error(sERROR,text);
    }
    collect_missing_clauses(string,-1);
    if (string[0]) {
      error_without_position(sERROR,string);
    }
  }
}

void report_conflicting_close(char *text,int missing) {
  error(sERROR,text);
  collect_missing_clauses(string,missing);
  error(sERROR,string);
}

void collect_missing_clauses(char *string, char exclude) {
  char buff[INBUFFLEN];
  
  string[0]='\0';
  if (missing_endif && exclude!='e') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"if-statement starting at line %d has seen no 'endif' yet",missing_endif_line);
    strcat(string, buff);
  }

  if (missing_next && exclude!='n') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"for-loop starting at line %d has seen no 'next' yet",missing_next_line);
    strcat(string, buff);
  }

  if (missing_wend && exclude!='w') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"while-loop starting at line %d has seen no 'wend' yet",missing_wend_line);
    strcat(string, buff);
  }

  if (missing_until && exclude!='u') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"repeat-loop starting at line %d has seen no 'until' yet",missing_until_line);
    strcat(string, buff);
  }
  
  if (missing_loop && exclude!='l') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"do-loop starting at line %d has seen no 'loop' yet",missing_loop_line);
    strcat(string, buff);
  }
}


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

#include "bison.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tFNUM = 3,                      /* tFNUM  */
  YYSYMBOL_tSYMBOL = 4,                    /* tSYMBOL  */
  YYSYMBOL_tSTRSYM = 5,                    /* tSTRSYM  */
  YYSYMBOL_tDOCU = 6,                      /* tDOCU  */
  YYSYMBOL_tDIGITS = 7,                    /* tDIGITS  */
  YYSYMBOL_tHEXDIGITS = 8,                 /* tHEXDIGITS  */
  YYSYMBOL_tBINDIGITS = 9,                 /* tBINDIGITS  */
  YYSYMBOL_tSTRING = 10,                   /* tSTRING  */
  YYSYMBOL_tFOR = 11,                      /* tFOR  */
  YYSYMBOL_tTO = 12,                       /* tTO  */
  YYSYMBOL_tSTEP = 13,                     /* tSTEP  */
  YYSYMBOL_tNEXT = 14,                     /* tNEXT  */
  YYSYMBOL_tWHILE = 15,                    /* tWHILE  */
  YYSYMBOL_tWEND = 16,                     /* tWEND  */
  YYSYMBOL_tREPEAT = 17,                   /* tREPEAT  */
  YYSYMBOL_tUNTIL = 18,                    /* tUNTIL  */
  YYSYMBOL_tIMPORT = 19,                   /* tIMPORT  */
  YYSYMBOL_tGOTO = 20,                     /* tGOTO  */
  YYSYMBOL_tGOSUB = 21,                    /* tGOSUB  */
  YYSYMBOL_tLABEL = 22,                    /* tLABEL  */
  YYSYMBOL_tON = 23,                       /* tON  */
  YYSYMBOL_tSUB = 24,                      /* tSUB  */
  YYSYMBOL_tENDSUB = 25,                   /* tENDSUB  */
  YYSYMBOL_tLOCAL = 26,                    /* tLOCAL  */
  YYSYMBOL_tSTATIC = 27,                   /* tSTATIC  */
  YYSYMBOL_tEXPORT = 28,                   /* tEXPORT  */
  YYSYMBOL_tERROR = 29,                    /* tERROR  */
  YYSYMBOL_tEXECUTE = 30,                  /* tEXECUTE  */
  YYSYMBOL_tEXECUTE2 = 31,                 /* tEXECUTE2  */
  YYSYMBOL_tCOMPILE = 32,                  /* tCOMPILE  */
  YYSYMBOL_tRUNTIME_CREATED_SUB = 33,      /* tRUNTIME_CREATED_SUB  */
  YYSYMBOL_tINTERRUPT = 34,                /* tINTERRUPT  */
  YYSYMBOL_tBREAK = 35,                    /* tBREAK  */
  YYSYMBOL_tCONTINUE = 36,                 /* tCONTINUE  */
  YYSYMBOL_tSWITCH = 37,                   /* tSWITCH  */
  YYSYMBOL_tSEND = 38,                     /* tSEND  */
  YYSYMBOL_tCASE = 39,                     /* tCASE  */
  YYSYMBOL_tDEFAULT = 40,                  /* tDEFAULT  */
  YYSYMBOL_tLOOP = 41,                     /* tLOOP  */
  YYSYMBOL_tDO = 42,                       /* tDO  */
  YYSYMBOL_tSEP = 43,                      /* tSEP  */
  YYSYMBOL_tEOPROG = 44,                   /* tEOPROG  */
  YYSYMBOL_tIF = 45,                       /* tIF  */
  YYSYMBOL_tTHEN = 46,                     /* tTHEN  */
  YYSYMBOL_tELSE = 47,                     /* tELSE  */
  YYSYMBOL_tELSIF = 48,                    /* tELSIF  */
  YYSYMBOL_tENDIF = 49,                    /* tENDIF  */
  YYSYMBOL_tIMPLICITENDIF = 50,            /* tIMPLICITENDIF  */
  YYSYMBOL_tUSING = 51,                    /* tUSING  */
  YYSYMBOL_tPRINT = 52,                    /* tPRINT  */
  YYSYMBOL_tINPUT = 53,                    /* tINPUT  */
  YYSYMBOL_tRETURN = 54,                   /* tRETURN  */
  YYSYMBOL_tDIM = 55,                      /* tDIM  */
  YYSYMBOL_tEND = 56,                      /* tEND  */
  YYSYMBOL_tEXIT = 57,                     /* tEXIT  */
  YYSYMBOL_tAT = 58,                       /* tAT  */
  YYSYMBOL_tSCREEN = 59,                   /* tSCREEN  */
  YYSYMBOL_tREVERSE = 60,                  /* tREVERSE  */
  YYSYMBOL_tCOLOUR = 61,                   /* tCOLOUR  */
  YYSYMBOL_tBACKCOLOUR = 62,               /* tBACKCOLOUR  */
  YYSYMBOL_tAND = 63,                      /* tAND  */
  YYSYMBOL_tOR = 64,                       /* tOR  */
  YYSYMBOL_tNOT = 65,                      /* tNOT  */
  YYSYMBOL_tBITNOT = 66,                   /* tBITNOT  */
  YYSYMBOL_tEOR = 67,                      /* tEOR  */
  YYSYMBOL_tSHL = 68,                      /* tSHL  */
  YYSYMBOL_tSHR = 69,                      /* tSHR  */
  YYSYMBOL_tNEQ = 70,                      /* tNEQ  */
  YYSYMBOL_tLEQ = 71,                      /* tLEQ  */
  YYSYMBOL_tGEQ = 72,                      /* tGEQ  */
  YYSYMBOL_tLTN = 73,                      /* tLTN  */
  YYSYMBOL_tGTN = 74,                      /* tGTN  */
  YYSYMBOL_tEQU = 75,                      /* tEQU  */
  YYSYMBOL_tEQU2 = 76,                     /* tEQU2  */
  YYSYMBOL_tPOW = 77,                      /* tPOW  */
  YYSYMBOL_tREAD = 78,                     /* tREAD  */
  YYSYMBOL_tDATA = 79,                     /* tDATA  */
  YYSYMBOL_tRESTORE = 80,                  /* tRESTORE  */
  YYSYMBOL_tOPEN = 81,                     /* tOPEN  */
  YYSYMBOL_tCLOSE = 82,                    /* tCLOSE  */
  YYSYMBOL_tSEEK = 83,                     /* tSEEK  */
  YYSYMBOL_tTELL = 84,                     /* tTELL  */
  YYSYMBOL_tAS = 85,                       /* tAS  */
  YYSYMBOL_tREADING = 86,                  /* tREADING  */
  YYSYMBOL_tWRITING = 87,                  /* tWRITING  */
  YYSYMBOL_tORIGIN = 88,                   /* tORIGIN  */
  YYSYMBOL_tWINDOW = 89,                   /* tWINDOW  */
  YYSYMBOL_tDOT = 90,                      /* tDOT  */
  YYSYMBOL_tLINE = 91,                     /* tLINE  */
  YYSYMBOL_tCIRCLE = 92,                   /* tCIRCLE  */
  YYSYMBOL_tTRIANGLE = 93,                 /* tTRIANGLE  */
  YYSYMBOL_tTEXT = 94,                     /* tTEXT  */
  YYSYMBOL_tCLEAR = 95,                    /* tCLEAR  */
  YYSYMBOL_tFILL = 96,                     /* tFILL  */
  YYSYMBOL_tPRINTER = 97,                  /* tPRINTER  */
  YYSYMBOL_tWAIT = 98,                     /* tWAIT  */
  YYSYMBOL_tBELL = 99,                     /* tBELL  */
  YYSYMBOL_tLET = 100,                     /* tLET  */
  YYSYMBOL_tARDIM = 101,                   /* tARDIM  */
  YYSYMBOL_tARSIZE = 102,                  /* tARSIZE  */
  YYSYMBOL_tBIND = 103,                    /* tBIND  */
  YYSYMBOL_tRECT = 104,                    /* tRECT  */
  YYSYMBOL_tGETBIT = 105,                  /* tGETBIT  */
  YYSYMBOL_tPUTBIT = 106,                  /* tPUTBIT  */
  YYSYMBOL_tGETCHAR = 107,                 /* tGETCHAR  */
  YYSYMBOL_tPUTCHAR = 108,                 /* tPUTCHAR  */
  YYSYMBOL_tNEW = 109,                     /* tNEW  */
  YYSYMBOL_tCURVE = 110,                   /* tCURVE  */
  YYSYMBOL_tSIN = 111,                     /* tSIN  */
  YYSYMBOL_tASIN = 112,                    /* tASIN  */
  YYSYMBOL_tCOS = 113,                     /* tCOS  */
  YYSYMBOL_tACOS = 114,                    /* tACOS  */
  YYSYMBOL_tTAN = 115,                     /* tTAN  */
  YYSYMBOL_tATAN = 116,                    /* tATAN  */
  YYSYMBOL_tEXP = 117,                     /* tEXP  */
  YYSYMBOL_tLOG = 118,                     /* tLOG  */
  YYSYMBOL_tSQRT = 119,                    /* tSQRT  */
  YYSYMBOL_tSQR = 120,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 121,                   /* tMYEOF  */
  YYSYMBOL_tABS = 122,                     /* tABS  */
  YYSYMBOL_tSIG = 123,                     /* tSIG  */
  YYSYMBOL_tINT = 124,                     /* tINT  */
  YYSYMBOL_tCEIL = 125,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 126,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 127,                    /* tFRAC  */
  YYSYMBOL_tROUND = 128,                   /* tROUND  */
  YYSYMBOL_tMOD = 129,                     /* tMOD  */
  YYSYMBOL_tRAN = 130,                     /* tRAN  */
  YYSYMBOL_tVAL = 131,                     /* tVAL  */
  YYSYMBOL_tLEFT = 132,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 133,                   /* tRIGHT  */
  YYSYMBOL_tMID = 134,                     /* tMID  */
  YYSYMBOL_tLEN = 135,                     /* tLEN  */
  YYSYMBOL_tMIN = 136,                     /* tMIN  */
  YYSYMBOL_tMAX = 137,                     /* tMAX  */
  YYSYMBOL_tSTR = 138,                     /* tSTR  */
  YYSYMBOL_tINKEY = 139,                   /* tINKEY  */
  YYSYMBOL_tCHR = 140,                     /* tCHR  */
  YYSYMBOL_tASC = 141,                     /* tASC  */
  YYSYMBOL_tHEX = 142,                     /* tHEX  */
  YYSYMBOL_tDEC = 143,                     /* tDEC  */
  YYSYMBOL_tBIN = 144,                     /* tBIN  */
  YYSYMBOL_tUPPER = 145,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 146,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 147,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 148,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 149,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 150,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 151,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 152,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 153,                   /* tRTRIM  */
  YYSYMBOL_tINSTR = 154,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 155,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 156,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 157,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 158,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 159,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 160,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 161,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 162,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 163,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 164,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 165,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 166,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 167,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 168,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 169,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 170,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 171,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 172,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 173,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 174,                    /* tDATE  */
  YYSYMBOL_tTIME = 175,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 176,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 177,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 178,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 179,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 180,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 181,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 182,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 183, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 184,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 185, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 186,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 187,                   /* tEVAL2  */
  YYSYMBOL_tBEAM_OPEN = 188,               /* tBEAM_OPEN  */
  YYSYMBOL_tBEAM_CLOSE = 189,              /* tBEAM_CLOSE  */
  YYSYMBOL_tBEAM_TITLE = 190,              /* tBEAM_TITLE  */
  YYSYMBOL_tBEAM_SIZE = 191,               /* tBEAM_SIZE  */
  YYSYMBOL_tBEAM_RUNNING = 192,            /* tBEAM_RUNNING  */
  YYSYMBOL_tBEAM_BEGIN = 193,              /* tBEAM_BEGIN  */
  YYSYMBOL_tBEAM_END = 194,                /* tBEAM_END  */
  YYSYMBOL_tBEAM_BUTTON = 195,             /* tBEAM_BUTTON  */
  YYSYMBOL_tBEAM_LABEL = 196,              /* tBEAM_LABEL  */
  YYSYMBOL_tBEAM_TEXT = 197,               /* tBEAM_TEXT  */
  YYSYMBOL_tBEAM_INPUT = 198,              /* tBEAM_INPUT  */
  YYSYMBOL_tBEAM_CHECKBOX = 199,           /* tBEAM_CHECKBOX  */
  YYSYMBOL_tBEAM_COMBO = 200,              /* tBEAM_COMBO  */
  YYSYMBOL_tBEAM_SLIDER = 201,             /* tBEAM_SLIDER  */
  YYSYMBOL_tBEAM_PROGRESS = 202,           /* tBEAM_PROGRESS  */
  YYSYMBOL_tBEAM_VBAR = 203,               /* tBEAM_VBAR  */
  YYSYMBOL_tBEAM_SEPARATOR = 204,          /* tBEAM_SEPARATOR  */
  YYSYMBOL_tBEAM_SPACING = 205,            /* tBEAM_SPACING  */
  YYSYMBOL_tBEAM_IMAGE = 206,              /* tBEAM_IMAGE  */
  YYSYMBOL_tBEAM_ROW = 207,                /* tBEAM_ROW  */
  YYSYMBOL_tBEAM_ROW_END = 208,            /* tBEAM_ROW_END  */
  YYSYMBOL_tBEAM_GROUP_BEGIN = 209,        /* tBEAM_GROUP_BEGIN  */
  YYSYMBOL_tBEAM_GROUP_END = 210,          /* tBEAM_GROUP_END  */
  YYSYMBOL_tBEAM_PANEL_BEGIN = 211,        /* tBEAM_PANEL_BEGIN  */
  YYSYMBOL_tBEAM_PANEL_END = 212,          /* tBEAM_PANEL_END  */
  YYSYMBOL_tBEAM_MSGBOX = 213,             /* tBEAM_MSGBOX  */
  YYSYMBOL_tBEAM_CONFIRM = 214,            /* tBEAM_CONFIRM  */
  YYSYMBOL_tBEAM_OPEN_FILE = 215,          /* tBEAM_OPEN_FILE  */
  YYSYMBOL_tBEAM_SAVE_FILE = 216,          /* tBEAM_SAVE_FILE  */
  YYSYMBOL_tBEAM_SET_COLOR = 217,          /* tBEAM_SET_COLOR  */
  YYSYMBOL_tBEAM_SET_STYLE = 218,          /* tBEAM_SET_STYLE  */
  YYSYMBOL_tBEAM_TIME = 219,               /* tBEAM_TIME  */
  YYSYMBOL_tBEAM_SLEEP = 220,              /* tBEAM_SLEEP  */
  YYSYMBOL_tBEAM_NMEA_OPEN = 221,          /* tBEAM_NMEA_OPEN  */
  YYSYMBOL_tBEAM_NMEA_CLOSE = 222,         /* tBEAM_NMEA_CLOSE  */
  YYSYMBOL_tBEAM_NMEA_READ = 223,          /* tBEAM_NMEA_READ  */
  YYSYMBOL_tBEAM_NMEA_FIELD = 224,         /* tBEAM_NMEA_FIELD  */
  YYSYMBOL_225_ = 225,                     /* '-'  */
  YYSYMBOL_226_ = 226,                     /* '+'  */
  YYSYMBOL_227_ = 227,                     /* '*'  */
  YYSYMBOL_228_ = 228,                     /* '/'  */
  YYSYMBOL_UMINUS = 229,                   /* UMINUS  */
  YYSYMBOL_230_ = 230,                     /* ';'  */
  YYSYMBOL_231_ = 231,                     /* ','  */
  YYSYMBOL_232_ = 232,                     /* '('  */
  YYSYMBOL_233_ = 233,                     /* ')'  */
  YYSYMBOL_234_ = 234,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 235,                 /* $accept  */
  YYSYMBOL_program_or_expression = 236,    /* program_or_expression  */
  YYSYMBOL_program = 237,                  /* program  */
  YYSYMBOL_statement_list = 238,           /* statement_list  */
  YYSYMBOL_239_1 = 239,                    /* $@1  */
  YYSYMBOL_240_2 = 240,                    /* $@2  */
  YYSYMBOL_assignment = 241,               /* assignment  */
  YYSYMBOL_statement = 242,                /* statement  */
  YYSYMBOL_243_3 = 243,                    /* $@3  */
  YYSYMBOL_244_4 = 244,                    /* $@4  */
  YYSYMBOL_245_5 = 245,                    /* $@5  */
  YYSYMBOL_246_6 = 246,                    /* $@6  */
  YYSYMBOL_247_7 = 247,                    /* $@7  */
  YYSYMBOL_248_8 = 248,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 249,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 250,        /* string_assignment  */
  YYSYMBOL_to = 251,                       /* to  */
  YYSYMBOL_open_clause = 252,              /* open_clause  */
  YYSYMBOL_seek_clause = 253,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 254,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 255,        /* string_expression  */
  YYSYMBOL_string_function = 256,          /* string_function  */
  YYSYMBOL_number_assignment = 257,        /* number_assignment  */
  YYSYMBOL_expression = 258,               /* expression  */
  YYSYMBOL_259_9 = 259,                    /* $@9  */
  YYSYMBOL_260_10 = 260,                   /* $@10  */
  YYSYMBOL_arrayref = 261,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 262,          /* string_arrayref  */
  YYSYMBOL_coordinates = 263,              /* coordinates  */
  YYSYMBOL_function = 264,                 /* function  */
  YYSYMBOL_const = 265,                    /* const  */
  YYSYMBOL_number = 266,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 267,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 268,                  /* dimlist  */
  YYSYMBOL_function_or_array = 269,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 270,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 271,                /* call_list  */
  YYSYMBOL_272_11 = 272,                   /* $@11  */
  YYSYMBOL_calls = 273,                    /* calls  */
  YYSYMBOL_call_item = 274,                /* call_item  */
  YYSYMBOL_function_definition = 275,      /* function_definition  */
  YYSYMBOL_276_12 = 276,                   /* $@12  */
  YYSYMBOL_277_13 = 277,                   /* $@13  */
  YYSYMBOL_278_14 = 278,                   /* $@14  */
  YYSYMBOL_endsub = 279,                   /* endsub  */
  YYSYMBOL_function_name = 280,            /* function_name  */
  YYSYMBOL_export = 281,                   /* export  */
  YYSYMBOL_local_list = 282,               /* local_list  */
  YYSYMBOL_local_item = 283,               /* local_item  */
  YYSYMBOL_static_list = 284,              /* static_list  */
  YYSYMBOL_static_item = 285,              /* static_item  */
  YYSYMBOL_paramlist = 286,                /* paramlist  */
  YYSYMBOL_paramitem = 287,                /* paramitem  */
  YYSYMBOL_for_loop = 288,                 /* for_loop  */
  YYSYMBOL_289_15 = 289,                   /* $@15  */
  YYSYMBOL_290_16 = 290,                   /* $@16  */
  YYSYMBOL_291_17 = 291,                   /* $@17  */
  YYSYMBOL_292_18 = 292,                   /* $@18  */
  YYSYMBOL_next = 293,                     /* next  */
  YYSYMBOL_step_part = 294,                /* step_part  */
  YYSYMBOL_next_symbol = 295,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 296,  /* switch_number_or_string  */
  YYSYMBOL_297_19 = 297,                   /* $@19  */
  YYSYMBOL_sep_list = 298,                 /* sep_list  */
  YYSYMBOL_number_or_string = 299,         /* number_or_string  */
  YYSYMBOL_case_list = 300,                /* case_list  */
  YYSYMBOL_301_20 = 301,                   /* $@20  */
  YYSYMBOL_default = 302,                  /* default  */
  YYSYMBOL_303_21 = 303,                   /* $@21  */
  YYSYMBOL_do_loop = 304,                  /* do_loop  */
  YYSYMBOL_305_22 = 305,                   /* $@22  */
  YYSYMBOL_loop = 306,                     /* loop  */
  YYSYMBOL_while_loop = 307,               /* while_loop  */
  YYSYMBOL_308_23 = 308,                   /* $@23  */
  YYSYMBOL_309_24 = 309,                   /* $@24  */
  YYSYMBOL_wend = 310,                     /* wend  */
  YYSYMBOL_repeat_loop = 311,              /* repeat_loop  */
  YYSYMBOL_312_25 = 312,                   /* $@25  */
  YYSYMBOL_until = 313,                    /* until  */
  YYSYMBOL_if_clause = 314,                /* if_clause  */
  YYSYMBOL_315_26 = 315,                   /* $@26  */
  YYSYMBOL_316_27 = 316,                   /* $@27  */
  YYSYMBOL_317_28 = 317,                   /* $@28  */
  YYSYMBOL_318_29 = 318,                   /* $@29  */
  YYSYMBOL_endif = 319,                    /* endif  */
  YYSYMBOL_short_if = 320,                 /* short_if  */
  YYSYMBOL_321_30 = 321,                   /* $@30  */
  YYSYMBOL_end_of_if = 322,                /* end_of_if  */
  YYSYMBOL_else_part = 323,                /* else_part  */
  YYSYMBOL_elsif_part = 324,               /* elsif_part  */
  YYSYMBOL_325_31 = 325,                   /* $@31  */
  YYSYMBOL_326_32 = 326,                   /* $@32  */
  YYSYMBOL_maybe_then = 327,               /* maybe_then  */
  YYSYMBOL_inputlist = 328,                /* inputlist  */
  YYSYMBOL_329_33 = 329,                   /* $@33  */
  YYSYMBOL_input = 330,                    /* input  */
  YYSYMBOL_readlist = 331,                 /* readlist  */
  YYSYMBOL_readitem = 332,                 /* readitem  */
  YYSYMBOL_datalist = 333,                 /* datalist  */
  YYSYMBOL_printlist = 334,                /* printlist  */
  YYSYMBOL_using = 335,                    /* using  */
  YYSYMBOL_inputbody = 336,                /* inputbody  */
  YYSYMBOL_337_34 = 337,                   /* $@34  */
  YYSYMBOL_338_35 = 338,                   /* $@35  */
  YYSYMBOL_339_36 = 339,                   /* $@36  */
  YYSYMBOL_340_37 = 340,                   /* $@37  */
  YYSYMBOL_341_38 = 341,                   /* $@38  */
  YYSYMBOL_prompt = 342,                   /* prompt  */
  YYSYMBOL_printintro = 343,               /* printintro  */
  YYSYMBOL_hashed_number = 344,            /* hashed_number  */
  YYSYMBOL_goto_list = 345,                /* goto_list  */
  YYSYMBOL_gosub_list = 346                /* gosub_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */

void
yyerror(char *message) {
  error(sERROR,message);
}

void
lyyerror(int severity, char *message) {
  error(severity,message);
}


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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int16 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  229
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8620

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  516
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1357

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   480


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   234,     2,     2,     2,     2,
     232,   233,   227,   226,   231,   225,     2,   228,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   230,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     229
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   203,   203,   204,   205,   206,   207,   210,   213,   214,
     214,   214,   217,   218,   219,   220,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   238,   239,   239,   240,   241,   242,   243,   244,
     245,   246,   246,   248,   248,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   260,   261,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   278,   279,
     280,   281,   282,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   353,
     357,   358,   359,   360,   361,   365,   366,   367,   368,   369,
     370,   373,   374,   377,   378,   379,   380,   381,   384,   385,
     388,   389,   392,   393,   394,   395,   396,   397,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   442,
     443,   445,   446,   449,   450,   453,   453,   454,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   489,   492,   495,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   581,   584,   585,   586,   589,
     590,   591,   592,   595,   596,   599,   600,   601,   602,   605,
     608,   611,   611,   614,   615,   616,   619,   620,   623,   624,
     627,   623,   632,   633,   636,   637,   640,   641,   642,   643,
     646,   647,   650,   651,   652,   653,   656,   657,   660,   661,
     662,   663,   666,   667,   668,   671,   672,   673,   674,   677,
     678,   683,   698,   677,   703,   704,   705,   706,   707,   708,
     711,   712,   715,   716,   721,   721,   725,   726,   729,   730,
     734,   736,   735,   740,   741,   741,   745,   745,   751,   752,
     753,   754,   755,   756,   760,   761,   760,   767,   768,   772,
     772,   777,   778,   779,   780,   781,   782,   785,   786,   786,
     788,   785,   792,   793,   794,   795,   796,   797,   800,   800,
     805,   806,   809,   810,   813,   815,   817,   814,   821,   822,
     825,   826,   826,   829,   830,   832,   833,   837,   838,   841,
     842,   844,   845,   849,   850,   851,   852,   855,   856,   857,
     858,   859,   862,   863,   864,   867,   867,   868,   868,   869,
     869,   870,   870,   871,   871,   874,   875,   878,   879,   880,
     881,   882,   883,   884,   885,   886,   887,   888,   889,   890,
     891,   894,   895,   897,   898,   901,   902
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tFNUM", "tSYMBOL",
  "tSTRSYM", "tDOCU", "tDIGITS", "tHEXDIGITS", "tBINDIGITS", "tSTRING",
  "tFOR", "tTO", "tSTEP", "tNEXT", "tWHILE", "tWEND", "tREPEAT", "tUNTIL",
  "tIMPORT", "tGOTO", "tGOSUB", "tLABEL", "tON", "tSUB", "tENDSUB",
  "tLOCAL", "tSTATIC", "tEXPORT", "tERROR", "tEXECUTE", "tEXECUTE2",
  "tCOMPILE", "tRUNTIME_CREATED_SUB", "tINTERRUPT", "tBREAK", "tCONTINUE",
  "tSWITCH", "tSEND", "tCASE", "tDEFAULT", "tLOOP", "tDO", "tSEP",
  "tEOPROG", "tIF", "tTHEN", "tELSE", "tELSIF", "tENDIF", "tIMPLICITENDIF",
  "tUSING", "tPRINT", "tINPUT", "tRETURN", "tDIM", "tEND", "tEXIT", "tAT",
  "tSCREEN", "tREVERSE", "tCOLOUR", "tBACKCOLOUR", "tAND", "tOR", "tNOT",
  "tBITNOT", "tEOR", "tSHL", "tSHR", "tNEQ", "tLEQ", "tGEQ", "tLTN",
  "tGTN", "tEQU", "tEQU2", "tPOW", "tREAD", "tDATA", "tRESTORE", "tOPEN",
  "tCLOSE", "tSEEK", "tTELL", "tAS", "tREADING", "tWRITING", "tORIGIN",
  "tWINDOW", "tDOT", "tLINE", "tCIRCLE", "tTRIANGLE", "tTEXT", "tCLEAR",
  "tFILL", "tPRINTER", "tWAIT", "tBELL", "tLET", "tARDIM", "tARSIZE",
  "tBIND", "tRECT", "tGETBIT", "tPUTBIT", "tGETCHAR", "tPUTCHAR", "tNEW",
  "tCURVE", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP",
  "tLOG", "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tCEIL",
  "tFLOOR", "tFRAC", "tROUND", "tMOD", "tRAN", "tVAL", "tLEFT", "tRIGHT",
  "tMID", "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX",
  "tDEC", "tBIN", "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB",
  "tMOUSEMOD", "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR", "tCHOMP",
  "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tFRNFN_CALL",
  "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_ALLOC", "tFRNBF_FREE",
  "tFRNBF_SIZE", "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET", "tFRNBF_GET2",
  "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE", "tTIME", "tTOKEN",
  "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB", "tSTART_PROGRAM",
  "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION", "tSTART_ASSIGNMENT",
  "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2", "tBEAM_OPEN",
  "tBEAM_CLOSE", "tBEAM_TITLE", "tBEAM_SIZE", "tBEAM_RUNNING",
  "tBEAM_BEGIN", "tBEAM_END", "tBEAM_BUTTON", "tBEAM_LABEL", "tBEAM_TEXT",
  "tBEAM_INPUT", "tBEAM_CHECKBOX", "tBEAM_COMBO", "tBEAM_SLIDER",
  "tBEAM_PROGRESS", "tBEAM_VBAR", "tBEAM_SEPARATOR", "tBEAM_SPACING",
  "tBEAM_IMAGE", "tBEAM_ROW", "tBEAM_ROW_END", "tBEAM_GROUP_BEGIN",
  "tBEAM_GROUP_END", "tBEAM_PANEL_BEGIN", "tBEAM_PANEL_END",
  "tBEAM_MSGBOX", "tBEAM_CONFIRM", "tBEAM_OPEN_FILE", "tBEAM_SAVE_FILE",
  "tBEAM_SET_COLOR", "tBEAM_SET_STYLE", "tBEAM_TIME", "tBEAM_SLEEP",
  "tBEAM_NMEA_OPEN", "tBEAM_NMEA_CLOSE", "tBEAM_NMEA_READ",
  "tBEAM_NMEA_FIELD", "'-'", "'+'", "'*'", "'/'", "UMINUS", "';'", "','",
  "'('", "')'", "'#'", "$accept", "program_or_expression", "program",
  "statement_list", "$@1", "$@2", "assignment", "statement", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "clear_fill_clause", "string_assignment",
  "to", "open_clause", "seek_clause", "string_scalar_or_array",
  "string_expression", "string_function", "number_assignment",
  "expression", "$@9", "$@10", "arrayref", "string_arrayref",
  "coordinates", "function", "const", "number", "symbol_or_lineno",
  "dimlist", "function_or_array", "stringfunction_or_array", "call_list",
  "$@11", "calls", "call_item", "function_definition", "$@12", "$@13",
  "$@14", "endsub", "function_name", "export", "local_list", "local_item",
  "static_list", "static_item", "paramlist", "paramitem", "for_loop",
  "$@15", "$@16", "$@17", "$@18", "next", "step_part", "next_symbol",
  "switch_number_or_string", "$@19", "sep_list", "number_or_string",
  "case_list", "$@20", "default", "$@21", "do_loop", "$@22", "loop",
  "while_loop", "$@23", "$@24", "wend", "repeat_loop", "$@25", "until",
  "if_clause", "$@26", "$@27", "$@28", "$@29", "endif", "short_if", "$@30",
  "end_of_if", "else_part", "elsif_part", "$@31", "$@32", "maybe_then",
  "inputlist", "$@33", "input", "readlist", "readitem", "datalist",
  "printlist", "using", "inputbody", "$@34", "$@35", "$@36", "$@37",
  "$@38", "prompt", "printintro", "hashed_number", "goto_list",
  "gosub_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-964)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-438)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     444,  4763,  3864,  4243,    28,    49,    29,   -57,   -56,  -964,
    -964,  -964,  -964,  -964,    96,    96,    96,  3466,  -964,  -964,
    -964,  4243,  -964,  -964,  4243,    15,    30,  -964,  -964,  -964,
    3864,   -38,  -964,  3864,   167,  -964,  3864,  3864,  3864,   275,
      43,    96,  2073,  1874,  2471,   -31,  3864,  3267,  3864,   348,
       6,  3864,  -964,   212,  4243,  4243,  4243,    45,  -113,  -103,
     -73,   -44,   -14,  2471,  4243,  4243,  4243,    -1,    18,    32,
     107,   118,   155,   170,   173,   179,   185,   211,   224,   263,
     274,   287,   325,   347,   361,   370,   371,   408,   423,  -964,
      72,  -964,  -964,    -8,  -964,  -964,  -964,  -964,   123,   154,
    -964,   258,  -964,  -964,  -964,  -964,  -964,  -964,  -964,  -964,
     460,   461,  -964,  -964,  -964,  -964,   470,   502,   504,   515,
    3864,   516,   547,   548,   558,   580,   597,   615,   621,   624,
     632,   656,   667,   682,   691,   697,   707,   721,   722,   723,
     724,   731,   737,   743,   746,   748,   749,   751,   753,   754,
     758,   759,   760,   763,   765,   766,   769,   770,   771,   772,
     773,   781,   782,   783,   786,   787,   790,   799,   800,   806,
     807,   812,   814,   831,   832,   834,   840,   841,   843,   849,
     860,   866,   876,   878,   879,   881,   887,   890,   891,   892,
     893,   894,   895,   896,   903,   905,   906,   907,   909,   911,
     912,   913,   914,   915,   916,   918,   920,   921,   926,   927,
     932,   933,   936,   939,  3864,  3864,   645,  -964,   110,  -964,
    -964,  -964,  -964,  4243,   -32,   256,   123,   154,   297,  -964,
    3864,  -964,  4243,  -964,   442,  3864,  4553,  -964,  -964,  -964,
    -964,  -964,   281,   235,   360,   386,   328,  -964,  3864,  -964,
     328,  -964,  -964,  3864,  4553,   355,   940,   465,   941,     4,
    3864,   -55,   645,  8392,   942,   944,   427,  8392,   645,   599,
     645,  1742,   945,   950,   472,  -964,  -964,   344,   344,  -964,
    -964,   546,  -964,  3864,  4243,  3864,    19,  8392,   561,  -964,
    -964,  -964,  -964,   618,  4243,  6765,  -964,  3864,  -964,   -10,
     643,  -964,  -964,  3864,  3665,  -964,  -964,  8392,  -964,  -964,
     328,   -11,   -11,  -964,   882,   882,   882,  2670,  4243,   457,
     669,   328,  -148,   -68,  3864,  3864,  3864,  3864,  3864,  4243,
    4243,  3864,  3864,   359,  3864,  4243,  3864,   411,  4243,   456,
    4243,   683,  3864,  4243,  3864,  3864,  -964,   929,  3864,  3864,
    3864,  3864,  4243,  -964,  -964,  -964,  3864,  3864,    76,  3864,
    3864,  3864,  3864,  2272,  2471,   429,   429,  3864,  3864,  3864,
    3864,  3864,  3864,  3864,  3864,  3864,  3864,  3864,  3864,  2471,
    3864,  3864,  3864,  3864,  3864,  3864,  3864,  3864,  2869,  4243,
    4243,  4243,  4243,  4243,  3864,  3864,  3864,  3068,  3864,  4243,
    3864,  4243,  3864,  4243,  4243,  1197,  1309,  1461,  1566,  4243,
    4243,  4243,  4243,  4243,  4243,  4243,  4243,  2471,  4243,  -964,
    -964,  4243,  3864,  4243,  4243,  4243,  4243,  4243,   744,   954,
    4243,   882,  4243,   882,  4243,  4243,  4243,  3864,  3864,  4243,
    4243,  4243,  4243,  3864,  4243,  4243,  4243,  4243,   955,  4243,
    3864,  4243,  1063,    94,   733,  4243,  4243,  4243,  4243,  4243,
    4243,  4243,  4243,  -964,  -964,  -964,  3864,  3864,  3864,  3864,
    3864,  3864,  3864,  3864,  3864,  3864,  3864,  3864,  -178,  -964,
    -964,  -964,  8392,   956,   328,   957,  1116,  8392,   740,  -964,
    -964,  -964,  -964,   961,   962,   964,  -964,   965,   966,   968,
    -964,   645,  8392,   969,  -964,   645,  8392,  1153,   817,  1157,
    4553,  3864,   972,  4243,  -964,  -964,  3864,   645,   426,   248,
     976,    17,  -964,  1199,  -964,  -964,   476,  3864,  3864,  -964,
    -964,   275,  -964,  -964,    63,  6780,   328,  8392,   405,  4043,
    3864,   328,  3864,  -964,   -55,  -964,  -964,  3864,  4243,  -964,
    3864,   -10,  3864,  3864,   978,   980,   981,   982,  -964,  1198,
    -147,  3864,  3864,  3864,  3864,  1430,  6827,  6853,  1488,  1684,
    -146,    12,  6885,  6946,  -964,  1699,    39,  6961,  -964,   -96,
    -964,    87,  -964,  6993,   -34,  2287,  2486,  -964,   983,   -10,
     -10,  8392,   328,   489,   984,   985,  7019,  7051,  2685,  7066,
    7081,  7127,   986,   379,   989,   988,   990,   991,   992,   993,
     996,   998,   -10,  7159,  2884,  3083,  3282,  3481,  3680,   524,
    3879,   545,  4061,  4261,   997,  4468,  4601,  4657,  4867,  5014,
    5045,  5077,  7185,  -964,  5133,   -19,   327,   435,   453,    -7,
    7247,  7262,   130,   560,  -964,  5148,  5180,    11,  5211,  -129,
    5243,    41,    64,  -964,    95,  -964,   310,  -964,   313,  -964,
     319,   322,   323,   358,   480,   536,   378,   380,   381,   412,
    1001,   -36,  1008,  1009,   413,  5258,   415,     9,   587,   631,
     639,  -964,  -964,   642,  -166,   655,  -116,   658,   416,   417,
    7293,  5273,   659,   672,   675,   676,  7325,   684,   687,   431,
     434,  -964,   699,  5314,   701,  -964,  -964,   328,   328,   328,
     328,   328,   328,   328,  -964,  3864,  3864,   668,  1057,   935,
      59,   196,   -17,    -3,  -964,   -50,   -50,  1063,  1063,  -964,
    -964,  -964,  4553,  -964,  -964,  3864,  -964,  -964,  -964,  -964,
      96,    96,  -964,  -964,   360,  -964,  -964,   386,  3864,  -964,
    1172,  -964,  -964,  -964,  -964,  -964,  -964,  -964,  -964,   458,
    7351,  3864,   177,  5346,  4339,  -964,  -964,  3864,  3864,  -964,
    -964,  3864,  -964,   530,  1010,  1011,   999,  1013,  7366,  7381,
    1023,  1024,  -964,  -964,  -964,  3864,  1131,  1139,  -964,   717,
    7428,  8392,  -964,  -964,   719,  -964,  3864,  7459,  7491,  -964,
    3864,  3864,  3864,  -964,  -964,   645,  8392,   645,  8392,  7547,
    7562,  -964,  4243,  3864,  -964,  -964,  -964,  3864,  3864,  3864,
    -964,  3864,  3864,  -964,  3864,  3864,  -964,  -964,  -964,  4553,
    3864,  3864,  3864,  -964,  -964,  -964,  -964,  -964,  3864,  3864,
    -964,  3864,  3864,  3864,  -964,  4243,  -964,  4139,  -964,  1025,
    1030,  -964,  -964,  3864,  3864,  3864,  3864,  -964,  -964,  -964,
    -964,  -964,  3864,  -964,  -964,  3864,  -964,  -964,  -964,  -964,
    -964,  -964,  -964,  -964,  -964,  -964,  -964,  3864,  -964,  -964,
    3864,  3864,  3864,  -964,  3864,  3864,  -964,  4243,  -964,  -964,
    -964,  -964,  -964,  3864,  -964,  -964,  -964,  -964,  -964,  -964,
    -964,  -964,  -964,  -964,  -964,  4243,  4243,  -964,  -964,  -964,
    -964,  -964,  4243,  -964,  -964,  -964,  -964,  -964,  -964,  3864,
    -964,  3864,  3864,  3864,  1260,  4243,  -964,  1260,  4243,  -964,
    4243,  -964,  -964,  3864,  -964,  3864,  3864,  3864,  3864,  3864,
    4243,  4243,  -964,  -964,  3864,  -964,  3864,    76,  4366,  3864,
      10,  8392,  -964,  1035,  -964,  1036,  1046,  1047,  -964,  1048,
    1056,  -964,  -964,  -964,   528,  4553,  -964,  -964,  -964,  3864,
    7594,  4243,  1233,  -964,  4243,   328,   645,   426,  7625,   530,
     530,  5377,  1060,  1061,  -964,  1064,  -964,  -964,  -964,  -964,
    3864,  3864,  -964,  -964,  7657,  2471,  2471,  4243,  4243,  4243,
    -964,  3864,  3864,  1065,  5439,  5454,   953,  4243,  4243,   452,
    7672,  7687,  7728,  7760,  7791,  5480,  7853,  7868,  -964,  8392,
     -10,  -964,  1062,  5512,  5543,  5558,  5573,  5620,   454,  1066,
     183,  -964,  -964,  5646,  5678,  1067,    35,  5739,  5754,  5786,
    5812,  5844,  1176,  5859,  5874,   214,  5920,   279,   285,   468,
    5952,  7894,  7926,  5978,     1,   471,    21,   479,   497,  7957,
    7972,  7987,  6040,  8034,  8060,   498,   499,  6055,  6086,    50,
    -964,  -964,  -964,    96,    96,  -964,  -964,  -964,  -964,  3864,
    1253,  1259,  1262,  6118,  3864,   527,  1075,   291,  -964,  3864,
    -964,  -964,  -964,  -964,  -964,  -964,  1076,  1077,  8392,  8392,
    4243,  -964,  -964,   328,   328,   720,  8092,  8392,  -964,  1236,
    1237,  3864,  1238,   745,   328,  -964,  3864,  3864,  3864,  3864,
    3864,  -964,  3864,  3864,  3864,   565,  -964,  -964,  -964,  -964,
    -964,  -964,  -964,  4243,  -964,  -964,  -964,  -964,  3864,  -964,
    -964,  -964,  -964,  -964,  3864,  -964,  -964,  -964,  4243,  -964,
    -964,  3864,  -964,  3864,  -964,  -964,  -964,  4243,  3864,  -964,
    4243,  -964,  -964,  4243,  -964,  -964,  -964,  4243,  3864,  3864,
    -964,  3864,  3864,  -964,  -964,  -964,  -964,  3864,  -964,  -964,
    -964,  -964,  -964,  1269,   529,  6144,  1263,  3864,  4243,  6159,
     530,  1085,  1087,   530,  -964,  -964,   328,  4243,  4243,  4243,
    4243,  6174,  4243,  3864,  6221,  6252,  8153,  8168,  6284,  6340,
    6355,  -964,  1090,  1092,   100,  -964,   535,  8200,  6387,   549,
    6418,  6450,   568,  6465,   569,   588,   612,  6480,  6521,  8226,
    8258,    68,  4553,  4973,  3864,  1279,  -964,  1095,  -964,  1100,
    8273,   617,  -964,  -964,  -964,  -964,  -964,   328,   328,   328,
     328,  1258,   328,  8392,  -964,  -964,  3864,  3864,  -964,  -964,
    -964,  1101,  1105,   565,  -964,  -964,  3864,  -964,  -964,  -964,
    -964,  -964,  -964,  -964,  -964,  -964,  -964,  -964,  3864,  3864,
    3864,  -964,  1262,  1306,   501,  4553,  -964,  4243,  3864,  3864,
    -964,  1199,  4243,  6553,  6584,  -964,  -964,  -964,  4553,  6646,
    8288,  8334,  8392,  4553,  -964,  -964,  1262,   828,   311,  8366,
    6661,   530,   328,  -964,  -964,     0,  -964,  3864,  3864,  1262,
    4553,  -964,  -964,  -964,  -964,  -964,  -964,  -964,  4243,  -964,
    3864,  -964,  -964,  -964,  -964,  -964,  6687,  6719,   908,  1262,
     622,  6750,  -964,  -964,  -964,  -964,  -964,  -964,  -964,  -964,
    1341,  1269,  -964,  -964,  -964,  -964,  -964
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   140,     0,     0,     0,   366,     0,     0,     0,   112,
     389,   424,   429,    18,     0,     0,     0,     0,    31,    33,
     367,     0,   351,   351,     0,   368,    25,    27,   404,   416,
       0,   497,    55,    67,     0,   109,   110,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   141,
     142,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       9,    17,     8,     0,    12,    46,    48,    14,    29,    30,
      28,     0,    20,    21,    24,    23,    22,    35,    36,   339,
     235,   162,   340,   341,   342,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
       0,     0,     0,     0,     0,     0,     0,   295,   298,   301,
     304,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,   193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,     0,   249,
     229,   234,   164,     0,     0,     0,     0,     0,     0,     1,
       0,   351,     0,   351,     0,     0,    16,   344,   343,    37,
      38,    45,     0,     0,     0,     0,    19,    50,   353,    51,
      49,   369,    26,     0,    16,   448,     0,   501,     0,     0,
     477,   493,    69,    68,     0,     0,    70,   111,    60,     0,
      62,     0,   469,   471,    63,   467,   473,     0,     0,   474,
     336,    64,    66,     0,    96,     0,     0,   512,     0,    93,
      98,    86,    47,     0,     0,     0,    74,     0,    57,    79,
       0,    95,    94,     0,     0,   143,   144,    99,    13,    15,
     113,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     0,     0,   358,   351,   351,     0,     0,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   351,
     351,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,   217,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,   213,     0,   145,     0,     0,   425,     9,    39,
      40,    41,    43,   372,   373,    32,   370,   378,   379,    34,
     376,   356,   357,   352,   354,   409,   408,     0,     9,     0,
      16,     0,     0,     0,   498,   499,     0,   480,   482,    52,
       0,     0,    56,   495,   351,   351,     0,     0,     0,   351,
     351,     0,   338,   337,     0,     0,    97,   511,     0,     0,
       0,    73,     0,    78,   493,   152,   151,     0,     0,    75,
       0,    81,     0,     0,   160,     0,     0,     0,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,     0,     0,     0,   131,     0,
     133,     0,   135,     0,     0,     0,     0,    10,     0,     0,
       0,   214,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   275,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,     0,     0,     0,     0,     0,
       0,     0,     0,   296,     0,   299,     0,   302,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   192,   194,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   332,     0,     0,     0,   167,   250,   244,   246,   248,
     245,   247,   242,   243,   166,     0,     0,   222,   224,   226,
     223,   225,   220,   221,   240,   237,   236,   238,   239,   349,
     350,   390,    16,   436,   434,     0,   435,   431,   433,   430,
       0,     0,   351,   351,     0,   351,   351,     0,     0,   406,
     410,   423,   421,   422,   419,   418,   420,   417,   438,     9,
       0,     0,     0,     0,     0,   478,    53,    54,     0,   485,
     487,     0,   496,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   468,   475,   476,     0,     0,     0,   155,   154,
     158,   253,    58,    76,    89,    80,     0,     0,     0,   351,
       0,     0,     0,   103,   104,   105,   106,   107,   108,     0,
       0,   118,     0,     0,   121,   122,   123,     0,     0,     0,
     129,     0,     0,   132,     0,     0,   137,   138,   139,    16,
       0,     0,     0,   364,   365,   359,   317,   205,     0,     0,
     308,     0,     0,     0,   318,     0,   319,     0,   312,     0,
       0,   230,   231,     0,     0,     0,     0,   254,   255,   256,
     257,   258,     0,   259,   261,     0,   262,   264,   265,   227,
     271,   272,   266,   268,   269,   270,   267,     0,   274,   279,
       0,     0,     0,   278,     0,     0,   175,     0,   172,   178,
     179,   280,   203,     0,   281,   204,   180,   181,   294,   297,
     300,   303,   184,   182,   183,     0,     0,   185,   287,   186,
     293,   292,     0,   195,   288,   187,   289,   188,   291,     0,
     189,     0,     0,     0,     0,     0,   198,     0,     0,   200,
       0,   324,   208,     0,   326,     0,     0,     0,     0,     0,
       0,     0,   209,   210,     0,   211,     0,   218,   216,     0,
       9,   432,   513,    42,   515,    44,     0,     0,   371,     0,
       0,   377,   355,   407,   413,    16,   450,   451,   449,     0,
       0,     0,   502,   500,     0,   483,   481,   482,     0,     0,
       0,     0,   463,   465,   494,   460,   345,   347,   351,   351,
       0,     0,   470,   472,    71,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    87,
       0,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     428,   427,   426,     0,     0,   374,   375,   380,   381,     0,
       0,     0,   439,     0,     0,     0,     0,     0,   479,     0,
     486,   488,   489,   351,   351,   461,     0,     0,    59,    61,
       0,   156,   157,   153,   159,    90,    83,    84,   161,     0,
       0,     0,     0,   116,   117,   119,     0,     0,     0,     0,
       0,   130,     0,     0,     0,   382,   306,   307,   309,   310,
     311,   320,   321,     0,   322,   232,   233,   201,     0,   260,
     263,   273,   168,   169,     0,   171,   276,   277,     0,   173,
     282,     0,   283,     0,   285,   196,   190,     0,     0,   207,
       0,   314,   197,     0,   316,   199,   228,     0,     0,     0,
     329,     0,     0,   333,   334,   335,   212,     0,   514,   516,
     411,   414,   405,   454,   504,     0,   503,     0,     0,     0,
       0,     0,     0,     0,   346,   348,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,   385,   386,     0,   383,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   400,    16,   140,     0,   452,   508,     0,   505,     0,
       0,     0,   491,   490,   464,   466,   462,    91,    82,   148,
     149,     0,   147,   115,   120,   124,     0,     0,   125,   134,
     136,     0,     0,     0,   360,   323,     0,   170,   174,   284,
     286,   290,   206,   313,   315,   325,   327,   328,     0,     0,
       0,   391,   412,     9,   458,    16,   440,     0,     0,     0,
     484,   495,     0,     0,     0,   387,   388,   384,    16,     0,
       0,     0,   401,    16,   459,   455,   453,     0,     0,     0,
       0,     0,   146,   126,   127,     9,   202,     0,     0,   392,
      16,   447,   444,   445,   446,   442,   443,   441,     0,   509,
       0,   506,   492,   363,   362,   361,     0,     0,     0,   456,
       0,     0,   330,   331,   395,   397,   398,   399,   394,   396,
     402,   454,   510,   507,   403,   393,   457
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -964,  -964,  -964,  -191,  -964,  -964,  1342,   518,  -964,  -964,
    -964,  -964,  -964,  -964,  -964,  1298,  -298,  -964,  -964,  -240,
     644,  -964,  1299,    -2,  -964,  -964,   995,  -361,   109,  -964,
     820,   -30,    23,  -964,     3,     5,   166,  -964,  -964,   608,
    1353,  -964,  -964,  -964,  -964,  -964,  -964,  -964,   619,  -964,
     620,  -964,   101,  -964,  -964,  -964,  -964,  -964,  -964,  -964,
    -964,  -964,  -964,  -964,   280,  -964,  -964,  -964,  -964,  -964,
    -964,  -964,  -964,  -964,  -964,  -964,  -964,  -964,  -964,  -964,
    -964,  -964,  -964,  -964,  -964,  -964,  -964,  -964,  -964,    22,
    -964,  -964,  -964,  -963,  -964,  -964,  -964,   835,  -964,  -964,
     393,   833,  -964,  -964,  -964,  -964,  -964,    84,  -964,    25,
    -964,  -964
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    89,    90,   347,   829,    91,    92,   244,   245,
     740,   741,   261,   544,    93,    94,   547,    95,    96,   555,
     216,   217,    97,   295,   716,   715,   608,   609,   296,   219,
     279,   220,   239,   266,   221,   222,   247,   248,   503,   504,
     100,   593,  1022,  1298,  1335,   835,   101,   495,   496,   499,
     500,  1214,  1215,   102,   234,   949,  1303,  1338,  1350,  1281,
    1355,   103,   253,   750,   507,   964,  1232,  1081,  1233,   104,
     254,   757,   105,   235,   732,  1072,   106,   236,   739,   107,
     509,   965,  1183,  1307,  1327,   108,   510,   968,  1286,  1235,
    1320,  1351,  1305,   984,  1193,   985,   274,   275,   281,   519,
     765,   522,   979,   980,  1190,  1291,   523,   773,   260,   288,
     953,   955
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     218,   545,   545,   520,    98,   611,    99,   226,   514,   227,
     280,   515,   479,   552,   553,   243,  1090,  1091,   230,   232,
     256,   769,   257,   258,   770,  1333,  1070,   473,   255,   229,
     538,   263,     7,     8,   267,   269,   271,   252,   240,   241,
     287,   287,   287,   251,  1334,   488,   109,   545,   462,   307,
     112,   113,   114,   276,  1071,   705,   226,   294,   227,   472,
     473,   287,  1177,   508,   282,   925,   109,   926,   292,   293,
     112,   113,   114,   783,   473,   556,   557,    20,   462,   462,
     462,  1280,    25,   563,   348,   349,   804,   816,   320,   455,
     456,   457,   458,   459,   460,   461,   350,   462,   464,   465,
     237,   306,   893,   238,   894,   466,   467,   468,   469,   470,
     471,   472,   473,   464,   465,   928,   346,   929,   358,   314,
     466,   467,   468,   469,   470,   471,   472,   473,    53,   315,
     462,   464,   465,   470,   471,   472,   473,   823,   466,   467,
     468,   469,   470,   471,   472,   473,   466,   467,   468,   469,
     470,   471,   472,   473,   463,   313,   299,   300,   462,   316,
      58,    59,    60,   564,   455,   456,   457,   458,   459,   460,
     461,   264,   265,   464,   465,   231,   233,   476,   477,   521,
     466,   467,   468,   469,   470,   471,   472,   473,   317,   249,
     462,   684,   462,   686,   462,   912,   259,   913,   351,   826,
     455,   456,   457,   458,   459,   460,   461,   462,   474,   475,
     476,   477,   452,   454,   879,   462,     7,     8,   318,   462,
     546,   546,   474,   475,   476,   477,   883,  1243,   482,   352,
    1246,   324,  1160,   487,  1161,   462,   516,   462,   462,    98,
     919,    99,   920,   817,   891,   462,   502,   532,   533,   771,
     325,   506,  1163,   796,  1164,   491,   492,    98,   518,    99,
     474,   475,   476,   477,   326,   462,   546,   462,   277,   278,
     821,   471,   472,   473,   896,   474,   475,   476,   477,   272,
     273,   535,   353,   537,   474,   475,   476,   477,   277,   278,
     462,   831,   832,   474,   475,   476,   477,   897,   464,   465,
     480,   474,   475,   476,   477,   466,   467,   468,   469,   470,
     471,   472,   473,   462,   855,   559,   489,   490,   824,   759,
     462,   462,   565,   566,   567,   568,   569,   705,   898,   572,
     573,  1263,   575,  1264,   577,   474,   475,   476,   477,   327,
     583,   481,   585,   586,    58,    59,    60,   109,  1332,   591,
     328,   112,   113,   114,   596,   597,   462,   598,   599,   600,
     601,   287,   287,   886,   493,   494,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   287,   625,   626,
     627,   628,   629,   630,   631,   632,   634,   329,   604,   605,
     497,   498,   640,   641,   643,   645,   646,   483,   648,   485,
     650,  -437,   330,   462,   624,   331,   543,   301,   971,   462,
     972,   332,   549,   551,  1133,   287,  1134,   333,   464,   465,
     675,   474,   475,   476,   477,   466,   467,   468,   469,   470,
     471,   472,   473,   606,   607,   690,   691,   302,   303,   304,
     462,   696,   670,   334,   305,  1148,   486,  1149,   703,   455,
     456,   457,   458,   459,   460,   461,   335,   588,   589,   590,
     474,   475,   476,   477,   717,   718,   719,   720,   721,   722,
     723,   724,   725,   726,   727,   728,   612,   764,   766,   767,
     776,   777,   455,   456,   457,   458,   459,   460,   461,   464,
     465,   786,   787,   833,   834,   336,   466,   467,   468,   469,
     470,   471,   472,   473,   280,   462,   337,   966,   967,   760,
    1151,   462,  1152,    98,   763,    99,  1153,   462,  1154,   338,
     594,   595,  1188,   512,   705,   778,   779,   455,   456,   457,
     458,   459,   460,   461,   982,   983,   462,   462,   790,   462,
     791,   950,  1328,   899,  1329,   462,   900,  1304,   462,   462,
     797,   798,   901,   462,   462,   902,   903,   339,   880,   806,
     808,   809,   810,  1054,   464,   465,  1056,  1079,  1080,  1212,
    1213,   466,   467,   468,   469,   470,   471,   472,   473,   340,
     474,   475,   476,   477,   462,   672,   673,   464,   465,  1236,
    1237,   904,   574,   341,   466,   467,   468,   469,   470,   471,
     472,   473,   342,   343,   462,   462,   462,   462,   464,   465,
     845,   907,   846,   908,   909,   466,   467,   468,   469,   470,
     471,   472,   473,   464,   465,     1,     2,     3,     4,     5,
     466,   467,   468,   469,   470,   471,   472,   473,   462,   462,
     344,   462,   462,   462,   578,   910,   916,   224,   918,   931,
     932,   474,   475,   476,   477,   345,   793,   462,   526,   795,
     462,   462,   464,   465,   942,   246,   881,   943,   250,   466,
     467,   468,   469,   470,   471,   472,   473,   262,   462,   462,
     462,   268,   270,   462,   882,  1115,   286,  1131,   561,   580,
     774,   775,   231,   233,   462,   780,   781,   462,   310,   311,
     312,  1155,   354,   531,  1162,   462,   462,   319,   321,   322,
     323,   905,  1165,   947,   948,   455,   456,   457,   458,   459,
     460,   461,  1124,   462,   462,   462,   474,   475,   476,   477,
    1166,  1173,  1174,   951,   355,    98,   356,    99,  1138,   467,
     468,   469,   470,   471,   472,   473,   502,   357,   359,   474,
     475,   476,   477,   462,   733,   862,   734,   863,   735,   970,
    1186,   462,   462,   952,   954,   977,   978,   906,  1265,   981,
     474,   475,   476,   477,  1082,   462,   865,   534,   866,   360,
     361,   736,  1268,   994,   737,   474,   475,   476,   477,   738,
     362,   887,   539,   888,   462,   462,   464,   465,  1004,  1005,
    1006,  1271,  1273,   466,   467,   468,   469,   470,   471,   472,
     473,  1010,   363,   462,   462,  1011,  1012,  1013,   921,  1014,
    1015,  1274,  1016,  1017,   474,   475,   476,   477,  1019,   364,
     527,   751,    98,   752,    99,   753,  1023,  1024,   462,  1025,
    1026,  1027,  1321,   462,  1322,  1275,  1323,   365,   462,   540,
    1290,  1033,  1034,   366,  1036,  1352,   367,   462,   754,   453,
    1037,   755,   922,  1038,   368,   462,   756,   478,   462,  1324,
     923,   462,  1325,   924,   548,  1039,   484,  1326,  1040,  1041,
    1042,   462,  1043,  1044,   462,   462,   927,   554,   369,   930,
     935,  1046,   501,   474,   475,   476,   477,   505,   462,   370,
     562,   462,   462,   936,   517,  1000,   937,   938,   956,   957,
     462,   959,   960,   462,   371,   940,   582,  1050,   941,  1051,
    1052,  1053,  1344,   372,  1345,   462,  1346,   462,   536,   373,
     944,  1059,   946,  1060,  1061,  1062,  1063,  1064,   541,   374,
    1020,  1021,  1067,   462,  1068,   462,   462,  1069,   997,  1347,
     999,  1197,  1348,   375,   376,   377,   378,  1349,   474,   475,
     476,   477,   560,   379,  1035,  1003,   706,  1083,    98,   380,
      99,   462,   587,   570,   571,   381,  1203,   681,   382,   576,
     383,   384,   579,   385,   581,   386,   387,   584,  1098,  1099,
     388,   389,   390,   287,   287,   391,   592,   392,   393,  1106,
    1107,   394,   395,   396,   397,   398,   467,   603,   469,   470,
     471,   472,   473,   399,   400,   401,   464,   465,   402,   403,
    1101,  1102,   404,   466,   467,   468,   469,   470,   471,   472,
     473,   405,   406,   635,   636,   637,   638,   639,   407,   408,
     642,  1282,  1283,   647,   409,   649,   410,   651,   652,   654,
     656,   658,   660,   661,   662,   663,   664,   665,   666,   667,
     668,   669,   671,   411,   412,   674,   413,   676,   677,   678,
     679,   680,   414,   415,   683,   416,   685,   506,   687,   688,
     689,   417,  1185,   692,   693,   694,   695,  1189,   697,   698,
     699,   700,   418,   702,  1306,   704,  1178,  1179,   419,   707,
     708,   709,   710,   711,   712,   713,   714,  1315,   420,  1201,
     421,   422,  1319,   423,  1204,  1205,  1206,  1207,  1208,   424,
    1209,  1210,   425,   426,   427,   428,   429,   430,   431,  1339,
     469,   470,   471,   472,   473,   432,  1217,   433,   434,   435,
     473,   436,  1218,   437,   438,   439,   440,   441,   442,  1220,
     443,  1221,   444,   445,  1096,  1097,  1223,   762,   446,   447,
     474,   475,   476,   477,   448,   449,  1227,  1228,   450,  1229,
    1230,   451,   511,   513,   524,  1231,   525,   529,   474,   475,
     476,   477,   530,   789,  1111,  1240,  1112,   682,   701,   729,
     730,   731,   794,   742,   743,   744,   749,   745,   746,   747,
     748,  1253,   111,   758,   761,   805,   807,   115,   768,   772,
     799,   800,   801,   802,   830,   963,   995,   836,   837,   844,
     847,   848,   849,   850,   996,   851,   852,   853,   117,   854,
     869,   988,  1284,  1211,   911,    98,    98,    99,    99,   464,
     465,   914,   915,   986,   987,   989,   466,   467,   468,   469,
     470,   471,   472,   473,  1293,  1294,   992,   993,  1031,  1191,
    1192,   464,   465,  1032,  1299,   607,  1073,  1074,   466,   467,
     468,   469,   470,   471,   472,   473,  1300,  1301,  1302,  1075,
    1076,  1077,   474,   475,   476,   477,  1309,  1310,    98,  1078,
      99,  1086,  1093,  1094,  1125,  1095,  1181,  1182,  1108,  1132,
    1137,    98,   129,    99,   130,    -9,    98,  1187,    99,  1194,
    1195,  1199,  1200,  1202,   111,  1336,  1337,  1234,  1244,   115,
    1245,  1239,  1261,    98,  1262,    99,  1285,  1287,  1341,   152,
     153,   154,  1288,  1292,  1295,   158,   159,   160,  1296,   162,
     117,   164,   165,   166,  -415,  1354,   225,  1018,   171,   172,
     173,   308,   309,   176,   784,   178,   962,   180,   228,  1180,
     182,   610,   184,   958,  1297,   186,   782,   961,   188,   189,
    1088,   190,   191,  1356,   193,  1311,   195,   792,     0,     0,
       0,     0,     0,     0,   198,     0,     0,     0,     0,     0,
       0,     0,   501,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,     0,     0,  1144,   975,  1145,
       0,   976,   208,   209,   129,     0,   130,     0,     0,     0,
     212,   213,     0,   474,   475,   476,   477,     0,     0,   223,
     653,   803,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   152,   153,   154,     0,     0,     0,   158,   159,   160,
       0,   162,     0,   164,   165,   166,  1009,     0,     0,     0,
     171,   172,   173,     0,     0,   176,   111,   178,     0,   180,
       0,   115,   182,     0,   184,     0,     0,   186,     0,     0,
     188,   189,     0,   190,   191,     0,   193,     0,   195,  1028,
       0,  1030,   117,   464,   465,     0,   198,     0,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   208,   209,     0,     0,     0,     0,
       0,  1045,   212,   213,     0,     0,     0,     0,     0,     0,
       0,   223,   655,     0,     0,     0,     0,     0,     0,  1047,
    1048,   464,   465,     0,     0,     0,  1049,     0,   466,   467,
     468,   469,   470,   471,   472,   473,   129,     0,   130,  1055,
       0,   111,  1057,     0,  1058,     0,   115,     0,     0,     0,
       0,     0,     0,     0,  1065,  1066,     0,     0,     0,     0,
       0,     0,     0,   152,   153,   154,     0,   117,     0,   158,
     159,   160,     0,   162,     0,   164,   165,   166,     0,     0,
       0,     0,   171,   172,   173,  1085,     0,   176,  1087,   178,
       0,   180,     0,     0,   182,     0,   184,     0,     0,   186,
       0,     0,   188,   189,     0,   190,   191,     0,   193,     0,
     195,  1103,  1104,  1105,     0,     0,     0,     0,   198,     0,
       0,  1113,  1114,     0,     0,   474,   475,   476,   477,     0,
       0,     0,     0,   811,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   130,     0,     0,   208,   209,     0,     0,
       0,     0,     0,     0,   212,   213,     0,     0,     0,     0,
       0,     0,     0,   223,   657,     0,     0,     0,   152,   153,
     154,     0,     0,     0,   158,   159,   160,     0,   162,     0,
     164,   165,   166,   474,   475,   476,   477,   171,   172,   173,
       0,   814,   176,   505,   178,     0,   180,     0,     0,   182,
       0,   184,     0,     0,   186,     0,     0,   188,   189,     0,
     190,   191,     0,   193,  1196,   195,     0,   464,   465,     0,
       0,     0,     0,   198,   466,   467,   468,   469,   470,   471,
     472,   473,   464,   465,     0,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,  1216,     0,     0,
       0,   208,   209,     0,     0,     0,     0,     0,     0,   212,
     213,     0,  1219,     0,     0,     0,     0,     0,   223,   659,
       0,  1222,     0,     0,  1224,   464,   465,  1225,     0,     0,
       0,  1226,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1241,     0,     0,     0,     0,     0,     0,     0,
       0,  1247,  1248,  1249,  1250,     0,  1252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   111,
       0,   112,   113,   114,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,   117,     0,     0,     0,   474,
     475,   476,   477,     0,     0,     0,     0,   815,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,     0,     0,
       0,  1308,   820,     0,     0,     0,  1312,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,     0,     0,   126,     0,
       0,     0,     0,   289,     0,     0,     0,   474,   475,   476,
     477,   290,  1340,   528,     0,   127,   128,     0,     0,   129,
       0,   130,     0,     0,   291,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,     0,   181,   182,   183,   184,
       0,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,     0,     0,     0,     0,     0,
     197,   198,   199,     0,     0,     0,   200,     0,     0,   201,
       0,     0,   202,   203,   204,   205,   109,   110,   111,     0,
     112,   113,   114,   115,     0,     0,     0,   206,   207,   208,
     209,     0,     0,   210,     0,   211,     0,   212,   213,   214,
       0,     0,     0,   116,   117,     0,   215,     0,   285,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,   126,     0,     0,
       0,     0,   283,     0,     0,     0,     0,     0,     0,     0,
     284,     0,     0,     0,   127,   128,     0,     0,   129,     0,
     130,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,     0,   181,   182,   183,   184,     0,
     185,   186,     0,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,   196,     0,     0,     0,     0,     0,   197,
     198,   199,     0,     0,     0,   200,     0,     0,   201,     0,
       0,   202,   203,   204,   205,   109,   110,   111,     0,   112,
     113,   114,   115,     0,     0,     0,   206,   207,   208,   209,
       0,     0,   210,     0,   211,     0,   212,   213,   214,     0,
       0,     0,   116,   117,     0,   215,     0,   285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
     464,   465,     0,   125,     0,     0,   126,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,   602,
       0,     0,     0,   127,   128,     0,     0,   129,     0,   130,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,     0,   181,   182,   183,   184,     0,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,     0,     0,     0,     0,     0,   197,   198,
     199,     0,     0,     0,   200,     0,     0,   201,     0,     0,
     202,   203,   204,   205,   109,   110,   111,     0,   112,   113,
     114,   115,     0,     0,     0,   206,   207,   208,   209,     0,
       0,   210,     0,   211,     0,   212,   213,   214,     0,     0,
       0,   116,   117,     0,   215,     0,   285,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,     0,     0,
     827,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,     0,     0,     0,     0,     0,   464,
     465,     0,   125,     0,     0,   126,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   128,     0,     0,   129,     0,   130,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,     0,   181,   182,   183,   184,     0,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,   196,     0,     0,     0,     0,     0,   197,   198,   199,
       0,     0,     0,   200,     0,     0,   201,     0,     0,   202,
     203,   204,   205,   109,   110,   111,     0,   112,   113,   114,
     115,     0,     0,     0,   206,   207,   208,   209,     0,     0,
     210,     0,   211,     0,   212,   213,   214,     0,     0,     0,
     116,   117,     0,   215,     0,   285,     0,     0,     0,     0,
       0,   474,   475,   476,   477,     0,     0,     0,     0,   828,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
       0,   125,     0,     0,   126,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,   127,   128,     0,     0,   129,     0,   130,     0,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,     0,   181,   182,   183,   184,     0,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,     0,     0,     0,     0,     0,   197,   198,   199,     0,
       0,     0,   200,     0,     0,   201,     0,     0,   202,   203,
     204,   205,   109,   110,   111,     0,   112,   113,   114,   115,
       0,     0,     0,   206,   207,   208,   209,     0,     0,   210,
       0,   211,     0,   212,   213,   214,     0,     0,     0,   116,
     117,     0,   215,   558,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,     0,     0,     0,     0,   840,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   465,     0,
     125,     0,     0,   126,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
     127,   128,     0,     0,   129,     0,   130,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
       0,   181,   182,   183,   184,     0,   185,   186,     0,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,   196,
       0,     0,     0,     0,     0,   197,   198,   199,     0,     0,
       0,   200,     0,     0,   201,     0,     0,   202,   203,   204,
     205,   109,   110,   111,     0,   112,   113,   114,   115,     0,
       0,     0,   206,   207,   208,   209,     0,     0,   210,     0,
     211,     0,   212,   213,   214,     0,     0,     0,   116,   117,
       0,   215,   633,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,     0,     0,     0,     0,   857,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,     0,     0,
       0,     0,     0,     0,     0,     0,   464,   465,     0,   125,
       0,     0,   126,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128,     0,     0,   129,     0,   130,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,     0,
     181,   182,   183,   184,     0,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,     0,
       0,     0,     0,     0,   197,   198,   199,     0,     0,     0,
     200,     0,     0,   201,     0,     0,   202,   203,   204,   205,
     109,   110,   111,     0,   112,   113,   114,   115,     0,   297,
       0,   206,   207,   208,   209,     0,     0,   210,     0,   211,
       0,   212,   213,   214,     0,     0,     0,   116,   117,     0,
     215,   644,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,     0,     0,     0,     0,   858,     0,     0,     0,
     298,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,     0,     0,     0,
       0,     0,     0,     0,     0,   464,   465,     0,   125,     0,
       0,   126,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
       0,     0,   129,     0,   130,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,     0,   181,
     182,   183,   184,     0,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,   196,     0,     0,
       0,     0,     0,   197,   198,   199,     0,     0,     0,   200,
       0,     0,   201,     0,     0,   202,   203,   204,   205,   109,
     110,   111,     0,   112,   113,   114,   115,     0,     0,     0,
     206,   207,   208,   209,     0,     0,   210,     0,   211,     0,
     212,   213,   214,     0,     0,     0,   116,   117,     0,   215,
     242,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,     0,     0,     0,     0,   859,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,     0,
       0,     0,     0,     0,   464,   465,     0,   125,     0,     0,
     126,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,     0,
       0,   129,     0,   130,     0,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,     0,   181,   182,
     183,   184,     0,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,     0,     0,     0,
       0,     0,   197,   198,   199,     0,     0,     0,   200,     0,
       0,   201,     0,     0,   202,   203,   204,   205,   109,   110,
     111,     0,   112,   113,   114,   115,     0,   550,     0,   206,
     207,   208,   209,     0,     0,   210,     0,   211,     0,   212,
     213,   214,     0,     0,     0,   116,   117,     0,   215,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
       0,     0,     0,     0,   860,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   465,     0,   125,     0,     0,   126,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,     0,     0,
     129,     0,   130,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,     0,   181,   182,   183,
     184,     0,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
       0,   197,   198,   199,     0,     0,     0,   200,     0,     0,
     201,     0,     0,   202,   203,   204,   205,   109,   110,   111,
       0,   112,   113,   114,   115,     0,     0,     0,   206,   207,
     208,   209,     0,     0,   210,     0,   211,     0,   212,   213,
     214,     0,     0,     0,   116,   117,     0,   215,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,     0,
       0,     0,     0,   861,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   465,     0,   125,     0,     0,   126,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,     0,     0,   129,
       0,   130,     0,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,     0,   181,   182,   183,   184,
       0,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,     0,     0,     0,   111,     0,
     197,   198,   199,   115,     0,     0,   200,     0,     0,   201,
       0,     0,   202,   203,   204,   205,     0,     0,     0,     0,
       0,     0,     0,     0,   117,     0,     0,   206,   207,   208,
     209,     0,     0,   210,     0,   211,     0,   212,   213,   214,
       0,     0,     0,     0,     0,     0,   215,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,     0,     0,
       0,     0,   864,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   464,   465,     0,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
     788,     0,     0,     0,   111,     0,     0,     0,   129,   115,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,     0,     0,     0,   152,   153,   154,     0,     0,
       0,   158,   159,   160,     0,   162,     0,   164,   165,   166,
       0,     0,     0,     0,   171,   172,   173,     0,     0,   176,
       0,   178,     0,   180,     0,     0,   182,     0,   184,     0,
       0,   186,     0,     0,   188,   189,     0,   190,   191,     0,
     193,     0,   195,     0,     0,     0,     0,     0,     0,     0,
     198,     0,     0,     0,     0,     0,  1029,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,     0,   111,     0,
       0,     0,     0,   115,     0,     0,     0,     0,   208,   209,
       0,     0,     0,     0,     0,     0,   212,   213,     0,     0,
       0,   152,   153,   154,   117,   223,     0,   158,   159,   160,
       0,   162,     0,   164,   165,   166,   474,   475,   476,   477,
     171,   172,   173,     0,   867,   176,     0,   178,     0,   180,
       0,     0,   182,     0,   184,     0,     0,   186,     0,     0,
     188,   189,     0,   190,   191,     0,   193,     0,   195,     0,
       0,     0,     0,     0,   464,   465,   198,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,   111,     0,     0,     0,   129,   115,
     130,     0,     0,     0,   208,   209,     0,     0,     0,     0,
       0,     0,   212,   213,     0,     0,     0,     0,     0,     0,
     117,   223,     0,     0,     0,   152,   153,   154,     0,     0,
       0,   158,   159,   160,     0,   162,     0,   164,   165,   166,
       0,     0,     0,     0,   171,   172,   173,     0,     0,   176,
       0,   178,     0,   180,     0,     0,   182,     0,   184,     0,
       0,   186,     0,     0,   188,   189,     0,   190,   191,     0,
     193,     0,   195,     0,     0,     0,     0,     0,     0,   464,
     198,     0,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,   129,     0,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,   209,
       0,     0,     0,     0,     0,     0,   212,   213,     0,     0,
       0,   152,   153,   154,     0,   223,     0,   158,   159,   160,
       0,   162,     0,   164,   165,   166,   474,   475,   476,   477,
     171,   172,   173,     0,   868,   176,     0,   178,     0,   180,
       0,     0,   182,     0,   184,     0,     0,   186,     0,     0,
     188,   189,     0,   190,   191,     0,   193,     0,   195,     0,
       0,     0,     0,     0,     0,     0,   198,     0,     0,     0,
       0,   464,   465,     0,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,   208,   209,     0,     7,     8,     9,
       0,     0,   212,   213,    10,     0,     0,     0,    11,     0,
      12,   974,    13,    14,    15,    16,    17,  -366,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,   474,   475,   476,   477,    29,     0,     0,    30,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    45,    46,    47,  -140,  -140,    48,    49,    50,
       0,    51,    52,    53,     0,     0,    54,  -140,     0,    55,
       0,    56,    57,     0,   464,   465,     0,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,    58,    59,    60,     0,     0,
       0,     0,    61,   474,   475,   476,   477,     0,     0,     0,
       0,   870,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,    63,     0,     0,     0,     0,    64,
     464,   465,    65,     0,     0,     0,    66,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,    70,    71,     0,    72,
      73,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     7,     8,     9,
      85,    86,     0,    87,    10,    88,     0,     0,    11,     0,
      12,     0,    13,    14,    15,    16,    17,  -366,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,     0,     0,     0,     0,    29,   -16,   -16,    30,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    37,    38,   474,   475,   476,   477,
       0,     0,     0,     0,   871,     0,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    45,    46,    47,     0,     0,    48,    49,    50,
       0,    51,    52,    53,     0,     0,    54,     0,     0,    55,
       0,    56,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,     0,     0,
     872,     0,     0,     0,     0,    58,    59,    60,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,    63,     0,     0,     0,     0,    64,
     464,   465,    65,     0,     0,     0,    66,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,    70,    71,     0,    72,
      73,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     7,     8,     9,
      85,    86,     0,    87,    10,    88,     0,     0,    11,     0,
      12,     0,    13,    14,    15,    16,    17,  -366,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,   -16,     0,     0,     0,    29,   -16,     0,    30,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    45,    46,    47,     0,     0,    48,    49,    50,
       0,    51,    52,    53,     0,     0,    54,   464,   465,    55,
       0,    56,    57,     0,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,     0,     0,     0,     0,
     873,     0,     0,     0,     0,    58,    59,    60,   464,   465,
       0,     0,    61,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,    63,     0,     0,     0,     0,    64,
     464,   465,    65,     0,     0,     0,    66,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,    70,    71,     0,    72,
      73,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
      85,    86,     0,    87,     0,    88,   464,   465,     0,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,   464,   465,     0,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,   874,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,     0,     0,   875,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,     0,     0,
     876,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,   464,   465,     0,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,   464,   465,     0,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,     0,     0,     0,     0,   878,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,   889,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,     0,     0,   890,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,     0,     0,   892,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,     0,     0,     0,     0,   895,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,     0,     0,     0,
       0,   917,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,   464,   465,     0,     0,   934,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,   464,   465,     0,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,   945,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,     0,     0,   973,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,     0,     0,
    1092,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,   464,   465,     0,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,   464,   465,     0,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,     0,     0,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,  1110,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,     0,     0,  1121,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,     0,     0,  1126,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,     0,     0,     0,     0,  1127,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,     0,     0,     0,
       0,  1128,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,   464,   465,     0,     0,  1129,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,   464,   465,     0,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,     0,     0,  1130,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,     0,     0,  1135,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,  1136,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,   464,   465,     0,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,   464,   465,     0,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,     0,     0,
       0,     0,  1139,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,  1140,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,     0,     0,  1141,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,     0,     0,  1142,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,     0,     0,     0,     0,  1143,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,     0,     0,
       0,     0,  1146,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,  1147,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,   464,   465,
       0,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,     0,     0,  1150,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,     0,     0,  1156,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,  1159,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,   464,   465,     0,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,   464,   465,     0,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,     0,
       0,     0,     0,  1170,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,     0,     0,  1175,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,     0,     0,  1176,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,  1184,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,     0,     0,     0,     0,  1238,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,     0,     0,
       0,     0,  1242,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,  1251,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,   464,   465,
       0,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,     0,     0,  1254,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,     0,     0,  1255,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,  1258,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,   464,   465,
       0,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,   464,   465,     0,     0,     0,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,     0,
       0,     0,     0,  1259,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,     0,     0,  1260,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,     0,     0,
    1267,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,     0,
       0,  1269,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,     0,
       0,     0,     0,  1270,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,     0,     0,     0,     0,  1272,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,     0,     0,  1276,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,   464,   465,     0,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,     0,     0,  1277,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,   464,   465,     0,     0,  1313,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,     0,     0,  1314,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,   464,   465,
       0,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,   464,   465,     0,     0,     0,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,     0,     0,     0,     0,  1316,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,     0,     0,  1331,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,     0,     0,
    1342,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   464,   465,
       0,     0,  1343,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,     0,
       0,     0,     0,  1353,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,     0,     0,   542,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,   785,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,   464,   465,     0,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,   812,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,   464,   465,   813,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,   818,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,   464,
     465,     0,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,   464,   465,     0,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,     0,     0,   819,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,   822,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,   464,   465,   825,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   464,   465,
     838,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
       0,     0,   839,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,     0,     0,   841,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,   842,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,   843,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   464,   465,
     856,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,   877,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,   464,
     465,     0,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,   464,   465,     0,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,   884,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,   885,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,   464,   465,   933,     0,     0,     0,     0,   466,
     467,   468,   469,   470,   471,   472,   473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,   939,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
       0,     0,   969,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,     0,     0,   990,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,   991,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,   998,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   464,   465,
    1001,     0,     0,     0,     0,   466,   467,   468,   469,   470,
     471,   472,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,  1002,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
     464,   465,     0,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,  1007,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,  1008,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,  1084,     0,     0,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   464,   465,  1089,     0,     0,     0,
       0,   466,   467,   468,   469,   470,   471,   472,   473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,  1100,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,     0,     0,  1116,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,  1117,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,   464,   465,     0,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,  1118,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,  1119,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   474,   475,   476,   477,
     464,   465,  1120,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   464,   465,     0,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
     464,   465,     0,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,     0,     0,  1122,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,  1123,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,  1157,     0,     0,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,  1158,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,     0,     0,  1167,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,     0,     0,  1168,     0,     0,     0,     0,     0,     0,
       0,     0,   474,   475,   476,   477,   464,   465,  1169,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,   464,   465,     0,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,   464,   465,  1171,     0,     0,     0,     0,
     466,   467,   468,   469,   470,   471,   472,   473,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,  1172,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477,   464,   465,  1198,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,   464,   465,     0,     0,
       0,     0,     0,   466,   467,   468,   469,   470,   471,   472,
     473,   464,   465,     0,     0,     0,     0,     0,   466,   467,
     468,   469,   470,   471,   472,   473,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,     0,     0,  1256,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,   464,   465,  1257,
       0,     0,     0,     0,   466,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   474,   475,   476,   477,   464,
     465,  1266,     0,     0,     0,     0,   466,   467,   468,   469,
     470,   471,   472,   473,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,   464,   465,  1278,     0,     0,
       0,     0,   466,   467,   468,   469,   470,   471,   472,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,     0,     0,  1279,
       0,     0,     0,     0,     0,     0,     0,     0,   474,   475,
     476,   477,     0,     0,  1289,     0,     0,     0,     0,     0,
       0,     0,     0,   474,   475,   476,   477,     0,     0,  1317,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
     475,   476,   477,     0,     0,  1318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   477,     0,     0,  1330,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   474,   475,   476,
     477
};

static const yytype_int16 yycheck[] =
{
       2,    12,    12,    58,     1,   366,     1,     4,     4,     4,
      40,     7,    44,   311,   312,    17,   979,   980,    75,    75,
      58,     4,    60,    61,     7,    25,    16,    77,    30,     0,
      11,    33,     4,     5,    36,    37,    38,     7,    15,    16,
      42,    43,    44,    28,    44,   236,     3,    12,   226,    51,
       7,     8,     9,    10,    44,   233,    53,    88,    53,    76,
      77,    63,    12,   254,    41,   231,     3,   233,    43,    44,
       7,     8,     9,    10,    77,   315,   316,    28,   226,   226,
     226,    13,    33,   231,    92,    93,   233,   233,    63,    70,
      71,    72,    73,    74,    75,    76,   104,   226,    63,    64,
       4,    95,   231,     7,   233,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,   231,    44,   233,   120,   232,
      70,    71,    72,    73,    74,    75,    76,    77,   100,   232,
     226,    63,    64,    74,    75,    76,    77,   233,    70,    71,
      72,    73,    74,    75,    76,    77,    70,    71,    72,    73,
      74,    75,    76,    77,    44,   110,    47,    48,   226,   232,
     132,   133,   134,   231,    70,    71,    72,    73,    74,    75,
      76,     4,     5,    63,    64,   232,   232,   227,   228,   234,
      70,    71,    72,    73,    74,    75,    76,    77,   232,    23,
     226,   431,   226,   433,   226,   231,   234,   233,    75,   233,
      70,    71,    72,    73,    74,    75,    76,   226,   225,   226,
     227,   228,   214,   215,   233,   226,     4,     5,   232,   226,
     231,   231,   225,   226,   227,   228,   233,  1190,   230,    75,
    1193,   232,   231,   235,   233,   226,   232,   226,   226,   236,
     231,   236,   233,   231,   233,   226,   248,   277,   278,   232,
     232,   253,   231,   551,   233,    20,    21,   254,   260,   254,
     225,   226,   227,   228,   232,   226,   231,   226,   225,   226,
     231,    75,    76,    77,   233,   225,   226,   227,   228,     4,
       5,   283,    24,   285,   225,   226,   227,   228,   225,   226,
     226,   589,   590,   225,   226,   227,   228,   233,    63,    64,
      44,   225,   226,   227,   228,    70,    71,    72,    73,    74,
      75,    76,    77,   226,   612,   317,    35,    36,   231,   510,
     226,   226,   324,   325,   326,   327,   328,   233,   233,   331,
     332,   231,   334,   233,   336,   225,   226,   227,   228,   232,
     342,    44,   344,   345,   132,   133,   134,     3,  1311,   351,
     232,     7,     8,     9,   356,   357,   226,   359,   360,   361,
     362,   363,   364,   233,     4,     5,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   232,   363,   364,
       4,     5,   394,   395,   396,   397,   398,   231,   400,   233,
     402,    46,   232,   226,   379,   232,   297,    59,   231,   226,
     233,   232,   303,   304,   231,   417,   233,   232,    63,    64,
     422,   225,   226,   227,   228,    70,    71,    72,    73,    74,
      75,    76,    77,     4,     5,   437,   438,    89,    90,    91,
     226,   443,   417,   232,    96,   231,     4,   233,   450,    70,
      71,    72,    73,    74,    75,    76,   232,   348,   349,   350,
     225,   226,   227,   228,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   367,    51,   230,   231,
       4,     5,    70,    71,    72,    73,    74,    75,    76,    63,
      64,    86,    87,     4,     5,   232,    70,    71,    72,    73,
      74,    75,    76,    77,   534,   226,   232,    49,    50,   511,
     231,   226,   233,   510,   516,   510,   231,   226,   233,   232,
     354,   355,   231,    58,   233,   527,   528,    70,    71,    72,
      73,    74,    75,    76,     4,     5,   226,   226,   540,   226,
     542,   732,   231,   233,   233,   226,   233,    46,   226,   226,
     552,   553,   233,   226,   226,   233,   233,   232,   231,   561,
     562,   563,   564,   924,    63,    64,   927,    39,    40,     4,
       5,    70,    71,    72,    73,    74,    75,    76,    77,   232,
     225,   226,   227,   228,   226,   419,   420,    63,    64,    60,
      61,   233,   233,   232,    70,    71,    72,    73,    74,    75,
      76,    77,   232,   232,   226,   226,   226,   226,    63,    64,
     231,   233,   233,   233,   233,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,   181,   182,   183,   184,   185,
      70,    71,    72,    73,    74,    75,    76,    77,   226,   226,
     232,   226,   226,   226,   233,   233,   233,     3,   233,   233,
     233,   225,   226,   227,   228,   232,   547,   226,   231,   550,
     226,   226,    63,    64,   233,    21,   231,   233,    24,    70,
      71,    72,    73,    74,    75,    76,    77,    33,   226,   226,
     226,    37,    38,   226,   231,   233,    42,   233,   231,   233,
     524,   525,   232,   232,   226,   529,   530,   226,    54,    55,
      56,   233,   232,   231,   233,   226,   226,    63,    64,    65,
      66,   231,   233,   715,   716,    70,    71,    72,    73,    74,
      75,    76,  1020,   226,   226,   226,   225,   226,   227,   228,
     233,   233,   233,   735,   232,   732,   232,   732,  1036,    71,
      72,    73,    74,    75,    76,    77,   748,   232,   232,   225,
     226,   227,   228,   226,    14,   231,    16,   233,    18,   761,
     233,   226,   226,   740,   741,   767,   768,   231,   233,   771,
     225,   226,   227,   228,   965,   226,   231,   231,   233,   232,
     232,    41,   233,   785,    44,   225,   226,   227,   228,    49,
     232,   231,   231,   233,   226,   226,    63,    64,   800,   801,
     802,   233,   233,    70,    71,    72,    73,    74,    75,    76,
      77,   813,   232,   226,   226,   817,   818,   819,   231,   821,
     822,   233,   824,   825,   225,   226,   227,   228,   830,   232,
     231,    14,   829,    16,   829,    18,   838,   839,   226,   841,
     842,   843,    14,   226,    16,   233,    18,   232,   226,   231,
     233,   853,   854,   232,   856,   233,   232,   226,    41,   215,
     862,    44,   231,   865,   232,   226,    49,   223,   226,    41,
     231,   226,    44,   231,   231,   877,   232,    49,   880,   881,
     882,   226,   884,   885,   226,   226,   231,     5,   232,   231,
     231,   893,   248,   225,   226,   227,   228,   253,   226,   232,
     231,   226,   226,   231,   260,   796,   231,   231,   742,   743,
     226,   745,   746,   226,   232,   231,   233,   919,   231,   921,
     922,   923,    14,   232,    16,   226,    18,   226,   284,   232,
     231,   933,   231,   935,   936,   937,   938,   939,   294,   232,
     831,   832,   944,   226,   946,   226,   226,   949,   231,    41,
     231,   231,    44,   232,   232,   232,   232,    49,   225,   226,
     227,   228,   318,   232,   855,   799,   233,   969,   965,   232,
     965,   226,    43,   329,   330,   232,   231,   233,   232,   335,
     232,   232,   338,   232,   340,   232,   232,   343,   990,   991,
     232,   232,   232,   995,   996,   232,   352,   232,   232,  1001,
    1002,   232,   232,   232,   232,   232,    71,   363,    73,    74,
      75,    76,    77,   232,   232,   232,    63,    64,   232,   232,
     995,   996,   232,    70,    71,    72,    73,    74,    75,    76,
      77,   232,   232,   389,   390,   391,   392,   393,   232,   232,
     396,  1232,  1233,   399,   232,   401,   232,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   232,   232,   421,   232,   423,   424,   425,
     426,   427,   232,   232,   430,   232,   432,  1079,   434,   435,
     436,   232,  1084,   439,   440,   441,   442,  1089,   444,   445,
     446,   447,   232,   449,  1285,   451,  1073,  1074,   232,   455,
     456,   457,   458,   459,   460,   461,   462,  1298,   232,  1111,
     232,   232,  1303,   232,  1116,  1117,  1118,  1119,  1120,   232,
    1122,  1123,   232,   232,   232,   232,   232,   232,   232,  1320,
      73,    74,    75,    76,    77,   232,  1138,   232,   232,   232,
      77,   232,  1144,   232,   232,   232,   232,   232,   232,  1151,
     232,  1153,   232,   232,   988,   989,  1158,   513,   232,   232,
     225,   226,   227,   228,   232,   232,  1168,  1169,   232,  1171,
    1172,   232,   232,   232,   232,  1177,   232,   232,   225,   226,
     227,   228,   232,   539,   231,  1187,   233,   233,   233,   233,
     233,    75,   548,   232,   232,   231,    43,   232,   232,   231,
     231,  1203,     5,    46,   232,   561,   562,    10,   232,    10,
     232,   231,   231,   231,   231,    43,    85,   233,   233,   233,
     231,   233,   232,   232,    85,   233,   233,   231,    31,   231,
     233,   232,  1234,  1124,   233,  1232,  1233,  1232,  1233,    63,
      64,   233,   233,   233,   233,   232,    70,    71,    72,    73,
      74,    75,    76,    77,  1256,  1257,   233,   233,   233,  1093,
    1094,    63,    64,   233,  1266,     5,   231,   231,    70,    71,
      72,    73,    74,    75,    76,    77,  1278,  1279,  1280,   233,
     233,   233,   225,   226,   227,   228,  1288,  1289,  1285,   233,
    1285,    58,   232,   232,   232,   231,    43,    38,   233,   233,
     233,  1298,   105,  1298,   107,    43,  1303,   232,  1303,   233,
     233,    75,    75,    75,     5,  1317,  1318,    48,   233,    10,
     233,    58,   232,  1320,   232,  1320,    47,   232,  1330,   132,
     133,   134,   232,    75,   233,   138,   139,   140,   233,   142,
      31,   144,   145,   146,    38,     4,     4,   829,   151,   152,
     153,    53,    53,   156,   534,   158,   748,   160,     5,  1079,
     163,   366,   165,   744,  1263,   168,   531,   747,   171,   172,
     977,   174,   175,  1351,   177,  1291,   179,   544,    -1,    -1,
      -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   748,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    -1,    -1,   231,   764,   233,
      -1,   767,   215,   216,   105,    -1,   107,    -1,    -1,    -1,
     223,   224,    -1,   225,   226,   227,   228,    -1,    -1,   232,
     233,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,   134,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,    -1,   144,   145,   146,   812,    -1,    -1,    -1,
     151,   152,   153,    -1,    -1,   156,     5,   158,    -1,   160,
      -1,    10,   163,    -1,   165,    -1,    -1,   168,    -1,    -1,
     171,   172,    -1,   174,   175,    -1,   177,    -1,   179,   845,
      -1,   847,    31,    63,    64,    -1,   187,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,    -1,
      -1,   887,   223,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,   905,
     906,    63,    64,    -1,    -1,    -1,   912,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   105,    -1,   107,   925,
      -1,     5,   928,    -1,   930,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   940,   941,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,   134,    -1,    31,    -1,   138,
     139,   140,    -1,   142,    -1,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,   152,   153,   971,    -1,   156,   974,   158,
      -1,   160,    -1,    -1,   163,    -1,   165,    -1,    -1,   168,
      -1,    -1,   171,   172,    -1,   174,   175,    -1,   177,    -1,
     179,   997,   998,   999,    -1,    -1,    -1,    -1,   187,    -1,
      -1,  1007,  1008,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,   107,    -1,    -1,   215,   216,    -1,    -1,
      -1,    -1,    -1,    -1,   223,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   233,    -1,    -1,    -1,   132,   133,
     134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,
     144,   145,   146,   225,   226,   227,   228,   151,   152,   153,
      -1,   233,   156,  1079,   158,    -1,   160,    -1,    -1,   163,
      -1,   165,    -1,    -1,   168,    -1,    -1,   171,   172,    -1,
     174,   175,    -1,   177,  1100,   179,    -1,    63,    64,    -1,
      -1,    -1,    -1,   187,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,  1133,    -1,    -1,
      -1,   215,   216,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,    -1,  1148,    -1,    -1,    -1,    -1,    -1,   232,   233,
      -1,  1157,    -1,    -1,  1160,    63,    64,  1163,    -1,    -1,
      -1,  1167,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1197,  1198,  1199,  1200,    -1,  1202,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,   225,
     226,   227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,
      -1,  1287,   233,    -1,    -1,    -1,  1292,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,   225,   226,   227,
     228,    97,  1328,   231,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,    -1,   162,   163,   164,   165,
      -1,   167,   168,    -1,   170,   171,   172,    -1,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,   195,
      -1,    -1,   198,   199,   200,   201,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,   213,   214,   215,
     216,    -1,    -1,   219,    -1,   221,    -1,   223,   224,   225,
      -1,    -1,    -1,    30,    31,    -1,   232,    -1,   234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,    -1,   162,   163,   164,   165,    -1,
     167,   168,    -1,   170,   171,   172,    -1,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    -1,    -1,   186,
     187,   188,    -1,    -1,    -1,   192,    -1,    -1,   195,    -1,
      -1,   198,   199,   200,   201,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,   213,   214,   215,   216,
      -1,    -1,   219,    -1,   221,    -1,   223,   224,   225,    -1,
      -1,    -1,    30,    31,    -1,   232,    -1,   234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    81,    -1,    -1,    84,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    97,
      -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    -1,   162,   163,   164,   165,    -1,   167,
     168,    -1,   170,   171,   172,    -1,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,    -1,    -1,    -1,   192,    -1,    -1,   195,    -1,    -1,
     198,   199,   200,   201,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,   213,   214,   215,   216,    -1,
      -1,   219,    -1,   221,    -1,   223,   224,   225,    -1,    -1,
      -1,    30,    31,    -1,   232,    -1,   234,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    81,    -1,    -1,    84,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    -1,   162,   163,   164,   165,    -1,   167,   168,
      -1,   170,   171,   172,    -1,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
      -1,    -1,    -1,   192,    -1,    -1,   195,    -1,    -1,   198,
     199,   200,   201,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,   213,   214,   215,   216,    -1,    -1,
     219,    -1,   221,    -1,   223,   224,   225,    -1,    -1,    -1,
      30,    31,    -1,   232,    -1,   234,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    -1,    -1,    -1,    -1,   233,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    81,    -1,    -1,    84,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,   165,    -1,   167,   168,    -1,
     170,   171,   172,    -1,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,    -1,
      -1,    -1,   192,    -1,    -1,   195,    -1,    -1,   198,   199,
     200,   201,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,   213,   214,   215,   216,    -1,    -1,   219,
      -1,   221,    -1,   223,   224,   225,    -1,    -1,    -1,    30,
      31,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      81,    -1,    -1,    84,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
      -1,   162,   163,   164,   165,    -1,   167,   168,    -1,   170,
     171,   172,    -1,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,    -1,    -1,    -1,   186,   187,   188,    -1,    -1,
      -1,   192,    -1,    -1,   195,    -1,    -1,   198,   199,   200,
     201,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,   213,   214,   215,   216,    -1,    -1,   219,    -1,
     221,    -1,   223,   224,   225,    -1,    -1,    -1,    30,    31,
      -1,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    81,
      -1,    -1,    84,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    -1,
     162,   163,   164,   165,    -1,   167,   168,    -1,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,    -1,    -1,    -1,
     192,    -1,    -1,   195,    -1,    -1,   198,   199,   200,   201,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    12,
      -1,   213,   214,   215,   216,    -1,    -1,   219,    -1,   221,
      -1,   223,   224,   225,    -1,    -1,    -1,    30,    31,    -1,
     232,   233,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    81,    -1,
      -1,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    -1,   162,
     163,   164,   165,    -1,   167,   168,    -1,   170,   171,   172,
      -1,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,    -1,    -1,    -1,   192,
      -1,    -1,   195,    -1,    -1,   198,   199,   200,   201,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
     213,   214,   215,   216,    -1,    -1,   219,    -1,   221,    -1,
     223,   224,   225,    -1,    -1,    -1,    30,    31,    -1,   232,
      34,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    81,    -1,    -1,
      84,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,    -1,   162,   163,
     164,   165,    -1,   167,   168,    -1,   170,   171,   172,    -1,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,    -1,    -1,    -1,   192,    -1,
      -1,   195,    -1,    -1,   198,   199,   200,   201,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    12,    -1,   213,
     214,   215,   216,    -1,    -1,   219,    -1,   221,    -1,   223,
     224,   225,    -1,    -1,    -1,    30,    31,    -1,   232,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    81,    -1,    -1,    84,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    -1,   162,   163,   164,
     165,    -1,   167,   168,    -1,   170,   171,   172,    -1,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,
      -1,   186,   187,   188,    -1,    -1,    -1,   192,    -1,    -1,
     195,    -1,    -1,   198,   199,   200,   201,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,   213,   214,
     215,   216,    -1,    -1,   219,    -1,   221,    -1,   223,   224,
     225,    -1,    -1,    -1,    30,    31,    -1,   232,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    81,    -1,    -1,    84,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,    -1,   162,   163,   164,   165,
      -1,   167,   168,    -1,   170,   171,   172,    -1,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,     5,    -1,
     186,   187,   188,    10,    -1,    -1,   192,    -1,    -1,   195,
      -1,    -1,   198,   199,   200,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,   213,   214,   215,
     216,    -1,    -1,   219,    -1,   221,    -1,   223,   224,   225,
      -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      97,    -1,    -1,    -1,     5,    -1,    -1,    -1,   105,    10,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,   132,   133,   134,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,    -1,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,   152,   153,    -1,    -1,   156,
      -1,   158,    -1,   160,    -1,    -1,   163,    -1,   165,    -1,
      -1,   168,    -1,    -1,   171,   172,    -1,   174,   175,    -1,
     177,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,   107,    -1,     5,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,   215,   216,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,    -1,    -1,
      -1,   132,   133,   134,    31,   232,    -1,   138,   139,   140,
      -1,   142,    -1,   144,   145,   146,   225,   226,   227,   228,
     151,   152,   153,    -1,   233,   156,    -1,   158,    -1,   160,
      -1,    -1,   163,    -1,   165,    -1,    -1,   168,    -1,    -1,
     171,   172,    -1,   174,   175,    -1,   177,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    63,    64,   187,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,   105,    10,
     107,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      31,   232,    -1,    -1,    -1,   132,   133,   134,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,    -1,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,   152,   153,    -1,    -1,   156,
      -1,   158,    -1,   160,    -1,    -1,   163,    -1,   165,    -1,
      -1,   168,    -1,    -1,   171,   172,    -1,   174,   175,    -1,
     177,    -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    63,
     187,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   105,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,    -1,    -1,
      -1,   132,   133,   134,    -1,   232,    -1,   138,   139,   140,
      -1,   142,    -1,   144,   145,   146,   225,   226,   227,   228,
     151,   152,   153,    -1,   233,   156,    -1,   158,    -1,   160,
      -1,    -1,   163,    -1,   165,    -1,    -1,   168,    -1,    -1,
     171,   172,    -1,   174,   175,    -1,   177,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,   216,    -1,     4,     5,     6,
      -1,    -1,   223,   224,    11,    -1,    -1,    -1,    15,    -1,
      17,   232,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,   225,   226,   227,   228,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,   106,
      -1,   108,   109,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,   225,   226,   227,   228,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,   166,
      63,    64,   169,    -1,    -1,    -1,   173,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,   191,    -1,   193,   194,    -1,   196,
     197,    -1,    -1,    -1,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,     4,     5,     6,
     217,   218,    -1,   220,    11,   222,    -1,    -1,    15,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    62,   225,   226,   227,   228,
      -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,   132,   133,   134,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,   166,
      63,    64,   169,    -1,    -1,    -1,   173,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,   191,    -1,   193,   194,    -1,   196,
     197,    -1,    -1,    -1,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,     4,     5,     6,
     217,   218,    -1,   220,    11,   222,    -1,    -1,    15,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    42,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,    63,    64,   106,
      -1,   108,   109,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   225,   226,   227,   228,    -1,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,   132,   133,   134,    63,    64,
      -1,    -1,   139,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,   166,
      63,    64,   169,    -1,    -1,    -1,   173,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   189,   190,   191,    -1,   193,   194,    -1,   196,
     197,    -1,    -1,    -1,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,   218,    -1,   220,    -1,   222,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,    -1,    -1,   233,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,    -1,    -1,
     233,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,    -1,    -1,   233,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,    -1,    -1,
     233,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,    -1,    -1,   233,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,    -1,    -1,   233,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,    -1,    -1,   233,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,    -1,    -1,   233,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    -1,    -1,    -1,    -1,   233,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,    -1,    -1,   233,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,    -1,    -1,
     233,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,    -1,
      -1,   233,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    -1,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,    -1,    -1,   233,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    -1,    -1,    -1,    -1,   233,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,    -1,    -1,   233,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,    -1,    -1,
     233,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,    64,
      -1,    -1,   233,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,   231,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,   231,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,    64,
     231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,   231,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,    64,
     231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,   231,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,   231,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,   231,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,    64,
     231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   227,   228,    63,    64,   231,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,   231,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,   231,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,   231,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,   231,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    63,    64,   231,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    63,    64,   231,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    63,    64,   231,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    63,    64,   231,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    63,
      64,   231,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    63,    64,   231,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     227,   228,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   227,   228,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   181,   182,   183,   184,   185,   236,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   132,   133,
     134,   139,   157,   161,   166,   169,   173,   189,   190,   191,
     193,   194,   196,   197,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   217,   218,   220,   222,   237,
     238,   241,   242,   249,   250,   252,   253,   257,   269,   270,
     275,   281,   288,   296,   304,   307,   311,   314,   320,     3,
       4,     5,     7,     8,     9,    10,    30,    31,    63,    64,
      65,    66,    67,    68,    69,    81,    84,   101,   102,   105,
     107,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   162,   163,   164,   165,   167,   168,   170,   171,   172,
     174,   175,   176,   177,   178,   179,   180,   186,   187,   188,
     192,   195,   198,   199,   200,   201,   213,   214,   215,   216,
     219,   221,   223,   224,   225,   232,   255,   256,   258,   264,
     266,   269,   270,   232,   255,   241,   269,   270,   275,     0,
      75,   232,    75,   232,   289,   308,   312,     4,     7,   267,
     267,   267,    34,   258,   243,   244,   255,   271,   272,   271,
     255,    28,     7,   297,   305,   258,    58,    60,    61,   234,
     343,   247,   255,   258,     4,     5,   268,   258,   255,   258,
     255,   258,     4,     5,   331,   332,    10,   225,   226,   265,
     266,   333,   267,    89,    97,   234,   255,   258,   344,    89,
      97,   110,   344,   344,    88,   258,   263,    12,    53,   263,
     263,    59,    89,    90,    91,    96,    95,   258,   250,   257,
     255,   255,   255,   110,   232,   232,   232,   232,   232,   255,
     344,   255,   255,   255,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,    44,   239,    92,    93,
     104,    75,    75,    24,   232,   232,   232,   232,   258,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   258,   255,   258,    70,    71,    72,    73,    74,
      75,    76,   226,    44,    63,    64,    70,    71,    72,    73,
      74,    75,    76,    77,   225,   226,   227,   228,   255,    44,
      44,    44,   258,   271,   255,   271,     4,   258,   238,    35,
      36,    20,    21,     4,     5,   282,   283,     4,     5,   284,
     285,   255,   258,   273,   274,   255,   258,   299,   238,   315,
     321,   232,    58,   232,     4,     7,   232,   255,   258,   334,
      58,   234,   336,   341,   232,   232,   231,   231,   231,   232,
     232,   231,   266,   266,   231,   258,   255,   258,    11,   231,
     231,   255,   231,   263,   248,    12,   231,   251,   231,   263,
      12,   263,   251,   251,     5,   254,   254,   254,   233,   258,
     255,   231,   231,   231,   231,   258,   258,   258,   258,   258,
     255,   255,   258,   258,   233,   258,   255,   258,   233,   255,
     233,   255,   233,   258,   255,   258,   258,    43,   263,   263,
     263,   258,   255,   276,   271,   271,   258,   258,   258,   258,
     258,   258,    97,   255,   344,   344,     4,     5,   261,   262,
     261,   262,   263,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   344,   258,   258,   258,   258,   258,
     258,   258,   258,   233,   258,   255,   255,   255,   255,   255,
     258,   258,   255,   258,   233,   258,   258,   255,   258,   255,
     258,   255,   255,   233,   255,   233,   255,   233,   255,   233,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     344,   255,   271,   271,   255,   258,   255,   255,   255,   255,
     255,   233,   233,   255,   254,   255,   254,   255,   255,   255,
     258,   258,   255,   255,   255,   255,   258,   255,   255,   255,
     255,   233,   255,   258,   255,   233,   233,   255,   255,   255,
     255,   255,   255,   255,   255,   260,   259,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   233,
     233,    75,   309,    14,    16,    18,    41,    44,    49,   313,
     245,   246,   232,   232,   231,   232,   232,   231,   231,    43,
     298,    14,    16,    18,    41,    44,    49,   306,    46,   238,
     258,   232,   255,   258,    51,   335,   230,   231,   232,     4,
       7,   232,    10,   342,   271,   271,     4,     5,   258,   258,
     271,   271,   332,    10,   265,   231,    86,    87,    97,   255,
     258,   258,   336,   263,   255,   263,   251,   258,   258,   232,
     231,   231,   231,   233,   233,   255,   258,   255,   258,   258,
     258,   233,   231,   231,   233,   233,   233,   231,   231,   231,
     233,   231,   231,   233,   231,   231,   233,   233,   233,   240,
     231,   251,   251,     4,     5,   280,   233,   233,   231,   231,
     233,   231,   231,   231,   233,   231,   233,   231,   233,   232,
     232,   233,   233,   231,   231,   251,   231,   233,   233,   233,
     233,   233,   231,   233,   233,   231,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   231,   233,   233,
     231,   231,   231,   233,   231,   231,   233,   231,   233,   233,
     233,   233,   233,   231,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   231,   231,   233,   233,   233,
     233,   233,   231,   233,   233,   233,   233,   233,   233,   231,
     233,   231,   231,   231,   231,   231,   233,   231,   231,   233,
     231,   233,   233,   231,   233,   231,   231,   231,   231,   231,
     231,   231,   233,   233,   231,   233,   231,   258,   258,   290,
     238,   258,   267,   345,   267,   346,   271,   271,   283,   271,
     271,   285,   274,    43,   300,   316,    49,    50,   322,   231,
     258,   231,   233,   233,   232,   255,   255,   258,   258,   337,
     338,   258,     4,     5,   328,   330,   233,   233,   232,   232,
     231,   231,   233,   233,   258,    85,    85,   231,   231,   231,
     263,   231,   231,   271,   258,   258,   258,   231,   231,   255,
     258,   258,   258,   258,   258,   258,   258,   258,   242,   258,
     263,   263,   277,   258,   258,   258,   258,   258,   255,    97,
     255,   233,   233,   258,   258,   263,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   255,   258,   255,   255,   255,
     258,   258,   258,   258,   262,   255,   262,   255,   255,   258,
     258,   258,   258,   258,   258,   255,   255,   258,   258,   258,
      16,    44,   310,   231,   231,   233,   233,   233,   233,    39,
      40,   302,   238,   258,   231,   255,    58,   255,   335,   231,
     328,   328,   233,   232,   232,   231,   271,   271,   258,   258,
     231,   344,   344,   255,   255,   255,   258,   258,   233,   233,
     233,   231,   233,   255,   255,   233,   231,   231,   231,   231,
     231,   233,   231,   231,   251,   232,   233,   233,   233,   233,
     233,   233,   233,   231,   233,   233,   233,   233,   251,   233,
     233,   233,   233,   233,   231,   233,   233,   233,   231,   233,
     233,   231,   233,   231,   233,   233,   233,   231,   231,   233,
     231,   233,   233,   231,   233,   233,   233,   231,   231,   231,
     233,   231,   231,   233,   233,   233,   233,    12,   267,   267,
     299,    43,    38,   317,   233,   258,   233,   232,   231,   258,
     339,   271,   271,   329,   233,   233,   255,   231,   231,    75,
      75,   258,    75,   231,   258,   258,   258,   258,   258,   258,
     258,   263,     4,     5,   286,   287,   255,   258,   258,   255,
     258,   258,   255,   258,   255,   255,   255,   258,   258,   258,
     258,   258,   301,   303,    48,   324,    60,    61,   233,    58,
     258,   255,   233,   328,   233,   233,   328,   255,   255,   255,
     255,   233,   255,   258,   233,   233,   231,   231,   233,   233,
     233,   232,   232,   231,   233,   233,   231,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   231,   231,
      13,   294,   238,   238,   258,    47,   323,   232,   232,   231,
     233,   340,    75,   258,   258,   233,   233,   287,   278,   258,
     258,   258,   258,   291,    46,   327,   238,   318,   255,   258,
     258,   342,   255,   233,   233,   238,   233,   231,   231,   238,
     325,    14,    16,    18,    41,    44,    49,   319,   231,   233,
     231,   233,   328,    25,    44,   279,   258,   258,   292,   238,
     255,   258,   233,   233,    14,    16,    18,    41,    44,    49,
     293,   326,   233,   233,     4,   295,   324
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   235,   236,   236,   236,   236,   236,   237,   238,   239,
     240,   238,   241,   241,   241,   241,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   243,   242,   244,   242,   242,   242,   242,   242,   242,
     242,   245,   242,   246,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   247,   242,   248,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     249,   249,   249,   249,   249,   250,   250,   250,   250,   250,
     250,   251,   251,   252,   252,   252,   252,   252,   253,   253,
     254,   254,   255,   255,   255,   255,   255,   255,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   257,   257,   259,   258,   260,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   261,   262,   263,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   265,   265,   265,   266,
     266,   266,   266,   267,   267,   268,   268,   268,   268,   269,
     270,   272,   271,   273,   273,   273,   274,   274,   276,   277,
     278,   275,   279,   279,   280,   280,   281,   281,   281,   281,
     282,   282,   283,   283,   283,   283,   284,   284,   285,   285,
     285,   285,   286,   286,   286,   287,   287,   287,   287,   289,
     290,   291,   292,   288,   293,   293,   293,   293,   293,   293,
     294,   294,   295,   295,   297,   296,   298,   298,   299,   299,
     300,   301,   300,   302,   303,   302,   305,   304,   306,   306,
     306,   306,   306,   306,   308,   309,   307,   310,   310,   312,
     311,   313,   313,   313,   313,   313,   313,   315,   316,   317,
     318,   314,   319,   319,   319,   319,   319,   319,   321,   320,
     322,   322,   323,   323,   324,   325,   326,   324,   327,   327,
     328,   329,   328,   330,   330,   330,   330,   331,   331,   332,
     332,   332,   332,   333,   333,   333,   333,   334,   334,   334,
     334,   334,   335,   335,   335,   337,   336,   338,   336,   339,
     336,   340,   336,   341,   336,   342,   342,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   344,   344,   345,   345,   346,   346
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     3,     3,     3,     2,     1,     0,
       0,     5,     1,     2,     1,     2,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     0,     3,     0,     3,     1,     1,     2,     2,     3,
       3,     0,     5,     0,     5,     2,     1,     2,     1,     2,
       2,     2,     3,     4,     4,     0,     3,     0,     4,     6,
       2,     6,     2,     2,     2,     1,     2,     1,     2,     2,
       2,     5,     7,     3,     2,     3,     4,     5,     3,     2,
       4,     3,     8,     6,     6,     2,     2,     5,     7,     4,
       6,     8,     5,     2,     2,     2,     2,     3,     2,     2,
       1,     1,     3,     4,     4,     4,     4,     4,     4,     1,
       1,     2,     1,     2,     2,     8,     6,     6,     4,     6,
       8,     4,     4,     4,     8,     8,    10,    10,     3,     4,
       6,     3,     4,     3,     8,     3,     8,     4,     4,     4,
       0,     1,     1,     2,     2,     3,    10,     8,     8,     8,
       3,     1,     1,     6,     4,     4,     6,     6,     4,     6,
       1,     4,     1,     1,     1,     1,     3,     3,     6,     6,
       8,     6,     4,     6,     8,     4,     1,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     1,     3,     1,     3,     4,     6,     6,     4,     6,
       4,     6,    10,     4,     4,     4,     8,     6,     4,     4,
       4,     4,     6,     3,     3,     0,     4,     0,     4,     2,
       3,     3,     3,     3,     3,     3,     3,     4,     6,     1,
       4,     4,     6,     6,     1,     1,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     3,     6,     6,     4,     4,
       4,     4,     6,     6,     8,     6,     8,     4,     4,     4,
       8,     4,     4,     4,     4,     1,     3,     4,     1,     3,
       4,     1,     3,     4,     1,     3,     6,     6,     4,     6,
       6,     6,     4,     8,     6,     8,     6,     4,     4,     4,
       6,     6,     6,     8,     4,     8,     4,     8,     8,     6,
      12,    12,     3,     6,     6,     6,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     4,     6,     4,     6,     4,
       4,     0,     2,     0,     1,     3,     1,     1,     0,     0,
       0,    11,     1,     1,     1,     1,     0,     1,     1,     2,
       1,     3,     1,     1,     4,     4,     1,     3,     1,     1,
       4,     4,     0,     1,     3,     1,     1,     3,     3,     0,
       0,     0,     0,    14,     1,     1,     1,     1,     1,     1,
       0,     2,     0,     1,     0,     7,     1,     2,     1,     1,
       0,     0,     5,     0,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     0,     0,     6,     1,     1,     0,
       4,     1,     2,     1,     1,     1,     1,     0,     0,     0,
       0,    11,     1,     1,     1,     1,     1,     1,     0,     5,
       1,     1,     0,     2,     0,     0,     0,     7,     0,     1,
       1,     0,     4,     1,     4,     1,     4,     1,     3,     1,
       4,     1,     4,     1,     1,     3,     3,     0,     2,     4,
       1,     3,     0,     2,     6,     0,     4,     0,     4,     0,
       6,     0,     9,     0,     3,     0,     1,     0,     2,     2,
       4,     1,     4,     6,     6,     7,    10,    12,     7,    10,
      12,     2,     1,     1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* program_or_expression: tSTART_EXPRESSION expression tEOPROG  */
                                         {YYACCEPT;}
    break;

  case 4: /* program_or_expression: tSTART_STRING_EXPRESSION string_expression tEOPROG  */
                                                       {YYACCEPT;}
    break;

  case 5: /* program_or_expression: tSTART_ASSIGNMENT assignment tEOPROG  */
                                         {YYACCEPT;}
    break;

  case 6: /* program_or_expression: tSTART_FUNCTION_DEFINITION function_definition tEOPROG  */
                                                           {YYACCEPT;}
    break;

  case 7: /* program: statement_list tEOPROG  */
                                {YYACCEPT;}
    break;

  case 9: /* $@1: %empty  */
                   {if (severity_so_far >= sERROR) {YYABORT;}}
    break;

  case 10: /* $@2: %empty  */
                                                                    {if (in_short_if > 0 && (yyvsp[0].nnl) > 0) lyyerror(sERROR,"short if-statement (i.e. without 'then' and ended by newline) does not contain any statements");}
    break;

  case 18: /* statement: tIMPORT  */
            {report_if_missing("can not import a library in a loop or an if-statement",FALSE);}
    break;

  case 19: /* statement: tERROR string_expression  */
                             {add_command(cERROR);}
    break;

  case 25: /* statement: tBREAK  */
           {add_command(cPOP_MULTI);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
    break;

  case 26: /* statement: tBREAK tDIGITS  */
                   {add_command(cPOP_MULTI);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
    break;

  case 27: /* statement: tCONTINUE  */
              {add_command(cPOP_MULTI);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror(sERROR,"continue outside loop");}
    break;

  case 29: /* statement: function_or_array  */
                      {create_call((yyvsp[0].symbol));add_command(cPOP);}
    break;

  case 30: /* statement: stringfunction_or_array  */
                            {create_call((yyvsp[0].symbol));add_command(cPOP);}
    break;

  case 31: /* $@3: %empty  */
           {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'local' outside functions");}
    break;

  case 33: /* $@4: %empty  */
            {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'static' outside functions");}
    break;

  case 37: /* statement: tGOTO symbol_or_lineno  */
                           {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 38: /* statement: tGOSUB symbol_or_lineno  */
                            {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 39: /* statement: tON tINTERRUPT tBREAK  */
                          {create_exception(TRUE);}
    break;

  case 40: /* statement: tON tINTERRUPT tCONTINUE  */
                             {create_exception(FALSE);}
    break;

  case 41: /* $@5: %empty  */
                         {add_command(cSKIPPER);}
    break;

  case 42: /* statement: tON expression tGOTO $@5 goto_list  */
              {add_command(cNOP);}
    break;

  case 43: /* $@6: %empty  */
                          {add_command(cSKIPPER);}
    break;

  case 44: /* statement: tON expression tGOSUB $@6 gosub_list  */
               {add_command(cNOP);}
    break;

  case 45: /* statement: tLABEL symbol_or_lineno  */
                            {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}
    break;

  case 46: /* statement: open_clause  */
                {add_command(cCHECKOPEN);}
    break;

  case 47: /* statement: tCLOSE hashed_number  */
                         {add_command(cCLOSE);}
    break;

  case 48: /* statement: seek_clause  */
                {add_command(cCHECKSEEK);}
    break;

  case 49: /* statement: tCOMPILE string_expression  */
                               {add_command(cCOMPILE);}
    break;

  case 50: /* statement: tEXECUTE call_list  */
                       {create_execute(0);add_command(cPOP);add_command(cPOP);}
    break;

  case 51: /* statement: tEXECUTE2 call_list  */
                        {create_execute(1);add_command(cPOP);add_command(cPOP);}
    break;

  case 52: /* statement: tPRINT printintro printlist  */
                                {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);}
    break;

  case 53: /* statement: tPRINT printintro printlist ';'  */
                                    {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 54: /* statement: tPRINT printintro printlist ','  */
                                    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);}
    break;

  case 55: /* $@7: %empty  */
           {tileol=FALSE;}
    break;

  case 57: /* $@8: %empty  */
                 {tileol=TRUE;}
    break;

  case 59: /* statement: tCOLOUR expression ',' expression ',' expression  */
                                                     {add_command(cGCOLOUR);}
    break;

  case 60: /* statement: tCOLOUR string_expression  */
                              {add_command(cGCOLOUR2);}
    break;

  case 61: /* statement: tBACKCOLOUR expression ',' expression ',' expression  */
                                                         {add_command(cGBACKCOLOUR);}
    break;

  case 62: /* statement: tBACKCOLOUR string_expression  */
                                  {add_command(cGBACKCOLOUR2);}
    break;

  case 65: /* statement: tRESTORE  */
             {create_restore("");}
    break;

  case 66: /* statement: tRESTORE symbol_or_lineno  */
                              {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 67: /* statement: tRETURN  */
            {if (function_type!=ftNONE) {
	       add_command(cCLEARSYMREFS);end_symref_chain();
	       add_command(cPOPSYMLIST);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL);
             } else {
               add_command(cRETURN_FROM_GOSUB);
            }}
    break;

  case 68: /* statement: tRETURN expression  */
                       {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 69: /* statement: tRETURN string_expression  */
                              {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 71: /* statement: tOPEN tWINDOW expression ',' expression  */
                                            {create_openwin(FALSE);}
    break;

  case 72: /* statement: tOPEN tWINDOW expression ',' expression ',' string_expression  */
         {create_openwin(TRUE);}
    break;

  case 73: /* statement: tWINDOW tORIGIN string_expression  */
                                      {add_command(cMOVEORIGIN);}
    break;

  case 74: /* statement: tDOT coordinates  */
                     {add_command(cDOT);}
    break;

  case 75: /* statement: tCLEAR tDOT coordinates  */
                            {add_command(cDOT);putindrawmode(dmCLEAR);}
    break;

  case 76: /* statement: tLINE coordinates to coordinates  */
                                     {create_line(2);}
    break;

  case 77: /* statement: tCLEAR tLINE coordinates to coordinates  */
                                            {create_line(2);putindrawmode(dmCLEAR);}
    break;

  case 78: /* statement: tLINE tTO coordinates  */
                          {create_line(1);}
    break;

  case 79: /* statement: tLINE coordinates  */
                      {create_line(1);}
    break;

  case 80: /* statement: tCLEAR tLINE tTO coordinates  */
                                 {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 81: /* statement: tCLEAR tLINE coordinates  */
                             {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 82: /* statement: tPUTBIT string_expression to expression ',' expression ',' string_expression  */
                                                                                 {add_command(cPUTBIT);}
    break;

  case 83: /* statement: tPUTBIT string_expression to expression ',' expression  */
                                                           {create_pushstr("solid"); add_command(cPUTBIT);}
    break;

  case 84: /* statement: tPUTCHAR string_expression to expression ',' expression  */
                                                            {add_command(cPUTCHAR);}
    break;

  case 85: /* statement: tNEW tCURVE  */
                {create_line(-1);}
    break;

  case 86: /* statement: tCLOSE tCURVE  */
                  {create_line(0);}
    break;

  case 87: /* statement: clear_fill_clause tCIRCLE coordinates ',' expression  */
                                                         {add_command(cCIRCLE);putindrawmode(0);}
    break;

  case 88: /* statement: clear_fill_clause tTRIANGLE coordinates to coordinates to coordinates  */
                                                                          {add_command(cTRIANGLE);putindrawmode(0);}
    break;

  case 89: /* statement: tTEXT coordinates ',' string_expression  */
                                            {add_command(cTEXT1);}
    break;

  case 90: /* statement: tTEXT coordinates ',' string_expression ',' string_expression  */
                                                                  {add_command(cTEXT2);}
    break;

  case 91: /* statement: tTEXT coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                        {add_command(cTEXT3);}
    break;

  case 92: /* statement: clear_fill_clause tRECT coordinates to coordinates  */
                                                       {add_command(cRECT);putindrawmode(0);}
    break;

  case 93: /* statement: tCLOSE tWINDOW  */
                   {add_command(cCLOSEWIN);}
    break;

  case 94: /* statement: tCLEAR tWINDOW  */
                   {add_command(cCLEARWIN);}
    break;

  case 95: /* statement: tCLEAR tSCREEN  */
                   {add_command(cCLEARSCR);}
    break;

  case 96: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 97: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 98: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 99: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 100: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 101: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 102: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 103: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 104: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 105: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 106: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 107: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 108: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 109: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 110: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 111: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 112: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 113: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 114: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 115: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 116: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 117: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 118: /* statement: tBEAM_CLOSE '(' expression ')'  */
                                   {add_command(cBEAM_CLOSE);}
    break;

  case 119: /* statement: tBEAM_TITLE '(' expression ',' string_expression ')'  */
                                                         {add_command(cBEAM_TITLE);}
    break;

  case 120: /* statement: tBEAM_SIZE '(' expression ',' expression ',' expression ')'  */
                                                                {add_command(cBEAM_SIZE);}
    break;

  case 121: /* statement: tBEAM_BEGIN '(' expression ')'  */
                                   {add_command(cBEAM_BEGIN);}
    break;

  case 122: /* statement: tBEAM_END '(' expression ')'  */
                                 {add_command(cBEAM_END);}
    break;

  case 123: /* statement: tBEAM_LABEL '(' string_expression ')'  */
                                          {add_command(cBEAM_LABEL);}
    break;

  case 124: /* statement: tBEAM_TEXT '(' string_expression ',' expression ',' expression ')'  */
                                                                       {add_command(cBEAM_TEXT);}
    break;

  case 125: /* statement: tBEAM_IMAGE '(' string_expression ',' expression ',' expression ')'  */
                                                                        {add_command(cBEAM_IMAGE);}
    break;

  case 126: /* statement: tBEAM_PROGRESS '(' expression ',' expression ',' expression ',' expression ')'  */
                                                                                   {add_command(cBEAM_PROGRESS);}
    break;

  case 127: /* statement: tBEAM_VBAR '(' expression ',' expression ',' expression ',' expression ')'  */
                                                                               {add_command(cBEAM_VBAR);}
    break;

  case 128: /* statement: tBEAM_SEPARATOR '(' ')'  */
                            {add_command(cBEAM_SEPARATOR);}
    break;

  case 129: /* statement: tBEAM_SPACING '(' expression ')'  */
                                     {add_command(cBEAM_SPACING);}
    break;

  case 130: /* statement: tBEAM_ROW '(' expression ',' expression ')'  */
                                                {add_command(cBEAM_ROW);}
    break;

  case 131: /* statement: tBEAM_ROW_END '(' ')'  */
                          {add_command(cBEAM_ROW_END);}
    break;

  case 132: /* statement: tBEAM_GROUP_BEGIN '(' string_expression ')'  */
                                                {add_command(cBEAM_GROUP_BEGIN);}
    break;

  case 133: /* statement: tBEAM_GROUP_END '(' ')'  */
                            {add_command(cBEAM_GROUP_END);}
    break;

  case 134: /* statement: tBEAM_PANEL_BEGIN '(' string_expression ',' expression ',' expression ')'  */
                                                                              {add_command(cBEAM_PANEL_BEGIN);}
    break;

  case 135: /* statement: tBEAM_PANEL_END '(' ')'  */
                            {add_command(cBEAM_PANEL_END);}
    break;

  case 136: /* statement: tBEAM_SET_COLOR '(' expression ',' expression ',' expression ')'  */
                                                                     {add_command(cBEAM_SET_COLOR);}
    break;

  case 137: /* statement: tBEAM_SET_STYLE '(' string_expression ')'  */
                                              {add_command(cBEAM_SET_STYLE);}
    break;

  case 138: /* statement: tBEAM_SLEEP '(' expression ')'  */
                                   {add_command(cBEAM_SLEEP);}
    break;

  case 139: /* statement: tBEAM_NMEA_CLOSE '(' expression ')'  */
                                        {add_command(cBEAM_NMEA_CLOSE);}
    break;

  case 140: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 141: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 142: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 143: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 144: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 145: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 146: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 147: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 148: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 149: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 150: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 153: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 154: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 155: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 156: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 157: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 158: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 159: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 160: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 161: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 162: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 164: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 165: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 166: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 168: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 169: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 170: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 171: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 172: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 173: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 174: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 175: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 176: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 177: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 178: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 179: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 180: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 181: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 182: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 183: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 184: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 185: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 186: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 187: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 188: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 189: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 190: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 191: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 192: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 193: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 194: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 195: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 196: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 197: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 198: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 199: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 200: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 201: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 202: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 203: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 204: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 205: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 206: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 207: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 208: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 209: /* string_function: tBEAM_OPEN_FILE '(' string_expression ')'  */
                                              {create_function(fBEAM_OPEN_FILE);}
    break;

  case 210: /* string_function: tBEAM_SAVE_FILE '(' string_expression ')'  */
                                              {create_function(fBEAM_SAVE_FILE);}
    break;

  case 211: /* string_function: tBEAM_NMEA_READ '(' expression ')'  */
                                       {create_function(fBEAM_NMEA_READ);}
    break;

  case 212: /* string_function: tBEAM_NMEA_FIELD '(' string_expression ',' expression ')'  */
                                                              {create_function(fBEAM_NMEA_FIELD);}
    break;

  case 213: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 214: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 215: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 216: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 217: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 218: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 219: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 220: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 221: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 222: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 223: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 224: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 225: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 226: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 227: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 228: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 229: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 230: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 231: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 232: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 233: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 234: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 235: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 236: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 237: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 238: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 239: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 240: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 241: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 242: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 243: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 244: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 245: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 246: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 247: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 248: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 251: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 252: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 254: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 255: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 256: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 257: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 258: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 259: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 260: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 261: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 262: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 263: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 264: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 265: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 266: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 267: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 268: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 269: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 270: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 271: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 272: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 273: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 274: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 275: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 276: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 277: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 278: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 279: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 280: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 281: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 282: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 283: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 284: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 285: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 286: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 287: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 288: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 289: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 290: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 291: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 292: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 293: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 294: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 295: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 296: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 297: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 298: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 299: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 300: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 301: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 302: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 303: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 304: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 305: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 306: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 307: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 308: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 309: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 310: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 311: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 312: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 313: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 314: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 315: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 316: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 317: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 318: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 319: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 320: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 321: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 322: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 323: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 324: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 325: /* function: tBEAM_OPEN '(' expression ',' expression ',' string_expression ')'  */
                                                                       {create_function(fBEAM_OPEN);}
    break;

  case 326: /* function: tBEAM_RUNNING '(' expression ')'  */
                                     {create_function(fBEAM_RUNNING);}
    break;

  case 327: /* function: tBEAM_BUTTON '(' string_expression ',' expression ',' expression ')'  */
                                                                         {create_function(fBEAM_BUTTON);}
    break;

  case 328: /* function: tBEAM_INPUT '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fBEAM_INPUT);}
    break;

  case 329: /* function: tBEAM_CHECKBOX '(' string_expression ',' expression ')'  */
                                                            {create_function(fBEAM_CHECKBOX);}
    break;

  case 330: /* function: tBEAM_COMBO '(' string_expression ',' expression ',' expression ',' expression ',' expression ')'  */
                                                                                                      {create_function(fBEAM_COMBO);}
    break;

  case 331: /* function: tBEAM_SLIDER '(' expression ',' expression ',' expression ',' expression ',' expression ')'  */
                                                                                                {create_function(fBEAM_SLIDER);}
    break;

  case 332: /* function: tBEAM_TIME '(' ')'  */
                       {create_function(fBEAM_TIME);}
    break;

  case 333: /* function: tBEAM_MSGBOX '(' string_expression ',' string_expression ')'  */
                                                                 {create_function(fBEAM_MSGBOX);}
    break;

  case 334: /* function: tBEAM_CONFIRM '(' string_expression ',' string_expression ')'  */
                                                                  {create_function(fBEAM_CONFIRM);}
    break;

  case 335: /* function: tBEAM_NMEA_OPEN '(' string_expression ',' expression ')'  */
                                                             {create_function(fBEAM_NMEA_OPEN);}
    break;

  case 336: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 337: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 338: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 339: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 340: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 341: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 342: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 343: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 344: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 345: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 346: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 347: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 348: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 349: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 350: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 351: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 358: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 359: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 360: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 361: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 362: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 363: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 364: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 365: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 366: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 367: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 368: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 369: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 372: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 373: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 374: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 375: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 378: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 379: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 380: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 381: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 385: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 386: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 387: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 388: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 389: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 390: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 391: /* $@17: %empty  */
                    { /* pushes another expression */
	     add_command(cSKIPONCE);
	     pushlabel();
	     add_command(cSTARTFOR);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     poplabel();

	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cSKIPONCE);
	     add_command(cFORINCREMENT);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cFORCHECK);
	     add_command(cDECIDE);
             pushlabel();}
    break;

  case 392: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 393: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 394: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 395: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 396: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 397: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 398: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 399: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 400: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 402: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 403: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 404: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 405: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 411: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 412: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 414: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 416: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 418: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 419: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 420: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 421: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 422: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 423: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 424: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 425: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 427: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 428: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 429: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 431: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 432: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 433: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 434: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 435: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 436: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 437: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 438: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 439: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 440: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 442: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'fi' at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 443: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 444: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 445: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 446: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 447: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 448: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 450: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 451: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 455: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 456: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 461: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 463: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 464: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 465: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 466: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 469: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 470: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 471: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 472: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 473: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 474: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 475: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 476: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 480: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 481: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 482: /* using: %empty  */
       {create_print('d');}
    break;

  case 483: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 484: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 485: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 486: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 487: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 488: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 489: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 490: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 491: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 492: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 493: /* $@38: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 494: /* inputbody: $@38 prompt inputlist  */
                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 495: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 496: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 497: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 498: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 499: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 500: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 501: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 502: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 503: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 504: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 505: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 506: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 507: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 508: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 509: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 510: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 513: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 514: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 515: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 516: /* gosub_list: gosub_list ',' symbol_or_lineno  */
                                    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;



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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

