//Memoization 
class Solution{
  int solve(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
      if(i==n-1) return triangle[i][j];
      if(dp[i][j]!=-1) return dp[i][j];  

      int down = solve(i+1,j,triangle,n,dp);
      int diag = solve(i+1,j+1,triangle,n,dp);

      return dp[i][j] = triangle[i][j] + min(down,diag);
  }
  int minimumPathSum(vector<vector<int>>& triangle, int n){
      vector<vector<int>> dp(n,vector<int> (n,-1));
      return solve(0,0,triangle,n,dp);
  }
}
//TC : O(N*N)
//SC : O(N*N) [DP array] + O(N) [Recursion Stack Space]

//Tabulation
class Solution2{
  int solve(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
      for(int j=0; j<n; j++) dp[n-1][j] = triangle[n-1][j];

      for(int i=n-2; i>=0; i--){
          for(int j=0; j<=i; j++){
              dp[i][j] = triangle[i][j] + min(dp[i+1][j+1], dp[i+1][j]);
          }
      }

      return dp[0][0];
  }
  int minimumPathSum(vector<vector<int>>& triangle, int n){
      vector<vector<int>> dp(n,vector<int> (n,-1));
      return solve(0,0,triangle,n,dp);
  }
}
//TC : O(N*N)
//SC : O(N*N) [DP array]

//Space optimized
class Solution3{
  int solve(vector<vector<int>>& triangle, int n){
      vector<int> prev(n,0); 
      for(int j=0; j<n; j++) prev[j] = triangle[n-1][j];
      for(int i=n-2; i>=0; i--){
          vector<int> cur(i+1,0);
          for(int j=0; j<=i; j++){
              cur[j] = triangle[i][j] + min(prev[j],prev[j+1]);
          }
          prev = cur;
      }
      return prev[0];
  }
  int minimumPathSum(vector<vector<int>>& triangle, int n){
      return solve(triangle,n);
  }
}
//Time Complexity : O(N*N)
//Space Complexity : O(1)
