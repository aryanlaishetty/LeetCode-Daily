class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k < nums.size()) {
            int kRev = nums.size() - k;
            for(int i=0; i<kRev; i++) {
                nums.push_back(nums[i]);
            }
            nums.erase(nums.begin(), nums.begin() + kRev);
        } else {
            for(int i=0; i<k; i++) {
                int lastEl = nums[nums.size()-1];
                nums.insert(nums.begin(), lastEl);
                nums.pop_back();
            }
        }
        
    }
};