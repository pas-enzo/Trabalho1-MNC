#include <stdio.h>
#define max 10
//sqrt raiz quadrada;

int somatorio(int k , int M[][max], int X[]){
	int cont=0, j, n;
	for(j=0 ; k<n ; k++){
		if(j!=k)
		cont+=M[k][j]*X[k];
	}
	return cont;
}

int calculae(int X[], int Xi[], int n){
	int maxx, A[max] , maxA;
	float e;
	maxx = X[0];
	for(int i=0 ; i<n ; i++){
		A[i] = X[i] - Xi[i];
		
		if(X[i]>maxx)maxx = X[i];
	
		if(i==0)maxA = A[i];
		else if(A[i] > maxA) maxA = A[i];
	}
	e = maxA / maxx;
	return e;
}


int calculaX(int n, int B[], int M[][max], int X[]){
	int Xi[max], e, k;
	for(k=0 ;  k<n ; k++){
		Xi[k]=X[k];
		X[k] = (B[k] - somatorio(k, M, X))/M[k][k];
	}
	e = calculae(X, Xi, n);
	
	return e;
}

void JACOBI(int t, int M[][10], int B[] , float erro, int maxint, int X[], int n){		//matriz de gaus compacta
	int i, j, e;	//operadores linha e coluna
	int L[max][max];	//matriz U e L
	n=0;
	for(i=0 ; i<maxint; i++, n++ ){
		//calcula raizes
		e = calculaX(t, B, M, X);
		
		//verifica ou continua
		if(e < erro)return;
		
}
		
}

int main(){
	
	int A[max][max], X[max], B[max];
	int i , n, j;
	int maxint, Bapro, e, inte;
	
	printf("Digite a ordem da matriz: ");
	scanf("%d", &n);
	
	printf("\nDigite a matriz dos coeficientes\n");
	for(i=0 ; i<n ; i++)
	for(j=0 ; j<n ; j++)
	scanf("%d", &A[i][j]);	
	
	printf("Digite o vetor B dos termos independentes");
	
	for(i=0 ; i<n ; i++)
	scanf("%d", &B[i]);
	
	printf("Digite o Maximo de interações");
	scanf("%d", &maxint);

	
	JACOBI(n, A, B, Bapro, e, maxint, X, inte);

	printf("\nO vetor X eh: ");
	
	for(i=0 ; i<n ; i++)
	printf("%d", X[i]);
}
