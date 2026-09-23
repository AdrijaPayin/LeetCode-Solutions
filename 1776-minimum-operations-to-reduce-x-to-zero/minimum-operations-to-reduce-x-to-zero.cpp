class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        if (totalSum == x) return n;
        if (totalSum < x) return -1;

        int answer = INT_MAX;

        int suffixSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            suffixSum += nums[i];

            if (suffixSum == x) {
                answer = n - i;
                break;
            }
        }

        int targetSum = totalSum - x;

        int left = 0;
        int currentSum = 0;
        int longestSubarrayLength = -1;

        for (int right = 0; right < n; right++) {
            currentSum += nums[right];

            while (currentSum > targetSum && left <= right) {
                currentSum -= nums[left];
                left++;
            }

            if (currentSum == targetSum) {
                longestSubarrayLength =
                    max(longestSubarrayLength, right - left + 1);
            }
        }

        if (longestSubarrayLength != -1) {
            answer = min(answer, n - longestSubarrayLength);
        }

        return answer == INT_MAX ? -1 : answer;
    }
};