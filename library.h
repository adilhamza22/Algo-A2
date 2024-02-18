#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

// populate vector 
vector<int> storeIntegers(int n) {
    vector<int> integers;

    for (int i = 0; i < n; i++) {
        // store random integers between -20 and 50
        integers.push_back(rand() % 70 - 20);
    }

    return integers;
}

void merge(vector<int> &sorted, int start, int mid, int end)
{
    int leftArrLen = mid - start + 1;
    int rightArrLen = end - mid;

    vector<int> leftArr(leftArrLen);
    vector<int> rightArr(rightArrLen);

    // copy sub arrays i.e "divide"
    for (int i = 0; i < leftArrLen; i++)
    {
        leftArr[i] = sorted[start + i];
    }
    for (int j = 0; j < rightArrLen; j++)
    {
        rightArr[j] = sorted[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;
    while (i < leftArrLen && j < rightArrLen)
    {
        if (leftArr[i] <= rightArr[j])
        {

            sorted[k++] = leftArr[i];
            i++;
        }
        else
        {
            sorted[k++] = rightArr[j];
            j++;
        }
    }
    // merge remaining elements of any of the two arrays
    while (i < leftArrLen)
    {
        // sorted.push_back(arrLarger[i]);
        sorted[k++] = leftArr[i];
        i++;
    }
    while (j < rightArrLen)
    {
        // sorted.push_back(arrSmaller[j]);
        sorted[k++] = rightArr[j];
        j++;
    }
}
void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "[" << i << "]  " << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(vector<int> &arr, int _left, int _right)
{
    int mid = (_left + _right - 1) / 2;
   

    if (_left < _right)
    {
        // recursively sort subarrays
        mergeSort(arr, _left, mid);
        mergeSort(arr, mid + 1, _right);
        // Merge the sorted subarrays
        merge(arr, _left, mid, _right);
    }


}


// qs2 

int partition(vector<int>& arr,int low, int high){
    int randomIndex = low + (rand() % (high - low + 1));
    // cout<<"randomIndex"<<randomIndex<<endl;
    // move pivot to end 
    swap(arr[randomIndex], arr[high]);
    //keep track of the pivot 
    int pivot = arr[high];

    int i=low-1;
    // move all elements smaller than pivot to the left
    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    //place pivot in its correct position 
    // cout<<"i+1"<<i+1<<endl;
    swap(arr[i+1], arr[high]);
    return i+1; // pivot index


}
void quickSort(vector<int>& arr, int low , int high){
    if(low<=high){
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

// qs3

int findMedianOfRandomThree(int low,int high){
    //choose random indexes three times
    int a = low + (rand() % (high - low + 1));
    int b = low + (rand() % (high - low + 1));
    int c = low + (rand() % (high - low + 1));
    //find median of them
    if (a > b) 
    {
        if (b > c)
            return b;
        else if (a > c)
            return c;
        else
            return a;
    }
    else
    {
        if (a > c)
            return a;
        else if (b > c)
            return c;
        else
            return b;
    }
}

//pivot as median of three random elements in array

int partitionRandomOfThree(vector<int>& arr,int low, int high){
    int randomIndex = findMedianOfRandomThree(low,high);
    // cout<<"randomIndex"<<randomIndex<<endl;
    // move pivot to end 
    swap(arr[randomIndex], arr[high]);
    //keep track of the pivot 
    int pivot = arr[high];

    int i=low-1;
    // move all elements smaller than pivot to the left
    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    //place pivot in its correct position 
    // cout<<"i+1"<<i+1<<endl;
    swap(arr[i+1], arr[high]);
    return i+1; // pivot index


}
void quickSortRandomOfThree(vector<int>& arr, int low , int high){
    if(low<=high){
        int p = partitionRandomOfThree(arr, low, high);
        quickSortRandomOfThree(arr, low, p-1);
        quickSortRandomOfThree(arr, p+1, high);
    }
}


//qs3-1.1
int kthSmallest(vector<int>& arr,int k ){
    //sort the array in Onlgn quicksort then return the kth element 
    quickSort(arr, 0, arr.size()-1);
    // get kth smallest element in terms of i 
    int i=arr.size()-1 - k;
    return arr[i];
}

//qs3-1.2
//time complexity O(n) in average case
//time complexity might increase to O(n^2) in worst case 
// when pivot is always the greatest or smallest element
//space complexity O(1)

int kthSort(vector<int>& arr,int low,int high,int k){
    if(k>0 && k<=high-low+1){
        int p = partition(arr, low, high);
        if(p-low == k-1){
            //kth element is the pivot
            return arr[p];
        }
        if(p-low > k-1){
            //kth element is in left subarray
            return kthSort(arr, low, p-1, k);
        }
        //kth element is in right subarray
        return kthSort(arr, p+1, high, k-p+low-1);
    }
    //k is out of range return -1
    return -1;
}
//qs3-1.3
int kthCountSort(vector<int>arr,int k){
    //use count sort to sort the array in O(n) time
    //then return the kth element
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    
    int range = max - min + 1;
    vector<int> count(range);

    //count the occurences of each element
    for(int num:arr){
        //num -min to make the index of count array positive 
        //starting from zero 
        //for example min =3 then num =3 then count[0]++ because 3-3 = 0
        count[num-min]++;
    }

    // travserse the count vector to get the kth element

    int countSum= 0;
    for(int i=0; i<range; i++){
        countSum += count[i];
        // When count_sum becomes greater than or equal to k,
        // it means that we have encountered the value corresponding
        // to the kth smallest element
        // in the input array. We return this value as the result.
        if (countSum >= k) {
          return i + min;
        }
    }
    //k is out of range return -1 || element not found
    return -1;
}

//qs3-2.1
//selection sort can be made stable if instead of swapping the
//min element is moved at its correct position
//i.e placing it at its correct position by performing a left shift by 1 

// PSEUDOCODE
// for i = 1 to n-1
// let min be the equal to i
//     min = i
//     then iterate from i+1 to n
//     for j = i+1 to n
//         if minimum than min found save it in key
//         if arr[j] < arr[min]
//             min = j
//     key = arr[min]
//     while(min > i)
//         left shift each element to create a hole for key
//         arr[min] = arr[min-1]
//         min--
//     place key at its correct position
//     arr[i] = key

//qs3-2.2
//  DRY RUN

//  INITIAL ARRAY[(10, a) (5, a) (4, a) (10, b) (3, a) (4, b) (1, a)]

// STEP#1:
//     MINIMUM ELEMENT (1, a)
//     [(1, a) (10, a) (5, a) (4, a) (10, b) (3, a) (4, b)]
// STEP#2:
//     MINIMUM ELEMENT (3, a)
//     [(1, a) (3, a) (10, a) (5, a) (4, a) (10, b) (4, b)]
// STEP#3:
//     MINIMUM ELEMENT (4, a)
//     [(1, a) (3, a) (4, a) (10, a) (5, a) (10, b) (4, b)]
// STEP#4:
//     MINIMUM ELEMENT (4, b)
//     [(1, a) (3, a) (4, a) (4, b) (10, a) (5, a) (10, b)]
// STEP#5:
//     MINIMUM ELEMENT (5, a)
//      [(1, a) (3, a) (4, a) (4, b) (5, a) (10, a) (10, b)]
// STEP#6:
//     MINIMUM ELEMENT (10, a)
//     [(1, a) (3, a) (4, a) (4, b) (5, a) (10, a) (10, b)]

// SORTED ARRAY[(1, a) (3, a) (4, a) (4, b) (5, a) (10, a) (10, b)]


// qs3-2.2

// | n     | Merge Sort (n/2) | Quick Sort (Random Pivot) | Quick Sort (Median of Three) |
// |-------|------------------|----------------------------|------------------------------|
// | 100   | 0ns              | 0ns                        | 0ns                          |
// | 1000   | 0ns              | 0ns                        | 0ns                          |
// | 10000   | 6ns              | 4ns                        | 4ns                          |
// | 100000   | 65ns              | 235ns                        | 248ns                          |