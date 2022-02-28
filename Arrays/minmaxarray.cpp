// Find the maximum and minimum element in an array
// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

// LINEAR APPROACH

#include <iostream>

using namespace std;
// STRUCT 

struct minmax
{
    int min;
    int max;
};

// Iterative Approach
struct minmax getMinMax(int arr[], int len)
{
    struct minmax result;

    if(len == 0)
    {
        result.min = arr[0];
        result.max = arr[0];
        return result;
    }

    if(arr[0] > arr[1])
    {
        result.min = arr[1];
        result.max = arr[0];
    }

    for(int i = 2; i < len; i++)
    {
        if(result.max < arr[i])
        {
            result.max = arr[i];
        }
        else if(result.min > arr[i])
        {
            result.min = arr[i];
        }
    }

    return result;
}

// Recursive Approach
struct minmax recursiveGetMinMax(int arr[], int low, int high)
{
    struct minmax result, mml, mmh;

// Single Element
    if(low == high)
    {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }
// Only Two Element
    if(high == low + 1)
    {
        if(arr[low] > arr[high])
        {
            result.min = arr[high];
            result.max = arr[low];
        }
        else
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        return result;
    }
// More than two elements then we'll call the fn recursively.
    int mid = (low + high)/2;
    mml = recursiveGetMinMax(arr, low, mid);
    mmh = recursiveGetMinMax(arr, mid+1, high);

// Comparing the min elements
    if(mml.min < mmh.min)
    {
        result.min = mml.min;
    }
    else 
    {
        result.min = mmh.min;
    }
    
// Comparing the max elements
    if(mml.max < mmh.max)
    {
        result.max = mmh.max;
    }
    else
    {
        result.max = mml.max;
    }
    return result;
}

// EVEN ODD Function 

int main()
{
    int len, arr[100];

    cout<<"Enter the number of elements to insert: ";
    cin>>len;

    cout<<"Enter the elements in the array: ";
    for(int i = 0; i < len; i++)
    {
        cin>>arr[i];
    }

    // Iterative Approach Call
    // struct minmax result = getMinMax(arr, len);
    // Recursive Fn Call
    struct minmax result = recursiveGetMinMax(arr, 0, len-1);

    cout<<"Minimum Value in array: "<<result.min<<endl;
    cout<<"Maximum Value in array: "<<result.max;

    return 0;
}