//Memoization
class Solution{
  int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
      if(ind==0){
          return (arr[ind]==target) + (target==0);
      }

      if(dp[ind][target]!=-1)
          return dp[ind][target];

      int notTaken = findWaysUtil(ind-1,target,arr,dp);

      int taken = 0;
      if(arr[ind]<=target)
          taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);

      return dp[ind][target] = notTaken + taken;
  }

  int findWays(vector<int> &num, int k){
      int n = num.size();
      vector<vector<int>> dp(n,vector<int>(k+1,-1));
      return findWaysUtil(n-1,k,num,dp);
  }
};
//TC : O(N*K)
//SC : O(N*K) [DP array] + O(N) [Stack Space]

//Tabulation
class Solution2{
  int findWays(vector<int> &num, int k){
       int n = num.size();

      vector<vector<int>> dp(n,vector<int>(k+1,0));
      
      dp[0][0] = 1;
    
      if(num[0]<=k)
          dp[0][num[0]] += 1;
    
      for(int ind = 1; ind<n; ind++){
          for(int target= 0; target<=k; target++){

              int notTaken = dp[ind-1][target];

              int taken = 0;
                  if(num[ind]<=target)
                      taken = dp[ind-1][target-num[ind]];

              dp[ind][target]= notTaken + taken;
          }
      }

      return dp[n-1][k];
  }
};
//TC : O(N*K)
//SC : O(N*K) [DP array]

//Space Optimized
class Solution{
  int findWays(vector<int> &num, int k)
  {
      int n = num.size();

      vector<int> prev(k+1,0);

      prev[0] = 1;

      for(int ind = 0; ind<n; ind++){
          vector<int> cur(k+1,0);
          for(int target = 0; target<=k; target++){

              int notTaken = prev[target];

              int taken = 0;
                  if(num[ind]<=target)
                      taken = prev[target-num[ind]];

              cur[target] = notTaken + taken;
          }

          prev = cur;
      }

      return prev[k];
  }
};
//TC : O(N*K)
//SC : O(K)

