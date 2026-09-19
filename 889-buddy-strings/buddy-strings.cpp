class Solution {
public:
    bool checkFreq(string s) {
        int arr[26] = {0};

        for (char c : s) {
            arr[c - 'a']++;
            if (arr[c - 'a'] > 1)
                return true;
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        if (s == goal)
            return checkFreq(s);

        vector<int> idx;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i])
                idx.push_back(i);
        }

        if (idx.size() != 2)
            return false;

        swap(s[idx[0]], s[idx[1]]);

        return s == goal;
    }
};