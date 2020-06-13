class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (target == nums[mid])
                return mid;

            if (nums[mid] >= nums[left]) {  // 先判断在那一截上面
                // 在根据对应截的单调性，看看 target 在不在这一截中，再决定左右边界的移动方案
                if (target >= nums[left] && target < nums[mid]) 
                    right = mid - 1;
                else
                    left = mid + 1;

            } else {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;

            }

        }   // end of while

        return -1;
    }
};