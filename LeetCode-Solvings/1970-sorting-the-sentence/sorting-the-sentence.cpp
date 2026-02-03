class Solution {
public:
    string sortSentence(string s) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
        string word = "";

        for(int i=0; i<s.size(); i++) {
            if(isdigit(s[i])) {
                q.push(make_pair((int)s[i], word));
                word = "";
                continue;
            }

            if(s[i] == ' ') {
                continue;
            }

            word += s[i];

        }

        string ans = "";
        while(!q.empty()) {
            ans += q.top().second;
            ans += ' ';
            q.pop();
        }

        ans.pop_back();

        return ans;
    }
};