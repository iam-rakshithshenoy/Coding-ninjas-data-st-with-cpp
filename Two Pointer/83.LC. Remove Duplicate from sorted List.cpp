//83.LC: Remove Duplicates from Sorted List 
/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
Input: head = [1,1,2,3,3]
Output: [1,2,3]
*/


// If the list is empty, return head.
// Set two pointers slow = head and fast = head.
// Traverse the list with fast:

//     *.If fast->val is different from slow->val, link slow->next = fast and move slow.

//     *.Move fast to the next node each time.
// After traversal, set slow->next = nullptr to remove  duplicate.

// Return head.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head) return head;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast)
        {
            if(fast->val !=slow->val)
            {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        slow->next = nullptr; // important step 
        return head;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(1)

