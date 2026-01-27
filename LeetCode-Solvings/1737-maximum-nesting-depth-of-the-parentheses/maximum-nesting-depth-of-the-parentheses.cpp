class Solution {
public:
    int maxDepth(string s) {
        int currCount = 0, maxCount = 0;
        stack<char> st;

        for(char ch : s) {
            if(ch == '(') {
                currCount++;
            } else if(ch == ')') {
                maxCount = max(maxCount, currCount);
                currCount--;
            }
        }   

        return maxCount;
    }
};