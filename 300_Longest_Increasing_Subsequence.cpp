



/* DP Version - O(n^2) */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        vector<int> dp_status(nums.size(), 1);  // 自己就能够成为一个序列，初始状态自然是 1 咯
        int max_val = dp_status[0];
        for (int curr = 0; curr < dp_status.size(); curr++) {   // pick curr(curr_last_one) in nums
            for (int sub = 0; sub < curr; sub++) {
                if (nums[curr] > nums[sub]) {
                    dp_status[curr] = max(dp_status[curr], dp_status[sub] + 1);
                    max_val = max(max_val, dp_status[curr]);
                }
            }
        }

        return max_val;
    }
};