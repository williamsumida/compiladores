/*Trabalho de compiladores
	Analisador lexico
  William Hitoshi Sumida*/
%option noyywrap
%x commentario
%{
int collumn = 0;
int lines = 1;
%}

comentario_linha \/\/([^\n])*

%%
"+"       	{printf("+\n");}					{collumn+=strlen(yytext);}
"-"        	{printf("-\n");}				{collumn+=strlen(yytext);}


[0-9]["e"]?["+"|"-"]?[0-9]*
["][ a-zA-Z0-9]+["]				{printf("STRING(%s)\n",yytext);}{collumn+=strlen(yytext);}
[0][1-7][0-7]*					{printf("NUM_OCTAL(%s)\n",yytext);}{collumn+=strlen(yytext);}
[00]?[0-9]+ 					{printf("NUM_INTEGER(%s)\n",yytext);}{collumn+=strlen(yytext);}


.          	{collumn++;}printf("ERRO\n");

%%
int main(){
	yylex();
	return 0;
}
