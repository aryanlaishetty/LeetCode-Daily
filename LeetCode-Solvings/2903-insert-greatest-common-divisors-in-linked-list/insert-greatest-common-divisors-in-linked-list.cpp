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
    //Optimal approach
    //tc = O(n)
    //sc = O(1) but O(n) new nodes to insert but not to compute algorithm 
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) return head;

        ListNode* curr = head;

        while(curr->next != NULL) {
            int gcdNum = gcd(curr->val, curr->next->val);
            ListNode* gcdNode = new ListNode(gcdNum);

            // first->next = NULL;
            gcdNode->next = curr->next;
            curr->next = gcdNode;

            curr = gcdNode->next;
        }

        return head;
    }
};