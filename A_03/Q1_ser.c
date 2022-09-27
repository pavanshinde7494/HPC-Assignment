#include<omp.h>
#include<stdio.h>
#include<stdlib.h>


void sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void sort_des(int arr[], int n)
{
    int i,j;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (arr[i] < arr[j])
            {
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}
int main()
{   
    //fill the code;
    int n;
    scanf("%d",&n);
    int arr1[n], arr2[n];
    int i;

    for(i = 0; i < n ; i++)
    {
        arr1[i] = rand()%1000;
    }

    for(i = 0; i < n ; i++)
    {
        arr2[i] = rand()%1000;
    }


    double startTime = omp_get_wtime();

    sort(arr1, n);
    sort_des(arr2, n);

    double endTime = omp_get_wtime();

    printf("Execution : %f" , endTime - startTime);

    int sum = 0;

    for(i = 0; i < n ; i++)
    {
        sum = sum + (arr1[i] * arr2[i]);
    }
    return 0;
}