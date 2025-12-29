/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool rootToNodePath(TreeNode* root, TreeNode* r, vector<int> &path) {
        if(root == NULL) {
            return false;
        }

        path.push_back(root->val);
        if(root == r) {
            return true;
        }

        bool isLeft = rootToNodePath(root->left, r, path); 
        bool isRight = rootToNodePath(root->right, r, path); 

        if(isLeft || isRight) {
            return true;
        }

        path.pop_back();
        return false;
    }

    TreeNode* findNode(TreeNode* root, int lca) {
        if(!root) {
            return NULL;
        }

        if(root->val == lca) {
            return root;
        }

        TreeNode* left = findNode(root->left, lca);

        if(left) {
            return left;
        }

        return findNode(root->right, lca);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> path1;
        vector<int> path2;

        rootToNodePath(root, p, path1);
        rootToNodePath(root, q, path2);

        int lca = -1;

        for(int i=0, j=0; i<path1.size() && j<path2.size(); i++,j++) {
            if(path1[i] != path2[j]) {
                break;
            }
            lca = path1[i];
        }
        
        return findNode(root, lca);
    }
};