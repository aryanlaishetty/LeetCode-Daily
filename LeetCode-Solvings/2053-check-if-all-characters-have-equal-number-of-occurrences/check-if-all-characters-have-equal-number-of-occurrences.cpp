class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<int, int> m;  //<num, freq>

        for(int i=0; i<s.size(); i++) {
            if(m.count(s[i])) {
                m[s[i]]++;
            } else {
                m[s[i]] = 1;
            }
        }

        int occur = m[s[0]];

        for(auto el : m) {
            if(el.second != occur) {
                return false;
            }
        }

        return true;

    }
};