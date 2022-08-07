class Solution{
  int solve(int ind, int act, int n, vector<vector<int>>& points, vector<vector<int>>& dp){
      if(ind==n) return 0;
      if(dp[ind][act]!=-1) return dp[ind][act];

      int res = 0;
      for(int i=0; i<=2; i++){
          if(act!=i) res = max(res,solve(ind+1,i,n,points,dp));
      }

      return dp[ind][act] = points[ind][act] + res;

  }

  int ninjaTraining(int n, vector<vector<int>> &points)
  {
      vector<vector<int>> dp(n,vector<int> (3,-1));

      int res = 0; 
      for(int i=0; i<=2; i++){
          res = max(res,solve(0,i,n,points,dp));
      }

      return res;
  }
}
