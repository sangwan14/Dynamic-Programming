//Memoization Approach
class Solution{
  int solveUtil(int ind, vector<int>& arr, vector<int>& dp){
      if(ind==0) return arr[ind];
      if(ind<0)  return 0;

      if(dp[ind]!=-1) return dp[ind];

      int pick= arr[ind]+ solveUtil(ind-2, arr,dp);
      int nonPick = 0 + solveUtil(ind-1, arr, dp);

      return dp[ind]=max(pick, nonPick);
  }

  int solve(vector<int>& arr){
      int n = arr.size();
      vector<int> dp(n,-1);
      return solveUtil(n-1, arr, dp);
  }

  int maximumNonAdjacentSum(vector<int> &nums){
      return solve(nums);
  }
}
//Time Complexity : O(N)
//Space Complexity : O(N) [Memoization] + O(N) [Recursion]

//Tabulation Approach
class Solution2{
  int solveUtil(int ind, vector<int>& arr, vector<int>& dp){
      dp[0] = arr[0];
    
      for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1) pick+=dp[i-2];
        int nonPick = dp[i-1];
        
        dp[i] = max(pick,nonPick);
      }
  }

  int solve(vector<int>& arr){
      int n = arr.size();
      vector<int> dp(n,-1);
      return solveUtil(n-1, arr, dp);
  }

  int maximumNonAdjacentSum(vector<int> &nums){
      return solve(nums);
  }
}
//Time Complexity : O(N)
//Space Complexity : O(N)

//Space Optimized Approach (Optimal)
class Solution3{
  int solveUtil(vector<int>& arr, vector<int>& dp){
      int n = arr.size();
      int prev = arr[0];
      int prev2 = 0;

      for(int i=1; i<n; i++){
          int pick = arr[i] + prev2;
          int nonPick = prev;

          prev2 = prev;
          prev = max(pick,nonPick);
      }

      return prev;
  }

  int solve(vector<int>& arr){
      vector<int> dp(arr.size(),-1);
      return solveUtil(arr, dp);
  }

  int maximumNonAdjacentSum(vector<int> &nums){
      return solve(nums);
  }
}
//Time Complexity : O(N)
//Space Complexity : O(1)
