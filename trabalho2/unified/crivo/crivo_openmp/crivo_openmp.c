#include <stdio.h>
#include <stdlib.h> 
#include <omp.h>

/* Inicializa o crivo de erastotenes */
void init_crivo(int nrThreads){
	/* Declaracao de variaveis */
	int N = 1000000; /* o maximo valor no qual procuramos numeros primos */
	int sqrtN = 1000; /* a raiz de N */
	int c = 2; /* usado para checar o proximo numero a ser circulado */
	int m = 3; /* usado para chegar o proximo numero a ser marcado */
	int lista[N]; /* a lista de numeros – se lista[x] igual a 1, entao x eh marcado. Senao eh desmarcado. */
	
	/* seta o numero de threads a serem usados */
	omp_set_num_threads(nrThreads);

	/* passa por todo numero na lista */
	#pragma omp parallel for
	for(c = 2; c <= N-1; c++){
		/* seta todos os numeros como desmarcados */
		lista[c] = 0;
	}

	/* executando ate a raiz de N */
	for(c = 2; c <= sqrtN; c++){
		/* se o numero esta desmarcado */
		if(lista[c] == 0){
			#pragma omp parallel for
			/* executa para cada numero maior que c */
			for(m = c+1; m <= N-1; m++){
				/* se m eh multiplo de c*/
				if(m % c == 0){
					/*marcar m*/
					lista[m] = 1;
				}
			}
		}
	}

	/* executa para todo numero na lista
	for(c = 2; c <= N - 1; c++){
		// se o numero esta desmarcado 
		if(lista[c] == 0){
			// o numero e primo 
			printf("%d ", c);
		}
	}
	printf("\n");
	*/
}

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("passagem errada de parametros\n");
		exit(0);
	}
	
	int nrThreads = atoi(argv[1]);
	
	init_crivo(nrThreads);

	return 0;
}
