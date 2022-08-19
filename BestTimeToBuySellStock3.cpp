//Memoization
class Solution{
  int f(int ind, int buy, int transactions, vector<vector<vector<int>>>& dp, vector<int>& prices, int n){
      if(ind==n or transactions==0) return 0;
      if(dp[ind][buy][transactions]!=-1) return dp[ind][buy][transactions];

      int profit;
      if(buy==0){
          profit = max(f(ind+1,0,transactions,dp,prices,n),-prices[ind] + f(ind+1,1,transactions,dp,prices,n));
      }
      if(buy==1){
          profit = max(f(ind+1,1,transactions,dp,prices,n),prices[ind] + f(ind+1,0,transactions-1,dp,prices,n));
      }

      return dp[ind][buy][transactions] = profit;
  }

  int maxProfit(vector<int>& prices, int n)
  {
      vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3,-1)));

      return f(0,0,2,dp,prices,n);
  }
};
//TC : O(N*2*3)
//SC : O(N*2*3) + O(N)

//Tabulation
class Solution2{
  int maxProfit(vector<int>& prices, int n)
  {
      vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0)));

      for(int ind=n-1; ind>=0; ind--){
          for(int buy=0; buy<=1; buy++){
              for(int transactions=1; transactions<=2; transactions++){
                  int profit;
                  if(buy==0){
                      profit = max(dp[ind+1][0][transactions], -prices[ind] + dp[ind+1][1][transactions]);
                  }
                  if(buy==1){
                      profit = max(dp[ind+1][1][transactions], prices[ind] + dp[ind+1][0][transactions-1]);
                  }
                  dp[ind][buy][transactions] = profit;
              }
          }
      }
      return dp[0][0][2];
  }
};
//TC : O(N*2*3)
//SC : O(N*2*3)

//Space Optimized
class Solution3{
  int maxProfit(vector<int>& prices, int n)
  {
      vector<vector<vector<int>>> dp(2, vector<vector<int>> (2, vector<int> (3,0)));

      for(int ind=n-1; ind>=0; ind--){
          for(int buy=0; buy<=1; buy++){
              for(int transactions=1; transactions<=2; transactions++){
                  int profit;
                  if(buy==0){
                      profit = max(dp[ind%2][0][transactions], -prices[ind] + dp[ind%2][1][transactions]);
                  }
                  if(buy==1){
                      profit = max(dp[ind%2][1][transactions], prices[ind] + dp[ind%2][0][transactions-1]);
                  }
                  dp[!(ind%2)][buy][transactions] = profit;
              }
          }
      }
      return dp[1][0][2];
  }
};
//TC : O(N*2*3)
//SC : O(1)
