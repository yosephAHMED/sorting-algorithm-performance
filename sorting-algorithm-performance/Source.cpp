#include <iostream>
using namespace std;

int main() {
	system("pause");
	return 0;
}

void insertionSort(int arr[], int n)
{
    int key;
    int j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int begin, int mid, int end)
{
    int* temp = new int[end - begin + 1];
    int i = begin, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (i = begin; k = 0; i <= end)
    {
        arr[i] = temp[k];
        i++;
        k++;
    }
    delete[] temp;
}

void mergeSort(int arr[], int begin, int end)
{
    int mid;
    if (begin > end)
    {
        // avoids overflow for large begin and end
        mid = begin + (end - 1) / 2;
        mergeSort(arr, begin, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}