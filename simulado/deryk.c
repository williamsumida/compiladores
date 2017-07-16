// UEL - Universidade Estadual de Londrina
// Aluno: Deryk Sedlak Ribeiro

#include <stdio.h>
#include <string.h>

/* Imprimir Tokens */
void printToken(int valor){
	/* Tokens */
	if(valor==3){printf("ELE");}
	else if(valor==6){printf("ELA");}
	else if(valor==8){printf("DELE");}
	else if(valor==10){printf("DELA");}
	else if(valor==13){printf("GATO");}
	else if(valor==14){printf("CARRO");}
	else if(valor==15){printf("GATOS");}
	else if(valor==16){printf("CARROS");}
	else if(valor==17){printf("MAIS");}
	else if(valor==18){printf("MENOS");}
	else if(valor==19){printf("INTEIRO ");}
	else if(valor==22){printf("REAL ");}
	/* ERRO */
	else if(valor==24){printf("White space or new line");}
	else if(valor==23){printf("ERRO");}

}

/* Associar valor/coluna */
int getSymbol(char valor){
	if(valor=='+'){return(1);}
	else if(valor=='-'){return(2);}
	else if(valor>='0' && valor<='9'){return(3);}
	else if(valor=='h'){return(4);}
	else if(valor=='s'){return(5);}
	else if(valor=='c'){return(6);}
	else if(valor=='e'){return(7);}
	else if(valor=='i'){return(8);}
	else if(valor=='a'){return(9);}
	else if(valor=='r'){return(10);}
	else if(valor=='t'){return(11);}
	else if(valor==' '){return(12);}
	else if(valor=='\n'){return(13);}
	/* ERRO */
	else{return(14);}
}

/* Tabela léxica de relações */
void createTable(char tabela[25][15]){
	int linha,coluna;
	for(linha=0;linha<25;linha++){
		for(coluna=0;coluna<15;coluna++){
			tabela[linha][coluna] = -1;
		}
	}
	/* Estados finais */
	tabela[3][0] = 0;
	tabela[6][0] = 0;
	tabela[8][0] = 0;
	tabela[10][0] = 0;
	tabela[13][0] = 0;
	tabela[14][0] = 0;
	tabela[15][0] = 0;
	tabela[16][0] = 0;
	tabela[17][0] = 0;
	tabela[18][0] = 0;
	tabela[19][0] = 0;
	tabela[22][0] = 0;
	tabela[23][0] = 0;
	tabela[24][0] = 0;
	/* Relações entre estados */
	// Estado 1
	tabela[1][1] = 17;
	tabela[1][2] = 18;
	tabela[1][3] = 19;
	tabela[1][4] = 2;
	tabela[1][5] = 4;
	tabela[1][6] = 11;
	tabela[1][7] = 23;
	tabela[1][8] = 23;
	tabela[1][9] = 23;
	tabela[1][10] = 23;
	tabela[1][11] = 23;
	tabela[1][12] = 24;
	tabela[1][13] = 24;
	tabela[1][14] = 23;
	// Estado 2
	tabela[2][7] = 3;
	tabela[2][8] = 7;
	// Estado 3
	tabela[3][10] = 9;
	// Estado 4
	tabela[4][4] = 5;
	// Estado 5
	tabela[5][7] = 6;
	// Estado 7
	tabela[7][5] = 8;
	// Estado 9
	tabela[9][5] = 10;
	// Estado 11
	tabela[11][9] = 12;
	// Estado 12
	tabela[12][11] = 13;
	tabela[12][10] = 14;
	// Estado 13
	tabela[13][5] = 15;
	// Estado 14
	tabela[14][5] = 16;
	// Estado 19
	tabela[19][3] = 19;
	tabela[19][7] = 20;
	// Estado 20
	tabela[20][1] = 21;
	tabela[20][2] = 21;
	tabela[20][3] = 22;
	// Estado 21
	tabela[21][3] = 22;
	// Estado 22
	tabela[22][3] = 22;
}

int main(){
	int c_pointer,b_pointer,t_pointer,estado,token,indice,tamanho,first;
  int aux_p1,aux_p2;
	char leitura[300000],aux_leitura;
	char tabela_lexica[25][15];

	/* Leitura de dados */
	indice = 0;
	while(scanf("%c",&leitura[indice])!=EOF){indice++;}

	/* Iniciar Tabela Léxica */
	createTable(tabela_lexica);

	/* Analisar entrada */
	tamanho = strlen(leitura);
	c_pointer=0;
	t_pointer=0;
	b_pointer=0;
  first=0;
	while(c_pointer<tamanho){
		/* Encontrar a maior substring */
		estado=1;
		token=23;
		while(1){
			estado = tabela_lexica[estado][getSymbol(leitura[b_pointer])];
			if(estado==-1){break;}
			else if(tabela_lexica[estado][0]==0){
				token = estado;
				t_pointer = b_pointer;
			}
			b_pointer++;
			if(b_pointer>tamanho){break;}
		}
		/* Ignorar tokens de \n e White space */
		if(token!=24){
			if(first){printf("\n");}else{first=1;}
			printToken(token);
		}
		/* Correr com os ponteiros */
		while(c_pointer<=t_pointer){
			if(token==19 || token==22){printf("%c",leitura[c_pointer]);}
			c_pointer++;
		}
		t_pointer = c_pointer;
		b_pointer = t_pointer;

	}
	return(0);
}
