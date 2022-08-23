class Solution {
public:
    bool isPred(string& a, string& b){
        int n = a.size();
        int m = b.size();
        if(m-n!=1) return false;
        int i,j;
        i = j = 0;
        int cnt = 0;
        while(i<n and j<m){
           if(a[i]!=b[j]){
               cnt++;
               j++;
           }
           else{
               i++;
               j++;
           } 
           if(cnt>1) return false; 
        }
        
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &l, const string &r) { return l.size() < r.size(); });
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(isPred(words[prev],words[i])){
                    dp[i] = max(dp[i],1+dp[prev]);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        return maxi;
    }
};
//TC - O(N*N*l)
//SC - O(N)
