#include <stdio.h>
#include <math.h>
#include <string.h>
#define max 10
//sqrt raiz quadrada;

double somatorioPrincipal(int i, double L[][max]){
	double cont=0;
	for(int k=0; k < i ; k++){
		cont+=pow(L[i][k], 2);
	}
	return cont;
}

void DPrincipal(int i, double M[][max], double L[][max]){
	if(i == 0){
		L[0][0] = sqrt(M[0][0]);
		printf("\n\nMatriz L[0][0]: %.4lf\n\n", L[0][0]);
	}
	else{
		L[i][i] = sqrt(M[i][i] - somatorioPrincipal(i, L));
		printf("Matriz L[%i][%i]: %.4lf\n\n", i, i, L[i][i]);
	}
}

double somatorioResto(int i, int j, double L[][max]){
	double cont = 0;
  		for(int k = 0; k < j; k++){
    		cont += L[i][k] * L[j][k];
  		}
  return cont;
}
	
void DResto(int i, int j, double M[][max], double L[][max]){
	if(i==0){
		L[i][j] = M[i][j]/L[i][i];
		printf("Matriz L[%d][%d] = %.4lf\n\n", i, j, L[i][j]);
		L[j][i] = L[i][j];
		printf("Matriz L[%d][%d] = %.4lf\n\n", i, j, L[j][i]);
	}
	else{ 
		L[i][j] = (M[i][j] - somatorioResto(i, j, L)/ L[j][j]);
		printf("Matriz L[%d][%d] = %.4lf\n\n", i, j, L[i][j]);
	}
}

double somatoriaEQLY(int j, int i, double L[][10], double X[]){
	double cont=0;
	for(;j < i-1 ; j++){
		cont += L[i+1][j] * X[j]; //Ã© i+1 para fixar a linha, pois na chamada de funÃ§Ã£o Ã© i-1
	}
	
	return cont;
}

void EQLY(int t, double L[][10], double Y[], double B[]){
	int i, j;
	for(i=0 ; i < t; i++){
		if(i==0) 
			Y[0] = B[0]/L[0][0];
		else 
			Y[i] = (B[i] - somatoriaEQLY(0, i-1, L, Y))/L[i][i];
	}
}

double somatoriaEQUX(int j, int i, double M[][10], double X[]){
	double cont=0;
	int aux;
	aux= j-1;	//linha de i fixada  pois j é i+1 na chamda da função
	for( ; j < i ; j++){
		cont+=M[aux][j] * X[j]; 
	}
	return cont;
}

void EQUX(double t, double L[][10], double X[], double B[]){
	int i, j;
	for(i=0 ; i<t ; i++){
		if(i==0)
			X[0]= B[0]/L[0][0];
		else 
			X[i]= (B[i] - somatoriaEQUX(i+1, t, L, X))/L[i][i];
	}
}

int MCHO(int t, double M[][10], double X[], double B[]){		//matriz de gaus compacta
	int i, j;	//operadores linha e coluna
	double L[max][max];	//matriz U e L
	
	for(i=0; i<t ; i++){
		for(j = 0; j < i; j++){
			DResto(i, j, M, L);
		}
	DPrincipal(i, M, L);
	}
	//precisa resolver a matriz Ly = b
	double Y[max];
	//Ly = b
	EQLY(t, L, Y, B);
	EQUX(t, L, X, Y);
}

int main(){
	
	double A[max][max], X[max], B[max];
	int i, j;
	int n;

	printf("Digite a ordem da matriz: ");
	scanf("%d", &n);
	
	printf("\nDigite a matriz\n");
	for(i=0 ; i<n ; i++)
		for(j=0 ; j<n ; j++)
			scanf("%lf", &A[i][j]);	
	
	// printf("Digite o vetor X\n");
	// for(i=0 ; i<n ; i++)
	// scanf("%d", &X[i]);
	
	printf("\nDigite o vetor B\n");
		for(i=0 ; i<n ; i++)
			scanf("%lf", &B[i]);
	
	printf("\nA matriz eh:\n");
		for(i=0 ; i<n ; i++){
			printf("\n ");
				for(j=0 ; j<n ; j++)
					printf("%.4lf ", A[i][j]);
}
	
	printf("\n\nO vetor B eh: \n(");
	
	for(i=0 ; i<n ; i++){
		printf(" %.4lf ", B[i]);
	}
	printf(")\n");

	MCHO(n, A, X, B);

	printf(" \nO vetor X eh: \n(");
	
	for(i=0 ; i<n ; i++)
		printf(" %.4lf ", X[i]);

	printf(")");
}
