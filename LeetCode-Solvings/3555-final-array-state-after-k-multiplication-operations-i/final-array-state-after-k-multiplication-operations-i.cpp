class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  //<num, idx>
        
        for(int i=0; i<nums.size(); i++) {
            pq.push(make_pair(nums[i], i));
        }

        for(int i=0; i<k; i++) {
            int idx = pq.top().second;
            pq.pop();
            nums[idx] *= multiplier;
            pq.push(make_pair(nums[idx], idx));
        }

        return nums;
    }
};