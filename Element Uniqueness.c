#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quickSort(int valor[], int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];
    while(i <= j){
        while(valor[i] < x && i < direita){
            i++;
        }
        while(valor[j] > x && j > esquerda){
            j--;
        }
        if(i <= j){
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda){
        quickSort(valor, esquerda, j);
    }
    if(i < direita){
        quickSort(valor,  i, direita);
    }
}

void unic(int v[],int n){ //Função que imprime os números únicos
	int j,k;
	v[n+1] = v[n] +1;  //Estabelece posição auxiliar diferente da adjacente para evitar erros de comparação   
	int *aux = (int*)malloc(n*sizeof(int)); //Estabele um vetor auxiliar que recebe os  numeros unicos
	int b=0;    //Estabelece um contador para o auxiliar
	for (j=0;j<n;j++){
		if (v[j]!= v[j+1] && v[j]!=v[j-1]){ //Estabelece a condição de unico comparando com os adjacentes
			aux[b] = v[j]; //O vetor auxiliar recebe o unico
			b++;           //o contador prepara para o próximo número único
		}
	}
	if (b==0){
		printf("Sem numeros unicos!");
	}
	else {
	    printf ("Os numeros unicos: ");
	    for (k=0;k<b;k++){     //Imprime os números únicos
		    printf ("%d ", aux[k]);
	    }
	}
	free (aux);
}

void main(){
	int n,i,k;
	printf("Digite o numero de elementos da lista: ");
	scanf("%d", &n);
	int *v = (int*)malloc((n+1)*sizeof(int)); // Estabelece o vetor que receberá a Lista com uma posição auxiliar livre
	printf("Digite os numeros da lista: ");
	for (i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	quickSort(v,0,n-1); //Ordena o vetor sem a posição auxiliar
	unic(v,n);   //Imprime os números únicos
	free (v);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

