#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){   
	int x, i, aux, cont=0, tam = 0;
	FILE *arq;
	char *linha;	
	// Abertura de um arquivo para leitura
	arq = fopen("Entrada.txt", "rt");
	if (arq == NULL){ 											// Se houve erro na abertura
	    printf("Problemas na abertura do arquivo\n");
	    return 0;
	}
	fgets(linha, 50, arq);
	fclose(arq);
	
	// Transformação em inteiro
	int n[strlen(linha)];
    for(i=0; i < strlen(linha); i++) {
    	if(linha[i] != ' ' && linha[i] != 'n' && linha[i] != '=' && linha[i] != '[' && linha[i] != ',' && linha[i] != ']'){
    		n[tam++] = linha[i] - '0';
		}   
    }
    
	// Contagem das diferenças
	x = 2;
	for(i=0; i<tam; i++){
		for(aux = i+1; aux<tam; aux++){
			if((n[i] - n[aux]) == x || (n[i] - n[aux]) == -x){
				cont++;
			}	
		}	
	}
	printf("%d\n", cont);
	system("pause");
	return 0;	
}
