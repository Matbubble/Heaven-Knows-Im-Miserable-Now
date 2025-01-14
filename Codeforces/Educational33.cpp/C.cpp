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
New
Paul McCartney
*/

class dsu{
    public:
        vector<long long>p;
        long long n;
        dsu(long long _n) : n(_n){
            p.resize(n);
            for(long long i=0 ; i<n ; i++) p[i]=i;
        }
        inline long long get(long long x){
            return (p[x]==x?x:(p[x]=get(p[x])));
        }
        inline bool united(long long x, long long y){
            x=get(x); y=get(y);
            if(x==y) return 1;
            p[x]=y;
            return 0;
        }
};

void solve(){
    long long n, m; cin>>n>>m;
    vector<long long>cost(n+1);
    for(long long i=1 ; i<=n ; i++) cin>>cost[i];
    dsu d(n+1);
    vector<vector<long long>>g(n+1);
    vector<bool>vis(n+1);
    vector<long long>dp(n+1);
    for(long long i=0 ; i<m ; i++){
        long long x, y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        d.united(x, y);
    }
    auto dfs=[&](auto &&self, long long v) -> void{
        vis[v]=1;
        dp[v]=cost[v];
        for(long long u:g[v]){
            if(vis[u]){
                dp[v]=min(dp[v], dp[u]);
                continue;
            }
            self(self, u);
            dp[v]=min(dp[v], dp[u]);
        }
    };
    long long ans=0;
    for(long long i=1 ; i<=n ; i++){
        if(d.p[i]==i){
            dfs(dfs, i);
            ans+=dp[i];
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