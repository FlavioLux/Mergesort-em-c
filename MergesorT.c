//Mergesort

# include <stdio.h>
# include <stdlib.h>

void Merge(int* v, int tamV ,int* e, int tamE, int* d, int tamD){
	int indexV=0;
	int indexE=0;
	int indexD=0;
	while ( indexE < tamE && indexD < tamD ){//Faz a comparação elemento a elemento e copia o menor para o vetor V
		if ( e[indexE] <= d[indexD] ){
			v[indexV] = e[indexE];
			indexE++;
			} else {
				v[indexV]=d[indexD];
				indexD++;
				}
				 
				indexV++;
			}
		
//Caso os vetores esquerdo e direito sobrem, sem ter como seus elementos serem mais comparados
		while ( indexE < tamE ){
			v[indexV]=e[indexE];
				indexE++;
				indexV++;
		}
		while ( indexD < tamD ){
			v[indexV]=d[indexD];
				indexD++;
				indexV++;
		}
	}
		
void Mergesort(int *v, int tamV){

	if(tamV>1){
		int meio=tamV/2;
		int tamE= meio;
		int* e=(int*) malloc (tamE*sizeof(int));
		for( int i = 0; i < meio; i++){
			e[i]=v[i];
			}
		int tamD= tamV - meio;
		int* d= (int*) malloc (tamD*sizeof(int));
		for( int i= meio; i < tamV; i++){
			d[i-meio]=v[i];
			}
			Mergesort(e,tamE);
			Mergesort(d,tamD);
			Merge(v,tamV,e,tamE,d,tamD);
	}

}			
void ImprimeVetor(int V[], int tam) {
    printf("[%d", V[0]);
    int i;
        for (i = 1; i < tam; i++) {
            printf(", %d",V[i]);
        }
    printf("]\n");
}	

int main(){

    int v[] = {5,31,4,8,1,0,7,11,23,3};
    int n = 10;
   
        Mergesort ( v, n);
        ImprimeVetor ( v , n);
        
        return 0;

}

				
			
			
			
			
			
			
			
			
			
			
			
