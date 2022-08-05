#include <bits/stdc++.h>

using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    vector<int> height{30,10,60 , 10 , 60 , 50};
    int n=height.size();
    int prev, prev2;
    prev = prev2 = 0;
    
    for(int i=1; i<n; i++){

        int jumpTwo = INT_MAX;
        int jumpOne = prev + abs(height[i]-height[i-1]);
        if(i>1) jumpTwo = prev2 + abs(height[i]-height[i-2]);

        int curi = min(jumpOne,jumpTwo);
        prev2 = prev;
        prev = curi;
        
    }
    cout<<prev<<endl;
}
