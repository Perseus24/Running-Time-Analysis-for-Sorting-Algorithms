#include<stdio.h>
#include<time.h>
#include<limits.h>

void insertionSort(unsigned long int unsortedArr[], int N);

void main(){
	
	int N;							//Number of Integers
	
	N=500000;
	
							//generating an unsorted array
	time_t timer;
	int i;
	unsigned long int max = ULONG_MAX;
	unsigned long int unsortedArr[N];
	//As of 3/15/2023, the maximum input is 500,000 without the use of static
	//unsigned long static int v[1000000] should be used for 1 million integers
	
	srand((unsigned long int)(time(NULL)));
	
	for(i=0; i<N; i++){
		unsortedArr[i] = (rand()% max + 1);
		printf(" %lu,", unsortedArr[i]);
	}
	
	
	insertionSort(unsortedArr, N);
	
	
}


void generateSorted(){
	
}

void insertionSort(unsigned long int unsortedArr[], int N){
	
	clock_t start, end;
	double cpu_time_used;
	
	start = clock();
	
	int i, key, initial, count=0;
    for(i=1; i<N; i++)
    {
        initial = unsortedArr[i];
        key = i-1;
        while (key >=0 && unsortedArr[key] >  initial)
        {
            unsortedArr[key+1] = unsortedArr[key];
            key = key - 1;
        }
        unsortedArr[key+1] = initial;
    }
    
    end = clock();
    cpu_time_used = ((double) (end - start))/ CLOCKS_PER_SEC;
    printf("\t\t\nUSING INSERTION SORT: \n");
    for(i=0; i<N; i++){
    	printf("\t> %d, ", unsortedArr[i]);
	}
	
	
	
	printf("\n\n||The running time is %f", cpu_time_used);
    
	
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
