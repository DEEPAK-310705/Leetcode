class Solution {
public:
    int lengthOfLastWord(string s) {
        int maxLength = 0;
        int i = s.length()-1;

        while(i >= 0 && s[i] ==' '){
            i--;
        }
        while(i >= 0 && s[i] !=' '){
            maxLength++;
            i--;
        }
        return maxLength;
    }
};