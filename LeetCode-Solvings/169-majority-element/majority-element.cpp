class Solution {
public:
    //Optimal Approach - Moore's Voting Algorithm
    //Tc = O(n) + O(n)
    //Sc = O(1)
    int majorityElement(vector<int> nums) {
        int count = 0, el;

        for(int i=0; i<nums.size(); i++) {
            if(count == 0) {
                count = 1;
                el = nums[i];
            } else if(nums[i] == el) {
                count++;
            } else {
                count--;
            }
        }

        int againCount = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == el) againCount++;
        }

        return againCount > nums.size()/2 ? el : -1;
    }
};