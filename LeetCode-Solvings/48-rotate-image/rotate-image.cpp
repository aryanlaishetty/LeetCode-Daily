class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //This is solved by first transposing the matrix and then reversing the elements in each row

        int n = matrix.size();

        //Transpose
        //O(n/2 * n/2)
        for(int i=0; i<n-1; i++) {  //O(n/2)
            for(int j=i+1; j<n; j++) {  //O(n/2)
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //Reverse elements in each row
        //O(n * n/2)
        for(int i=0; i<n; i++) {    //O(n)
            reverse(matrix[i].begin(), matrix[i].end());    //O(n/2)
        }
    }
};