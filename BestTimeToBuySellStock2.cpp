//Memoization
class Solution{
  long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp ){

      if(ind==n) return 0; //base case

      if(dp[ind][buy]!=-1)
          return dp[ind][buy];

      long profit;

      if(buy==0){// We can buy the stock
          profit = max(0+getAns(Arr,ind+1,0,n,dp), -Arr[ind] + getAns(Arr,ind+1,1,n,dp));
      }

      if(buy==1){// We can sell the stock
          profit = max(0+getAns(Arr,ind+1,1,n,dp), Arr[ind] + getAns(Arr,ind+1,0,n,dp));
      }

      return dp[ind][buy] = profit;
  }
  long getMaximumProfit(long *Arr, int n)
  {
      //Write your code here

      vector<vector<long>> dp(n,vector<long>(2,-1));

      if(n==0) return 0;
      long ans = getAns(Arr,0,0,n,dp);
      return ans;
  }    
};
//TC : O(N*2)
//SC : O(N*2) + O(N)
     
};
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
