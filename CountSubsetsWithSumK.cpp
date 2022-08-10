//Space Optimized
class Solution{
  int findWays(vector<int> &num, int k)
  {
      int n = num.size();

      vector<int> prev(k+1,0);

      prev[0] = 1;

      for(int ind = 0; ind<n; ind++){
          vector<int> cur(k+1,0);
          for(int target = 0; target<=k; target++){

              int notTaken = prev[target];

              int taken = 0;
                  if(num[ind]<=target)
                      taken = prev[target-num[ind]];

              cur[target] = notTaken + taken;
          }

          prev = cur;
      }

      return prev[k];
  }
};
//TC : O(N*K)
//SC : O(K)

