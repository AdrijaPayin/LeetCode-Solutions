class Solution {
public:
    const int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(26, 0);
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';
            int cnt = 0;

            for (int j = 0; j < 26; j++) {
                cnt = (cnt + dp[j]) % mod;
            }
            dp[idx] = (cnt + 1) % mod;
        }

        int sum = 0;
        for (int i = 0; i < dp.size(); i++) {
            sum = (sum + dp[i]) % mod;
        }
        
        return sum;
    }
};