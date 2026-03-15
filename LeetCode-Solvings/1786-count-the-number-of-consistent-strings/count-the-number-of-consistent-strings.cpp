class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_set<char> st;
        for(char ch : allowed) {
            st.insert(ch);
        }

        int count = 0;
        for(int i=0; i<words.size(); i++) {

            bool valid = true;

            for(int j=0; j<words[i].size(); j++) {
                if(!st.count(words[i][j])) {
                    valid = false;
                    break;
                }
            }

            if(valid) count++;
        }

        return count;
    }
};