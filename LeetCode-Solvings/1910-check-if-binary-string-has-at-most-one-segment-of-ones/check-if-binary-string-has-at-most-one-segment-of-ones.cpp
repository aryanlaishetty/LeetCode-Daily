class Solution {
public:
    //brute force approach
    //tc = O(n + n)
    //sc = O(1)
    bool checkOnesSegment(string s) {
        int count = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1') count++;
        }

        int newCount = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1') {
                newCount++;
            } else {
                break;
            }
        }

        return count == newCount;
    }
};