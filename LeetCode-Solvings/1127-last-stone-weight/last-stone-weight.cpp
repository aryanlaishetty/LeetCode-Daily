class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size() > 1) {
            int y = pq.top();   //largest
            pq.pop();
            int x = pq.top();   //second largest
            pq.pop();

            if(x != y) {
                pq.push(y-x);
            }
        }

        return !pq.empty() ? pq.top() : 0;
    }
};