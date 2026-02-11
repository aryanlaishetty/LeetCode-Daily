class Solution {
public:
    //Better Approach
    //tc = O(m+n) + O(mlogm)
    //sc = O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;

        for(int i=0; i<nums1.size(); i++) {
            if(nums1[i] == 0 && j < n) {
                nums1[i] = nums2[j++];
            }
        }

        sort(nums1.begin(), nums1.end());
    }
};