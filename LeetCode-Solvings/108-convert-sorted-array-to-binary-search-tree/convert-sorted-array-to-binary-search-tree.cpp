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
    TreeNode* buildBalancedBST(vector<int> sortedArr, int st, int end) {
        if(st > end) {
            return NULL;
        }

        int mid = st + (end-st)/2;
        TreeNode* curr = new TreeNode(sortedArr[mid]);

        curr->left = buildBalancedBST(sortedArr, st, mid-1);
        curr->right = buildBalancedBST(sortedArr, mid+1, end);

        return curr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBalancedBST(nums, 0, nums.size()-1);
    }
};