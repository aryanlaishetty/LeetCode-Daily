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
    //Brute Force Approach
    //tc = O(size + size)
    //sc = O(1)
    int getSize(ListNode* head) {
        int count = 0;
        while(head != NULL) {
            count++;
            head = head->next;
        }

        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);

        if(size == n) {
            ListNode* newHead = head->next;
            head->next = NULL;
            delete(head);
            return newHead;
        }

        int forwardN = size - n;

        ListNode* temp = head;
        while(temp != NULL) {
            forwardN--;

            if(forwardN == 0) {
                break;
            }

            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delNode->next = NULL;
        delete(delNode);
        
        return head;
    }
};