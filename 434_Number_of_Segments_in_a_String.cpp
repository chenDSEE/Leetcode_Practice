class Solution {
public:
    int countSegments(string s) {
        int word_cnt = 0;
        for (int check = 0; check < s.size(); check++) {
            if (s[check] != ' ') {
                word_cnt++;
                while (check < s.size() && s[++check] != ' ');
            }
        }

        return word_cnt;
    }
};