#include <stdio.h>
#include <math.h>
#define max 10
//sqrt raiz quadrada;

int somatorioPrincipal(int i, int L[][max]){
	int cont=0;
	printf("\nSOMATORIO PRINCIPAL\n");
	for(int k=0; k < i ; k++){
		cont+=pow(L[i][k], 2);
		printf("\nSomatoria: %d", cont);
	}
	return cont;
}

void DPrincipal(int i, int M[][max], int L[][max]){
	printf("\n\nDIAGONAL PRINCIPAL\n\n");
	if(i==0){
		L[0][0] = sqrt(M[0][0]);
		printf("\n\nMatriz L[0][0]: %d\n", L[0][0]);
		}
	else{
		L[i][i] = sqrt(M[i][i]- somatorioPrincipal(i, L));
		printf("\nMatriz L[%i][%i]: %d\n", i, i, L[i][i]);
	}
}

int somatorioResto(int i, int j, int L[][max]){
	int cont=0;
	
	for(int k=0; k<j ; k++){
		cont+=L[i][k]*L[j][k];
	}
	
	return cont;
}
	
void DResto(int i, int j,  int M[][max], int L[][max]){
	printf("\n\nOUTROS VALORES DA MATRIZ\n\n");
	if(i==0){
		printf("Para i = 0:\n\n");
		L[i][j] = M[i][j]/L[i][i];
		printf("Matriz L[%d][%d] = %d\n\n", i, j, L[i][j]);
		L[j][i] = L[i][j];
		printf("Matriz L[%d][%d] = %d\n\n", i, j, L[j][i]);
	}
	else{ 
		L[i][j] = (M[i][j]- somatorioResto(i , j, L)/ L[j][j]);
		printf("L[%d][%d] = %d", i, j, L[i][j]);
	}
}

int somatoriaEQLY(int j, int i , int M[][10], int X[]){
	int cont=0;
	for(;j < i-1 ; j++){
		cont+=M[i+1][j] * X[j]; //Ã© i+1 para fixar a linha, pois na chamada de funÃ§Ã£o Ã© i-1
	}
	
	return cont;
}

void EQLY(int t, int M[][10], int X[], int B[]){
	int i, j;
	for(i=0 ; i<t ; i++){
			if(i==0) X[0]= B[0]/M[0][0];
			else X[i]= (B[i] - somatoriaEQLY(0, i-1, M, X))/M[i][i];
}
}

int somatoriaEQUX(int j, int i , int M[][10], int X[]){
	int cont=0, aux;
	aux= j-1;	//linha de i fixada  pois j é i+1 na chamda da função
	for( ; j < i ; j++){
		cont+=M[aux][j] * X[j]; 
	}
	
	return cont;
}

void EQUX(int t, int M[][10], int X[], int B[]){
	int i, j;
	for(i=0 ; i<t ; i++){
			if(i==0) X[0]= B[0]/M[0][0];
			else X[i]= (B[i] - somatoriaEQUX(i+1, t, M, X))/M[i][i];
}
}

void MCHO(int t, int M[][10], int X[], int B[]){		//matriz de gaus compacta
	int i, j;	//operadores linha e coluna
	int L[max][max];	//matriz U e L
	
	for(i=0, j=0 ; i<t ; i++){
		DPrincipal(i, M, L);
		j++;
		DResto(i, j, M, L);
}
		 
	//precisa resolver a equacao
	int Y[max];
	//Ly = b
	EQLY(t, L , Y , B);
	EQUX(t, L, X, Y);	
	



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
	
	// printf("Digite o vetor X\n");
	// for(i=0 ; i<n ; i++)
	// scanf("%d", &X[i]);
	
	printf("Digite o vetor B\n");
	for(i=0 ; i<n ; i++)
	scanf("%d", &B[i]);
	
	printf("\nA matriz eh:\n");
	for(i=0 ; i<n ; i++){
	printf("\n ");
	for(j=0 ; j<n ; j++)
	printf("%d ", A[i][j]);
}
	
	printf("\nO vetor B eh: \n(");
	
	for(i=0 ; i<n ; i++){
		printf(" %d ", B[i]);
	}
	printf(")\n");

	MCHO(n, A, X, B);

	printf("\nO vetor X eh: ");
	
	for(i=0 ; i<n ; i++)
	printf("%d", X[i]);
}
