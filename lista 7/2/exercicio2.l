/*Trabalho de compiladores
	Analisador lexico
  William Hitoshi Sumida*/
%option noyywrap
%{

%}


%%

"if" 							{printf("IF\n");}			
"--"[a-z]*						{printf("%s comment\n",yytext);}
[0-9]+							{printf("%s NUM\n",yytext);}
[0-9]*[.]?[0-9]+						{printf("%s REAL\n",yytext);}
[a-zA-Z][a-zA-Z0-9]* 			{printf("%s ID\n",yytext);}
	
[\n \t]       					{printf("white space\n");}


.          	{printf("%s error\n",yytext);}

%%
int main(){
	yylex();
	return 0;
}
