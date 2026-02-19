class Solution {
public:
    //Optimal Approach - Using two pointers with sliding window
    //tc = O(n)
    //sc = O(256) ~ Constant sc
    int lengthOfLongestSubstring(string s) {
        vector<int> hashTable(256, -1); //not using map, because map might take logn time
        int left = 0, right = 0;
        int maxLen = 0;

        while(right < s.size()) {
            if(hashTable[s[right]] != -1) { //char repeated
                if(hashTable[s[right]] >= left) {   //left pointer should be always lesser than right
                    left = hashTable[s[right]] + 1; //left will move to the next index of repeated char
                }
            }
            
            int len = right - left + 1;
            maxLen = max(maxLen, len);

            hashTable[s[right]] = right;    //update the index of repeated char
            right++;
        }

        return maxLen;
    }
};