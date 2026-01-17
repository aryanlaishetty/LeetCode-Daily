class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> m;  //<num, freq>

        for(int i=0; i<nums.size(); i++) {
            if(m.count(nums[i])) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }

        int ans = 0;

        for(auto el : m) {
            if(el.second == 1) {
                ans += el.first;
            }
        }

        return ans;
    }
};