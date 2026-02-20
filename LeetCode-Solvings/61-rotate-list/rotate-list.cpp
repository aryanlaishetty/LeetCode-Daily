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
    //tc = O(size) + O(size-k)
    //sc = O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        
        int size = 1;
        ListNode* tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
            size++;
        }

        k = k % size;
        if(k == 0) return head;

        tail->next = head;  //1. tail->head, make circular

        ListNode* newTail = head;
        for(int i=0; i<size-k-1; i++) { //2. move newTail to (size-k)th node
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;  //3. move newHead to newTail->next
        newTail->next = NULL;   //4. break link, newTail->null

        return newHead;
    }
};