class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;  //<value, idx>
        vector<int> ans;

        //1st window
        for(int i=0; i<k; i++) {
            pq.push(make_pair(nums[i], i));
        }
        ans.push_back(pq.top().first);

        for(int i=k; i<nums.size(); i++) {
            while(!pq.empty() && pq.top().second < (i-k+1)) {   //outside window
                pq.pop();
            }

            pq.push(make_pair(nums[i], i));
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};