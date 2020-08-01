/* 贪心 */




/* DP(deque 优化)*/
// 实际上就是对 普通 DP 的疯狂剪枝
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;
        }

        vector<int> dp(nums.size(), 0);
        deque<int> window;  // 实际上是维护了一个单调队列，优先从最小的步数来更新 dp，明显过大的就直接扔了

        dp[0] = 0;
        for (int cnt = 0; cnt < dp.size(); cnt++) {
            // window 中前面的既然办法触碰到我这个 dp，那以后都没有必要检测它了，直接扔了
            while (!window.empty() && nums[window.front()] + window.front() < cnt) {
                window.pop_front();
            }

            // 每次更新当前 dp，只用 能到 dp[cnt] 且 最小的那个 来对 dp[cnt] 进行更新
            if (!window.empty()) {
                dp[cnt] = dp[window.front()] + 1;
            }

            // 扔掉部署前面比我多的 dp 点，日后直接不用检查它们
            // 既然能够用更少的步数到达我这里，那何必再去算一次比我更多，还在我前面的呢？
            while (!window.empty() && dp[window.back()] > dp[cnt]) {
                window.pop_back();
            }

            window.push_back(cnt);
        }

        return dp.back();
    }
};






/* DP Version - O(n^2) 超时 */
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;
        }

        vector<int> dp(nums.size(), INT_MAX - 1);
        dp[0] = 0;
        for (int cnt = 0; cnt < dp.size(); cnt++) {
            int jump_size = nums[cnt];
            for (int step = 0; step <= jump_size && cnt + step < dp.size(); step++) {
                dp[cnt + step] = min(dp[cnt + step], dp[cnt] + 1);
            }
        }

        return dp.back();
    }
};