class Solution {
public:
    //Optimal Approach - binary search
    //tc = O(log n)
    //sc = O(1)
    int searchInsert(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;

        if(target > nums[right]) return right+1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                return mid;
            } else if(target < nums[mid]) {
                right = mid-1;
            } else {    //numd[mid] < target
                left = mid+1;
            }
        }
        
        return left;
    }
};