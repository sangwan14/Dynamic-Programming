//Memoization
class Solution{
  int solve(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp){
      if(j<0 or j>=m) return INT_MIN;
      if(i==n-1) return matrix[i][j];
      if(dp[i][j]!=-1) return dp[i][j];

      int down = solve(i+1,j,n,m,matrix,dp);
      int leftDiag = solve(i+1,j-1,n,m,matrix,dp);
      int rightDiag = solve(i+1,j+1,n,m,matrix,dp);

      return matrix[i][j] + max(down, max(leftDiag, rightDiag));
  }
  int getMaxPathSum(vector<vector<int>> &matrix)
  {
      int n = matrix.size();
      int m = matrix[0].size();
      vector<vector<int>> dp(n, vector<int> (m,-1));

      int maxPathSum = INT_MIN;
      for(int i=0; i<m; i++) maxPathSum = max(solve(0,i,n,m,matrix,dp),maxPathSum);

      return maxPathSum;
  }
}
//TC : O(N*M)
//SC : O(N*M) [DP array] + O(N) [Recursion Stack Space]

class Solution2{
  int solve(int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp){
      for(int j=0; j<m; j++) dp[n-1][j] = matrix[n-1][j];

      for(int i=n-2; i>=0; i--){
          for(int j=0; j<m; j++){
              int down = dp[i+1][j]; 
              int leftDiag = j>0 ? dp[i+1][j-1] : INT_MIN;
              int rightDiag = j+1<m ? dp[i+1][j+1] : INT_MIN;
              dp[i][j] = matrix[i][j] + max(down,max(leftDiag,rightDiag));
          }
      }

      return *max_element(dp[0].begin(),dp[0].end());
  }
  int getMaxPathSum(vector<vector<int>> &matrix)
  {
      int n = matrix.size();
      int m = matrix[0].size();
      vector<vector<int>> dp(n, vector<int> (m,-1));

      return solve(n,m,matrix,dp);
  }
}
//TC : O(N*M)
//SC : O(N*M) [DP array] 

//Space Optimized
class Solution3{
  int solve(int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp){
      vector<int> prev;
      prev.assign(matrix[n-1].begin(),matrix[n-1].end());

      for(int i=n-2; i>=0; i--){
          vector<int> cur(m,0);
          for(int j=0; j<m; j++){
              int down = prev[j];
              int leftDiag = j>0 ? prev[j-1] : INT_MIN;
              int rightDiag = j+1<m ? prev[j+1] : INT_MIN;

              cur[j] = matrix[i][j] + max(down, max(leftDiag, rightDiag));
          }
          prev = cur;
      }

      return *max_element(prev.begin(),prev.end());
  }
  int getMaxPathSum(vector<vector<int>> &matrix)
  {
      int n = matrix.size();
      int m = matrix[0].size();
      vector<vector<int>> dp(n, vector<int> (m,-1));

      return solve(n,m,matrix,dp);
  }
}
//TC : O(N*M)
//SC : O(1)
