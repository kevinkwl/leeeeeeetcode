class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int curlen = 0, begin = 0;
        for (int i = 0; i < words.size(); i++) {
            // if adding the word would make currrent line too long, justify current line and leave the word to next line
            // check curlen != 0 because a single word will never be too long for one line
            if (curlen + 1 + words[i].length() > maxWidth && curlen != 0) {
                string line = words[begin];
                int extra = maxWidth - curlen;      // extra : extra whitespaces we need to distribute
                int gaps = i - begin - 1;
                if (gaps == 0) {        // if gaps == 0, all extra added to the end
                    res.push_back(line + string(maxWidth - curlen, ' '));
                } else {
                    int even_extra = extra / gaps;  // firstly distribute spaces evenly to all gaps
                    int more_extra = extra % gaps;  // the remaining spaces are distributed one by one from the left
                    for (int j = 1; j <= gaps; j++) {
                        if (j <= more_extra)
                            line += ' ';
                        line += string(even_extra + 1, ' ') + words[begin+j];
                    }
                    res.push_back(line);
                }
                begin = i;
                curlen = words[i].length();
            } else {
                curlen += words[i].length();
                if (i != begin)
                    curlen++;
            }
        }
        if (words.size() > 0) {
            string line = words[begin];
            for (int j = begin+1; j < words.size(); j++)
                line += ' ' + words[j];
            res.push_back(line + string(maxWidth - line.length(), ' '));
        }
        return res;
    }
};
