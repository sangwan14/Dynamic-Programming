//Memoization
class Solution{
  int f(int ind, int buy, int fee, vector<int> &prices, int n, vector<vector<int>> &dp){
      if(ind==n) return 0;
      if(dp[ind][buy]!=-1) return dp[ind][buy];
      int profit;
      if(buy==0){
          profit = max(f(ind+1,0,fee,prices,n,dp), -prices[ind] + f(ind+1,1,fee,prices,n,dp));
      }
      if(buy==1){
          profit = max(f(ind+1,1,fee,prices,n,dp), prices[ind] -fee + f(ind+1,0,fee,prices,n,dp));
      }
      return dp[ind][buy] = profit;
  }

  int maximumProfit(int n, int fee, vector<int> &prices) {
      vector<vector<int>> dp(n, vector<int> (2,-1));
      return f(0,0,fee,prices,n,dp);
  }
};
//TC : O(N*2)
//SC : O(N*2) + O(N)
     
//Tabulation
class Solution2{
  int maximumProfit(int n, int fee, vector<int> &prices) {
      vector<vector<long>> dp(n+1,vector<long>(2,0));

      for(int i=n-1; i>=0; i--){
          for(int j=0; j<=1; j++){
              long profit;
              if(j==0){
                  profit = max(dp[i+1][0], -prices[i] + dp[i+1][1]);
              } 
              if(j==1){
                  profit = max(dp[i+1][1], prices[i] -fee + dp[i+1][0]);
              }
              dp[i][j] = profit;
          }
      }

      return dp[0][0];
  }
};
//TC : O(2*N)
//SC : O(2*N)

//Space Optimized
class Solution3{
  int maximumProfit(int n, int fee, vector<int> &prices) {
      vector<vector<long>> dp(2,vector<long>(2,0));

      for(int i=n-1; i>=0; i--){
          for(int j=0; j<=1; j++){
              long profit;
              if(j==0){
                  profit = max(dp[i%2][0], -prices[i] + dp[i%2][1]);
              } 
              if(j==1){
                  profit = max(dp[i%2][1], prices[i] -fee + dp[i%2][0]);
              }
              dp[!(i%2)][j] = profit;
          }
      }

      return dp[1][0];
  }
};
//TC : O(2*N)
//SC : O(1)
