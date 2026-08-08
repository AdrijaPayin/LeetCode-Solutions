class Solution {
public:
    static int minOperations(vector<string>& logs) {
        int depth = 0;
        for (auto& s : logs) {
            if (s == "../")
                depth -= (depth > 0);
            else if (s != "./")
                depth++;
        }
        return depth;
    }
};