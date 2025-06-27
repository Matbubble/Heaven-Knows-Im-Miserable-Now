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

const int maxN=1e5;
vector<int>g[maxN+1];
int tin[maxN+1], tout[maxN+1], papi[maxN+1];
bool vis[maxN+1];
int timer=0, ans=0;

void dfs(int u){
    // vis[u]=1;
    tin[u]=tout[u]=++timer;
    for(int v:g[u]){
        if(!vis[v]){
            papi[v]=u;
            vis[v]=1;
            dfs(v);
            tout[u]=min(tout[u], tout[v]);
            if(tout[v]>tin[u]) ans++;
        }else if(v!=papi[u]) tout[u]=min(tout[u], tin[v]);
    }
}

void solve(){
    int n, m; cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(i);
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