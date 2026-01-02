/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* getInorderSuccessor(TreeNode* root) {
        while(root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }

        if(key < root->val) {  //left subtree
            root->left = deleteNode(root->left, key);
        } else if(key > root->val) {   //right subtree
            root->right = deleteNode(root->right, key);
        } else {    //root == val
        
            //case0: 0 children
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            //case1: 1 child
            if(root->left == NULL || root->right == NULL) {
                return root->left == NULL ? root->right : root->left;
            }

            //case2: 2 children
            TreeNode* IS = getInorderSuccessor(root->right);    //getting IS
            root->val = IS->val;  //replace root data with IS data
            root->right = deleteNode(root->right, IS->val);    //delete IS node
            return root;
        }

        return root;
    }
};