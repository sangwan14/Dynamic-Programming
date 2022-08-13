//Space Optimized
class Solution{
  int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
  {
      vector<int> prev(w+1,0);
      for(int i=0; i<=w; i++){
          prev[i] = (i/weight[0])*profit[0];
      }

      for(int ind=1; ind<n; ind++){
          vector<int> curr(w+1,0);
          for(int target=0; target<=w; target++){
              int take = 0;
              if(weight[ind]<=target)
                  take = profit[ind] + curr[target-weight[ind]];
              int notTake = prev[target];

              curr[target] = max(take,notTake);
          }
          prev = curr;
      }

      return prev[w];
  }
};
//TC : O(N*W)
//SC : O(W)
