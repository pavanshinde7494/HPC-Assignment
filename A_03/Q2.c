#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
    

    int row , col;


    printf("Enter No. of Rows : ");
    scanf("%d",&row);

    printf("Enter No of Columns : ") ;
    scanf("%d",&col);

    int a[row][col] , b[row][col] ,c[row][col];

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            a[i][j] = rand()*1000;
            b[i][j] = rand()*1000;
        }
    }

    

    double startTime = omp_get_wtime();



    omp_set_num_threads(8);
    #pragma omp parallel for shared(a,b,c,row,col) collapse(2)
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    double endTime = omp_get_wtime();

    printf("%f",endTime - startTime);
}