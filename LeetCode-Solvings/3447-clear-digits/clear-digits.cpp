class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        stack<int> st;

        for(int i=0; i<s.size(); i++) {
            if(isalpha(s[i])) {
                st.push(s[i]);
            }

            if(isdigit(s[i])) {
                st.pop();
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};