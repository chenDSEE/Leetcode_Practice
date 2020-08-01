/* 贪心 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;

        int prev_jump_pos = nums.size() - 1;
        for (int curr_pos = nums.size() - 1; curr_pos >= 0; curr_pos--) {
            if (nums[curr_pos] + curr_pos >= prev_jump_pos)
                prev_jump_pos = curr_pos;

        }

        return prev_jump_pos == 0 ? true : false;
    }
};


/* DP 剪枝 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) {
            return true;
        }

        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        for (int cnt = 0; cnt < dp.size(); cnt++) {
            for (int prev = cnt - 1; prev >= 0; prev--) {
                /**
                 * 为什么这样从后往前可以降低时间复杂度？
                 * 因为当这组数据长度变大的时候，跟 nums[cnt]\dp[cnt] 越接近的自然越快得到答案
                 * 你想想嘛，跟 nums[cnt]\dp[cnt] 只差一步的，自然是从他开始向左边找比较快啊
                 */
                if (dp[prev] == true && nums[prev] + prev >= cnt) {
                    dp[cnt] = true;
                    break;
                }
            }
        }

        return dp.back();
    }
};


/* 从前往后 DP O(n^2) 超时 */
// 毕竟你这个是要老老实实的从前往后刷写的，没办法剪枝
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }
        vector<bool> dp(nums.size(), false);

        dp[0] = true;
        // 当前节点是否可达，这是个很重要的判断
        for (int cnt = 0; cnt < dp.size() && dp[cnt] == true; cnt++) {
            int jump_size = nums[cnt];
            for (int step = 0; step <= jump_size && cnt + step < dp.size(); step++) {
                dp[cnt + step] = true;
            }
        }

        return dp.back();
    }
};