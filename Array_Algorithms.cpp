#include <iostream>
#include <conio.h>

using namespace std;

// Most basic code for displaying an array...
void displayArray(int arr[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " . ";
    }
    cout << endl;
}

// Bubble sort code for sorting array in ascending order --- Verily Optimized
void bubbleSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (not swapped)
            return;
    }
}

// Selection sort code for sorting array in ascending order --- Require optimization check
void selectionSort(int arr[], int size)
{
    int min;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        bool swapped = false;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
                swapped = true;
            }
        }
        if (swapped)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

// Search for a number in an array and return its index --- Most basic
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Perform Binary search --- Supposing that the array is already sorted
int binarySearch(int arr[], int size, int key)
{
    int left = 0, right = size - 1;
    int i = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[10] = {2, 5, 8, 3, 9, 4, 1, 7, 6, 0};
    cout << "Number 4 is at index " << linearSearch(arr, 10, 4);
    displayArray(arr, 10);
    selectionSort(arr, 10);
    displayArray(arr, 10);
    cout << "Number 4 is at index " << binarySearch(arr, 10, 4);

    return 0;
}