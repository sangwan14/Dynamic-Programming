//Memoization
class Solution{
  int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid,  vector<vector<vector<int>>> &dp){
      if(j1<0 or j2<0 or j1>=c or j2>=c) return -1e8;
      if(i==r-1){
          if(j1==j2) return grid[i][j1];
          else return grid[i][j1] + grid[i][j2];
      }
      if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

      int res = -1e8;
      for(int dj1=-1; dj1<=1; dj1++){
          for(int dj2=-1; dj2<=1; dj2++){
              int val = solve(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
              if(j1==j2) val += grid[i][j1];
              else val += grid[i][j1] + grid[i][j2];
              res = max(res,val);
          }
      }

      return dp[i][j1][j2] = res;
  }

  int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
      vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c,-1)));
      return solve(0,0,c-1,r,c,grid,dp);
  }
}
//TC : O(N*M*M*3)
//SC :  O(N*M*M) [DP array] + O(N) [Recursion Stack Space] 

//Tabulation
class Solution2{
  int solve(int r, int c, vector<vector<int>> &grid,  vector<vector<vector<int>>> &dp){
      for(int j1=0; j1<c; j1++){
          for(int j2=0; j2<c; j2++){
              if(j1==j2) dp[r-1][j1][j2] = grid[r-1][j1];
              else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
          }
      }

      for(int i=r-2; i>=0; i--){
          for(int j1=0; j1<c; j1++){
              for(int j2=0; j2<c; j2++){
                  int res = -1e8;
                  for(int dj1=-1; dj1<=1; dj1++){
                      for(int dj2=-1; dj2<=1; dj2++){
                          int val = -1e8;
                          if(j1+dj1>=0 and j2+dj2>=0 and j1+dj1<c and j2+dj2<c){
                              val = dp[i+1][j1+dj1][j2+dj2];
                              if(j1==j2) val+= grid[i][j1];
                              else val+= grid[i][j1] + grid[i][j2];
                          }  
                          res = max(res,val);
                      }
                  }
                  dp[i][j1][j2] = res;
              }
          }
      }

      return dp[0][0][c-1];
  }

  int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
      vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c,-1)));
      return solve(r,c,grid,dp);
  }
}
//TC : O(N*M*M*3)
//SC : O(N*M*M) [DP array]
