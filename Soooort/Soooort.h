
#ifndef PREHEAD
#define PREHEAD
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN		200000
#define TRUE		1
#define FALSE		0

int Swap(int * a, int * b, int bool);
void SetData(int arr[], int len);
void PrintData(int arr[], int len);
void Settingarr(int arr[], int len);
void SortTimer(int arr[], int len, char*(*fp)(int* arr, int len));
void SortTimer1(int arr[], int start, int end, char*(*fp)(int* arr, int start, int end));

#endif
#ifndef BUBBLESORT
#define BUBBLESORT
char* BubbleAsSort(int arr[], int len);
#endif
#ifndef SELECTIONSORT
#define SELECTIONSORT
char* SelecDsSort(int arr[], int len);
int SearchMinIdx(int arr[], int len, int end);
#endif
#ifndef INSERTIONSORT
#define INSERTIONSORT
char* InsertionAsSort(int arr[], int len);
#endif
#ifndef MERGESORT
#define MERGESORT
char* MergeDsSort(int arr[], int start, int end);
void MergeTwoArea(int arr[], int start, int mid,int end);
#endif
#ifndef SHELLSORT
#define SHELLSORT
char* ShellAsSort(int arr[], int len);
void InsertbyShellSort(int arr[], int len, int gap);
#endif
#ifndef QUICKSORT
#define QUICKSORT
char* QuickDsSort(int arr[], int start, int end);
int Partition(int arr[], int start, int end);
#endif
#ifndef HEAPSORT
#define HEAPSORT
char* HeapAsSort(int arr[], int len);
void BuildHeap(int arr[], int len);
void RebuildHeap(int arr[], int len);
#endif
#ifndef RADIXSORT
#define RADIXSORT
char* RadixSort(int arr[], int max, int len);
#endif