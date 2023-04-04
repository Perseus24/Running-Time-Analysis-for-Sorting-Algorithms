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
void heapify(unsigned long int (*sortedArr)[12], int n, int i, int index);
void heapSort(unsigned long int (*sortedArr)[12], int n, int index);
void generateValues(unsigned long int (*unsortedArr), unsigned long int (*randomSortedArr), int N, int x);
void copyToFile(unsigned long int (*sortedArr)[12], int k, int N, FILE* output);


int main(){
	
	
	
	int N, x;							//Number of Integers
	int i, j, k;
	
	printf("\nPlease input your preffered number of values to be sorted: ");
	scanf(" %d", &N);
	printf("\nPlease input an integer x (to be used in generating a sorted array): ");
	scanf(" %d", &x);
	
	clock_t start, end, start1, end1;
	double cpu_time_used;
	unsigned long int (*sortedArr)[12] = malloc(N*sizeof(*sortedArr));
	unsigned long int *unsortedArr = malloc(N*sizeof(unsigned long int));
	unsigned long int *randomSortedArr = malloc(N*sizeof(unsigned long int));
	double runningTime[12];
	FILE* output;

	
	
											//generating an unsorted array and a sorted array in increasing order
											
	generateValues(unsortedArr, randomSortedArr, N, x);
	
										
	output = fopen("out.txt", "w");									
	
	fprintf(output, "\n\nRandom generated values\n\n");
	for(i=1; i<N+1; i++){
		fprintf(output, "%lu ", unsortedArr[i-1]);
		if(i%50==0){
			fprintf(output, "\n");
		}
	} 
	fprintf(output, "\n\nSorted array\n\n");
	for(i=1; i<N+1; i++){
		fprintf(output, "%lu ", randomSortedArr[i-1]);
		if(i%50==0){
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
	
	printf("\n||Number of values to be sorted: %d", N);
	printf("\n\n--------------------------------------------------------------------------------------------\n");
	printf("|   ALGORITHM    |      RUNNNING TIME  (random)   |      RUNNNING TIME  (already sorted)   |\n");
	printf("--------------------------------------------------------------------------------------------\n");
	
	
	for(i=0; i<6; i++){
		switch(i){
			case 0: fprintf(output,"\n\n\nSorted array using Insertion Sort Algorithm\n");
					start = clock();
					//insertionSort(sortedArr, N, 0);
					end = clock();
					
					start1 = clock();
					//insertionSort(sortedArr, N, 1);
					end1 = clock();
					
					copyToFile(sortedArr, 0, N, output);
					printf("| Insertion Sort |   ");
					break;
					
			case 1: fprintf(output,"\n\n\nSorted array using Bubble Sort Algorithm\n");
					start = clock();
					//bubbleSort(sortedArr, N, 2);
					end = clock();
					
					start1 = clock();
					//bubbleSort(sortedArr, N, 3);
					end1 = clock();
					
					copyToFile(sortedArr, 2, N, output);
					printf("| Bubble Sort    |   ");
					break;
			
			case 2: fprintf(output,"\n\n\nSorted array using Selection Sort Algorithm\n");
					start = clock();
					//selectionSort(sortedArr, N, 4);
					end = clock();
					
					start1 = clock();
					//selectionSort(sortedArr, N, 5);
					end1 = clock();
					
					copyToFile(sortedArr, 4, N, output);
					printf("| Selection Sort |   ");
					break;
					
			case 3: fprintf(output,"\n\n\nSorted array using Merge Sort Algorithm\n");
					start = clock();
					MergeSort(sortedArr, 0, N-1, 6);
					end = clock();
					
					start1 = clock();
					MergeSort(sortedArr, 0, N-1, 7);
					end1 = clock();
					
					copyToFile(sortedArr, 6, N, output);
					printf("| Merge Sort     |   ");
					break;
					
			case 4: fprintf(output,"\n\n\nSorted array using Heap Sort Algorithm\n");
					start = clock();
					heapSort(sortedArr, N-1, 8);
					end = clock();
					
					start1 = clock();
					heapSort(sortedArr, N-1, 9);
					end1 = clock();
					
					copyToFile(sortedArr, 8, N, output);
					printf("| Heap Sort      |   ");
					break;
					
			case 5: fprintf(output,"\n\n\nSorted array using QuickSort Algorithm\n");
					start = clock();
					quickSort(sortedArr, 0, N-1, 10);
					end = clock();
					
					start1 = clock();
					quickSort(sortedArr, 0, N-1, 11);
					end1 = clock();
					
					copyToFile(sortedArr, 10, N, output);
					printf("| Quicksort      |   ");
					break;
					
		}
		cpu_time_used = ((double) (end - start))/ CLOCKS_PER_SEC; 
		runningTime[2*i] = cpu_time_used;
		cpu_time_used = ((double) (end1 - start1))/ CLOCKS_PER_SEC; 
		runningTime[2*i+1] = cpu_time_used;
		printf("\t   %.10f \t  |", runningTime[2*i]);
		printf("\t\t   %.10f \t   |\n", runningTime[2*i+1]);
		//printf("--------------------------------------------------------------------------------------------\n");
		printf("* - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * \n");


		
 }
	
	free(unsortedArr);
	free(randomSortedArr);
	
	free(sortedArr);

	return 0;
	
}

void copyToFile(unsigned long int (*sortedArr)[12], int k, int N, FILE* output){
	int i, j;
	
	for (i=k; i<k+2; i++){
		if(i == k)
			fprintf(output,"\n\n[Random Generated Values]\n\n");
		else
			fprintf(output,"\n\n[Already Sorted Values]\n\n");
						
		for(j=1; j<N+1; j++){
			fprintf(output, "%lu ", sortedArr[j-1][i]);
			if(j%50==0)
				fprintf(output, "\n");
							
		}
	}
	
}


void generateValues(unsigned long int (*unsortedArr), unsigned long int (*randomSortedArr), int N, int x){
	int i;
	unsigned long int max = ULONG_MAX;
	
	srand((unsigned long int)(time(NULL)));
	for(i=0; i<N; i++){
		unsortedArr[i] = (unsigned long int)((double)rand()/RAND_MAX * max);
	}
	
	for(i=0; i<N; i++){
		randomSortedArr[i] = (unsigned long int)(N + (i+1)*x);
	}

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
    unsigned long int mid = sortedArr[(high + low)/2][index];
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
    for (j = low; j <= high; j++) {

        if (sortedArr[j][index] <= pivot) {

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

    unsigned long int (*L)= malloc(n1 * sizeof(unsigned long int));
    unsigned long int (*R)= malloc(n2 * sizeof(unsigned long int));
	
    
    for (i = 0; i < n1; i++){
    	L[i] = sortedArr[l + i][index];
	}
       
    for (j = 0; j < n2; j++){
    	R[j] = sortedArr[mid + 1 + j][index];	
	}
        

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

void heapify(unsigned long int (*sortedArr)[12], int n, int i, int index) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && sortedArr[l][index] > sortedArr[largest][index])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && sortedArr[r][index] > sortedArr[largest][index])
        largest = r;

    // If largest is not root
    if (largest != i) {
        unsigned long int temp = sortedArr[i][index];
        sortedArr[i][index] = sortedArr[largest][index];
        sortedArr[largest][index] = temp;

        // Recursively heapify the affected sub-tree
        heapify(sortedArr, n, largest, index);
    }
}

// main heap sort
void heapSort(unsigned long int (*sortedArr)[12], int n, int index) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(sortedArr, n, i, index);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        unsigned long int temp = sortedArr[0][index];
        sortedArr[0][index] = sortedArr[i][index];
        sortedArr[i][index] = temp;

        // call max heapify on the reduced heap
        heapify(sortedArr, i, 0, index);
    }
}







