			/* Agregamos el contructor for */
#include <omp.h>
#include <stdio.h>

void imprimirArray(int a[], int tam);
void inciarArray(int a[], int tam, int fac);

int main(int argc, char const *argv[])
{
	int nthreads = 4, i;
	omp_set_num_threads(nthreads);

	// Definición de arreglos
	int tamArray = 10;
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
		#pragma omp for
			for (i = 0; i < tamArray; ++i)
			{
				c[i] = a[i] + b[i];
			}
		/* Fin de la seccion for*/
	}/* Fin de la seccion en paralelo*/

	/* Verificar los resultados*/
	printf("La suma de los arreglos es:\n");
	imprimirArray(c, tamArray);


	return 0;
}

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