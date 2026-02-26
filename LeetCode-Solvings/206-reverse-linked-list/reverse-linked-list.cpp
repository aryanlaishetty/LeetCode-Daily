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
    //Optimal Approach - Using recursion
    //tc = O(n)
    //sc = O(1)
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        ListNode* front = head->next;

        front->next = head;

        head->next = NULL;

        return newHead;
    }
};