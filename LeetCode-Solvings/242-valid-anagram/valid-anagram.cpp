class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> freq; //<char, freq>
        
        //store freq of every char of string s in map
        for(int i=0; i<s.size(); i++) {
            if(freq.count(s[i])) {
                freq[s[i]]++;
            } else {
                freq[s[i]] = 1;
            }
        }

        //decrease freq of every char of string t from map
        for(int i=0; i<t.size(); i++) {
            if(freq.count(t[i])) {
                freq[t[i]]--;
                if(freq[t[i]] == 0) {
                    freq.erase(t[i]);
                }
            } else {
                return false;
            }
        }

        return freq.size() == 0;
    }
};