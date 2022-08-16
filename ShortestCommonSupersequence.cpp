class Solution{
  string shortestSupersequence(string a, string b)
  {
      int n = a.size();
      int m = b.size();

      vector<vector<int>> dp(n+1, vector<int> (m+1,0));

      for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
              dp[i+1][j+1] = a[i]==b[j] ? dp[i][j] + 1 : max(dp[i+1][j],dp[i][j+1]);
          }
      }

      string res = "";

      int i,j;
      i=n; j=m;

      while(i>0 and j>0){
          if(a[i-1]==b[j-1]){
              res += a[i-1];
              i--; j--;
          }
          else{
              if(dp[i-1][j]>dp[i][j-1]){
                  res += a[i-1];
                  i--;
              }
              else {
                  res += b[j-1];
                  j--;
              }
          }
      }

      while(i>0) res += a[--i];

      while(j>0) res += b[--j];

      reverse(res.begin(),res.end());
      return res;
  }
};
