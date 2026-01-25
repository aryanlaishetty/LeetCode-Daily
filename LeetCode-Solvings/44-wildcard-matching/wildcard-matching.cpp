class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();   //string size
        int m = p.size();   //pattern size

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;    //when s and p both are empty than p can be converted into s

        for(int j=1; j<m+1; j++) {  //0th row, when text is empty
            if(p[j-1] == '*') {
                dp[0][j] = dp[0][j-1];  
            } else {    //when char is some alphabet or '?'
                dp[0][j] = false;
            }
        }

        //Bottom up fill DP table
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<m+1; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];
    }
};