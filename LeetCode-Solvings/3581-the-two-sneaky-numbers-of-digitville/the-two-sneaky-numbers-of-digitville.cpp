class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> m;  //<num[i], freq>

        for(int i=0; i<nums.size(); i++) {
            if(m.count(nums[i])) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }

        vector<int> ans;
        for(pair<int, int> el : m) {
            if(el.second == 2) {
                ans.push_back(el.first);
            }
        }

        return ans;
    }
};