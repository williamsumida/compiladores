/*Trabalho de compiladores
	Analisador lexico
  William Hitoshi Sumida*/
%option noyywrap
%{

%}


%%

"aba"+	 						{printf("action 1\n");}			
[a][b]*[a]						{printf("action 2\n");}		
[ab]							{printf("action 3\n");}	

%%
int main(){
	yylex();
	return 0;
}
