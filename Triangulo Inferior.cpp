#include <stdio.h>
#define max 10

int somatoria(int j, int i , int M[][10], int X[]){
	int cont=0;
	for( ; j < i-1 ; j++){
		cont+=M[i+1][j] * X[j]; //é i+1 para fixar a linha, pois na chamada de função é i-1
	}
	
	return cont;
}

void TriInferior(int t, int M[][10], int X[], int B[]){
	int i, j, ii=1, jj;
	for(i=0 ; i<t ; i++){
			if(i==0) X[0]= B[0]/M  [0][0];
			else X[i]= (B[i] - somatoria(0, i-1, M, X))/M[i][i];
}
}

int main(){
	
	int A[max][max], X[max], B[max];
	int i , n, j;
	
	printf("Digite a ordem da matriz: ");
	scanf("%d", &n);
	
	printf("\nDigite a matriz\n");
	for(i=0 ; i<n ; i++)
	for(j=0 ; j<n ; j++)
	scanf("%d", &A[i][j]);	
	
	printf("Digite o vetor X");
	
	for(i=0 ; i<n ; i++)
	scanf("%d", &X[i]);
	
	printf("Digite o vetor B");
	
	for(i=0 ; i<n ; i++)
	scanf("%d", &B[i]);
	
	printf("\nA matriz eh:");
	for(i=0 ; i<n ; i++){
	printf("\n");
	for(j=0 ; j<n ; j++)
	printf("%d ", A[i][j]);
}
	
	printf("\nO vetor B eh: ");
	
	for(i=0 ; i<n ; i++)
	printf("%d", B[i]);
	
	TriInferior(n, A, X, B);

	printf("\nO vetor X eh: ");
	
	for(i=0 ; i<n ; i++)
	printf("%d", X[i]);
}