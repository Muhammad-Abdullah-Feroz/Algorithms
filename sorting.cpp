#include<iostream>
#include<conio.h>

using namespace std;

void bubbleSort(int arr[] , int size){
    for(int i = 0 ; i < size-1 ; i++){
        for(int j = 0 ; j < size - 1 - i ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int size = 5){
    for(int i = 0; i < size-1 ; i++){
        int minIdx = i;
        for(int j = i+1 ; j < size ; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }
}

void insertionSort(int  arr[], int size = 5){
    for (int i = 1 ; i < size ; i++){
        int curr = i;
        int prev = i-1;
        while(prev >= 0 && arr[prev] > arr[curr]){
            arr[prev +1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = arr[curr];
    }
}

void merge(int arr[] , int left , int mid , int right){
    int n1 = mid - left +1;
    int n2 = right - mid;

    int* arr1 = new int[n1];
    int* arr2 = new int[n2];

    for(int i = 0 ; i < n1 ; i++){
        arr1[i] = arr[left+i];
    }
    for(int i = 0 ; i < n2 ; i++){
        arr2[i] = arr[mid +1+ i];
    }

    int i = 0 , j = 0 , count = left;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            arr[count] = arr1[i]; 
            i++;
        }else{
            arr[count] = arr2[j];
            j++;
        }
        count++;
    }
    while(i < n1){
        arr[count] = arr1[i];
        i++;
        count++;
    }
    while(j < n2){
        arr[count] = arr2[j];
        j++;
        count++;
    }
}

void mergeSort(int arr[] , int left=0 , int right=4){
    if(left >= right) return;

    int mid = (left+right)/2;

    mergeSort(arr , left , mid);
    mergeSort(arr, mid+1 , right);
    
    merge(arr , left , mid , right);
}


int partition(int arr[] , int l = 0 , int r = 4)
{
    int p = arr[r];
    int prev = l -1;
    for(int i = l ; i < r ; i++){
        if(arr[i] < p){
            prev++;
            swap(arr[i] , arr[prev]);
        }
    }
    swap (arr[prev+1] , arr[r]);
    return prev+1;
}

void quickSort(int arr[] , int l = 0, int r = 4){

    if(l >= r) return;

    int pivot = partition(arr , l , r);

    quickSort(arr , l , pivot-1);
    quickSort(arr , pivot+1 , r);
}

void printArr(int arr[] , int size = 5){
    cout<<endl;
    for (int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[] = {5, 3, 8, 1, 2};
    int arr1[] = {5, 3, 8, 1, 2};
    int arr2[] = {5, 3, 8, 1, 2};
    // bubbleSort(arr , 5);
    // printArr(arr,5);
    // selectionSort(arr1 , 5);
    // printArr(arr1,5);
    // insertionSort(arr);
    quickSort(arr);
    printArr(arr);
    return 0;
}
