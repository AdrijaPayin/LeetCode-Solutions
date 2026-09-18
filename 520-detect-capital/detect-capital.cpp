class Solution {
public:
    bool detectCapitalUse(string word) {
    int cnt = 0;
    for( char c : word){
        if (c == toupper(c)) cnt ++;
    }   

    if (cnt ==  word.size()) return true;
    else if (cnt == 0) return true;
    else if (cnt == 1 && word[0]==toupper(word[0])) return true;
    else return false;  
    }
};