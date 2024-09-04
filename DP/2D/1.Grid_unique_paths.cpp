class Solution {
public:
    // int findPath(int i, int j, vector<vector<int>>& dp){
        //base case
        if(i==0 || j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        //do all stuffs on index
        int left = findPath(i-1,j,dp);
        int up = findPath(i,j-1,dp);
        //add them to find total path
        return dp[i][j] = left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return findPath (m-1,n-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i = 0; i < m; i++) {
        dp[i][0] = 1;
        }
    
        for(int j = 0; j < n; j++) {
        dp[0][j] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1;j<n; j++){
                int right = dp[i][j-1];
                int down = dp[i-1][j];
                dp[i][j] = right + down;
            }
        }
        return dp[m-1][n-1];
    }
};
