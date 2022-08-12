//Space Optimized
class Solution{
  int solve(int ind, vector<int> weight, vector<int> value, int n, int maxWeight, int curr, vector<vector<int>> dp){
      if(ind==0){
          if(curr+weight[ind]<=maxWeight) return value[ind];
          else return 0;
      }
      if(dp[ind][curr]!=-1) return dp[ind][curr];

      int taken = 0;
      if(curr+weight[ind]<=maxWeight)   
          taken += value[ind] + solve(ind-1,weight,value,n,maxWeight,curr+weight[ind],dp);
      int notTaken = solve(ind-1,weight,value,n,maxWeight,curr,dp);

      return dp[ind][curr] = max(taken,notTaken);
  }

  int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
  {
      vector<int> prev(maxWeight+1,0);
      for(int i=weight[0]; i<=maxWeight; i++) prev[i] = value[0];

      for(int ind=1; ind<n; ind++){
          vector<int> curr(maxWeight+1,0);
          for(int target=0; target<=maxWeight; target++){
              int notTaken = prev[target];
              int taken = 0;
              if(weight[ind]<=target)
                  taken = value[ind] + prev[target-weight[ind]];
              curr[target] = max(taken,notTaken);
          }
          prev = curr;
      }

      return prev[maxWeight];
  }
};
//TC : O(N * maxWeight)
//SC : O(maxWeight)
