// Pair Sum
/*
Problem statement
You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.

Note:
Each pair should be sorted i.e the first value should be less than or equals to the second value. 

Sample Input 1:
5 5
1 2 3 4 5
Sample Output 1:
1 4
2 3
*/


// Map based approach
// Use a map to store counts of numbers already seen.
// For each element x in the array:
// Compute y = S - x
// If y exists in the map, there are freq[y] pairs (y, x) → add them
// Store each pair as {min(x,y), max(x,y)} to satisfy a ≤ b
// Update freq[x]++ i.e: element freq in arr
// Sort the  vector of pairs  
#include <map>
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   map<int,int> freq; // store the count of number in arr
   vector<vector<int>> ans;


   for(int i=0;i<arr.size();i++)
   {
      int x = arr[i];
      int y = s-x;

      if(freq.count(y))
      {
         //add the pair
         for(int j=0;j<freq[y];j++)
            ans.push_back({min(y,x),max(x,y)});
      }
      freq[x]++;
   }

   sort(ans.begin(),ans.end()); sort pairs by first, then second
   return ans;
};
// Time Complexity: Sorting --- O(P log P) + map<int,int> i.e: O(NlogN+PlogP) 
// if unordered_map O(N+PlogP)

