class Solution {
public:
    //DP Approadh
    //tc = O(n)
    //sc = O(1)
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;

        for(int i=1; i<prices.size(); i++) {
            int currProfit = prices[i]-mini;
            maxProfit = max(maxProfit, currProfit);
            mini = min(mini, prices[i]);
        }

        return maxProfit;
    }
};