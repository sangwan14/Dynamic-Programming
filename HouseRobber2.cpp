//Space Optimized Approach (Optimal)

long long int solve(vector<int>& arr, bool flag){
    int n = arr.size();
    long long int prev, prev2;
    prev = flag ? arr[0] : arr[1];
    prev2 = 0;
    
    if(flag)
        for(int i=1; i<n-1; i++){
            long long int pick = arr[i] + prev2;
            long long int notPick = prev;    

            prev2 = prev;
            prev = max(pick,notPick);
        }
    
    else
        for(int i=2; i<n; i++){
            long long int pick = arr[i] + prev2;
            long long int notPick = prev;    

            prev2 = prev;
            prev = max(pick,notPick);
        }

    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    long long int inc = solve(valueInHouse,true);
    long long int exc = solve(valueInHouse, false);

    return max(inc,exc);
}

//Time Complexity : O(N)
//Space Complexity : O(1)
