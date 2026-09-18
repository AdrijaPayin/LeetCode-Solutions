
class Solution {
public:
    bool halvesAreAlike(std::string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt = 0;
        int mid = s.length() / 2;

        for (int i = 0; i < mid; i++) {
            char c1 = s[i];
            char c2 = s[mid + i];

            if (vowels.count(c1)) cnt++;
            if (vowels.count(c2)) cnt--;
        }

        return cnt == 0;
    }
};

