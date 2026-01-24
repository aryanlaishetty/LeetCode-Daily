class Solution {
public:
    int reverseInteger(int num) {
        int revNum = 0;

        while (num != 0) {
            int remainder = num % 10;   // last digit
            revNum = revNum * 10 + remainder; // Add to revNum
            num /= 10;  // Remove the last digit from the original number
        }

        return revNum;
    }

    bool isSameAfterReversals(int num) {
        if(num == 0) return 1;
        
        int lastDigit = num % 10;

        return lastDigit != 0;
    }
};