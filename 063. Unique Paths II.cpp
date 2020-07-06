#define fi first
#define se second

typedef pair<int, int> pii;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // if(obstacleGrid == null) return 0;
        if(obstacleGrid[0][0] == 1) return 0;
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        int dp[n+1][m+1];
        dp[0][0] = 1;
        for(int i = 1; i < n; i++) {
            dp[i][0] = (obstacleGrid[i][0] == 1) || (dp[i-1][0] == 0) ? 0 : 1;
        }
        for(int j = 1; j < m; j++) {
            dp[0][j] = (obstacleGrid[0][j] == 1) || (dp[0][j-1] == 0) ? 0 : 1;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j] = (obstacleGrid[i][j] == 0) ? dp[i-1][j]+dp[i][j-1] : 0;
            }
        }
        return dp[n-1][m-1];
    }
};