//3. Reverse a String

/*

Problem statement
You are given a string 'STR'. The string contains [a-z] [A-Z] [0-9] [special characters]. You have to find the reverse of the string.

For example:

 If the given string is: STR = "abcde". You have to print the string "edcba".
*/

//Approach
//Create a stack and traverse and push each string character on to the stack.
//while stack is not empty
// pop the character & append it to the result string

//Use 2 pointer approach for optimal solution

#include <bits/stdc++.h> 
string reverseString(string str)
{
	// Write your code here.
	stack<char> st;
	string ans;
	for(char ch:str)
	{
		st.push(ch);
	}

	while(!st.empty())
	{
		ans +=st.top();
		st.pop();
	}
	return ans;
}

//Time complexity : O(N)
//Space Complexity : O(N)