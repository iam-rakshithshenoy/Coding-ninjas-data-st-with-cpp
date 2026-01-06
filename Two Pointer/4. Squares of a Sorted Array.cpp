//4. Squares of a Sorted Array
/*
Problem statement
You are given an array/list ‘ARR’ of ‘N’ integers. You have to generate an array/list containing squares of each number in ‘ARR’, sorted in increasing order.

For example :

Input:
‘ARR’ = [-6,-3, 2, 1, 5] 

If we take a square of each element then the array/list will become [36, 9, 4, 1, 25].
Then the sorted array/list will be [1, 4, 9, 25, 36].

Output :
[1, 4, 9, 25, 36].
*/


//Since array is already sorted then the Largest square comes from either end (negative or positive)
//Fill result array from the back

// Create a result vector of size n //important
// set the left =0 and right pointer as n-1 and the pos index at the end(n-1).
// compare positive left and right value and always greater element square put at array end.
// move the pointer, decrement pos index for each iteration
#include <bits/stdc++.h> 
vector < int > sqsorted(vector < int > & arr) {
    // Write your code here.
    int n = arr.size();
    vector<int> res (n);
    
    int left = 0, right = n-1, pos = n-1;

    while(left<=right)
    {
        if(abs(arr[left])< abs(arr[right]))
        {
            res[pos] = arr[right]*arr[right];
            right--;
        }
        else
        {
            res[pos] = arr[left]*arr[left];
            left++;
            
        }
        pos--;
    }
return res;
}
//Time Complexity: O(N)
//Space Complexity: O(N)

