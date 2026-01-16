class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;  //<freq, int>
        unordered_map<int, int> m;  //<freq, int>

        for(int i=0; i<nums.size(); i++) {
            if(m.count(nums[i])) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }

        for(auto it : m) {
            pq.push(make_pair(it.second, it.first));    //second=freq=value    first=nums[i]=key
        }

        while(ans.size() != k) {
            pair<int, int> curr = pq.top();
            pq.pop();

            ans.push_back(curr.second);
        }

        return ans;
    }
};