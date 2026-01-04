// Sort 0 1
/*
# Sort 0s and 1s in an Array

## Problem Statement
Given an array consisting only of `0`s and `1`s, sort the array such that all `0`s appear before all `1`s.

### Constraints
- The array should be sorted in-place.
- No extra array should be used.
- The array should be traversed only once.


Sample Input 1:
1
7
0 1 1 0 1 0 1
Sample Output 1:
0 0 0 1 1 1 1
*/


// Approach
// The solution uses the two-pointer technique:
//- One pointer starts from the beginning (`left`)
//- Another pointer starts from the end (`right`)
//- Swap elements when a `1` is found on the left side to right
//- decrement the right by 1
void sortZeroesAndOne(int arr[], int size)
{
    //Write your code here
    int left =0, right = size-1;

    while(left<right)
    {
        if(arr[left]==1)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            right--;
        }
        else
        {
            left++;
        }
    }
}

// Time Complexity: O(N)
// Space Complexity: O(1)

