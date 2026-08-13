class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});

        while (k--) {
            auto [num, index] = pq.top();
            pq.pop();
            pq.push({num * multiplier, index});
        }

          while(!pq.empty()) {
            auto [num, index] = pq.top();
            pq.pop();
            nums[index] = num;
        }
        return nums;
    }
};