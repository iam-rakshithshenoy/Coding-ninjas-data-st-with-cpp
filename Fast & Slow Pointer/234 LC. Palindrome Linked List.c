//234. Palindrome Linked List

/*

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

*/



//Simple Approach
/*To Check if the Given Linked List is palindrome or not , 
we can simply copy the data in stack and then check if the list if palindrome or not.

Complexity
Time complexity: O(N)
Space complexity: O(N)
*/

//Better Approach
// A linked list is a palindrome if: the 1st and last elements are equal and so on...
// Since we can’t traverse backward in a singly linked list, we:

// Use two pointer one will move with the speed of 1 and one with the speed of 2, so when the fast pointer reaches the end, slow pointer would be at mid.
// 1. Reverse the second half of the list
// 2. compare it with the first half

// This avoids extra space.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return false;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reached end and slow at mid
        //reverse the rest till I reach nullptr

        ListNode *prev = nullptr;
        while(slow)
        {
            ListNode *nextnode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextnode;
        }

        ListNode *middle = prev;
        fast = head;

        while(middle !=nullptr)
        {
            if(middle->val == fast->val)
            {
                middle = middle->next;
                fast = fast->next;
            }
            else
                return false;
        }
         return true;
    }
   
};

//Time Complexity: O(N)
//Space Complexity: O(1)