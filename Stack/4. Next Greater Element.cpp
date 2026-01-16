// Next Greater Element

/*
Problem statement
You are given an array 'a' of size 'n'.



Print the Next Greater Element(NGE) for every element.

The Next Greater Element for an element 'x' is the first element on the right side of 'x' in the array, which is greater than 'x'.

If no greater elements exist to the right of 'x', consider the next greater element as -1.


For example:
Input: 'a' = [7, 12, 1, 20]

Output: NGE = [12, 20, 20, -1]
*/

//Approach
//Start from the last element because the  last element has no elements on its right.
//Traverse from back side and if elements in stack are smaller or equal to current element then they are useless so better to remove them.
//If stack becomes empty → no greater element else stack top is greater element on right.
//Push arr[i] into stack for future elements. 

#include<stack>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	// Write your code here

	vector<int>result (n);
	stack<int>st;
	
	for(int i=n-1;i>=0;i--)
	{
		while(!st.empty() && st.top() <= arr[i])
		{
				st.pop();
		}
			
		if(st.empty())
		{
			result[i]=-1;
		}
		else
		{
			result[i] = st.top();
		}
		st.push(arr[i]);
	}
	return result;
}