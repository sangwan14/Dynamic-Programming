#include<bits/stdc++.h>
vector<int> divisibleSet(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<int> dp(n,1);
    vector<int> pred(n);
    int lastIndex = 0;
    int maxi = 1;
    
    for(int i=1; i<n; i++){
        pred[i] = i;
        for(int prev=0; prev<i; prev++){
            if(arr[i]%arr[prev]==0 and 1 + dp[prev] > dp[i]){
                pred[i] = prev;
                dp[i] = 1 + dp[prev];
            }
        }
        if(dp[i]>maxi){
            lastIndex = i;
            maxi = dp[i];
        }
    }
    
    vector<int> res;
    res.push_back(arr[lastIndex]);
    while(pred[lastIndex]!=lastIndex){
        lastIndex = pred[lastIndex];
        res.push_back(arr[lastIndex]);
    }
    
    reverse(res.begin(),res.end());
    
    return res;
}
//TC - O(N*N)
//SC - O(N)
