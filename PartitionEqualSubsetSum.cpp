//Space Optimized 
bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for(int i=0 ; i<n; i++) sum+=arr[i];
    
    if(sum%2==1) return false;
    
    int k = sum>>1;
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
//TC : O(N*K)
//SC : O(N*K)
