#include <stdio.h>
#define max 10

int somatoria(int j, int i , int M[][10], int X[]){
	int cont=0, aux;
	aux= j-1;	//linha de i fixada  pois j é i+1 na chamda da função
	for( ; j < i ; j++){
		cont+=M[aux][j] * X[j]; 
	}
	
	return cont;
}

void TriSuperior(int t, int M[][10], int X[], int B[]){
	int i, j, ii=1, jj;
	for(i=0 ; i<t ; i++){
			if(i==0) X[0]= B[0]/M  [0][0];
			else X[i]= (B[i] - somatoria(i+1, t, M, X))/M[i][i];
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
	
	TriSuperior(n, A, X, B);

	printf("\nO vetor X eh: ");
	
	for(i=0 ; i<n ; i++)
	printf("%d", X[i]);
}