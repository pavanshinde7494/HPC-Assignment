
#include <stdlib.h>   
#include <stdio.h>    
#include <omp.h>      

#define ARRAY_SIZE 1000000
#define NUM_THREADS 8

int main () 
{

	double start , finish;



	int * a;
	int * b; 
	int * c;
        
    int n = ARRAY_SIZE;            
	int n_per_thread;              
	int total_threads = NUM_THREADS;
	int i;       
        
   
    a = (int *) malloc(sizeof(int)*n);
	b = (int *) malloc(sizeof(int)*n);
	c = (int *) malloc(sizeof(int)*n);

   
    for(i=0; i<n; i++) {
        a[i] = i;
    }
    for(i=0; i<n; i++) {
        b[i] = i;
    }   
    

	omp_set_num_threads(total_threads);
	
	
	n_per_thread = n/total_threads;
	
    

    start = omp_get_wtime(); 

	
    for(i=0; i<n; i++) {
		c[i] = a[i]+b[i];
    }


	finish = omp_get_wtime(); 
	
	
	
    printf("Execution Time : %f\n",finish - start);

    free(a);  free(b); free(c);
	
	return 0;
}

