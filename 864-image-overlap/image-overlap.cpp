class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int, int>> i1, i2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (img1[i][j]) i1.push_back({i, j});
                if (img2[i][j]) i2.push_back({i, j});
            }
        }

        map<pair<int, int>, int> mp;
        for (auto [r1, c1] : i1) {
            for (auto [r2, c2] : i2) {
                mp[{r2 - r1, c2 - c1}]++;
            }
        }

        int ans = 0;
        for (auto [x, y] : mp) ans = max(ans, y);

        return ans;
    }

};