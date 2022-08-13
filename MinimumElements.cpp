//Memoization
class Solution{
  int solve(int ind, vector<int> &num, int x,  vector<vector<int>> &dp){
      if(ind==0){
          if(x%num[ind]==0) return x/num[ind];
          return 1e9;
      }
      if(dp[ind][x]!=-1) return dp[ind][x];

      int take = 1e9;
      if(num[ind]<=x)
          take = 1 + solve(ind,num,x-num[ind],dp); 
      int notTake = solve(ind-1,num,x,dp); 

      return dp[ind][x] = min(take,notTake);
  }
  int minimumElements(vector<int> &num, int x)
  {
      int n = num.size();

      vector<vector<int>> dp(n, vector<int> (x+1,-1));
      int res = solve(n-1,num,x,dp);

      if(res==1e9) return -1;
      else return res;
  }
};
//TC : O(N*X)
//SC : O(N*X) [DP array] + O(N) [Stack Space]

//Tabulation
class Solution2{
  int minimumElements(vector<int> &num, int x)
  {
      int n = num.size();

      vector<vector<int>> dp(n, vector<int> (x+1,0));
      for(int i=0; i<=x; i++){
          if(i%num[0]==0) dp[0][i] = i/num[0];
          else dp[0][i] = 1e9;
      }

      for(int ind=1; ind<n; ind++){
          for(int target=0; target<=x; target++){
              int take = 1e9;
              if(num[ind]<=target){
                  take = 1 + dp[ind][target-num[ind]];
              }
              int notTake = dp[ind-1][target];

              dp[ind][target] = min(take,notTake);
          }
      }

      int res = dp[n-1][x];
      if(res>=1e9) return -1;
      else return res;
  }
};
//TC : O(N*K)
//SC : O(N*X)

//Space Optimized
class Solution3{
  int minimumElements(vector<int> &num, int x)
  {
      int n = num.size();

      vector<int> prev(x+1);
      for(int i=0; i<=x; i++) {
          if(i%num[0]==0) prev[i] = i/num[0];
          else prev[i] = 1e9;
      }

      for(int ind=1; ind<n; ind++){
          vector<int> cur(x+1,0);
          for(int target=0; target<=x; target++){
              int take = 1e9;
              if(num[ind]<=target)
                  take = 1 + cur[target-num[ind]];
              int notTake = prev[target];

              cur[target] = min(take,notTake);
          }
          prev = cur;
      }

      if(prev[x]>=1e9) return -1;
      else return prev[x];
  }
};
//TC : O(N*X)
//SC : O(X)
