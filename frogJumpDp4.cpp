//Recursive Approach

#include<bits/stdc++.h>

using namespace std;

int solve(int ind, int k, vector<int>& height, vector<int>& dp){
  if(ind == 0) return 0;
  int minSteps = INT_MAX;
  for(int i=1; i<=k; i++){ 

    if(ind-i>=0){
      int jump =  solve(ind-i,k,height,dp) + abs(height[ind] - height[ind-i]);
      minSteps = min(jump,minSteps);
    }
  }
  return minSteps;
}

int main() {

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  vector<int> height{30, 10, 60 , 10 , 60 , 50};
  int n=height.size();
  int k=2;
  vector<int> dp(n,-1);
  cout<<solve(n-1,k,height,dp);
}

//Time Complexity : O(k^N)
//Space Complexity : O(N) [Stack Space]

//Memoization Approach

#include<bits/stdc++.h>

using namespace std;

int solve(int ind, int k, vector<int>& height, vector<int>& dp){
  if(ind == 0) return 0;
  if(dp[ind]!=-1) return dp[ind];

  int minSteps = INT_MAX;
  for(int i=1; i<=k; i++){
  
    if(ind-i>=0){
      int jump =  solve(ind-i,k,height,dp) + abs(height[ind] - height[ind-i]);
      minSteps = min(jump,minSteps);
    }
  }
  return dp[ind] = minSteps;
}

int main() {

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  vector<int> height{30, 10, 60 , 10 , 60 , 50};
  int n=height.size();
  int k=2;
  vector<int> dp(n,-1);
  cout<<solve(n-1,k,height,dp);
}

//Time Complexity : O(N*K)
//Space Complexity : O(N) [Memoization] + O(N) [Stack Space]

//Tabulation Approach (Optimal)

#include<bits/stdc++.h>

using namespace std;

int main() {

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  vector<int> height{30, 10, 60 , 10 , 60 , 50};
  int n=height.size();
  int k=2;
  vector<int> dp(n,INT_MAX);
  dp[0] = 0;
  for(int i=1; i<n; i++){
    int minSteps = INT_MAX;

    for(int j=1; j<=k; j++){ 

      if(i-j>=0){
        int jump =  dp[i-j] + abs(height[i] - height[i-j]);
        dp[i] = min(jump,dp[i]);
      } 
    }
  }
  
  cout<<dp[n-1]<<endl;
}

//Time Complexity : O(N*K)
//Space Complexity : O(N)
