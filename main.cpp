#include"library.h"
#include<iostream>
#include<vector>
#include <chrono>
#include <unistd.h>
using namespace std;

int main(){
    //qs1A
    cout<<"----------------------qs1A-------------------------"<<endl;
    // vector<int> arr = { 5, 4, 3, 2, 1 };
    vector<int> arr = storeIntegers(100000);
    // printArr(arr);

    auto start = chrono::steady_clock::now();

    mergeSort(arr, 0, arr.size() - 1);

    auto end = chrono::steady_clock::now();

    cout << "After Merge sorting: \n";
    // printArr(arr);
    cout << "Elapsed time in miliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ns" << endl;
    cout << "Before Merge sorting: \n";
    ;

    //qs1B
    cout<<"----------------------qs1B-------------------------"<<endl;
    // vector<int> arr2 = {5, 12, -5, 0, 1,2,4,-19 };
    vector<int> arr2 = storeIntegers(100000);

    cout << "Before Quick sorting: \n";
    // printArr(arr2);
    auto start2 = chrono::steady_clock::now();
    quickSort(arr2, 0, arr2.size() -1 );
    auto end2 = chrono::steady_clock::now();
    cout << "After Quick sorting: \n";
    // printArr(arr2);
    cout << "Elapsed time in miliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end2 - start2).count()
        << " ns" << endl;

    //qs1C
    cout<<"----------------------qs1C-------------------------"<<endl;
    // vector<int> arr3 = { 5, 12, -5, 0, 1,2,4,-19 };
    vector<int> arr3 = storeIntegers(100000);
    cout << "Before QuickSort with random of three: \n";
    // printArr(arr3);
    auto start3 = chrono::steady_clock::now();
    quickSortRandomOfThree(arr3, 0, arr3.size() - 1);
    auto end3 = chrono::steady_clock::now();
    cout << "After QuickSort with random of three: \n";
    // printArr(arr3);
    cout << "Elapsed time in miliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end3 - start3).count()
        << " ns" << endl;
    //qs3-1.1
    cout<<"----------------------qs3-1.1-------------------------"<<endl;
    vector<int> arr4 = { 5, 12, -5, 0, 1,2,4,-19 };
    cout << "Before Kth Smallest \n";
    printArr(arr4);
    cout << "Kth Smallest: " << kthSmallest(arr4, 3) << endl;
    // cout << "After Kth Smallest \n";
    // printArr(arr4);

    //qs3-1.2
    cout<<"----------------------qs3-1.2-------------------------"<<endl;
    vector<int> arr5 = { 5, 12, -5, 0, 1,2,4,-19 };
    cout << "Before KthSort \n";
    printArr(arr5);
    cout<<"\nKthSortSmallest "<<kthSort(arr5,0,arr5.size(), 3);
    cout << "\nAfter KthSort \n";
    printArr(arr5);

    //qs3-1.3
    cout<<"----------------------qs3-1.3-------------------------"<<endl;
    vector<int> arr6 = { 5, 12, -5, 0, 1,2,4,-19 };
    cout<<"Before KthCountSort \n";
    printArr(arr6);
    int kthCountSortSmallest = kthCountSort(arr6, 3);
    cout<< "kthCountSortSmallest " << kthCountSortSmallest<<endl;



// solution of qs3-2.2

// | n     | Merge Sort (n/2) | Quick Sort (Random Pivot) | Quick Sort (Median of Three) |
// |-------|------------------|----------------------------|------------------------------|
// | 100   | 0ns              | 0ns                        | 0ns                          |
// | 1000   | 0ns              | 0ns                        | 0ns                          |
// | 10000   | 6ns              | 4ns                        | 4ns                          |
// | 100000   | 65ns              | 235ns                        | 248ns                          |



}