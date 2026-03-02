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
    //Brute force approach
    //tc = O(n + n)
    //sc = O(1)

    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftHt = height(root->left);
        int rightHt = height(root->right);
        int currHt = max(leftHt, rightHt) + 1;

        return currHt; 
    }

    int helper(TreeNode* root, int level, int height, int sum) {
        if(root == NULL) return 0;

        if(level == height) return sum += root->val;

        int left = helper(root->left, level+1, height, sum);
        int right = helper(root->right, level+1, height, sum);

        return left + right;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int ht = height(root);
        return helper(root, 1, ht, 0);
    }
};