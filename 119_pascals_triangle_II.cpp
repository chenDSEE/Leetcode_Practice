/* DP 反向填充（简洁）（not my Version !!!） */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);

        res[0] = 1;
        for (int row = 1; row < rowIndex + 1; row++) {
            for (int cnt = row; cnt >= 1; cnt--) {
                res[cnt] += res[cnt - 1];
            }
        }
        
        return res;
    }
};


/* 状态压缩 DP */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return vector<int> {};
        }

        vector<int> dp(rowIndex + 1, 0);
        dp[0] = 1;
        for (int level = 1; level <= rowIndex + 1; level++) {
            int prev = 1;
            for (int cnt = 1; cnt < level; cnt++) {
                int tmp = dp[cnt];
                dp[cnt] = prev + dp[cnt];
                prev = tmp;
            }
//            dp[0] = 1, dp[level - 1] = 1;
        }

        return dp;
    }
};