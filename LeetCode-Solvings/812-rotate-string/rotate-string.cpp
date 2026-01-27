class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        for(int i=0; i<s.size(); i++) {
            if(s == goal) {
                return true;
            }

            s.push_back(s[0]);
            s.erase(0, 1);
        }

        return false;
    }
};