class Solution{
  int cutRod(vector<int> &price, int n)
  {
      vector<int> prev(n+1,0);
      for(int i=1; i<=n; i++) prev[i] = i*price[0];

      for(int len=2; len<=n; len++){
          vector<int> curr(n+1,0);
          for(int target=1; target<=n; target++){
              int take = 0;
              if(len<=target) 
                  take += price[len-1] + curr[target-len];
              int notTake = prev[target];   

              curr[target] = max(take,notTake);
          }
          prev = curr;
      }

      return prev[n];
  }
};
