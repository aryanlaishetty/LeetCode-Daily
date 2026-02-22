class Solution {
public:
    //Optimal Approach - using mergeSort, revise mergeSort and countInverse problems before this, here countReverse function the left pointer acts as constant and right varies every single time
    //tc = O(nlogn + 2n)
    //sc = O(n)
    void merge(vector<int>& nums, int low, int mid, int high) {
        int left = low; //starting of left half;
        int right = mid+1;  //starting of right half
        vector<int> temp;

        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) { //left element is smaller
                temp.push_back(nums[left]);
                left++;
            } else {    //right element is smaller
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid) {    //left half elements are remaining
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high) {  //right half elements are remaining
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low; i<=high; i++) {  //copy temps element into original array
            nums[i] = temp[i-low];
        }
    }

    int countReverse(vector<int>& nums, int low, int mid, int high) {
        int right = mid+1;
        int count = 0;

        for(int i=low; i<=mid; i++) {
            while(right <= high && (long long)nums[i] > (long long)2*nums[right]) right++;
            count += (right - (mid + 1));
        }

        return count;
    }
    
    int mergeSort(vector<int>& nums, int low, int high) {
        int count = 0;

        if(low >= high) return 0;

        int mid = low + (high - low)/2;
        
        count += mergeSort(nums, low, mid);    //left half
        count += mergeSort(nums, mid+1, high);   //right half
        
        count += countReverse(nums, low, mid, high); 

        merge(nums, low, mid, high);
        
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};