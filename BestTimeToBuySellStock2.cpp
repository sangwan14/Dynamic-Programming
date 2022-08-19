//Tabulation
class Solution2{
  long getMaximumProfit(long *Arr, int n)
  {
      vector<vector<long>> dp(n+1,vector<long>(2,0));

      for(int i=n-1; i>=0; i--){
          for(int j=0; j<=1; j++){
              long profit;
              if(j==0){
                  profit = max(dp[i+1][0], -Arr[i] + dp[i+1][1]);
              } 
              if(j==1){
                  profit = max(dp[i+1][1], Arr[i] + dp[i+1][0]);
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
  long getMaximumProfit(long *Arr, int n)
  {
      vector<vector<long>> dp(2,vector<long>(2,0));

      for(int i=n-1; i>=0; i--){
          for(int j=0; j<=1; j++){
              long profit;
              if(j==0){
                  profit = max(dp[i%2][0], -Arr[i] + dp[i%2][1]);
              } 
              if(j==1){
                  profit = max(dp[i%2][1], Arr[i] + dp[i%2][0]);
              }
              dp[!(i%2)][j] = profit;
          }
      }

      return dp[1][0];
  }
};
//TC : O(2*N)
//SC : O(1)

//Linear Time (One pass) 
class Solution3{
  long getMaximumProfit(long *prices, int n)
  {
      long profit = 0;

      for(int i=0; i<n-1; i++){
          if(prices[i]<prices[i+1]){
              profit+=prices[i+1]-prices[i];
          }
      }

      return profit;
  }
};
//TC : O(N)
//SC : O(1)
