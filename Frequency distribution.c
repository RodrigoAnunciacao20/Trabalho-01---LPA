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

int freq(int v[], int n){ //Fun��o que acha a maior frequ�ncia de um vetor com uma posi��o auxiliar(posi��o sem n�meros da lista)
	int x;
	int aux = 1;      //Estabelece o contador de maior frenqu�ncia 
	int tmp = 1;      //Estabelece o contador de frenqu�ncia tempor�rio
	v[n+1]=v[n]+1;    //Estabelece posi��o auxiliar diferente de adjacente para evitar erros de compara��o
	for (x=0;x<n;x++){   //Percorreo vetor achando a maior frequ�ncia
		if (v[x]==v[x+1]){ 
			tmp++;         
		}else{
			if (tmp>aux){  //Atualiza a maior frenqu�ncia comparando com o tempor�rio
				aux = tmp;  
			}
			tmp = 1;       //Reinicializa o ciclo do tempor�rio
		}
	}
	return aux;
}
void main(){
	int n,i,k,x;
	printf("Digite o numero de elementos da lista: ");
	scanf("%d", &n);
	int *v = (int*)malloc((n+1)*sizeof(int)); // Estabelece o vetor que receber� a Lista com uma posi��o auxiliar livre
	printf("Digite os numeros da lista: ");
	for (i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	quickSort(v,0,n-1); //Ordena o vetor sem a posi��o auxiliar
	int f = freq(v,n); //Pega a maior frequencia no vetor
	printf("Maior frequencia: "); //Percorre o vetor procurando o primeiro n�mero de maior frequ�ncia
	for (k=0;k<n-1;k++){
	   	if (v[k]==v[k+f-1]){
	   		printf("%d",v[k]);
	   		k=n;
		}
	}
	free(v);	
}

