#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>


#define CLOCKS_PER_MS (CLOCKS_PER_SEC/1000)

void insertionSort(unsigned long int (*sortedArr)[6], int N);
void bubbleSort(unsigned long int (*sortedArr)[6], int N);
void selectionSort(unsigned long int (*sortedArr)[6], int N);
int partition(unsigned long int (*sortedArr)[6], int low, int high);
void swap(unsigned long int* a, unsigned long int* b);
void quickSort(unsigned long int (*sortedArr)[6], int low, int high);

int main(){
	
	int N;							//Number of Integers
	N = 700;
	int i, j;
	clock_t start, end;
	double cpu_time_used;
	unsigned long int (*sortedArr)[6] = malloc(N*sizeof(*sortedArr));
	unsigned long int max = ULONG_MAX;
	unsigned long int *unsortedArr = malloc(N*sizeof(unsigned long int));
	double runningTime[6];
	FILE* output;
	
											//generating an unsorted array
											
	srand((unsigned long int)(time(NULL)));
	for(i=0; i<N; i++){
		unsortedArr[i] = (unsigned long int)((double)rand()/RAND_MAX * max);
	}
	
										//copying unsorted array to the 2D array to be used by the 6 sorting algorithms
	for(i=0; i<N; i++){
		for(j=0; j<6; j++){
			sortedArr[i][j] = unsortedArr[i];
		}
	}
	
	output = fopen("out.txt", "w");
	fprintf(output, "Unsorted array using random generated values\n\n");
	for(i=1; i<N+1; i++){
		fprintf(output, "%lu ", unsortedArr[i-1]);
		if(i%50==0){
			fprintf(output, "\n");
		}
	} 
	
	
	for(i=0; i<6; i++){
		switch(i){
			case 0: fprintf(output,"\n\nSorted array using Insertion Sort Algorithm\n\n");
					start = clock();
					insertionSort(sortedArr, N);
					end = clock();
					for(j=1; j<N+1; j++){
						fprintf(output, "%lu ", sortedArr[j-1][0]);
						if(j%50==0){
							fprintf(output, "\n");
						}
					}
					break;
					
			case 1: fprintf(output,"\n\nSorted array using Bubble Sort Algorithm\n\n");
					start = clock();
					bubbleSort(sortedArr, N);
					end = clock();
					for(j=1; j<N+1; j++){
						fprintf(output, "%lu ", sortedArr[j-1][1]);
						if(j%50==0){
							fprintf(output, "\n");
						}
					}
					break;
			
			case 2: fprintf(output,"\n\nSorted array using Selection Sort Algorithm\n\n");
					start = clock();
					selectionSort(sortedArr, N);
					end = clock();
					for(j=1; j<N+1; j++){
						fprintf(output, "%lu ", sortedArr[j-1][2]);
						if(j%50==0){
							fprintf(output, "\n");
						}
					}
					break;
			case 5: fprintf(output,"\n\nSorted array using QuickSort Algorithm\n\n");
					start = clock();
					quickSort(sortedArr, 0, N-1);
					end = clock();
					for(j=1; j<N+1; j++){
						fprintf(output, "%lu ", sortedArr[j-1][5]);
						if(j%50==0){
							fprintf(output, "\n");
						}
					}
					break;
		}
		cpu_time_used = ((double) (end - start))/ CLOCKS_PER_SEC; 
		runningTime[i] = cpu_time_used;
		printf("\n\n||The running time is %.10f", runningTime[i]);

		
	}
	
	free(sortedArr);
	free(unsortedArr);


	return 0;
	
}


void generateSorted(){
	
}

void insertionSort(unsigned long int (*sortedArr)[6], int N){
	
	int i, key;
	unsigned long int initial;
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

void bubbleSort(unsigned long int (*sortedArr)[6], int N){
	
	int i, n;
	unsigned long int temp;
	
	for (i = 0; i<N; i++)
    {
        for (n = 0; n < N - 1; n++)
        {
            if  (sortedArr[n][1] >  sortedArr[n+1][1])
            {
                temp = sortedArr[n][1];
                sortedArr[n][1] = sortedArr[n+1][1];
                sortedArr[n+1][1] = temp;
            }
        }
    }
	
}

void selectionSort(unsigned long int (*sortedArr)[6], int N){
	
	int i, position, length;
	unsigned long int swap;
	for (i = 0; i<N-1; i++)
    {
        position = i;
        for (length = i+1; length<N; length++)
        {
        	
            if (sortedArr[position][2] > sortedArr[length][2])
            {
                position = length;
            }
        }
        if (position != i)
        {
            swap = sortedArr[i][2];
            sortedArr[i][2] = sortedArr[position][2];
            sortedArr[position][2] = swap;
        }   
    }
	
}

void mergeSort(){
	
}

void heapSort(){
	
}

void quickSort(unsigned long int (*sortedArr)[6], int low, int high){
    if (low < high) {
        int pivotIndex = partition(sortedArr, low, high);
        quickSort(sortedArr, low, pivotIndex - 1);
        quickSort(sortedArr, pivotIndex + 1, high);
    }
}

int partition(unsigned long int (*sortedArr)[6], int low, int high) {
    unsigned long int pivot = sortedArr[high][5];
    int i = low - 1;
    int j;
    for (j = low; j < high; j++) {
        if (sortedArr[j][5] < pivot) {
            i++;
            swap(&sortedArr[i][5], &sortedArr[j][5]);
        }
    }
    swap(&sortedArr[i + 1][5], &sortedArr[high][5]);
    return i + 1;
}

void swap(unsigned long int* a, unsigned long int* b) {
    unsigned long int temp = *a;
    *a = *b;
    *b = temp;
}
