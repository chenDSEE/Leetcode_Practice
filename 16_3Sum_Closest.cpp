class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return 0;
        }

        int close = INT_MAX;
        int answer = 0;
        sort(nums.begin(), nums.end());
        for (int index = 0; index < nums.size() - 2; index++) {
            if (index > 0 && nums[index] == nums[index - 1]) {
                continue;
            }

            int left = index + 1, right = nums.size() - 1;
            int prev_sum = 0;
            while (left < right) {
                int sum = nums[index] + nums[left] + nums[right];
                int distance = target < sum ? sum - target : target - sum;
                if (distance < close) {
                    close = distance;
                    answer = sum;
                }

                if (sum > target) {
                    while (left < right && nums[right] == nums[--right]);

                } else if (sum < target) {
                    while (left < right && nums[left] == nums[++left]);

                } else {
                    return answer;
                }
            }
        }

        return answer;
    }
};