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
    long long n, m, t; cin>>n>>m>>t;
    long long l=64-__builtin_clzll(n);
    // dbg(l)
    vector<vector<pair<long long, long long>>>g(n+1);
    vector<vector<long long>> up(n+1, vector<long long>(l+1, 0));
    for(long long i=0 ; i<m ; i++){
        long long a, b, w; cin>>a>>b>>w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    vector<long long>dis(n+1), tin(n+1), tout(n+1);
    long long timer=0;
    auto dfs=[&](auto &&self, long long v, long long root)->void{
        tin[v]=timer;
        up[v][0]=root;
        for(long long i=1 ; i<=l ; i++){
            up[v][i]=up[up[v][i-1]][i-1];
        }
        for(auto[u, w]:g[v]){
            if(u==root) continue;
            dis[u]=dis[v]+w;
            self(self, u, v);
        }
        tout[v]=++timer;
    };
    auto is_ancestor=[&](long long a, long long b){
        return tin[a]<=tin[b] && tout[a]>=tout[b];
    };
    auto lca=[&](long long u, long long v){
        if(is_ancestor(u, v)) return u;
        if(is_ancestor(v, u)) return v;
        for(long long i=l ; i>=0 ; i--){
            if(!is_ancestor(up[u][i], v)){
                u=up[u][i];
            }
        }
        return up[u][0];
    };
    dfs(dfs, 0, 0);
    long long ans=0;
    for(long long i=0 ; i<n-1 ; i++){
        for(long long j=i+1 ; j<n ; j++){
            long long curr=lca(i, j);
            ans+=(dis[i]+dis[j]-(2*dis[curr])<=t);
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}