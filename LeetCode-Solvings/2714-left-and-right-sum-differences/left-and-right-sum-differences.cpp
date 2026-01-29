class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum, rightSum(n, 0), ans;
        int left = 0, right = 0;

        for(int i=0; i<n; i++) {
            leftSum.push_back(left);
            left += nums[i];
        }

        for(int i=n-1; i>=0; i--) {
            rightSum[i] = right;
            right += nums[i];
        }

        for(int i=0; i<n; i++) {
            ans.push_back(abs(leftSum[i] - rightSum[i]));
        }

        return ans;
    }
};