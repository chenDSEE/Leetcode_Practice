/* 数组取代 stack */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) { // 剪枝
            return false;
        }

        long rev_num = 0;
        int backup = x;
        while (backup != 0) {
            rev_num = rev_num * 10 + backup % 10;
            backup /= 10;
        }

        return x == rev_num;
    }
};



/* my Stack Version */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        stack<int> cache;
        int tmp = x;
        while (x != 0) {
            cache.push(x % 10);
            x = x / 10;
        }

        while (!cache.empty()) {
            if (cache.top() != (tmp % 10)) {
                return false;
            }
            cache.pop();
            tmp = tmp / 10;
        }

        return true;
    }
};