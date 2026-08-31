class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int a, b, c;
        vector<vector<int>> ans;

        for (int i = 0; i < n; i += 3) {
            a = nums[i], b = nums[i + 1], c = nums[i + 2];

            if (c - a > k) return {};

            ans.push_back({a, b, c});
        }
        
        return ans;
    }
};