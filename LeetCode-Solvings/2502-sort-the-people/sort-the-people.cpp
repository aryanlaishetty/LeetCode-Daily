class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int, string>> q;

        for(int i=0; i<names.size(); i++) {
            q.push(make_pair(heights[i], names[i]));
        }

        for(int i=0; i<names.size(); i++) {
            names[i] = q.top().second;
            q.pop();
        }

        return names;
    }
};