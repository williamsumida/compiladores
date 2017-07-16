/*Trabalho de compiladores
	Analisador lexico
  William Hitoshi Sumida*/
%option noyywrap
%{

%}


%%

"+"   	{printf("%s\n",yytext);}
"-"    	{printf("%s\n",yytext);}


[0-9]+["e"][-+]?[0-9]+		{printf("%s\n",yytext);}
[a-zA-Z][a-zA-Z0-9]* 			{printf("%s\n",yytext);}
[0-9]+ 							{printf("%s\n",yytext);}

[\n]       				


.          	printf( "ERRO\n" );

%%
int main(){
	yylex();
	return 0;
}
