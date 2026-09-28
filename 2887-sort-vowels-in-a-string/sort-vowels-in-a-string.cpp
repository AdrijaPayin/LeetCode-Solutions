class Solution {
public:
    string sortVowels(string s) {
        string vowels = "";

        for (char c : s) {
            if (string("AEIOUaeiou").find(c) != string::npos) 
                vowels += c;
        }

        sort(vowels.begin(), vowels.end());

        int j = 0;
        for (char &c : s) {
            if (string("AEIOUaeiou").find(c) != string::npos) 
                c = vowels[j++];      
        }

        return s;
    }
};