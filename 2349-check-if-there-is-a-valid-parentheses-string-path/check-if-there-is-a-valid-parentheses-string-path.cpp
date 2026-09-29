class Solution {
public:
    bool dfs(int i, int j, int balance, vector<vector<char>>& grid,
             vector<vector<vector<int>>>& memo) {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n)
            return false;

        if (grid[i][j] == '(') {
            balance++;
        } else {
            balance--;
        }

        if (balance < 0 || balance > m + n)
            return false;

        if (i == m - 1 && j == n - 1) {
            return balance == 0;
        }

        if (memo[i][j][balance] != -1) {
            return memo[i][j][balance];
        }

        bool found = dfs(i + 1, j, balance, grid, memo) ||
                     dfs(i, j + 1, balance, grid, memo);

        return memo[i][j][balance] = found;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxb = m + n;

        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(n, vector<int>(maxb + 1, -1)));
        return dfs(0, 0, 0, grid, memo);
    }
};