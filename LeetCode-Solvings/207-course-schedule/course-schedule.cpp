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

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {    //prerequisites = graph points
        int V = numCourses;

        vector<bool> visited(V, false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(isCycle(i, visited, recPath, prerequisites)) {
                    return false;
                }
            }
        }

        return true;
    }
};