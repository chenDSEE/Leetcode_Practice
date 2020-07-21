/* DP Version */



// 一次遍历
// 虽然题目要求不能同一天进行交易，但是实际上对于程序来说是没有关系的
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        int sum = 0;
        for (int day = 1; day < prices.size(); day++) {
            if (prices[day] > prices[day - 1]) {
                sum += prices[day] - prices[day - 1];
                // 既然长期持有也是赚钱，短期持有也是赚钱，还不如每天都买卖，每天锁定利润
            }
        }

        return sum;
    }
};