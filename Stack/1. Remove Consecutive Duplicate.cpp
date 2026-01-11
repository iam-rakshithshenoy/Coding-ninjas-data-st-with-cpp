// Remove Consecutive Duplicates

/*
You are given a string ‘str’ of size ‘N’.
Your task is to remove consecutive duplicates from this string.

Example:
Input:  "aazbbby"
Output: "azby"

Note: Only adjacent duplicate characters are removed.
*/

// Approach 1

// Create an empty result string and insert the first character of the input string.
// Traverse the input string from the second character onward.
// For each character until end of input string:
//      Compare it with the last character in the result string.
//      If it is the same, skip it (it’s a consecutive duplicate).
//      If it is different, append it to the result string.
// Return the result string  it is now has all consecutive duplicates removed.


//Approach 2
// Create a stack of characters and an empty result string.
// Traverse the input string character by character.
// For each character:
//    - If the stack is not empty and the top of the stack is equal
//      to the current character, skip it.
//    - Otherwise, push the character onto the stack.
// After traversal, the stack contains the required characters but in reverse order.
// Pop all characters from the stack into a string.
// Reverse the string using reverse() to get the required output.

#include<stack>
#include<string>
#include<algorithm>
string removeDuplicate(string &s)
{
    stack<char>st;

    for(char c:s)
    {
        if(!st.empty() && st.top()==c)
        {
            continue; //skip
        }
        else
            st.push(c);
    }
    string ans;
    while(!st.empty())
    {
        ans +=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


//Time Complexity O(N)
//Space Complexity O(N)