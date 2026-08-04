class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int lineLength = words[i].length();
            int j = i + 1;
            while (j < n &&
                   lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }
            int totalWords = j - i;
            string line;
            int letters = 0;
            for (int k = i; k < j; k++)
                letters += words[k].length();
            if (j == n || totalWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1)
                        line += " ";
                }
                while (line.length() < maxWidth)
                    line += " ";
            }
            else {

                int totalSpaces = maxWidth - letters;
                int gaps = totalWords - 1;
                int evenSpace = totalSpaces / gaps;
                int extra = totalSpaces % gaps;
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        line += string(evenSpace, ' ');
                        if (extra > 0) {
                            line += " ";
                            extra--;
                        }
                    }
                }
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};