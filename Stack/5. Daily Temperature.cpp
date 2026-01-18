//Daily Temperature

/*


Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait 
after the ith day to get a warmer temperature. If there is no future day 
for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

*/


//Approach
//Go from left to right
// Keep a stack of indices, where Stack stores days whose answer is not found yet
// When today is warmer than stack top day:
//     Pop that day
// Fill its answer using index difference
// Push today’s index

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
     int n = temp.size();
    vector<int> ans (n,0);
    stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && temp[i]>temp[st.top()])
            {
                int prevIndex = st.top();
                st.pop();
                ans[prevIndex] = i-prevIndex;
            }
            st.push(i);
        }
        return ans;
    }
};

//Time complexity: O(n)
//Space Complexity: O(n)