#include <stdio.h>
#define max 10

int somatorioU(int i, int j , int M[][max], int L[][max], int U[][max]){	//somatorio de U
	int cont=0, k;
	for(k=0 ; k < i ; k++){
		cont+=L[i][k] * U[k][j]; 
	}
	
	return cont;
}

void MU(int i, int j , int n, int M[][max], int L[][max], int U[][max]){	//Matriz de U
	for(j=0 ; j < n ; j++){
		if(i==0)U[i][j]=M[i][j];
		else{
		U[i][j]=M[i][j] - somatorioU(i, j, M, L ,U); 
	}
}
}

int somatorioL(int i, int j , int M[][max], int L[][max], int U[][max]){	//Somatorio de L
	int cont=0, k;
	for(k=0 ; k < j ; k++){
		cont+=L[i][k] * U[k][j]; 
	}
	
	return cont;
}

void ML(int i, int j , int n, int M[][max], int L[][max], int U[][max]){	//Matriz de L
	for(i=0 ; i < n ; i++){
		if(j==0)L[i][j]=M[i][j]/U[j][j];
		else{
		L[i][j]=(M[i][j] - somatorioL(i, j, M, L ,U))/U[j][j]; 
	}
}
}

void MLU(int t, int M[][10], int X[], int B[]){
	int i, j;	//operadores linha e coluna
	int U[max][max], L[max][max];	//matriz U e L
	
	for(i=0, j=0 ; i<t ; i++){
		MU(i, j, t, M, L, U);
		j++;
		ML(i, j, t, M, L, U);
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
	
	MLU(n, A, X, B);

	printf("\nO vetor X eh: ");
	
	for(i=0 ; i<n ; i++)
	printf("%d", X[i]);
}