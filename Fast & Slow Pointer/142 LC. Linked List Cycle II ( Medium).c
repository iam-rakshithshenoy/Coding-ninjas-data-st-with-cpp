//142. Linked List Cycle II


/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.


*/

//Approach: fast & slow pointer

//1. Try to find the loop exisit or not
// Use Two pointer, slow & fast, where slow moves one step and fast moves two step everytime
//If slow == fast then loop exist else fast->next == nullptr then we reached the end(no loop detected)
//2. Now one pointer moves to start of LL.
// To understand the concept, we need to know how long distance c is. 
// Consider distance of slow pointer is A+B
//distance of fast pointer is A+B+C+B (since it moves twice of slow)
// since fast pointer move twice then slow
// 2(A+B) = A+B+C+B
// 2A + 2B = A + 2B + C (after simplifying)
// 2A = A+C ie A = C
// Actual distance A and distance C are same.

//3. So move one pointer back to head and move pointer only 1 step, If they meet each other at some pointer then
// that node is end of distance of A and distance C. we can move exactly C distance.




class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                slow = head;

                while(slow !=fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

//Time complexity : O(n)
//Space complexity : O(1)