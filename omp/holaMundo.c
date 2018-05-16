		/* Hola mundo en OMP  */

#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
	int nthreads = 4;  // Numero de hilos
	int tid;   			
	//Establecemos el numero de hilos
	omp_set_num_threads(nthreads);

	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();
		printf("Hola mundo soy el hilo %d\n",tid);
	}

	printf("El numero de hilos totales son %d\n",nthreads);

	return 0;
}