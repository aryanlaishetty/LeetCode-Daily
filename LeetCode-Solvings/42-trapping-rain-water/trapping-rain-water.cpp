class Solution {
public:
    //Optimal approach
    //tc = O(n)
    //sc = O(1)
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int leftMax = 0, rightMax = 0, waterTrapped = 0;

        //we only need min(leftMax and rightMax) not both

        while(l < r) {
            if(height[l] <= height[r]) {
                if(leftMax > height[l]) {
                    waterTrapped += (leftMax - height[l]);
                } else {
                    leftMax = height[l];
                }
                l = l + 1;
            } else {
                if(rightMax > height[r]) {
                    waterTrapped += (rightMax - height[r]);
                } else {
                    rightMax = height[r];
                }
                r = r - 1;
            }
        }

        return waterTrapped;
    }
};