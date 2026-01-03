// Two Sum - Leetcode 167
/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
*/


// Initialize two pointers: left at the start and right at the end of the array.
// Calculate the sum of the numbers at the two pointers.
// If the sum equals the target, return the indices (1-based).
// If the sum is greater than the target, move the right pointer left to reduce the sum.
// If the sum is less than the target, move the left pointer right to increase the sum.
// Repeat until the pair is found or pointers cross.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int left = 0,right = n-1;
        while(left < right)
        {   
            int currsum = numbers[left]+numbers[right];
            if(currsum==target)
                return {left+1,right+1};
            else if(currsum>target)
            {
                right--;
            }
            else
            {
                left ++;
            }
        }
        return {-1,-1};
    }
};
//Time Complexity: O(N) – single pass through the array
//Space Complexity: O(1) – constant extra space

