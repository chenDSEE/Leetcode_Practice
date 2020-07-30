/* BFS + 贪心 */




/* DP Version */
// 自己生成 coins change 里面的 coins，然后这个问题就是 coins change 了
class Solution {
public:
    int numSquares(int n) {
        vector<int> inter_val;
        for (int index = 0; index * index <= n; index++) {
            inter_val.emplace_back(index * index);
        }

        vector<int> dp_status(n + 1);
        for (int index = 0; index < dp_status.size(); index++) {
            dp_status[index] = index;
        }

        for (int curr = 1; curr <= n; curr++) {
            for (int type = 1; type < inter_val.size(); type++) {
                if (curr >= inter_val[type]) {
                    dp_status[curr] = min(dp_status[curr - inter_val[type]] + 1, dp_status[curr]);
                }
            }
        }

        return dp_status.back();
    }
};