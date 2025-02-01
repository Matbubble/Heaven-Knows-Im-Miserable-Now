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

void solve(){
    int n; cin>>n;
    vector<vector<int>>g(n+1);
    vector<int>dp(n+1);
    for(int i=1 ; i<n ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans=0, aux=0;
    multiset<int, greater<int>>s;
    auto dfs=[&](auto &&self, int u, int root)->void{
        dp[u]=(int)g[u].size();
        // if(root>=0){
        //     dp[u]++;
        // }
        // dbg(u)
        // dbg(dp[u])
        s.insert(dp[u]);
        for(int v:g[u]){
            if(v==root) continue;
            self(self, v, u);
        }
        int maxi=0;
        s.erase(s.find(dp[u]));
        for(int v:g[u]){
            // if(v==root) continue;
            s.erase(s.find(dp[v]));
            maxi=max(maxi, dp[v]-1);
        }
        ans=max(ans, dp[u]+maxi-1);
        if(!s.empty()) ans=max(ans, dp[u]+*s.begin()-1);
        // dbg(u)
        // dbg(dp[u])
        // dbg(maxi)
        // dbg(*s.begin())
        s.insert(dp[u]);
        for(int v:g[u]){
            // if(v==root) continue;
            s.insert(dp[v]);
        }
    };
    dfs(dfs, 1, -1);
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}