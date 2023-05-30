#include <stdio.h>
#define max 10

float det(int t, float M[][max]){
	if(t==1){
		return M[0][0];
	}
	else{
	float cont = 0;
    int i, jj, ii, aux, col;
	//ida
	for(i=0 ; i<t ; i++){
		//sempre escolhe a primeira linha para calcular
		if (M[0][i] != 0) {
			ii = jj =0;

			float A1[max][max];
			
		//como escolheu a primeira linha, compara com linha 1 da inicial
    	for(aux = 1; aux < t; aux++){
    		for(col = 0; col < t; col++){
    			//tirando a coluna 
       			if(col != i){
            	A1[ii][jj] = M[aux][col];
            	jj++;	//se adicionou ent anda com coluna
        }
    }
    ii++;	//como monto 1 linha ent soma pra prox coluna
   	jj = 0;
}
 	float factor = (i % 2 == 0)? M[0][i] : -M[0][i];
    cont = cont + factor * det(t - 1, A1);
	//	if(i%2==0)
	//	cont =cont + det(t-1, A1);
	//	else cont = cont - det(t-1, A1);

	}
}
//	printf("\no determinante eh : %.0f", cont);
	return cont;
}
	
}
    

int main(){
	
	float A[max][max];
	int i , n, j;
	
	printf("Digite a ordem da matriz: ");
	scanf("%d", &n);
	
	printf("\nDigite a matriz\n");
	for(i=0 ; i<n ; i++)
	for(j=0 ; j<n ; j++)
	scanf("%f", &A[i][j]);	
	
	printf("\nA matriz eh:");
	for(i=0 ; i<n ; i++){
	printf("\n");
	for(j=0 ; j<n ; j++)
	printf("%.0f ", A[i][j]);
}
	printf("\no determinante eh : %.0f", det(n, A));
}