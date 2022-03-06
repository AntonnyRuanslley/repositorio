#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){   
	int i, menor, org, aux, impar;
	char *arr;
	FILE *arq;
		
	// Abertura de um arquivo para leitura
	arq = fopen("Entrada.txt", "rt");
	if (arq == NULL){ 											// Se houve erro na abertura
	    printf("Problemas na abertura do arquivo\n");
	    return 0;
	}
	fgets(arr, 50, arq);
	fclose(arq);
	
	// Transforma��o em inteiro
	int saida[strlen(arr)];
	impar = 0;
    for(i = 0; i < strlen(arr); i++) {
    	if(arr[i] != ' ' && arr[i] != 'a'  && arr[i] != 'r' && arr[i] != '=' && arr[i] != '[' && arr[i] != ',' && arr[i] != ']'){
    		saida[impar++] = arr[i] - '0';
		}   
    }
    
    // Verificando se a lista cont�m uma quantidade impar de n�meros
	if(impar%2 != 0){
		
		// Organiza��o do lista de n�meros 
		org = -1;
		do{
			org++;
    		menor = org;
    		for(i = org+1; i<impar; i++){
    			if (saida[i] < saida[menor]){
					menor = i;
				}
    		}
    		aux = saida[org];
    		saida[org] = saida[menor];
			saida[menor] = aux;
		}while (org < impar);
		
		// Apresenta��o da mediana
		printf("%d \n", saida[org/2]);	
	}
	system("pause");		
	return 0;	
}
