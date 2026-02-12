class Solution {
public:
    //Optimal Approach
    //tc = O(logn)
    //sc = O(1)
    double myPow(double x, int n) {
        long long N = n;    // prevent overflow
        
        if (N < 0) {
            x = 1 / x;
            N = -N; //abs(N)
        }

        double result = 1;

        while (N > 0) {
            if (N % 2 == 1) {   // if odd
                result *= x;
            }

            x *= x; // square base
            N /= 2; // halve exponent
        }

        return result;
    }
};