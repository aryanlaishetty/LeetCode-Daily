class Solution {
public:
    //Optimal Approach - using 2 constant pointers i & j, and two variable pointer k & l
    //tc = O(nlogn) + O(n*n*n)
    //sc = O(size of ans array), we are using this array only to return ans, not in algorithm
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;   //no consecutive elements 
            for(int j=i+1; j<n; j++) {
                if(j>i+1 && nums[j] == nums[j-1]) continue; //no consecutive elements 

                int k = j+1;
                int l = n-1;
                
                while(k<l) {
                    // long long sum = nums[i] + nums[j] + nums[k] + nums[l];   //can overflow
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum > target) {
                        l--;
                    } else if(sum < target) {
                        k++;
                    } else {    //if (sum == target)
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;
                        while(k < l && nums[k] == nums[k-1]) k++;   //no consecutive elements 
                        while(k < l && nums[l] == nums[l+1]) l--;   //no consecutive elements 
                    }
                }
            }
        }

        return ans;
    }
};