#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr)
{
    // start at the first index and iterate through to the end
    for (int i = 1; i < arr.size(); i++) {
        int currentIndex = i;
        /*
         * Check:
         *      1. that currentIndex is at least 1
         *      2. that the item directly before the currentIndex is greater than the item at currentIndex
         *
         * If both conditions are met, swap the indexes
         */
        while (currentIndex > 0 && arr[currentIndex - 1] > arr[currentIndex]) {
            int temp = arr[currentIndex];
            arr[currentIndex] = arr[currentIndex - 1];
            arr[currentIndex - 1] = temp;
            currentIndex--;
        }
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

void generateSortedInput(vector<int> &arr, int n) 
{
    for (int i = n; i > 0; i--) {
        arr.push_back(i);
    }
}

void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }
}

int main() 
{
    /*
    testing algorithms to ensure they are sorting properly
    */

    cout << "Testing Insertion Sort and Merge Sort Algorithms to Ensure They Are Working Properly" << endl;

    vector<int> testVecArr = { 5, 4, 3, 2 , 1 };

    cout << "-------- insertion sort --------" << endl;
    cout << "input before: ";
    printVector(testVecArr); 
    cout << endl;

    insertionSort(testVecArr);
    cout << "input after: ";
    printVector(testVecArr);
    cout << endl << "--------------------------------" << endl;

    // clear the vector to remove all elements
    testVecArr.clear();

    testVecArr = { 12, 11, 15, 10, 9, 1, 2, 3, 13, 14, 4, 5, 6, 7, 8 };

    cout << endl << "---------- merge sort ----------" << endl;
    cout << "input before: ";
    printVector(testVecArr);
    cout << endl;

    mergeSort(testVecArr, 0, static_cast<int>(testVecArr.size() - 1));
    cout << "input after: ";
    printVector(testVecArr);
    cout << endl << "--------------------------------" << endl;

    // free the memory taken by vector object
    // swap the vector with an empty vector to deallocate memory
    vector<int>().swap(testVecArr);

    /*
    end of test
    */

    vector<int> vecArr = {};
    generateSortedInput(vecArr, 100);
    printVector(vecArr);

    system("pause");
    return 0;
}