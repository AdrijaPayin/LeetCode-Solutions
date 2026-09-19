class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long int n = nums.size();

        long long total = (n * (n - 1)) / 2;

        long long int good = 0;

        for (int i = 0; i < n; i++) {

            int key = nums[i] - i;
            good = good + mp[key];
            mp[key]++;
        }
        
        return total - good;
    }
};