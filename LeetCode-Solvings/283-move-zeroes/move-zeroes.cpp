class Solution {
public:
    //Optimal - 2 pointer approach
    //tc = O(n), array traversed only onced
    //sc = O(1), No extra space is used
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int j = -1;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                j = i;  //Here, j points at element 0
                break;
            }
        }

        if(j == -1) return; //if no zeroes exist in nums

        for(int i=j+1; i<n; i++) {
            if(nums[i] != 0) {  //as j is non zero
                swap(nums[i], nums[j]); //swap non zero element with zero element
                j++;
            }
        } 
        
    }
};