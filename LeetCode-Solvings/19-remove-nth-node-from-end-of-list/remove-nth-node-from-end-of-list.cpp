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
    //Optimal Solution - Using slow and fast pointers
    //tc = O(size)
    //sc = O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for(int i=1; i<=n; i++) fast = fast->next;

        if(fast == NULL) {  //edge case
            ListNode* newHead = head->next;
            head->next = NULL;
            delete(head);
            return newHead;
        }

        ListNode* slow = head;
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delNode->next = NULL;
        delete(delNode);

        return head;
    }
};