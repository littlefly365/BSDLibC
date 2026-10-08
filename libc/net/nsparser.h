#ifndef __nsyy_defines_h_
#define __nsyy_defines_h_

#define NL 257
#define SUCCESS 258
#define UNAVAIL 259
#define NOTFOUND 260
#define TRYAGAIN 261
#define RETURN 262
#define CONTINUE 263
#define STRING 264
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
	char *str;
	int   mapval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE _nsyylval;

#endif /* __nsyy_defines_h_ */
