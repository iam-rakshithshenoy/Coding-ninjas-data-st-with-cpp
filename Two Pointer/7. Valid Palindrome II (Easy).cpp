//Valid Pallindrome ll

/*

Problem statement
Ninja’s friend challenged him with a trick question. He gave him a string ‘S’ and asked him if it is possible to make this string palindrome by deleting one character from the string. Can you help the ninja to solve this problem?

You are given a string ‘S’ of size ‘N’.You have to determine whether it is possible to make the string palindrome by deleting at most one character.

For Example
If the string is ‘AZBCDCBA’, the answer will be YES as we can delete the character ‘Z’ and the remaining string is a palindrome. 


*/









#include <bits/stdc++.h> 

bool isPalindrome(const string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
bool validPalindrome(int n, string &s)
{
    int left = 0, right = s.size() - 1;

    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            // Only one deletion allowed
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
    }

    return true; 
}