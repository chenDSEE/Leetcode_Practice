class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        if (nums.size() < 3)
            return answer;
        
        std::sort(nums.begin(), nums.end());
        for (int target = 0; target < nums.size() - 2; target++) {
            if (nums[target] > 0)
                break;
            if (target > 0 && nums[target] == nums[target - 1])
                continue;
            
            int left = target + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[target] + nums[left] + nums[right];
                if (sum < 0)
                    while (left < right && nums[left] == nums[++left]);     // 'left' can not self-add in for-loop !
                else if (sum > 0)
                    while (left < right && nums[right] == nums[--right]);   // 'right' can not self-add in for-loop !
                else {
                    answer.push_back(vector<int> {nums[target], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[++left]);
                    while (left < right && nums[right] == nums[--right]);
                }

            } // end of while (left < right)
        }

        return answer;
    }
};