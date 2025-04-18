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

const int maxN=1e5, MOD=1e9+7;
int dp[maxN+1][4], vis[maxN+1];
vector<int>g[maxN+1];
void dfs(int u, int root){
    bool leaf=1;
    for(int v:g[u]){
        if(v==root) continue;
        dfs(v, u);
        leaf=0;
        dp[u][1]*=dp[v][2]+dp[v][3];
        dp[u][2]*=dp[v][1]+dp[v][3];
        dp[u][3]*=dp[v][1]+dp[v][2];
        if(vis[u]==1) dp[u][2]=dp[u][3]=0;
        if(vis[u]==2) dp[u][1]=dp[u][3]=0;
        if(vis[u]==3) dp[u][1]=dp[u][2]=0;
    }
    if(leaf){
        if(vis[u]==0){
            dp[u][1]=1; dp[u][2]=1; dp[u][3]=1;
        }else dp[u][vis[u]]=1;
    }
}

void solve(){
    int n, k; cin>>n>>k;
    for(int i=1 ; i<n ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0 ; i<k ; i++){
        int a, b; cin>>a>>b;
        vis[a]=b;
    }
    for(int i=1 ; i<=n ; i++){
        dp[i][1]=dp[i][2]=dp[i][3]=1;
    }
    dfs(1, -1);
    cout<<dp[1][1]+dp[1][2]+dp[1][3]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}