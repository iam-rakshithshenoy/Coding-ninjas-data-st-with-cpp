//5. 3 Sum
/*
You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.

An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.
*/


// Approach

// Sort the array to apply 2 pointer approach
// Fix first element i and iterate for 3
// Now left = i + 1 & right = n - 1. Calculate the sum
// Move pointers based on the sum.
// If the element is same as forward/backward then skip and move pointer
// Increment left and decrement right to search for new combo



#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	
	vector<vector<int>> ans;

	if(n<3) return ans;

	sort(arr.begin(),arr.end());


	for(int i=0;i<n-2;i++)
	{
		if(i>0 && arr[i]==arr[i-1]) continue; // skip duplicate


		int left = i+1, right = n-1;

		while(left<right)
		{
			int sum = arr[i]+arr[left]+arr[right];

			if(sum == K)
			{
				ans.push_back({arr[i],arr[left],arr[right]});
		
				//skip duplicate insert
				while(left < right && arr[left]==arr[left+1]) left++;
				while(left< right && arr[right]==arr[right-1]) right--;

				left++;
				right--;
			}
			else if(sum < K)
				left++;
			else 
				right--;
		}	
	}
return ans;
}
//Time Complexity: O(N²)
//Space Complexity: O(N²)
