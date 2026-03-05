class Solution {
public:
    //brute force approach
    //tc = O(m * n * log m) + O(k * log n)
    //sc = O(m + n)
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min queue  <soldiers, row>

        for(int i=0; i<mat.size(); i++) {
            int solCount = 0;
            for(int j=0; j<mat[i].size(); j++) {
                if(mat[i][j] == 1) solCount++;
            }
            pq.push(make_pair(solCount, i));
        }

        vector<int> ans;

        for(int i=0; i<k; i++) {
            int row = pq.top().second;
            pq.pop();
            ans.push_back(row);
        }

        return ans;
    }
};