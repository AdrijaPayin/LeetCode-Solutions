class Solution {
public:
    bool check(string word, unordered_set<string>& st, unordered_map<string, bool>& memo) {

        if (memo.count(word)) return memo[word];

        int n = word.size();

        for (int i = 1; i < n; i++) {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i);

            if (st.count(prefix) && (st.count(suffix) || check(suffix, st, memo))) {
                return memo[word] = true;
            }
        }

        return memo[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> st;

        for (string& word : words) st.insert(word);

        for (string& word : words) {
            st.erase(word);

            unordered_map<string, bool> memo;

            if (check(word, st, memo)) ans.push_back(word);

            st.insert(word);
        }

        return ans;
    }
};