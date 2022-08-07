//Memoization
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
};
//Time Complexity : O(N*3*3)
//Space Complexity : O(N*3)

//Tabulation
class Solution2{
  int ninjaTraining(int n, vector<vector<int>> &points)
  {
      vector<vector<int>> dp(n,vector<int> (3,0));
      dp[0][0] = max(points[0][1], points[0][2]);
      dp[0][1] = max(points[0][0], points[0][2]);
      dp[0][2] = max(points[0][0], points[0][1]);

      for(int day=1; day<n; day++){
          for(int last=0; last<=2; last++){
              for(int act=0; act<=2; act++){
                  if(act!=last) dp[day][last] = max(dp[day][last], points[day][act] + dp[day-1][act]);
              }
          }
      }

      return max(dp[n-1][0],dp[n-1][1]);
  }
};
//Time Complexity : O(N*3*3)
//Space Complexity : O(N*3)

//Space Optimized 
class Solution3{
    int ninjaTraining(int n, vector<vector<int>>& points)
  {
      vector<int> prev(3);
      prev[0] = max(points[0][1],points[0][2]);
      prev[1] = max(points[0][0],points[0][2]);
      prev[2] = max(points[0][1],points[0][0]); 

      for(int day=1; day<n; day++){
          vector<int> cur(3);
          cur[0] = points[day][0] + prev[0];
          cur[1] = points[day][1] + prev[1];
          cur[2] = points[day][2] + prev[2];

          prev[0] = max(cur[1],cur[2]);
          prev[1] = max(cur[0],cur[2]);
          prev[2] = max(cur[0],cur[1]); 
      }

      return max(prev[0],prev[1]);
  }
};  
