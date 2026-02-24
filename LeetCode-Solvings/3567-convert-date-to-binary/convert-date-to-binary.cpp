class Solution {
public:
    //Brute Force Approach
    //tc = O(n^2) ~ not exactly n^2 but its quadratic power
    //sc = O(n+n+n) ~ nearly O(3n)
    string toBinary(int num) {
        string bin = "";

        while(num > 0) {
            bin += num % 2 + '0';
            num /= 2;
        }

        reverse(bin.begin(), bin.end());

        return bin;
    }

    string convertDateToBinary(string date) {
        int temp = 0;
        
        string ans = "";

        for(int i=0; i<date.size(); i++) {
            if(date[i] == '-') {
                ans += toBinary(temp);
                ans += '-';
                temp = 0;
            } else if (date[i] != '-') {
                temp = temp * 10 + (date[i] - '0');
            }
        }
            
        ans += toBinary(temp);

        return ans;
    }
};