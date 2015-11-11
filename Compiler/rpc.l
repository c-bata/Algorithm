/* 逆ポーランド計算機 */
%{
#include <stdio.h>
#define STACKSIZE  256

double S[STACKSIZE], x;		/* スタックと一時退避領域 */
int P = -1;			/* スタックポインタ */

void printStack();		/* スタックの内容を表示する関数 */
%}

%option noyywrap
DIGIT	[0-9]

%%
[ \t\r]+	{ /* ignored */ }
\n		{ printStack(); }
"-"?{DIGIT}+("."{DIGIT}*)?	{ sscanf(yytext, "%lf", &S[++P]); }
"+"		{ if (P>0) { S[P-1] += S[P]; --P; } }
"-"		{ if (P>0) { S[P-1] -= S[P]; --P; } }
"*"		{ if (P>0) { S[P-1] *= S[P]; --P; } }
"/"		{ if (P>0) { S[P-1] /= S[P]; --P; } }
"+-"		{ if (P>-1) S[P] = -S[P]; }
p		{ if (P>-1) --P; }
d		{ if (P>-1) { ++P; S[P] = S[P-1]; } }
o		{ if (P>0) { ++P; S[P] = S[P-2]; } }
s		{ if (P>0) { x=S[P-1]; S[P-1]=S[P]; S[P]=x; } }
r		{ if (P>1) { x=S[P-2]; S[P-2]=S[P-1]; S[P-1]=S[P]; S[P]=x; } }
c		{ P=-1; }
q		{ return; }
[^ \t\r\n]+	{ fprintf(stderr, "unknown token (%s)\n", yytext); }
%%

main() {
  printf("*** Reverse Polish Calculator \n");
  printf("> ");
  yylex();
}

void printStack() {
  int i;
  for(i=0; i<=P; i++) printf("%.8g ", S[i]);
  printf("> ");
}
