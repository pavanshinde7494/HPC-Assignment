#include<omp.h>
#include<stdio.h>
#include<stdlib.h>


int main(){
    #pragma omp parallel 
    {   
        #pragma omp for nowait
        for(int i=1;i<=10;i++)
        {
            printf("Inner omp block No Wait : %d\n" , i);
        }
        printf("Outer omp block : %d\n",omp_get_thread_num());
    }
}
