class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n;
        string newN = to_string(n);
        reverse(newN.begin(), newN.end());
        n = stoi(newN);
        return abs(temp - n);
    }
};