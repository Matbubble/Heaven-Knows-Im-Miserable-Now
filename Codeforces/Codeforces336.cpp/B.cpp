#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
MC lover
*/

const int maxN=500;
int dp[maxN+1][maxN+1];

void solve(){
    int n; cin>>n;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=n ; j++) dp[i][j]=-1;
    }
    auto recursive=[&](auto &&self, int i, int j){
        if(dp[i][j]!=-1) return dp[i][j];
        if(j<i) return dp[i][j]=0;
        else if(i==j) return dp[i][j]=1;
        int ans=self(self, i+1, j)+1;
        for(int k=i+2 ; k<=j ; k++){
            if(v[k]==v[i]) ans=min(ans, self(self, i+1, k-1)+self(self, k+1, j));
        }
        if(v[i+1]==v[i]) ans=min(ans, self(self, i+2, j)+1);
        return dp[i][j]=ans;
    };
    cout<<recursive(recursive, 0, n-1)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}