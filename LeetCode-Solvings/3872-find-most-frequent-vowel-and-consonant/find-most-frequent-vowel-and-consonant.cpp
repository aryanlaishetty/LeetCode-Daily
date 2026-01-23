class Solution {
public:
    int maxFreqSum(string s) {

        unordered_map<int, int> vowsMap;
        unordered_map<int, int> consMap;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                if(vowsMap.count(s[i])) {
                    vowsMap[s[i]]++;
                } else {
                    vowsMap[s[i]] = 1;
                }
            } else {
                if(consMap.count(s[i])) {
                    consMap[s[i]]++;
                } else {
                    consMap[s[i]] = 1;
                }
            }
        }

        priority_queue<pair<int, int>> vowsPq;
        priority_queue<pair<int, int>> consPq;

        int ans = 0;

        if(!vowsMap.empty()) {
            for(auto el : vowsMap) {
                vowsPq.push(make_pair(el.second, el.first));
            }
            ans += vowsPq.top().first;
        }

        if(!consMap.empty()) {
            for(auto el : consMap) {
                consPq.push(make_pair(el.second, el.first));
            }
            ans += consPq.top().first;
        }
        
        return ans;
    }
};