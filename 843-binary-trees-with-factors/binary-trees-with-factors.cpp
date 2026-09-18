class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        const long long MOD = 1e9 + 7;

        unordered_map<int, long long> mp;

        for (int num : arr) mp[num] = 1;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < i; j++) {

                if (arr[i] % arr[j] == 0) {
                    int right = arr[i] / arr[j];

                    if (mp.find(right) != mp.end()) {
                        mp[arr[i]] += mp[arr[j]] * mp[right];
                        mp[arr[i]] %= MOD;
                    }
                }
            }
        }
        long long count = 0;

        for (int num : arr)
            count = (count + mp[num]) % MOD;

        return count;
    }
};