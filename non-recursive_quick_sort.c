#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) //меняет местами
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; //опорный элемент - последний
    int i = low - 1;

    for (int j = low; j < high; j++)
        if (arr[j] <= pivot)
            swap(&arr[++i], &arr[j]);

    swap(&arr[++i], &arr[high]); //индекс i является опорным элементом в массиве
    return i;
}

void quicksort(int arr[], int low, int high)
{
    int* stack = (int*)malloc((high - low + 1) * sizeof(int)); //память для стека
    int top = -1; //стек пустой

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) //пока стек не пустой
    {
        high = stack[top--];//извлекаем значения из стека
        low = stack[top--];

        int pivot_index = partition(arr, low, high); //разделяет на две части, меньше опорного и больше опорного элемента

        if (pivot_index - 1 > low)//элементы слева есть 
        {
            stack[++top] = low;
            stack[++top] = pivot_index - 1;
        }

        if (pivot_index + 1 < high) //элементы справа есть
        {
            stack[++top] = pivot_index + 1;
            stack[++top] = high;
        }
    }

    free(stack);
}

void printarr(int arr[], int size)
{
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n = 0;
    printf("size of array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("enter array: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Before:\n");
    printarr(arr, n);

    quicksort(arr, 0, n - 1);

    printf("After:\n");
    printarr(arr, n);

    free(arr);
    return 0;
}
