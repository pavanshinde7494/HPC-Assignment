
#include<omp.h>
#include<bits/stdc++.h>
int main(){
	
	#pragma omp parallel
	{
		printf("Hello World from process: %d\n", omp_get_thread_num());
	}
    return 0;
}

