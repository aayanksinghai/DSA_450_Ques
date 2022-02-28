// Write a program to reverse an array or string
// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/




#include <bits/stdc++.h>

using namespace std;

// Iterative Approach
void reverseArray(int arr[], int start, int len)
{
    int temp, end = len-1;
    
    while(start <= end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Recursive Code
void RecursivereverseArray(int arr[], int start, int end)
{
    int temp;
    
    if(start >= end) return;

    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    RecursivereverseArray(arr, start+1, end-1);    
}
int main()
{
    int i, arr[1000];
    cout<<"Enter the size of array: ";
    cin>>i;

    cout<<"Enter the elements in the array: ";
    for(int j = 0; j < i; j++)
    {
        cin>>arr[j];
    }

    // reverseArray(arr, 0, i);

    RecursivereverseArray(arr, 0, i-1);

    for(int j = 0; j < i; j++)
    {
        cout<<arr[j]<<" ";
    }
    return 0;
}
