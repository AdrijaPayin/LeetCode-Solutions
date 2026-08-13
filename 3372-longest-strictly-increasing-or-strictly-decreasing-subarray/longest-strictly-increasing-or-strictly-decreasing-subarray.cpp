class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;

        int curr = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                curr++;
            else
                curr = 1;

            inc = max(inc, curr);
        }

        curr = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                curr++;
            else
                curr = 1;

            dec = max(dec, curr);
        }

        return max(inc, dec);
    }
};