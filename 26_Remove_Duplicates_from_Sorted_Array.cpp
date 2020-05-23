class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, cnt = 0;
        nums.push_back(INT_MAX);
        while (i < nums.size() - 1) {
            nums[cnt++] = nums[i];
            while (nums[i] == nums[++i]);
        } // end of while (i < nums.size() - 1)

        nums.pop_back();
        return cnt;
    }
};

/**
 * if you want to use this 'while (nums[i] == nums[++i]);', you have to code 'nums.push_back(INT_MAX);' !
 * This is diff with 3sum !
 * In 3sum, 'while (left < right)' , what more the 'nums[++left]' will not overflow, beause right start at the position nums[num.size() - 1]
 * therefore 'left < right' make sure 'nums[++left]' will not overflow!
 * 
 * BUT In this, you can not use 'i < nums.size() - 1' to make sure 'nums[++i]' will not overflow !
 * If you do so, there will be an endless-loop ! For i have no way to self-add to over 'i < nums.size()' !
 * 
 * If you want to make use of the last one element in vector:
 * 1. make sure '++i' will not overflow;
 * 2. make sure you can self-add to jump out of the loop;
 * 
 * EXAMPLE:
 * 1. while (nums[i] == nums[++i]); you will overflow;
 * 2. while (i < nums.size() && nums[i] == nums[++i]); you can not make i self-add to 'i >= nums.size()';
*/




class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        for (int i : nums) {
            if (cnt == 0 || i > nums[cnt - 1])  // you can make use of '||' to skip the first situation
                nums[cnt++] = i;
        }

        return cnt;
    }
};


