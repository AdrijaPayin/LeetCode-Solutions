class Solution {
public:
    int sumOfDigits(int num) {
        int sum = 0;

        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;

    }
    int countLargestGroup(int n) {
        vector<int> sumSize(37, 0);
        int maxGroupSize = INT_MIN;

        for (int num = 1; num <= n; num++) {
            int sum = sumOfDigits(num);
            sumSize[sum]++;
            maxGroupSize = max(maxGroupSize, sumSize[sum]);
        }

        int totalCountMaxGroup = 0;

        for (int i = 1; i < 37; i++) {

            if (sumSize[i] == maxGroupSize)
                totalCountMaxGroup++;
        }
        return totalCountMaxGroup;
    }
};