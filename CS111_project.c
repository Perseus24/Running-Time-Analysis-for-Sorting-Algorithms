#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>


#define CLOCKS_PER_MS (CLOCKS_PER_SEC/1000)

void insertionSort(unsigned long int (*sortedArr)[6], int N);

int main(){
	
	int N;							//Number of Integers
	N=10000;
	int r;
	clock_t start, end;
	double cpu_time_used;
	unsigned long int sortedArr[N][6];
	double runningTime[6];
	FILE output;
											//generating an unsorted array

	int i;
	int j;
	unsigned long int max = ULONG_MAX;
	unsigned long int unsortedArr[N];
	//As of 3/15/2023, the maximum input is 500,000 without the use of static
	//unsigned long static int v[1000000] should be used for 1 million integers
	
	srand(time(0));
	for(i=0; i<N; i++){
		unsortedArr[i] = (rand()% max + 1);
		//printf(" %lu,", unsortedArr[i]);
	}
	
							//copying unsorted array to the 2D array
	for(i=0; i<N; i++){
		for(j=0; j<6; j++){
			sortedArr[i][j] = unsortedArr[i];
		}
	}
	
	for(i=0; i<6; i++){
		switch(i){
			case 0: start = clock();
					insertionSort(sortedArr, N);
					end = clock();
					break;
					
		}
		cpu_time_used = ((double) (end - start))/ CLOCKS_PER_SEC;
		runningTime[i] = cpu_time_used;
		printf("\n\n||The running time is %.10f", cpu_time_used);
		
	}
	
	
	//	printf("\n\n||The running time is %.10f", cpu_time_used);

	return 0;
	
}


void generateSorted(){
	
}

void insertionSort(unsigned long int (*sortedArr)[6], int N){
	
	int i, key, initial, count=0;
    for(i=1; i<N; i++)
    {
        initial = sortedArr[i][0];
        key = i-1;
        while (key >=0 && sortedArr[key][0] >  initial)
        {
            sortedArr[key+1][0] = sortedArr[key][0];
            key = key - 1;
        }
        sortedArr[key+1][0] = initial;
    }
    
	
}

void bubbleSort(){
	
}

void selectionSort(){
	
}

void mergeSort(){
	
}

void heapSort(){
	
}

void quickSort(){
	
}
