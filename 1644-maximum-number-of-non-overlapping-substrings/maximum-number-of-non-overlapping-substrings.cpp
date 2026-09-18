class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; i++) {
            int ind = s[i] - 'a';
            if (first[ind] == -1)
                first[ind] = i;
            last[ind] = i;
        }

        vector<pair<int, int>> intervals;

        for (int i = 0; i < 26; i++) {
            if (first[i] == -1)
                continue;

            int l = first[i], r = last[i], ok = 1;

            for (int j = l; j <= r; j++) {
                int currind = s[j] - 'a';

                if (first[currind] < l) {
                    ok = 0;
                    break;
                }

                r = max(r, last[currind]);
            }

            if (ok)
                intervals.push_back({r, l});
        }

        sort(intervals.begin(), intervals.end());

        int prev = -1;
        vector<string> ans;

        for (auto it : intervals) {
            int l = it.second, r = it.first;

            if (prev == -1 || prev < l) {
                ans.push_back(s.substr(l, r - l + 1));
                prev = r;
            }
        }

        return ans;
    }
};