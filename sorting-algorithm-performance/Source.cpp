#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }
}

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

void testSortingAlgorithms() 
{
    /*
    testing algorithms to ensure they are sorting properly
    */

    vector<int> testVecArr = { 5, 4, 3, 2, 1 };

    cout << "Testing Sorting Algorithms to Ensure They Are Working Properly" << endl;
    cout << "------------ insertion sort ------------" << endl;
    cout << "input before: ";
    printVector(testVecArr);
    cout << endl;

    insertionSort(testVecArr);
    cout << "input after: ";
    printVector(testVecArr);

    // clear the vector to remove all elements
    testVecArr.clear();

    testVecArr = { 12, 11, 15, 10, 9, 1, 2, 3, 13, 14, 4, 5, 6, 7, 8 };

    cout << endl << "------------ merge sort ---------------" << endl;
    cout << "input before: ";
    printVector(testVecArr);
    cout << endl;

    mergeSort(testVecArr, 0, static_cast<int>(testVecArr.size() - 1));
    cout << "input after: ";
    printVector(testVecArr);
    cout << endl << "---------------------------------------" << endl;

    // free the memory taken by vector object
    // swap the vector with an empty vector to deallocate memory
    vector<int>().swap(testVecArr);

    /*
    end of test
    */
}

void generateSortedInput(vector<int> &arr, int n) 
{
    // n, n-1, ..., 3, 2, 1
    for (int i = n; i > 0; i--) {
        arr.push_back(i);
    }
}

void generateReverselySortedInput(vector<int>& arr, int n)
{
    // 1, 2, 3, ..., n
    for (int i = 0; i < n; i++) {
        arr.push_back(i + 1);
    }
}

void generateRandomPermutation(vector<int>& arr, int n)
{
    // 1, ..., ?, n (no duplicates)
    generateReverselySortedInput(arr, n);
    random_shuffle(arr.begin(), arr.end());
}

int main() 
{
    ofstream outFile;
    outFile.open("results.txt");
    
    // computer internal clock controls the choice of the seed
    srand(unsigned(time(NULL)));

    // test sorting algorithms working correctly
    testSortingAlgorithms();

    // the main vector we will be using in sorting computations
    vector<int> vecArr = {};

    // a vector to store the number of inputs (n)
    vector<int> inputArr = { 10 };
    // vector<int> inputArr = { 100, 200, 300, 400, 500, 1000, 4000, 10000 };

    // variables to determine running time of algorithms
    using namespace std::chrono;
    high_resolution_clock::time_point t1, t2;
    chrono::duration<double, milli> runningTime;

    for (int i = 0; i < inputArr.size(); i++) 
    {
        outFile << "Input size: " << inputArr[i] << endl;

        // #INPUT #1: n, n-1, ..., 3, 2, 1
        generateSortedInput(vecArr, inputArr[i]);

        // run insertion sort on vecArr and obtain running time
        t1 = high_resolution_clock::now();
        insertionSort(vecArr);
        t2 = high_resolution_clock::now();
        runningTime = t2 - t1;
        outFile << "InsertionSort Running Time For SortedInput: " << runningTime.count() << endl;

        // clear vector and initialize
        vecArr.clear();
        generateSortedInput(vecArr, inputArr[i]);

        // run merge sort on vecArr and obtain running time
        t1 = high_resolution_clock::now();
        mergeSort(vecArr, 0, static_cast<int>(vecArr.size() - 1));
        t2 = high_resolution_clock::now();
        runningTime = t2 - t1;
        outFile << "MergeSort Running Time For SortedInput: " << runningTime.count() << endl;

        // #INPUT #2: 1, 2, 3, ..n
        vecArr.clear();
        generateReverselySortedInput(vecArr, inputArr[i]);

        // run insertion sort on vecArr and obtain running time
        t1 = high_resolution_clock::now();
        insertionSort(vecArr);
        t2 = high_resolution_clock::now();
        runningTime = t2 - t1;
        outFile << "InsertionSort Running Time For ReverselySortedInput: " << runningTime.count() << endl;

        // clear vector and initialize
        vecArr.clear();
        generateSortedInput(vecArr, inputArr[i]);

        // run merge sort on vecArr and obtain running time
        t1 = high_resolution_clock::now();
        mergeSort(vecArr, 0, static_cast<int>(vecArr.size() - 1));
        t2 = high_resolution_clock::now();
        runningTime = t2 - t1;
        outFile << "MergeSort Running Time For ReverselySortedInput: " << runningTime.count() << endl;

        // #INPUT #3: 1, ..., ?, n (no duplicates)
        vecArr.clear();
        generateRandomPermutation(vecArr, inputArr[i]);

        // run insertion sort on vecArr and obtain running time
        t1 = high_resolution_clock::now();
        insertionSort(vecArr);
        t2 = high_resolution_clock::now();
        runningTime = t2 - t1;
        outFile << "InsertionSort Running Time For RandomPermutation: " << runningTime.count() << endl;

        // clear vector and initialize
        vecArr.clear();
        generateRandomPermutation(vecArr, inputArr[i]);

        // run merge sort on vecArr and obtain running time
        t1 = high_resolution_clock::now();
        mergeSort(vecArr, 0, static_cast<int>(vecArr.size() - 1));
        t2 = high_resolution_clock::now();
        runningTime = t2 - t1;
        outFile << "MergeSort Running Time For RandomPermutation: " << runningTime.count() << endl;
    }
    
    system("pause");
    return 0;
}