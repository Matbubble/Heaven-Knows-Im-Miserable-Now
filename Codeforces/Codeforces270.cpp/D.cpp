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
#include <cassert>

using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
MC lover
*/

struct dsu{
    long long n;
    vector<long long>p;
    dsu(long long n):n(n){
        for(long long i=0 ; i<=n ; i++) p.push_back(i);
    }
    long long find(long long x){
        return (p[x]==x?x:p[x]=find(p[x]));
    }
    bool united(long long a, long long b){
        a=find(a); b=find(b);
        if(a==b) return true;
        else{
            p[a]=b;
            return false;
        }
    }
};

void solve(){
    long long n; cin>>n;
    vector<pair<long long, pair<long long, long long>>>edge;
    vector<vector<long long>>dis(n, vector<long long>(n));
    bool ok=1;
    for(long long i=0 ; i<n ; i++){
        for(long long j=0 ; j<n ; j++){
            long long curr; cin>>curr;
            dis[i][j]=curr;
            if(i==j){
                if(curr>0) ok=0;
            }
            else{
                if(curr<=0) ok=0;
                edge.push_back(make_pair(curr, make_pair(i, j)));
            }
        }
    }
    if(!ok){
        cout<<"NO\n";
        return;
    }
    sort(edge.begin(), edge.end());
    dsu d(n);
    vector<vector<pair<long long, long long>>>g(n);
    for(long long i=0 ; i<(long long)edge.size() ; i++){
        if(!d.united(edge[i].second.first, edge[i].second.second)){
            g[edge[i].second.first].push_back({edge[i].second.second, edge[i].first});
            g[edge[i].second.second].push_back({edge[i].second.first, edge[i].first});
        }
    }
    for(long long i=0 ; i<n ; i++){
        vector<long long>dp(n);
        auto dfs=[&](auto &&self, long long u, long long root) -> void{
            if(dis[i][u]!=dp[u]) ok=0;
            for(pair<long long, long long>v:g[u]){
                if(v.first==root) continue;
                dp[v.first]=v.second+dp[u];
                self(self, v.first, u);
            }
        };
        dfs(dfs, i, -1);
        if(!ok){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}