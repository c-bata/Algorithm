%{
#define TRUE 1
%}
%%
[ \t\r\n]+		{ }
"=="		{ printf("[%s]", yytext); return TRUE; }
"!="		{ printf("[%s]", yytext); return TRUE; }
"<="		{ printf("[%s]", yytext); return TRUE; }
">="		{ printf("[%s]", yytext); return TRUE; }
"&&"		{ printf("[%s]", yytext); return TRUE; }
"||"		{ printf("[%s]", yytext); return TRUE; }
[0-9]+		{ printf("[%s]", yytext); return TRUE; }
\"[^"\n]*\"	{ printf("[%s]", yytext); return TRUE; }
[A-Za-z][A-Za-z0-9]*	{ printf("[%s]", yytext); return TRUE; }
.		{ printf("[%s]", yytext); return TRUE; }
"//".*$		{ }
%%
main() { while(yylex()); }
int yywrap() { return TRUE; }
