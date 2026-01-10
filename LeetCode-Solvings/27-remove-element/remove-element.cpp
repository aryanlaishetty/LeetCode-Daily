class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == val) {
                nums[i] = INT16_MAX;
                count++;
            }
        }

        sort(nums.begin(), nums.end());

        // for(int i=0; i<nums.size(); i++) {
        //     if(nums[i] == INT16_MAX) {
        //         break;
        //     }
        //     count++;
        // }
        return nums.size() - count;
    }
};