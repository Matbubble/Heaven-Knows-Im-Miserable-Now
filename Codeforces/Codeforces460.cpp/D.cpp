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
Misery
Maroon 5
*/

const int maxN=3e5;
int dp[maxN+1][28], color[maxN+1];
vector<int> g[maxN+1];
bool vis[maxN+1];

void solve(){
    int n, m; cin>>n>>m;
    string s; cin>>s;
    for(int i=0 ; i<m ; i++){
        int x, y; cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
    }
    auto dfs1=[&](auto &&self, int u) -> bool{
        color[u]=1;
        bool ok=1;
        for(int v:g[u]){
            if(color[v]==0){
                ok&=self(self, v);
            }else if(color[v]==1) ok=0;
        }
        color[u]=2;
        return ok;
    };
    for(int i=0 ; i<n ; i++){
        if(color[i]==0){
            if(!dfs1(dfs1, i)){
                cout<<-1<<"\n";
                return;
            }
        }
    }
    auto dfs=[&](auto &&self, int u) -> void{
        vis[u]=1; 
        for(int v:g[u]){
            if(vis[v]){
                for(int j=0 ; j<28 ; j++){
                    dp[u][j]=max(dp[u][j], dp[v][j]);
                }
                continue;
            }
            self(self, v);
            for(int j=0 ; j<28 ; j++){
                dp[u][j]=max(dp[u][j], dp[v][j]);
            }
        }
        dp[u][s[u]-'a']++;
    };
    for(int i=0 ; i<n ; i++){
        if(!vis[i]) dfs(dfs, i);
    }
    int ans=0;
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<28 ; j++) ans=max(ans, dp[i][j]);
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