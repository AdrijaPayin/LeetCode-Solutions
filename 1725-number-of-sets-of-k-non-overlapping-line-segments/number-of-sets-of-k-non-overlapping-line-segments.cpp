class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

    long long modInverse(long long x) { return power(x, MOD - 2); }

    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;

        long long ans = 1;

        for (int i = 1; i <= R; i++) {
            ans = (ans * (N - i + 1)) % MOD;
            ans = (ans * modInverse(i)) % MOD;
        }

        return ans;
    }
};