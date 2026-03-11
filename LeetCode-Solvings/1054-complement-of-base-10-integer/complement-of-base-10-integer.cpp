class Solution {
public:
    //Brute force approach
    //tc = O(log n)
    //sc = O(1)
    string getBinary(int n) {
        string res = "";

        while(n) {
            res += ((n % 2) + '0');
            n /= 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    int calDeci(string nBin) {
        int ans = 0;

        for(int i=nBin.size()-1; i>=0; i--) {
            int num = nBin[i] - '0';
            ans += (pow(2, nBin.size()-i-1) * num);
        } 

        return ans;
    }

    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        string nBin = getBinary(n);

        //take complement
        for(int i=0; i<nBin.size(); i++) {
            if(nBin[i] == '0') {
                nBin[i] = '1';
            } else {    //nBin[i] == '1'
                nBin[i] = '0';
            }
        }

        return calDeci(nBin);
    }
};