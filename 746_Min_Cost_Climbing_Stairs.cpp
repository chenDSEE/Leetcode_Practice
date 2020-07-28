/* 状态压缩 DP */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 0) {
            return 0;
        }

        // 到达当前 step 的 cost 总数
        int f1 = cost[0], f2 = cost[1];
        for (int step = 2; step < cost.size(); step++) {
            int curr = cost[step] + min(f1, f2);
            f1 = f2;
            f2 = curr;
        }

        return min(f1, f2);
    }
};



/* DP Version */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 0) {
            return 0;
        }

        // 到达当前 step 的 cost 总数
        vector<int> dp_status(cost.size(), 0);
        dp_status[0] = cost[0];
        dp_status[1] = cost[1];
        for (int step = 2; step < cost.size(); step++) {
            dp_status[step] = cost[step] + min(dp_status[step - 1], dp_status[step - 2]);
        }

        return min(dp_status[dp_status.size() - 1], dp_status[dp_status.size() - 2]);
    }
};