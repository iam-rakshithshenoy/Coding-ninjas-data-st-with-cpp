//2.  Valid Parentheses

/*

You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .



Return true if the given string 'S' is balanced, else return false.



For example:
'S' = "{}()".


*/

//Approach
//Create stack of characters and traverse the given string
//If characters is an opening bracket (,{,[ then push them into the stack else if any other return false.
// If the stack is not empty & characters is closing bracket },),]
//  and stack top element is matching the opening bracket then pop the element from the stack
//  else return false.
// After traversal
//if the stack empty return true else return false.


bool isValidParenthesis(string s)
{
    // Write your code here.

    stack<char>st;

    for(char ch:s)
    {
        if(ch=='(' || ch == '{' || ch =='[')
        {
            st.push(ch);
        }
        else
        {
            if(st.empty())
                return false;
           

                if((ch==')' && st.top() == '(') || (ch == '}' && st.top() =='{') || (ch == ']' && st.top() == '['))
                    st.pop();
                else
                    return false;
            
        }
    }
    return st.empty();
}

//Time Complexity : O(N)
//Space Complexity : O(N)