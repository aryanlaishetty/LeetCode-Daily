class Solution {
public:
    //Bruteforce approach
    //tc = O(log n)
    //sc = O(log n)
    int reverse(int x) {
        bool isNeg = false;

        string str = to_string(x);

        if(x >= 0) {
            std::reverse(str.begin(), str.end());
        } else {
            str.erase(0, 1);
            isNeg = true;
            std::reverse(str.begin(), str.end());
        }

        long long rev = stoll(str);

        if(isNeg) rev = -rev;

        if(rev > INT_MAX || rev < INT_MIN) return 0;

        return (int)rev;
    }
};