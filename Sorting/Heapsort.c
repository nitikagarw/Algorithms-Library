//Implementation of HEAPSORT Algorithm
#include<stdio.h>
#include<stdlib.h>

struct MaxHeap
             {
                 int size;
                 int* array;
             };

PrintArray(int* arr, int size);
struct MaxHeap* BuildMaxHeap(int* array, int size);
void HeapSort(int* array, int size);
void swap(int*a, int*b);
void MaxHeapify(struct MaxHeap* maxheap,int index);

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = (sizeof(arr))/(sizeof(arr[0]));

    printf("\nGiven array of elements is :\n");
    PrintArray(arr, size);

    HeapSort(arr, size);

    printf("\nThe sorted Array is :\n");
    PrintArray(arr, size);

    return 0;
}

PrintArray(int* arr, int size)
{
    int i ;
    for (i=0; i<size; i++)
        printf("%5d", arr[i]);
    printf("\n");
}

void swap(int*a, int*b)
{
    int t = *a;
    *a = *b;
    *b = t;

}

void MaxHeapify(struct MaxHeap* maxheap,int index)
{
    int largest = index;
    int left = (index <<1) + 1;
    int right = (index+1) << 1;

    if(left < maxheap->size && maxheap->array[left] > maxheap->array[largest])
        largest = left;
    if(right < maxheap->size && maxheap->array[right] > maxheap->array[largest])
        largest = right;
    if(largest != index)
    {
        swap(&maxheap->array[index], &maxheap->array[largest]);
        MaxHeapify(maxheap, largest);
    }
}

struct MaxHeap* BuildMaxHeap(int* array, int size)
{
    int i;
    struct MaxHeap* maxheap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    maxheap->size = size;
    maxheap->array = array;

    for(i= (maxheap->size - 2)/2; i>=0; i--)
        MaxHeapify(maxheap, i);

    return maxheap;
}

void HeapSort(int* array, int size)
{
    struct MaxHeap* maxheap = BuildMaxHeap(array, size);

    while(maxheap->size >1)
    {
        swap(&maxheap->array[0], &maxheap->array[maxheap->size-1]);
        maxheap->size -= 1;

        MaxHeapify(maxheap, 0);
    }


}

