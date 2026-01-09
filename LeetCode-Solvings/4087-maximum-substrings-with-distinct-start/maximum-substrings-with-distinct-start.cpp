class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> uniSet;

        for(int i=0; i<s.size(); i++) {
            uniSet.insert(s[i]);
        }

        return uniSet.size();
    }
};