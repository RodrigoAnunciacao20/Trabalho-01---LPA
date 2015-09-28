#include<stdio.h>	  
#include <stdlib.h>
#include <math.h>

struct ponto{        //Estrutura de um ponto
	int x;
	int y;
};

void igual(struct ponto u[],int i, struct ponto v[], int j){ //Função que iguala dois pontos de dois vetores
	u[i].x = v[j].x;
	u[i].y = v[j].y;
}

double dist(struct ponto p1, struct ponto p2){     //Função que calcula a distância de dois pontos
	double d = (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
	return sqrt(d);
}

double CosAngle (struct ponto p1, struct ponto p2){ //Função que calcula o seno do ângulo polar formado por um ponto ao eixo formado pelo outro ponto
	struct ponto p;
	p.x = (p1.x)+1;
	p.y = p1.y;
	double a = ((p1.x-p.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p1.y-p.y))/dist(p2,p1);
	return a;	
}

int Sentido(struct ponto p1, struct ponto p2, struct ponto p3){ //Função que determina o sentido de giro entre três pontos
	int a = (p2.x-p1.x)*(p3.y-p2.y)+(p3.x-p2.x)*(p2.y-p1.y);
	if (a>0){
		return 1;
	}
	if (a<0){
		return 2;
	}
	if (a==0){
		return 3;
	}
}

void troca(struct ponto v[], int i, int j){  //Função que troca as coordenadas de dois pontos de um mesmo vetor 
	struct ponto tmp;
	tmp.x = v[i].x;
	tmp.y = v[i].y;
	v[i].x = v[j].x;
	v[i].y = v[j].y;
	v[j].x = tmp.x;
	v[j].y = tmp.y;
}

int LowY(struct ponto v[], int n){  //Função que acha a ponto de menor y, caso haja pontos com mesmo y, o de maior x será escolhido
	int i;
	int tmp = v[0].y;
	int aux = 0;
	for (i=0;i<n;i++){
		if (v[i].y<tmp||v[i].y==tmp&&v[i].x>v[aux].x){
			tmp = v[i].y;
			aux = i;
		}
	}
	return aux;
}


void SortByAngle (struct ponto v[], int n){ //Função que ordena os pontos pelo seu ângulo polar em relação ao de menor coordenadas
	int i,j;
	int f = LowY(v,n);
	troca (v,0,f);
	for (i=1;i<n-1;i++){
		for (j=1;j<n-i-1;j++){
			if (CosAngle(v[j+1],v[0])<CosAngle(v[j],v[0])){
				troca(v,j,j+1);
			}
		}
	}
	
}

void ComplexHull(struct ponto v[],int n){ //Função que acha os pontos pertencentes ao "Convex Hull"
	int i,j,k,l;
	SortByAngle(v,n);
	struct ponto *aux = (struct ponto*)malloc((n)*sizeof(struct ponto));
	igual(aux,0,v,0);
	igual(aux,1,v,1);
	k = 1;
	i = 2;
	while(k<n-1){
		if (Sentido(v[k],v[k+1],v[k+2])==1&&Sentido(v[k+1],v[k+2],v[k+3])==1||Sentido(v[k],v[k+1],v[k+2])==3){ //Se o giro for duas vezes consecutivas no 
			igual(aux,i,v,k+1);                                                                                // sentido anti-horário, então o ponto está 
			i++;                                                                                               //no polígono
			k++;
		}
		else{
			k++;
		}
	}
	n = i+1; //Só se preocupa agora com um número de posições igual à do auxiliar
	for (j=0;j<n;j++){
		igual(v,j,aux,j);
	}
	free (aux);
}

void main(){
	int n,a;
	printf("Quantos pontos serão analisados: ");
	scanf("%d",&n);
	if (n<3){                //O menor polígono é um triângulo
		printf("Nao havera poligono!");
	}
	else{
        int i,j,k;
		struct ponto *v = (struct ponto*)malloc((n)*sizeof(struct ponto));
		printf("Digite os pontos: ");
		for (i=0;i<n;i++){
			    scanf("%d",&v[i].x);
			    scanf("%d",&v[i].y);
		    }
		if (n==3){
		    printf("Os pontos do poligono: ");
		    for (k=0;k<n;k++){
			    printf("(%d,%d)",v[k].x,v[k].y);
		    }
	    }
		else{ 
		    ComplexHull(v,n);
		    printf("Os pontos do poligono: ");
		    for (j=0;j<n;j++){
			    printf("(%d,%d)",v[j].x,v[j].y);
		    }
	    }
		free(v);
	}
	
}

