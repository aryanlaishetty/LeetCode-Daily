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
    //brute force approach - using hashmaps
    //tc = O(n + n)
    //sc = O(n + n), one of the 'n' is not reduceable 
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        map<Node*, Node*> m;

        while(temp != NULL) {
            Node* newNode = new Node(temp->val);
            m[temp] = newNode;
            temp = temp->next;
        }

        temp = head;

        while(temp != NULL) {
            Node* copyNode = m[temp];
            copyNode->next = m[temp->next];
            copyNode->random = m[temp->random];
            temp = temp->next;
        }

        return m[head];
    }
};