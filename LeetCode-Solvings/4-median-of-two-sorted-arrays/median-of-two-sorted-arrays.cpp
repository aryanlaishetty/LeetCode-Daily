class Solution {
public:
    double findMedian(vector<int>& data) {
        // Sort the vector in ascending order
        sort(data.begin(), data.end());

        int n = data.size();

        if (n % 2 != 0) {
            // Odd number of elements: return the middle element
            return data[n / 2];
        } else {
            // Even number of elements: return the average of the two middle elements
            double middle1 = data[n / 2 - 1];
            double middle2 = data[n / 2];
            return (middle1 + middle2) / 2.0;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0; i<nums2.size(); i++) {
            nums1.push_back(nums2[i]);
        }
        
        return findMedian(nums1);
    }
};