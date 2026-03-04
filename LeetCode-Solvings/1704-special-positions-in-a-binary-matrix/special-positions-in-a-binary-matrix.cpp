class Solution {
public:
    //brute force approach
    //tc = O(m*n * (m+n))
    //sc = O(1)
    bool check(int i, int j, vector<vector<int>>& mat) {
        for(int p=0; p<mat.size(); p++) {
            if(mat[p][j] == 1) {
                if(p == i) continue;
                return false;
            } 
        }

        for(int q=0; q<mat[i].size(); q++) {
            if(mat[i][q] == 1) {
                if(q == j) continue;
                return false;
            }
        }

        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;

        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[i].size(); j++) {
                if(mat[i][j] == 1 && check(i, j, mat)) count++;
            }
        }

        return count;
    }

};