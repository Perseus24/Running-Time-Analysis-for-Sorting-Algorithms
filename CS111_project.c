#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>


#define CLOCKS_PER_MS (CLOCKS_PER_SEC/1000)

void insertionSort(unsigned long int (*sortedArr)[12], int N, int index);
void bubbleSort(unsigned long int (*sortedArr)[12], int N, int index);
void selectionSort(unsigned long int (*sortedArr)[12], int N, int index);
int partition(unsigned long int (*sortedArr)[12], int low, int high, int index);
void swap(unsigned long int* a, unsigned long int* b);
void quickSort(unsigned long int (*sortedArr)[12], int low, int high, int index);
void Merge(unsigned long int (*sortedArr)[12], int l, int m, int r, int index);
void MergeSort(unsigned long int (*sortedArr)[12], int l, int r, int index);

int main(){
	
	int N;							//Number of Integers
	N=1000;
	int i, j, k;
	clock_t start, end, start1, end1;
	double cpu_time_used;
	unsigned long int (*sortedArr)[12] = malloc(N*sizeof(*sortedArr));
	unsigned long int max = ULONG_MAX;
	unsigned long int *unsortedArr = malloc(N*sizeof(unsigned long int));
	unsigned long int *randomSortedArr = malloc(N*sizeof(unsigned long int));
	double runningTime[12];
	FILE* output;
	
											//generating an unsorted array
											
	srand((unsigned long int)(time(NULL)));
	for(i=0; i<N; i++){
		unsortedArr[i] = (unsigned long int)((double)rand()/RAND_MAX * max);
	}
	
										//generating a sorted array in increasing order
	output = fopen("out.txt", "w");									
	unsigned long int X = 5;
	fprintf(output, "\n\nSorted array using random generated values\n\n");
	for(i=0; i<N; i++){
		if(i==0){
			randomSortedArr[i] = (unsigned long int)(N + X);
		}
		else{
			randomSortedArr[i] = (unsigned long int)(randomSortedArr[i-1] + X);
		}
		
		fprintf(output, "%lu ", randomSortedArr[i]);
		if(i+1%50==0){
			fprintf(output, "\n");
		}
	}
	
										//copying unsorted array to the 2D array to be used by the 6 sorting algorithms
	for(i=0; i<N; i++){
		for(j=0; j<12; j+=2){
			sortedArr[i][j] = unsortedArr[i];
			sortedArr[i][j+1] = randomSortedArr[i];	
			
		}
	}
	
	
	
										//printing of the unsorted array to the .txt file
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
					insertionSort(sortedArr, N, 0);
					end = clock();
					
					start1 = clock();
					insertionSort(sortedArr, N, 1);
					end1 = clock();
					
					for (k=0; k<2; k++){
						if(k == 0){
							fprintf(output,"\n\n[Random Generated Values]\n\n");
						}
						else{
							fprintf(output,"\n\n[Already Sorted Values]\n\n");
						}
						for(j=1; j<N+1; j++){
							fprintf(output, "%lu ", sortedArr[j-1][k]);
							if(j%50==0){
								fprintf(output, "\n");
							}
						}
					}
					break;
					
			case 1: fprintf(output,"\n\nSorted array using Bubble Sort Algorithm\n\n");
					start = clock();
					bubbleSort(sortedArr, N, 2);
					end = clock();
					
					start1 = clock();
					bubbleSort(sortedArr, N, 3);
					end1 = clock();
					for (k=2; k<4; k++){
						if(k == 2){
							fprintf(output,"\n\n[Random Generated Values]\n\n");
						}
						else{
							fprintf(output,"\n\n[Already Sorted Values]\n\n");
						}
						for(j=1; j<N+1; j++){
							fprintf(output, "%lu ", sortedArr[j-1][k]);
							if(j%50==0){
								fprintf(output, "\n");
							}
						}
					}
					break;
			
			case 2: fprintf(output,"\n\nSorted array using Selection Sort Algorithm\n\n");
					start = clock();
					selectionSort(sortedArr, N, 4);
					end = clock();
					
					start1 = clock();
					selectionSort(sortedArr, N, 5);
					end1 = clock();
					
					for (k=4; k<6; k++){
						if(k == 4){
							fprintf(output,"\n\n[Random Generated Values]\n\n");
						}
						else{
							fprintf(output,"\n\n[Already Sorted Values]\n\n");
						}
						for(j=1; j<N+1; j++){
							fprintf(output, "%lu ", sortedArr[j-1][k]);
							if(j%50==0){
								fprintf(output, "\n");
							}
						}
					}
					break;
					
			case 3: fprintf(output,"\n\nSorted array using Merge Sort Algorithm\n\n");
					start = clock();
					MergeSort(sortedArr, 0, N, 6);
					end = clock();
					
					start1 = clock();
					MergeSort(sortedArr, 0, N, 7);
					end1 = clock();
					
					for (k=6; k<8; k++){
						if(k == 6){
							fprintf(output,"\n\n[Random Generated Values]\n\n");
						}
						else{
							fprintf(output,"\n\n[Already Sorted Values]\n\n");
						}
						for(j=1; j<N+1; j++){
							fprintf(output, "%lu ", sortedArr[j-1][k]);
							if(j%50==0){
								fprintf(output, "\n");
							}
						}
					}
					break;
			case 5: fprintf(output,"\n\nSorted array using QuickSort Algorithm\n\n");
					start = clock();
					quickSort(sortedArr, 0, N-1, 10);
					end = clock();
					
					start1 = clock();
					quickSort(sortedArr, 0, N-1, 11);
					end1 = clock();
					
					
					for (k=10; k<12; k++){
						if(k == 10){
							fprintf(output,"\n\n[Random Generated Values]\n\n");
						}
						else{
							fprintf(output,"\n\n[Already Sorted Values]\n\n");
						}
						for(j=1; j<N+1; j++){
							fprintf(output, "%lu ", sortedArr[j-1][k]);
							if(j%50==0){
								fprintf(output, "\n");
							}
						}
					}
					break;
					
		}
		cpu_time_used = ((double) (end - start))/ CLOCKS_PER_SEC; 
		runningTime[2*i] = cpu_time_used;
		cpu_time_used = ((double) (end1 - start1))/ CLOCKS_PER_SEC; 
		runningTime[2*i+1] = cpu_time_used;
		printf("\n\n||The running time is %.10f", runningTime[2*i]);
		printf("\n\n||The running time (sorted) is %.10f", runningTime[2*i+1]);

		
	}
	
	free(unsortedArr);
	free(randomSortedArr);
	
	free(sortedArr);

	return 0;
	
}


void generateSorted(){
	
}

void insertionSort(unsigned long int (*sortedArr)[12], int N, int index){
	
	int i, key;
	unsigned long int initial;
    for(i=1; i<N; i++)
    {
        initial = sortedArr[i][index];
        key = i-1;
        while (key >=0 && sortedArr[key][index] >  initial)
        {
            sortedArr[key+1][index] = sortedArr[key][index];
            key = key - 1;
        }
        sortedArr[key+1][index] = initial;
    }
    
	
}

void bubbleSort(unsigned long int (*sortedArr)[12], int N, int index){
	
	int i, n;
	unsigned long int temp;
	
	for (i = 0; i<N; i++)
    {
        for (n = 0; n < N - 1; n++)
        {
            if  (sortedArr[n][index] >  sortedArr[n+1][index])
            {
                temp = sortedArr[n][index];
                sortedArr[n][index] = sortedArr[n+1][index];
                sortedArr[n+1][index] = temp;
            }
        }
    }
	
}

void selectionSort(unsigned long int (*sortedArr)[12], int N, int index){
	
	int i, position, length;
	unsigned long int swap;
	for (i = 0; i<N-1; i++)
    {
        position = i;
        for (length = i+1; length<N; length++)
        {
        	
            if (sortedArr[position][index] > sortedArr[length][index])
            {
                position = length;
            }
        }
        if (position != i)
        {
            swap = sortedArr[i][index];
            sortedArr[i][index] = sortedArr[position][index];
            sortedArr[position][index] = swap;
        }   
    }
	
}


void quickSort(unsigned long int (*sortedArr)[12], int low, int high, int index){

    if (low < high) {

        int pivotIndex = partition(sortedArr, low, high, index);
        quickSort(sortedArr, low, pivotIndex - 1, index);
        quickSort(sortedArr, pivotIndex + 1, high, index);

    }

}


int partition(unsigned long int (*sortedArr)[12], int low, int high, int index) {

    //unsigned long int pivot = sortedArr[high][index];
    unsigned long int left = sortedArr[low][index];
    unsigned long int right = sortedArr[high][index];
    unsigned long int mid = sortedArr[(high+1)/2][index];
    unsigned long int pivot;
    
    if((left>=right && left<=mid)||(left>=mid && left<=right)){
    	pivot = left;
	}
	else if((right>=left && right<=mid)||(right>=mid && right<=left)){
    	pivot = right;
	}
	else if((mid>=right && mid<=left)||(mid>=left && mid<=right)){
    	pivot = mid;
	}

    int i = low - 1;
	int j;
    for (j = low; j < high; j++) {

        if (sortedArr[j][index] < pivot) {

            i++;

            swap(&sortedArr[i][index], &sortedArr[j][index]);

        }

    }

    swap(&sortedArr[i + 1][index], &sortedArr[high][index]);

    return i + 1;

}




void swap(unsigned long int* a, unsigned long int* b) {

    unsigned long int temp = *a;

    *a = *b;

    *b = temp;

}

void MergeSort(unsigned long int (*sortedArr)[12], int l, int r, int index){
	
	if(l < r){
		int mid = l + (r - l) / 2; // find the mid index.
	
		MergeSort(sortedArr,l, mid, index);			  // sorting the left subarray
		MergeSort(sortedArr, mid + 1, r, index);		  // sorting the right subarray
		Merge(sortedArr, l, mid, r, index); // Merging L and R into A as sorted list.

	}
}

void Merge(unsigned long int (*sortedArr)[12], int l, int mid, int r, int index){
	int i, j, k;
	
	int n1 = mid - l + 1;
    int n2 = r - mid;
    
    unsigned long int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = sortedArr[l + i][index];
    for (j = 0; j < n2; j++)
        R[j] = sortedArr[mid + 1 + j][index];

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (sortedArr)
	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			sortedArr[k][index] = L[i];
			i++;
		}
		else{
			sortedArr[k][index] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1){
		sortedArr[k][index] = L[i];
		k++;
		i++;
	}
		
	while (j < n2){
		sortedArr[k][index] = R[j];
		k++;
		j++;
	}
}









