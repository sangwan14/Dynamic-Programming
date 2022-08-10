//Memoization
class Solution{
  bool subsetSumUtil(int ind, int target, vector < int > & arr, vector < vector 
  < int >> & dp) {
    if (target == 0)
      return dp[ind][target]=true;

    if (ind == 0)
      return dp[ind][target] = arr[0] == target;

    if (dp[ind][target] != -1)
      return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
      taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
  }

  int minSubsetSumDifference(vector < int > & arr, int n) {

   int totSum = 0;

    for (int i = 0; i < n; i++) {
      totSum += arr[i];
    }

    vector < vector < int >> dp(n, vector < int > (totSum + 1, -1));

    for (int i = 0; i <= totSum/2; i++) {
      bool dummy = subsetSumUtil(n - 1, i, arr, dp);
    }

    int mini = 1e9;
    for (int i = 0; i <= totSum/2; i++) {
      if (dp[n - 1][i] == true) {
        int diff = abs(i - (totSum - i));
        mini = min(mini, diff);
      }
    }
    return mini;
  }
}; 
//TC : O(N * total Sum/2) + O(N) + O(total Sum/2)
//SC : O(N* total Sum/2) [DP array] + O(N) [Stack Space]

//Tabulation
class Solution2{
  int minSubsetSumDifference(vector < int > & arr, int n) {

   int totSum = 0;

    for (int i = 0; i < n; i++) {
      totSum += arr[i];
    }

    vector < vector < bool >> dp(n, vector < bool > (totSum/2 + 1, false));

    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }

    if(arr[0]<=totSum/2) dp[0][arr[0]] = true;

    for (int k = 0; k <= totSum/2; k++) {
      for(int ind = 1; ind<n; ind++){
          dp[ind][k] = dp[ind-1][k] or (k>=arr[ind] ? dp[ind-1][k-arr[ind]] : false);
      }
    }

    int mini = 1e9;
    for (int k = 0; k <= totSum/2; k++) {
      if (dp[n - 1][k]) {
        int diff = abs(k - (totSum - k));
        mini = min(mini, diff);
      }
    }
    return mini;
  }
};
//TC : O(N * total Sum/2) + O(N) + O(total Sum/2)
//SC : O(N * total Sum/2)

//Space Optimized
int minSubsetSumDifference(vector < int > & arr, int n) {

    int totSum = 0;

    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    vector < bool > prev(totSum/2 + 1, false);
    prev[0] = true;
    if(arr[0]<=totSum/2) prev[arr[0]] = true;

    for(int ind = 1; ind<n; ind++){
        vector<bool> cur(totSum/2 +1, false);
        for (int k = 0; k <= totSum/2; k++) {
            cur[k] = prev[k] or (k>=arr[ind] ? prev[k-arr[ind]] : false);
        }
        prev = cur;
    }

    int mini = 1e9;
    for (int k = 0; k <= totSum/2; k++) {
        if (prev[k]) {
            int diff = abs(k - (totSum - k));
            mini = min(mini, diff);
        }
    }
    return mini;
}
//TC : O(N * total Sum/2) + O(N) + O(total Sum/2)
//SC : O(total Sum/2)
