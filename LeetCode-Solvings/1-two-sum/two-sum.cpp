class Solution {
public:
    //Optimal approach for return indexes - using hashmap
    //tc = O(n) * O(log n), worst case - O(n) * O(n)
    //sc = O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;  //<nums[i], i>

        for(int i=0; i<nums.size(); i++) {
            int curr = nums[i];
            int remaining = target - curr;  

            if(m.count(remaining)) {
                return {m[remaining], i};
            }
            
            m[nums[i]] = i;
        }

        return {};
    }
};