class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        for (char c : s) freq[c - 'a']++;

        int odd = 0;
        int even = s.size();

        for (int f : freq) {
            if (f == 0) continue;

            if (f % 2 == 1) odd = max(odd, f);
            else even = min(even, f);
        }

        return odd - even;
    }
};