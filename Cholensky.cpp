#include <stdio.h>
#define max 10
//sqrt raiz quadrada;

int somatorioPrincipal(int i, int L[][max]){
	int cont=0;
	
	for(k=0; k< i ; k++){
		cont+=pow(L[i][k], 2);
	}
	return cont;
}

void DPrincipal(int i, int M[][max], int L[][max]){
	if(i==0)L[0][0] = sqrt(M[0][0]);
	else L[i][i] = sqrt(M[i][i]- somatorioPrincipal(i, L));
}

int somatorioResto(int i, int j, int L[][max]){
	int cont=0;
	
	for(k=0; k<j ; k++){
		cont+=L[i][k]*L[j][k];
	}
	
	return cont;
}
	
void DResto(int i, int j,  int M[][max], int L[][max]){
	if(i==0){
	L[i][j] = M[i][j]/L[i][i];
	L[j][i] = L[i][j];
}
	else L[i][j] = (M[i][j]- somatorioResto(i , j, L)/ L[j][j]);
}

void MCHO(int t, int M[][10], int X[], int B[]){		//matriz de gaus compacta
	int i, j;	//operadores linha e coluna
	int L[max][max];	//matriz U e L
	
	for(i=0, j=0 ; i<t ; i++, j++){
		DPrincipal(i, M, L);
		//j++
		DResto(i, j, M, L);
}
		 
		//precisa resolver a equacao
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
	
	MCHO(n, A, X, B);

	printf("\nO vetor X eh: ");
	
	for(i=0 ; i<n ; i++)
	printf("%d", X[i]);
}