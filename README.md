
# CS111_project

Analysis of the six sorting algorithms. With the number of integers:

<br/>10
<br/>100
<br/>1000
<br/>100000
<br/>1000000

Using a random generated integers, and an already sorted array

The program will generate an unsorted array and will then be copied to a 2D array
to be used by the 6 algorithms.

Indexing as follows:
<br/>
<br/>sortedArr[][0] = Insertion sort
<br/>sortedArr[][1] = Bubble Sort
<br/>sortedArr[][2] = Selection Sort
<br/>sortedArr[][3] = Mergesort
<br/>sortedArr[][4] = Heapsort
<br/>sortedArr[][5] = Quicksort

The parameters of the algorithms are the 2D array and the N (num of integers)
Format as follows:

void insertionSort(unsigned long int (*sortedArr)[6], int N);

The program outputs a .txt file containing the unsorted values and the 6 sorted arrays.
