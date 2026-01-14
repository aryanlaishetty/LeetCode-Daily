class Solution {
public:
bool isCycle(int src, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>> &prerequisites) {
        visited[src] = true;
        recPath[src] = true;

        for(int i=0; i<prerequisites.size(); i++) {
            //v <----- u
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if(u == src) {
                if(!visited[v]) {
                    if(isCycle(v, visited, recPath, prerequisites)) {
                        return true;
                    }
                } else {
                    if(recPath[v]) {
                        return true;
                    }
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    void topologicalSort(int src, vector<bool> &visited, stack<int> &s, vector<vector<int>>& prerequisites) {
        visited[src] = true;

        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if(u == src) {
                if(!visited[v]) {
                    topologicalSort(v, visited, s, prerequisites);
                }
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;

        vector<bool> visited(V, false);
        vector<bool> recPath(V, false);
        vector<int> ans;

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(isCycle(i, visited, recPath, prerequisites)) {
                    return ans; //return empty if DAG does not exist
                }
            }
        }

        //perform topological sort
        vector<bool> visited2(V, false);
        stack<int> s;
        for(int i=0; i<V; i++) {
            if(!visited2[i]) {
                topologicalSort(i, visited2, s, prerequisites);
            }
        }

        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};