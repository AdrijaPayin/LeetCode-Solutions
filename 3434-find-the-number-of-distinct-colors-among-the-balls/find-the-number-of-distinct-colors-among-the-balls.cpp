class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_map<int, int> colorCount;

        vector<int> ans;
        int unique = 0;

        for (auto &q : queries) {
            int ball = q[0];
            int color = q[1];

            if (ballColor.find(ball) != ballColor.end()) {
                int oldColor = ballColor[ball];

                colorCount[oldColor]--;

                if (colorCount[oldColor] == 0)   unique--;
            }

            ballColor[ball] = color;
            colorCount[color]++;

            if (colorCount[color] == 1)  unique++;

            ans.push_back(unique);
        }

        return ans;
    }
};