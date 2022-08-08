//Memoization Approach
class Solution{
  int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
      if(i==0 and j==0) return grid[0][0];
      if(i<0 or j<0) return INT_MAX;
      if(dp[i][j]!=-1) return dp[i][j];

      int up = solve(i-1,j,grid,dp);
      int down = solve(i,j-1,grid,dp);
      return dp[i][j] = grid[i][j] + min(up,down);
  }
  int minSumPath(vector<vector<int>> &grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>> dp(n,vector<int> (m,-1));
      return solve(n-1,m-1,grid,dp);
  }
}
//Time Complexity : O(N*M)
//Space Complexity : O(N*M) [DP array] + O((N-1) + (M-1)) [Stack Space]

//Tabulation Approach
class Solution2{
  int solve(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
      dp[0][0] = grid[0][0];
      for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
              if(i==0 and j==0) continue;
              int up = i>0 ? dp[i-1][j] : INT_MAX;
              int left = j>0 ? dp[i][j-1] : INT_MAX;
              dp[i][j] = grid[i][j] + min(up,left);
          }
      }
      return dp[n-1][m-1];
  }
  int minSumPath(vector<vector<int>> &grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>> dp(n,vector<int> (m,-1));
      return solve(n,m,grid,dp);
  }
}
//Time Complexity : O(N*M)
//Space Complexity : O(N*M)

//Space Optimized Approach [Optimal]
class Solution3{
  int solve(int n, int m, vector<vector<int>>& grid){
      vector<int> prev(m,0);
      for(int i=0; i<n; i++){
          vector<int> cur(m,0);
          for(int j=0; j<m; j++){
              if(i==0 and j==0) {
                  cur[0] = grid[0][0];
                  continue;
              }
              int up = i>0 ? prev[j] : INT_MAX;
              int left = j>0 ? cur[j-1] : INT_MAX;
              cur[j] = grid[i][j] + min(up,left);
          }
          prev = cur;
      }
      return prev[m-1];
  }
  int minSumPath(vector<vector<int>> &grid) {
      int n = grid.size();
      int m = grid[0].size();
      return solve(n,m,grid);
  }
}
//Time Complexity : O(N*M)
//Space Complexity : O(N)
