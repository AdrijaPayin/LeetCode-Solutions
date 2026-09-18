class Solution {
public:
    bool checkIfPangram(string sentence) {
        int size = unordered_set<char>(sentence.begin(), sentence.end()).size();

        return size == 26;
    }
};