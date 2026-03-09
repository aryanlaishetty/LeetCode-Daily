/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //Optimal approach - inserting nodes in between existing nodes
    //tc = O(n + n + n)
    //sc = O(n), 'n' is not reducible and no extra space is used
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        
        //insert nodes in between, here next pointer is automatically assigned
        while(temp != NULL) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }

        //connect random pointers
        temp = head;

        while(temp != NULL) {
            Node* copyNode = temp->next;
            if(temp->random) copyNode->random = temp->random->next;
            temp = temp->next->next;
        }

        //unlink inbetween nodes and rearrange them properly
        temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        while(temp != NULL) {
            res->next = temp->next;
            temp->next = res->next->next;
            res = res->next;
            temp = temp->next;
        }
        
        return dummy->next;
    }
};