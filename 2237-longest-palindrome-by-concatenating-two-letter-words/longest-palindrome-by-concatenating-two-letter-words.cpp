class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;
        bool center = false;

        for (string word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (mp[rev] > 0) {
                ans += 4;
                mp[rev]--;
            } 
            else  mp[word]++;
    
        }

        for (auto& [word, freq] : mp) {
            if (word[0] == word[1] && freq > 0) {
                ans += 2;
                break;
            }
        }

        return ans;
    }
};