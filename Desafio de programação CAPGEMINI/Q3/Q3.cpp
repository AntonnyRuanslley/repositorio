#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){   
	int linha1, linha2, coluna, cont = 0, tam;
	char s[50];
	FILE *arq;
		
	// Abertura de um arquivo para leitura
	arq = fopen("Entrada.txt", "rt");
	if (arq == NULL){ 											// Se houve erro na abertura
	    printf("Problemas na abertura do arquivo\n");	
	    return 0;
	}
	fgets(s, 50, arq);
	fclose(arq);
    
    // Contagem de letras
	for(linha1=4; linha1<strlen(s); linha1++){
		if(s[linha1] != ' '){
			cont++;
		}
	}
	
	// Criação do Grid
	tam = round(sqrt(cont));
	linha2 = 4;	
	char grid[tam][tam];
	for(linha1=0; linha1<tam; linha1++){
		for(coluna=0; coluna<tam;){
			if(s[linha2] != ' '){
				grid[linha1][coluna] = s[linha2];
				coluna++;
			}	
			linha2++;
		}
	}
	
	// Fazendo a criptografia 	
	memset(s, 0, 50);
	linha2 = 0;	 
	for(linha1=0; linha1<tam; linha1++){
		for(coluna=0; coluna<tam; coluna++){	
			if(grid[coluna][linha1] != NULL){
				s[linha2++] = grid[coluna][linha1];
			}
		}
		s[linha2++] = ' ';
	}
	printf("%s\n", s);	
	system("pause");
	return 0;
}
