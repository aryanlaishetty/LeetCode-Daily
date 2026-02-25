class Solution {
public:
    //Bruteforce approach, store counts of bits of each element by making pair of both and sorting them in ascending order, can also use priority queue to get pair which has smallest number of bits as top or you can use simple vector of pairs it wont make much difference in tc and sc
    //tc = O(n + nlogn + n)
    //sc = O(2*n)
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> kCounts;

        for(int i=0; i<arr.size(); i++) {
            int num = arr[i];

            int k = __builtin_popcount(num);

            kCounts.push_back(make_pair(k, num));
        }

        sort(kCounts.begin(), kCounts.end());

        for(int i=0; i<kCounts.size(); i++) {
            arr[i] = kCounts[i].second;
        }

        return arr;
    }
};