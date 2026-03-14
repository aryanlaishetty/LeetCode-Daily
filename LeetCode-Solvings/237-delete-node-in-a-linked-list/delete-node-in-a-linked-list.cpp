/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //Optimal Solution (only solution) - assign next nodes data to current node and point current node to next to next node and delete the current node's next node
    //tc = O(1)
    //sc = O(1)
    void deleteNode(ListNode* node) {
        ListNode* temp = node;

        node->val = node->next->val;
        ListNode* delNode = node->next;

        node->next = node->next->next;

        delNode->next = NULL;

        delete(delNode);
    }
};