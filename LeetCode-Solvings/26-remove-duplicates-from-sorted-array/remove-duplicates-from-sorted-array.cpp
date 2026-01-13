class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        int ignore = 0;

        for(int i=0; i<nums.size(); i++) {
            if(s.count(nums[i])) {
                nums[i] = INT_MAX;
                ignore++;
            } else {
                s.insert(nums[i]);
            }
        }

        sort(nums.begin(), nums.end());

        return nums.size()-ignore;
    }
};