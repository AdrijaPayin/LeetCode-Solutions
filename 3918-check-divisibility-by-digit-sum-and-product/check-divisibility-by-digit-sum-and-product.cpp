class Solution {
public:
    bool checkDivisibility(int n) {
        int product = 1;
        int sum = 0;
        int num = n;

        while (num > 0) {
            int rem = num % 10;

            sum += rem;
            product *= rem;

            num /= 10;
        }

        int total = product + sum;

        return n % total == 0;
    }
};