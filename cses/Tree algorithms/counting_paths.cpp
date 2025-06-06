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

const int maxN=2e5;

int sum[maxN+1], res[maxN+1], res1[maxN+1], dp[maxN+1];
vector<int>g[maxN+1];

int up[maxN+1][20], tin[maxN+1], tout[maxN+1];
int timer=0;

void dfs(int u, int root){
    tin[u]=++timer;
    up[u][0]=root;
    for(int i=1 ; i<20 ; i++){
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(int v:g[u]){
        if(v==root) continue;
        dfs(v, u);
    }
    tout[u]=++timer;
}

bool padre(int u, int v){
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}

int lca(int u, int v){
    if(padre(u, v)) return u;
    if(padre(v, u)) return v;
    for(int i=19 ; i>=0 ; i--){
        if(padre(up[u][i], v)) continue;
        u=up[u][i];
    }
    return up[u][0];
}

void dfs1(int u, int root){
    for(int v:g[u]){
        if(v==root) continue;
        dfs1(v, u);
        sum[u]+=sum[v];
    }
    sum[u]-=res1[u];
    dp[u]=sum[u];
    sum[u]-=res[u];
}

void solve(){
    int n, m; cin>>n>>m;
    for(int i=1 ; i<n ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 1);
    for(int i=0 ; i<m ; i++){
        int a, b; cin>>a>>b;
        sum[a]++; sum[b]++;
        res[lca(a, b)]++;
        res1[lca(a, b)]++;
    }
    dfs1(1, -1);
    for(int i=1 ; i<=n ; i++) cout<<dp[i]<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}