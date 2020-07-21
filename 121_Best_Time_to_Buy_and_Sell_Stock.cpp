/* DP Version */





// 找到最小值，计算价格差
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        int min_val = INT_MAX;
        int max_sum = 0;

        // 实际上这不仅仅是做了一次交易
        // 而是不断尝试新一天的价格 - 当前遇到过的最小值，看看能不能刷新 max_sum
        // max_sum 实际上是被不断增量更新出来的
        for (int curr : prices) {
            min_val = curr < min_val ? curr : min_val;
            max_sum = max_sum < (curr - min_val) ? curr - min_val : max_sum;
        }

        return max_sum;
    }
};