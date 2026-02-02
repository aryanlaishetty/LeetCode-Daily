class Solution {
public:
    //Much Optimal Approach
    //TC = O(n)
    //SC = O(1)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;

        for(int i=0; i<n; i++) {
            xor1 ^= i+1;
            xor2 ^= nums[i];
        }

        return xor1 ^ xor2;
    }    
};