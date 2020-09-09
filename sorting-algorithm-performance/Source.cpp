#include <iostream>
#include <vector>
using namespace std;

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

void merge(vector<int> &arr, int begin, int mid, int end)
{
    vector<int> leftArray(mid - begin + 1);
    vector<int> rightArray(end - mid);

    // fill in left array
    for (int i = 0; i < leftArray.size(); ++i)
        leftArray[i] = arr[begin + i];

    // fill in right array
    for (int i = 0; i < rightArray.size(); ++i)
        rightArray[i] = arr[mid + 1 + i];

    /* Merge the temp arrays */

    // initial indexes of first and second subarrays
    int leftIndex = 0, rightIndex = 0;

    // the index we will start at when adding the subarrays back into the main array
    int currentIndex = begin;

    // compare each index of the subarrays adding the lowest value to the currentIndex
    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[currentIndex] = leftArray[leftIndex];
            leftIndex++;
        }
        else {
            arr[currentIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        currentIndex++;
    }

    // copy remaining elements of leftArray[] if any
    while (leftIndex < leftArray.size()) arr[currentIndex++] = leftArray[leftIndex++];

    // copy remaining elements of rightArray[] if any
    while (rightIndex < rightArray.size()) arr[currentIndex++] = rightArray[rightIndex++];
}

void mergeSort(vector<int> &arr, int begin, int end)
{
    // base case
    if (begin < end) {
        // find the middle point
        int mid = (begin + end) / 2;

        mergeSort(arr, begin, mid); // sort first half
        mergeSort(arr, mid + 1, end);  // sort second half

        // merge the sorted halves
        merge(arr, begin, mid, end);
    }
}

int main() {
    int testArr[] = { 5, 4, 3, 2, 1 };
    vector<int> vecArr = { 12, 11, 15, 10, 9, 1, 2, 3, 13, 14, 4, 5, 6, 7, 8 };

    cout << endl << "-------- insertion sort --------" << endl;
    insertionSort(testArr, 5);
    for (int i = 0; i < 5; i++)
        cout << "testArr[" << i << "]: " << testArr[i] << endl;

    cout << endl << "-------- merge sort --------" << endl;
    mergeSort(vecArr, 0, static_cast<int>(vecArr.size() - 1));
    for (int i = 0; i < vecArr.size(); i++) {
        cout << vecArr[i];
        if (i < vecArr.size() - 1) 
            cout << ", ";
    }

    cout << endl;

    system("pause");
    return 0;
}