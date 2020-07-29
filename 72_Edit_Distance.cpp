/* Two-End BFS Version */




/* DP Version */
/**
 *  (一)、当 word1[i] == word2[j] 时,由于遍历到了 i 和 j, 说明 word1 的 0 ~ i-1 和 word2 的 0 ~ j-1 的匹配结果已经生成,
 *  由于当前两个字符相同,因此无需做任何操作,dp[i][j]=dp[i-1][j-1]
 *  (二)、当word1[i]!=word2[j]时,可以进行的操作有3个:
 *        ① 替换操作:可能word1的0~i-1位置与word2的0~j-1位置的字符都相同,
 *             只是当前位置的字符不匹配,进行替换操作后两者变得相同,
 *             所以此时dp[i][j]=dp[i-1][j-1]+1(这个加1代表执行替换操作)
 *        ②删除操作:若此时word1的0~i-1位置与word2的0~j位置已经匹配了,
 *           此时多出了word1的i位置字符,应把它删除掉,才能使此时word1的0~i(这个i是执行了删除操作后新的i)
 *           和word2的0~j位置匹配,因此此时dp[i][j]=dp[i-1][j]+1(这个加1代表执行删除操作)
 *        ③插入操作:若此时word1的0~i位置只是和word2的0~j-1位置匹配,
 *            此时只需要在原来的i位置后面插入一个和word2的j位置相同的字符使得
 *            此时的word1的0~i(这个i是执行了插入操作后新的i)和word2的0~j匹配得上,
 *            所以此时dp[i][j]=dp[i][j-1]+1(这个加1代表执行插入操作)
 *        ④由于题目所要求的是要最少的操作数:所以当word1[i] != word2[j] 时,
 *            需要在这三个操作中选取一个最小的值赋格当前的dp[i][j]
 *  (三)总结:状态方程为:
 *  if(word1[i] == word2[j]):
 *        dp[i][j] = dp[i-1][j-1]
 *  else:
 *         min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp_status[sub_string: 0->word1][sub_string: 0->word2]
        // dp_status[][] 里面记录的是：在将 W1 变成 W2 的过程中，需要针对 W1 进行多少次操作？
        // dp_status[i][j] 表示：字符串 W1[0:i] 完全变成字符串 W2[0:j] 需要多少步

        // 重点，假设前面的 w1[0 ~ i-1] 已经完成变成了 w2[0 ~ j-1] 时，耗费的步数是 dp_status[i - 1][j - 1]
        // 那我当前层就是处理 w1[i] 跟 w2[j] 的关系
        vector<vector<int>> dp_status(word1.size() + 1, vector<int> (word2.size() + 1, 0));
        for (int row = 0; row < dp_status.size(); row++) {
            dp_status[row][0] = row;
        }
        for (int col = 0; col < dp_status[0].size(); col++) {
            dp_status[0][col] = col;
        }

        for (int pos_1 = 1; pos_1 < dp_status.size(); pos_1++) {
            for (int pos_2 = 1; pos_2 < dp_status[pos_1].size(); pos_2++) {
                if (word1[pos_1 - 1] == word2[pos_2 - 1]) {
                    dp_status[pos_1][pos_2] = dp_status[pos_1 - 1][pos_2 - 1];
                    
                } else {
                    dp_status[pos_1][pos_2] = 1 + min(dp_status[pos_1 - 1][pos_2 - 1], 
                                                      min(dp_status[pos_1 - 1][pos_2], dp_status[pos_1][pos_2 - 1]));
                }
            }
        }

        return dp_status.back().back();
    }
};