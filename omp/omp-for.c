			/* Agregamos el contructor for */
			/* Agregamos clausulas del for con sus valores*/
#include <omp.h>
#include <stdio.h>

void imprimirArray(int a[], int tam);
void inciarArray(int a[], int tam, int fac);

int main(int argc, char const *argv[])
{
	int nthreads = 4, i;
	int chuk = 4; /* El numero de interaciones por proceso
	 			en la directiva for*/
	omp_set_num_threads(nthreads);

	// Definición de arreglos
	int tamArray = 20;
	int a[tamArray], b[tamArray], c[tamArray];
	
	//Inciamos los array
	inciarArray(a, tamArray, 2);
	inciarArray(b, tamArray, 3);

	// Imprimir arrays
	printf("Los arrays son:\n");
	imprimirArray(a, tamArray);
	imprimirArray(b, tamArray);
	
	printf("Repartiendo el for (suma) entre los procesos\n");	

	/*Inicio de la sección en paralelo*/
	#pragma omp parallel private(i)
	{
		/* Inicio del constructor for */
		/* Agregamos la claula schedule(static)*/
		#pragma omp for schedule(static, chuk)
			for (i = 0; i < tamArray; ++i)
			{

				printf("soy el proceso: %d\n", omp_get_thread_num());
				c[i] = a[i] + b[i];
			}
		/* Fin de la seccion for*/
	}/* Fin de la seccion en paralelo*/

	/* Verificar los resultados*/
	printf("La suma de los arreglos es:\n");
	imprimirArray(c, tamArray);


	return 0;
}
/* En este ejemplo la clausula schedule(static, chuck) 
	divide las interaciones del for y añadiendo a los hilos estaticamente, 
	donde para cada proceso le corresponde chuck interaciones, los 
	interaciones sin asignar son realizadas por el thread maestro (0)
*/

void imprimirArray(int a[], int tam)
{
	int i;
	for (i = 0; i < tam; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void inciarArray(int a[], int tam, int fac)
{
	int i;
	for (i = 0; i < tam; ++i)
	{
		a[i] = 2*i + fac;
		/* code */
	}
}