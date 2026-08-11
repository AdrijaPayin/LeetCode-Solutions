class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        int count = 0;

        for (char c : allowed) st.insert(c);

        for (int i = 0; i < words.size(); i++) {
            bool consistent = true;

            for (char c : words[i]) {
                if (st.find(c) == st.end()) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) count++;
        }
        return count;
    }
};