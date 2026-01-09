class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> uniSet(s.begin(), s.end());
        return uniSet.size();
    }
};