//Memoization
class Solution{
  int solve(int i, int j, vector<vector<int>>& dp){
      if(i==0 or j==0)
          return 1;
      if(dp[i][j]!=-1) return dp[i][j];

      int up = solve(i-1,j,dp);
      int left = solve(i,j-1,dp);

      return dp[i][j] = up + left;
  }

  int uniquePaths(int m, int n) {
      vector<vector<int>> dp(m,vector<int> (n,-1));
      return solve(m-1,n-1,dp);
  }
}
//Time Complexity : O(N*M)
//Space Complexity : O(N+M) [Recursion] + O(N*M) [DP array]

//Tabulation
class Solution2{
  int uniquePaths(int m, int n) {
      vector<vector<int>> dp(m,vector<int> (n,-1));
      dp[0][0] = 1;

      for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
              if(i==0 and j==0) continue;

              int up = i>0 ? dp[i-1][j] : 0;
              int left = j>0 ? dp[i][j-1] : 0;

              dp[i][j] = up+left;
          }
      }

      return dp[m-1][n-1];
  }
}
//Time Complexity : O(N*M)
//Space Complexity : O(N*M)
