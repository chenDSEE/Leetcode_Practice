class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() <= 0)
            return 0;

        vector<int> dp_status(obstacleGrid[0].size(), 0);


        for (int i = 0; i < obstacleGrid[0].size(); i++) {  // 更新一次，dp_status[0][col = 0]
            if (obstacleGrid[0][i] == 1)
                break;
            else
                dp_status[i] = 1;
        }

        for (int row = 1; row < obstacleGrid.size(); row++) {
            for (int col = 0; col < obstacleGrid[row].size(); col++) {
                if (obstacleGrid[row][col] == 1) {  
                    // 一定要现在前面，这样才能当 obstacleGrid[row][0] 的时候，
                    // 让接下来的全部 dp_status[row][0] 成为 0；只有这里能够改变 col = 0 时的 dp_status，
                    // 其他情况则是继承上面的 dp_status，所以一旦有障碍，永远都是 0
                    dp_status[col] = 0;

                } else if (col != 0) {  // col == 0 无法参与计算
                    dp_status[col] += dp_status[col - 1];
                }
            }
        }

        return dp_status[obstacleGrid[0].size() - 1];
    }
};


/* only initization one point */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0)); // 左边、上边多留一个空行作为初始情况
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1]) // 因为空行的缘故，要进行一定程度的偏移
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};

/* simplify version */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        vector<int> dp_status(obstacleGrid[0].size() + 1, 0);   // 多预留一个空格给 col - 1, 但是就过程中，这个空格不使用
        dp_status[1] = 1;   // 仅仅作为初始情况
        for (int row = 0; row < obstacleGrid.size(); row++) {
            for (int col = 1; col < dp_status.size(); col++) {
                if (obstacleGrid[row][col - 1] == 0) {
                    dp_status[col] += dp_status[col - 1];
                } else {
                    dp_status[col] = 0; // 这里无法到达，同时更新，保留这个无法到达的点带来的影响
                }
            }
        }

        return dp_status[dp_status.size() - 1];
    }
};