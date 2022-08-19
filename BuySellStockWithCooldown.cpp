//Memoization
class Solution{
  int getAns(vector<int> &Arr, int ind, int buy, int n, vector<vector<int>> &dp ){

        if(ind>=n) return 0; //base case

        if(dp[ind][buy]!=-1)
            return dp[ind][buy];

        int profit;

        if(buy==0){// We can buy the stock
            profit = max(0+getAns(Arr,ind+1,0,n,dp), -Arr[ind] + getAns(Arr,ind+1,1,n,dp));
        }

        if(buy==1){// We can sell the stock
            profit = max(0+getAns(Arr,ind+1,1,n,dp), Arr[ind] + getAns(Arr,ind+2,0,n,dp));
        }

        return dp[ind][buy] = profit;
    }
  int stockProfit(vector<int> &Arr){
      int n = Arr.size();
      vector<vector<int>> dp(n, vector<int> (2,-1));
      return getAns(Arr,0,0,n,dp);
  }
};
//Tc : O(N*2)
//SC : O(N*2) + O(N)

//Tabulation
class Solution2{
  int stockProfit(vector<int> &Arr){
      int n = Arr.size();
      vector<vector<int>> dp(n+2,vector<int>(2,0));

      for(int i=n-1; i>=0; i--){
          for(int j=0; j<=1; j++){
              int profit;
              if(j==0){
                  profit = max(dp[i+1][0], -Arr[i] + dp[i+1][1]);
              } 
              if(j==1){
                  profit = max(dp[i+1][1], Arr[i] + dp[i+2][0]);
              }
              dp[i][j] = profit;
          }
      }

      return dp[0][0];
  }
};
//Tc : O(N*2)
//SC : O(N*2) 

//Space Optimization
class Solution3{
  int stockProfit(vector<int> &Arr){
      int n = Arr.size();
      vector<vector<long>> dp(3,vector<long>(2,0));

      for(int i=n-1; i>=0; i--){
          for(int j=0; j<=1; j++){
              int profit;
              if(j==0){
                  profit = max(dp[i%3][0], -Arr[i] + dp[i%3][1]);
              } 
              if(j==1){
                  profit = max(dp[i%3][1], Arr[i] + dp[(i+1)%3][0]);
              }
              dp[(i+2)%3][j] = profit;
          }
      }

      return dp[2][0];
  }
};
//TC : O(N*2)
//SC : O(1)
