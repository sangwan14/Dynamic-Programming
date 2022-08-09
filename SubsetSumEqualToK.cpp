//Memoization
class Solution{
  bool f(int ind, int target, vector<int> &arr, vector<vector<bool>> &dp){
      if(target==0) return true;
      if(ind==-1) return arr[ind] == target;
      if(dp[ind][target]) return true;

      bool notTaken = f(ind-1,target,arr,dp);
      bool taken = false;
      if(arr[ind]<=target)
          taken = f(ind-1,target-arr[ind],arr,dp);

      return dp[ind][target] = taken or notTaken;
  }
  bool subsetSumToK(int n, int k, vector<int> &arr) {
      vector<vector<bool>> dp(n, vector<bool> (k+1,false));
      return f(n-1,k,arr,dp);
  }
};
//TC : O(N*K)
//SC : O(N*K) + O(N)

//Tabulation
class Solution{
  bool subsetSumToK(int n, int k, vector<int> &arr) {
      vector<vector<bool>> dp(n, vector<bool> (k+1,false));
      for(int i=0; i<n; i++){
          dp[i][0] = true;
      }

       if(arr[0]<=k)
          dp[0][arr[0]] = true;

      for(int ind = 1; ind<n; ind++){
          for(int target= 1; target<=k; target++){

              bool notTaken = dp[ind-1][target];

              bool taken = false;
                  if(arr[ind]<=target)
                      taken = dp[ind-1][target-arr[ind]];

              dp[ind][target]= notTaken||taken;
          }
      }

      return dp[n-1][k];
  }
};
//TC : O(N*K)
//SC : O(N*K)

//Space Optimized 
class Solution3{
  bool subsetSumToK(int n, int k, vector<int> &arr) {
      vector<bool> prev(k+1,false);
      prev[0] = true;
      if(arr[0]<=k)
          prev[arr[0]] = true;

      for(int ind=1; ind<n; ind++){
          vector<bool> cur(k+1,false);
          for(int target=0; target<=k; target++){
              cur[target] = prev[target] or (target>=arr[ind] ? prev[target-arr[ind]] : false);
          }
          prev = cur; 
      }

      return prev[k];
  }
};
//TC : O(N*K)
//SC : O(K)
