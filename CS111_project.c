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
void heapify(unsigned long int (*sortedArr)[12], int N, int i, int index);
void heapSort(unsigned long int (*sortedArr)[12], int N, int index);
void median(unsigned long int (*sortedArr)[12], int low, int high, int index);

void generateValues(unsigned long int (*unsortedArr), unsigned long int (*randomSortedArr), int N, int x);
void copyToFile(unsigned long int (*sortedArr)[12], int k, int N, FILE* output);
void copyGeneratedValues(unsigned long int (*unsortedArr), unsigned long int (*randomSortedArr), int N, FILE *output);
void printIsSorted(unsigned long int (*sortedArr)[12], int N, int index, int index1);

int isSorted(unsigned long int (*sortedArr)[12], int N, int index);

int main(){
	
	
	
	int N, x;							//Number of Integers
	int i, j, temp;
	
	printf("\nPlease input your preffered number of values to be sorted: ");
	scanf(" %d", &N);
	printf("\nPlease input an integer x (to be used in generating a sorted array): ");
	scanf(" %d", &x);
	
	clock_t start, end, start1, end1;
	double cpu_time_used;
	unsigned long int (*sortedArr)[12] = malloc(N*sizeof(*sortedArr));			//A two-dimensional array to be used by the six sorting algorithms
	unsigned long int *unsortedArr = malloc(N*sizeof(unsigned long int));
	unsigned long int *randomSortedArr = malloc(N*sizeof(unsigned long int));
	double runningTime[12];
	FILE* output;
											
	generateValues(unsortedArr, randomSortedArr, N, x);	//generating an unsorted array and a sorted array in increasing order								
	output = fopen("out.txt", "w");	
	copyGeneratedValues(unsortedArr, randomSortedArr, N, output);	//prints the generated values to the output file
									
	

	//copying generated arrays to the 2D array to be used by the 6 sorting algorithms
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
			case 0: fprintf(output,"\n\n\n\tSorted array using Insertion Sort Algorithm\n");
					start = clock();
					insertionSort(sortedArr, N, 0);			//The even numbers refer to the column which the randomly generated
					end = clock();					// values are stored
					
					start1 = clock();
					insertionSort(sortedArr, N, 1);			//The odd numbers refer to the column which the already sorted
					end1 = clock();					// values are stored
							
					printf("| Insertion Sort |   ");
					break;
					
			case 1: fprintf(output,"\n\n\n\tSorted array using Bubble Sort Algorithm\n");
					start = clock();
					bubbleSort(sortedArr, N, 2);
					end = clock();
					
					start1 = clock();
					bubbleSort(sortedArr, N, 3);
					end1 = clock();
					
					printf("| Bubble Sort    |   ");
					break;
			
			case 2: fprintf(output,"\n\n\n\tSorted array using Selection Sort Algorithm\n");
					start = clock();
					selectionSort(sortedArr, N, 4);
					end = clock();
					
					start1 = clock();
					selectionSort(sortedArr, N, 5);
					end1 = clock();
					
					printf("| Selection Sort |   ");
					break;
					
			case 3: fprintf(output,"\n\n\n\tSorted array using Merge Sort Algorithm\n");
					start = clock();
					MergeSort(sortedArr, 0, N-1, 6);
					end = clock();
					
					start1 = clock();
					MergeSort(sortedArr, 0, N-1, 7);
					end1 = clock();
					
					printf("| Merge Sort     |   ");
					break;
					
			case 4: fprintf(output,"\n\n\n\tSorted array using Heap Sort Algorithm\n");
					start = clock();
					heapSort(sortedArr, N, 8);
					end = clock();
					
					start1 = clock();
					heapSort(sortedArr, N, 9);
					end1 = clock();
					
					printf("| Heap Sort      |   ");
					break;
					
			case 5: fprintf(output,"\n\n\n\tSorted array using QuickSort Algorithm\n");
					start = clock();
					quickSort(sortedArr, 0, N-1, 10);
					end = clock();
					
					start1 = clock();
					quickSort(sortedArr, 0, N-1, 11);
					end1 = clock();
					
					printf("| Quicksort      |   ");
					break;
					
		}
		copyToFile(sortedArr, i*2, N, output);			//prints the sorted array to the output file
		
		cpu_time_used = ((double) (end - start))/ CLOCKS_PER_SEC; 
		printf("\t   %.10lf \t  |", cpu_time_used);
		
		cpu_time_used = 0;
		
		cpu_time_used = ((double) (end1 - start1))/ CLOCKS_PER_SEC; 
		printf("\t\t   %.10lf \t   |", cpu_time_used);
		
		printIsSorted(sortedArr, N, 2*i, 2*i+1);
		printf("* - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * - * \n");

		
 }
	fclose(output);
	free(unsortedArr);
	free(randomSortedArr);
	free(sortedArr);

	return 0;
	
}

void copyToFile(unsigned long int (*sortedArr)[12], int k, int N, FILE* output){
			//prints the two generated arrays to the output file
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
	//The function generates both random values and a sorted array
	int i;
	unsigned long int max = ULONG_MAX;		//ULONG_MAX refers to the maximum value of unsigned long int
	
	srand((unsigned long int)(time(NULL)));
	for(i=0; i<N; i++){
		unsortedArr[i] = (unsigned long int)((double)rand()/RAND_MAX * max);
		randomSortedArr[i] = (unsigned long int)(N + (i+1)*x);
	}
	

}

void copyGeneratedValues(unsigned long int (*unsortedArr), unsigned long int (*randomSortedArr), int N, FILE *output){
	//prints the values of the two arrays to the output file
	int i;
	fprintf(output, "\n\nRandom generated values\n\n");
	for(i=1; i<N+1; i++){
		fprintf(output, "%lu ", unsortedArr[i-1]);
		if(i%50==0){
			fprintf(output, "\n");
		}
	} 
	fprintf(output, "\nAlready sorted array\n\n");
	for(i=1; i<N+1; i++){
		fprintf(output, "%lu ", randomSortedArr[i-1]);
		if(i%50==0){
			fprintf(output, "\n");
		}
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

void median(unsigned long int (*sortedArr)[12], int low, int high, int index){
	
	//This function determines the median of the array for it to be used as the pivot for the quicksort
	
	//It gets the value of the first index, last index, and the middle index
	//Then finds the median of the three
    unsigned long int left = sortedArr[low][index];
    unsigned long int right = sortedArr[high][index];
    unsigned long int mid = sortedArr[(high + low)/2][index];
    
	
    if((left>=right && left<=mid)||(left>=mid && left<=right)){
    	swap(&sortedArr[low][index], &sortedArr[high][index]);
	}
	else if((right>=left && right<=mid)||(right>=mid && right<=left)){
    	//as is
	}
	else if((mid>=right && mid<=left)||(mid>=left && mid<=right)){
    	swap(&sortedArr[(high+low)/2][index], &sortedArr[high][index]);
	}
}



int partition(unsigned long int (*sortedArr)[12], int low, int high, int index) {
    
    median(sortedArr, low, high, index);			
	
    unsigned long int pivot = sortedArr[high][index];
	
	
    int i = low - 1;
	int j;
    for (j = low; j <= high-1; j++) {
        if (sortedArr[j][index] <= pivot) {
            i++;
            swap(&sortedArr[i][index], &sortedArr[j][index]);
        }

    }

    swap(&sortedArr[i + 1][index], &sortedArr[high][index]);

    return (i+1);

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

void heapSort(unsigned long int (*sortedArr)[12], int N, int index){
 
    // Build max heap
    int i;
    for (i = N/2 - 1; i >= 0; i--)
        heapify(sortedArr, N, i, index);
        
    // Heap sort
    for (i = N - 1; i >= 0; i--) {
        swap(&sortedArr[0][index], &sortedArr[i][index]);
        // Heapify root element to get highest element at
        // root again
        heapify(sortedArr, i, 0, index);
    }
}

void heapify(unsigned long int (*sortedArr)[12], int N, int i, int index){
    // Find largest among root, left child and right child
 
    // Initialize largest as root
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && sortedArr[left][index] > sortedArr[largest][index])
        largest = left;
 
    // If right child is larger than largest
    
    if (right < N && sortedArr[right][index] > sortedArr[largest][index])
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
        swap(&sortedArr[i][index], &sortedArr[largest][index]);
        // Recursively heapify the affected
        // sub-tree
        heapify(sortedArr, N, largest, index);
    }
}

int isSorted(unsigned long int (*sortedArr)[12], int N, int index){
	
	//Checks the sorted array if it is sorted or not
	unsigned long int largest = sortedArr[0][index];
	int i;
	for(i=1; i<N; i++){
		if(largest<=sortedArr[i][index])
			largest = sortedArr[i][index];
		else
			return 0;		//if not sorted
	}
	
	return 1;
}

void printIsSorted(unsigned long int (*sortedArr)[12], int N, int index, int index1){
	int temp = 0, temp1 = 0;
	temp = isSorted(sortedArr, N, index);
	temp1 = isSorted(sortedArr, N, index1);
	
	if(temp == 0 && temp1 == 1)
		printf("  || The first array (random) is not sorted! ||\n");
	else if(temp == 1 && temp1 == 0)
		printf("  || The second array (already sorted) is not sorted! ||\n");
	else if(temp == 0 && temp1 == 0)
		printf("  Both arrays are not sorted! ||\n");
	else
		printf("  Both arrays are sorted! ||\n");
	
}

