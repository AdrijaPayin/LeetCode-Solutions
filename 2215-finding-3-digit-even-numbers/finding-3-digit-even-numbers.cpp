class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int, int> m;
        for (auto x : digits) m[x]++;

        for (int i = 100; i < 999; i += 2) {
            unordered_map<int, int> temp = m;
            int n = i, check = 1;

            while (n) {
                if (temp[n % 10] == 0)  check = 0;
                
                temp[n % 10]--;
                n /= 10;
            }

            if (check) ans.push_back(i);
        }
        
        return ans;
    }
};