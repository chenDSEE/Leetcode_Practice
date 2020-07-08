/* Selection Sort - 选择排序 - O(n^2) */
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int cnt = 0; cnt < nums.size(); cnt++) {
            int min_index = cnt;
            for (int check = cnt + 1; check < nums.size(); check++) {
                if (nums[min_index] > nums[check]) {
                    min_index = check;
                }
            }

            int tmp = nums[cnt];
            nums[cnt] = nums[min_index];
            nums[min_index] = tmp;
        }

        return nums;
    }
};

/* Insertion Sort - 插入排序 - O(n^2) */
// 先暂存这个每一个 nums[check]，然后将之前的元素逐个后移，留出空位，插入到合理的顺序中
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int unsort_index = 1; unsort_index < nums.size(); unsort_index++) {
            int tmp = nums[unsort_index];
            int move_index = unsort_index;
            while (move_index > 0 && tmp < nums[move_index - 1]) {
                nums[move_index] = nums[move_index - 1];
                move_index--;
            }

            nums[move_index] = tmp; // insert the num[unsort_index] into the right pos
        }

        return nums;
    }
};