class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int i=low; i<=high; i++) {
            string num = to_string(i);
            int len = num.size();

            if(len % 2 != 0) continue;

            int firstHalf = 0, secondHalf = 0;

            for(int j=0; j<len/2; j++) {
                firstHalf += num[j] - '0';
                secondHalf += num[j + len/2] - '0';
            } 

            if(firstHalf == secondHalf) {
                count++;
            }
        }

        return count;
    }
};