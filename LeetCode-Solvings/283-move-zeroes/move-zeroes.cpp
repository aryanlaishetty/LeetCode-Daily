class Solution {
public:
    //brute force approach
    //tc = O(2n)
    //sc = O(n-k), k = no. of non zeros
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        //copy non zeroes in temp
        vector<int> temp;
        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }

        //overwrite nums with temp
        int k = temp.size();
        for(int i=0; i<k; i++) {
            nums[i] = temp[i];
        }

        //overwrite remaining index with 0
        for(int i=k; i<n; i++) {
            nums[i] = 0;
        }
    }
};