class Solution {
public:
    //Optimal Approach - turtle approach, slow fast pointers
    //tc = O(n)
    //sc = O(1)
    //it is similar to detecting loop in linked list
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];  //move 1 step forward
            fast = nums[nums[fast]];    //move 2 steps forward
        } while(slow != fast);
        
        fast = nums[0];

        while(slow != fast) {
            slow = nums[slow];  //move 1 step forward
            fast = nums[fast];  //move 1 step forward
        }

        return slow;
    }
};