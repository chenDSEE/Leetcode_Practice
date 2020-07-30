/* 状态压缩 DP */
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') {
            return 0;
        }

        int prev = 1, curr = 1;
        for (int index = 1; index < s.size(); index++) {
            int tmp = 0;
            if (s[index] == '0') {
                if (s[index - 1] == '1' || s[index - 1] == '2') {
                    tmp = prev;

                } else {
                    return 0;
                }

            } else {
                tmp = curr;
                if (s[index - 1] == '1' || (s[index - 1] == '2' && s[index] <= '6' && s[index] >= '0')) {
                    tmp += prev;
                }
            }

            prev = curr;
            curr = tmp;
        }

        return curr;
    }
};






/* DP Version */
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') {
            return 0;
        }

        vector<int> dp_status(s.size() + 1, 0);
        dp_status[0] = 1;   // for dp_status[2]
        dp_status[1] = 1;   // s[0] self decode

        for (int cnt = 2, index = 1; cnt < dp_status.size(); cnt++, index++) {
            if (s[index] == '0') {    // 0 自己本身没有办法解码，只能跟前面的一起解码（01 无法解码）
                if (s[index - 1] == '1' || s[index - 1] == '2') {
                    dp_status[cnt] = dp_status[cnt - 2];

                } else {
                    return 0;
                }

            } else {
                // 一定能够自己本身解码，剩下的就是能不能跟前面的一起解码
                dp_status[cnt] = dp_status[cnt - 1];

                if (s[index - 1] == '1' || (s[index - 1] == '2' && s[index] <= '6' && s[index] >= '0')) {
                    dp_status[cnt] += dp_status[cnt - 2];
                }
            }
        }

        return dp_status.back();
    }
};


// 还行，简洁一些, not my Version

int numDecodings(string s) {
    // empty string or leading zero means no way
    if (!s.size() || s.front() == '0') return 0;

    // r1 and r2 store ways of the last and the last of the last
    int r1 = 1, r2 = 1;

    for (int i = 1; i < s.size(); i++) {    // 遇上 0 也不直接返回，就直接置 0，直接拖垮整体
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;
        
        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }

        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }

    return r1;
}