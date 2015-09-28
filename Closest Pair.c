#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quickSort(int valor[], int esquerda, int direita)//fun��o que ordena o vetor ao modo quicksort
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
int Sub(int v[],int n){ //fun��o que acha a primeira menor diferen�a
	int min;   //Variavel que recebe a menor diferen�a
    int sub;   //Variavel tempor�ria que recebe as diferen�as da lista
	int N;  //A posi��o relacionado a menor diferen�a
	int b;
	min = v[n-1] + 1;//Estabelece o valor da diferen�a inicial como o maior poss�vel: maior que o maior dos numeros
	for (b=0;b<n-1;b++){
		sub = v[b+1]-v[b]; 
		if (sub < min){ //Atualiza min comparando com sub
			min = sub;
			N = b;
		}
	}
	return N;
}

void main(){
	int n,i;
	printf("Digite o numero de elementos da lista: ");
	scanf("%d", &n);
	if (n<2){
		printf("Nao existe diferenca!");//A lista precisa ter mais de dois elementos para haver diferen�a
	}
	else{
		int *v = (int*)malloc(n*sizeof(int)); //define um vetor para receber a lista
	    printf("Digite os numeros da lista: ");
	    for (i=0;i<n;i++){
		    scanf("%d",&v[i]);
	    }
	    quickSort(v,0,n-1);
	    printf("A menor diferenca: %d e %d",v[Sub(v,n)+1],v[Sub(v,n)]);
	    free (v);
    }
}
	

