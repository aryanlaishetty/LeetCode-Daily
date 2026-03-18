class Solution {
public:
    //Optimal solution - using recursion
    //tc = O(2^t + k), k = average length of every combination generated
    //sc = O(k * x), x = total number of combinations
    void findCombinations(int idx, int target, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& ans) {
        if(idx == candidates.size()) {
            if(target == 0) ans.push_back(ds);
            return;
        }

        //pick
        if(candidates[idx] <= target) {
            ds.push_back(candidates[idx]);  //picked
            findCombinations(idx, target-candidates[idx], candidates, ds, ans);
            ds.pop_back();  
        }

        //non pick
        findCombinations(idx+1, target, candidates, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0,  target, candidates, ds, ans);

        return ans;
    }
};