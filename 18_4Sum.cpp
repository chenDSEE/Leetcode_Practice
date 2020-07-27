class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        if (nums.size() < 4) {
            return answer;
        }

        sort(nums.begin(), nums.end());
        for (int cnt = 0; cnt < nums.size(); cnt++) {
            // 第一个默认需要进行处理
            if (cnt > 0 && nums[cnt] == nums[cnt - 1]) {
                continue;
            }

            for (int sub = cnt + 1; sub < nums.size(); sub++) {
                // 第一个默认需要进行处理
                if (sub > cnt + 1 && nums[sub] == nums[sub - 1]) {
                    continue;
                }

                int left = sub + 1, right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[cnt] + nums[sub] + nums[left] + nums[right];
                    if (sum > target) {
                        while (left < right && nums[right] == nums[--right]);

                    } else if (sum < target) {
                        while (left < right && nums[left] == nums[++left]);

                    } else {
                        answer.emplace_back(vector<int> {nums[cnt], nums[sub], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[++left]);
                        while (left < right && nums[right] == nums[--right]);
                    }
                }
            }
        }

        return answer;
    }
};