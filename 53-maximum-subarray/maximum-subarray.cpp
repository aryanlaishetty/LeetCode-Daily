class Solution {
public:
    //Using Kadane's algo
    //tc = O(n)
    //sc = O(1)
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int largestSum = INT_MIN, currSum = 0;

        for(int i=0; i<n; i++) {
            currSum += nums[i];
            largestSum = max(largestSum, currSum);
            if(currSum < 0) {
                currSum = 0;
            }
        }

        return largestSum;
    }
};