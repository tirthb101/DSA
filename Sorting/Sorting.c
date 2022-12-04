#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertionsort(int arr[], int size)
{
    int tempIndex = 0;
    bool found = false;

    for (int i = 0; i < size - 1; i++)
    {
        tempIndex = i;
        found = false;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[tempIndex] > arr[j])
            {
                tempIndex = j;
                found = true;
            }
        }

        if (found == true)
        {
            swap(&arr[i], &arr[tempIndex]);
        }
    }
}

void merge(int arr[], int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;
    int a1[n1], a2[n2];

    for (int i = 0; i < n1; i++)
    {
        a1[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        a2[i] = arr[i + m + 1];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (a1[i] > a2[j])
        {
            arr[k] = a2[j];
            j++;
            k++;
        }
        else if (a1[i] < a2[j])
        {
            arr[k] = a1[i];
            i++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = a1[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = a2[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}
void print(int arr[], int size)
{
    printf(" ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    i++;
    swap(&arr[i], &arr[high]);
    return i;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pindex = partition(arr, low, high);
        quicksort(arr, low, pindex - 1);
        quicksort(arr, pindex + 1, high);
    }
}

void main(void)
{
    int arr[] = {5, 6, 4, 7, 8, 56, 34, 134, 652, 123, 5435, -1231, 1, 9}, size = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, size - 1);

    print(arr, size);
}