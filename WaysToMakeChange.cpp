//Space Optimized
class Solution{
  long findWays(int *num, int n, int k)
  {
      vector<long> prev(k+1,0);

      prev[0] = 1;

      for(int ind = 0; ind<n; ind++){
          vector<long> cur(k+1,0);
          for(int target = 0; target<=k; target++){

              long notTaken = prev[target];

              long taken = 0;
              if(num[ind]<=target)
                  taken = cur[target-num[ind]];

              cur[target] = notTaken + taken;
          }

          prev = cur;
      }

      return prev[k];
  }
  long countWaysToMakeChange(int *denominations, int n, int value)
  {
      return findWays(denominations,n,value);
  }
};
//TC - O(N*value)
//SC - O(value)
