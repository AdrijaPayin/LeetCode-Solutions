class Solution {
public:
    int M = 1e9 + 7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> l, r;

        int result = 0;

        for (int& num : nums) r[num]++;
        
        for (int& num : nums) {
            r[num]--;

            int left = l[num * 2];
            int right = r[num * 2];

            result = (result + (1LL * left * right)) % M;

            l[num]++;
        }

        return result;
    }
};