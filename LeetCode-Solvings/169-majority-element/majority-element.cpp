class Solution {
public:
    int majorityElement(vector<int> nums) {
        unordered_map<int, int> m;  //<nums[i], frequence>

        for(int i=0; i<nums.size(); i++) {
            if(m.count(nums[i])) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }

        for(pair<int, int> p : m) {     //<key=nums[i], freq>
            if(p.second > nums.size()/2) {
                return p.first;
            }
        }
        return -1;
    }
};