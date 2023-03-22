
# CS111_project

Analysis of the six sorting algorithms. With the number of integers:

10
100
1000
100000
1000000

Using a random generated integers, and an already sorted array

The program will generate an unsorted array and will then be copied to a 2D array
to be used by the 6 algorithms.

Indexing as follows:

sortedArr[][0] = Insertion sort
sortedArr[][1] = Bubble Sort
sortedArr[][2] = Selection Sort
sortedArr[][3] = Mergesort
sortedArr[][4] = Quicksort
sortedArr[][5] = Heapsort

The parameters of the algoroithms are the 2D array and the N (num of integers)
Format as follows:

void insertionSort(unsigned long int (*sortedArr)[0], int N);

The program outputs a .txt file containing the unsorted values and the 6 sorted arrays.
