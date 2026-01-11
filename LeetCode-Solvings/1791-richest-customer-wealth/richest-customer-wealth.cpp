class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int richest = INT_MIN;

        for(int i=0; i<accounts.size(); i++) {
            int currMax = 0;
            for(int j=0; j<accounts[i].size(); j++) {
                currMax += accounts[i][j];
            }
            richest = max(richest, currMax);
        }

        return richest;
    }
};