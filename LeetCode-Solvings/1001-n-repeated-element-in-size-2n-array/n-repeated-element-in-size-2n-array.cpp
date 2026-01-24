class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> m;  //<num[i], freq>
        int n = nums.size() / 2;

        for(int i=0; i<nums.size(); i++) {
            if(m.count(nums[i])) {
                m[nums[i]]++;
            } else {
                m[nums[i]]++;
            }
        }
        
        int ans = 0;
        for(auto el : m) {
            if(el.second == n) {
                ans = el.first;
                break;
            }
        }

        return ans;
    }
};