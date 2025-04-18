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

vector<int>g[maxN+1];
int maxi[maxN+1], smaxi[maxN+1], nmaxi[maxN+1];
int ans[maxN+1];

void dfs(int u, int root){
    for(int v:g[u]){
        if(v==root) continue;
        dfs(v, u);
        if(maxi[v]+1>maxi[u]){
            smaxi[u]=max(smaxi[u], maxi[u]);
            maxi[u]=maxi[v]+1;
            nmaxi[u]=v;
        }else smaxi[u]=max(smaxi[u], maxi[v]+1);
    }
}

void reroot(int u, int root){
    ans[u]=maxi[u];
    for(int v:g[u]){
        if(v==root) continue;
        if(v==nmaxi[u]){
            if(smaxi[u]+1>maxi[v]){
                smaxi[v]=max(smaxi[v], maxi[v]);
                maxi[v]=smaxi[u]+1;
                nmaxi[v]=u;
            }else smaxi[v]=max(smaxi[v], smaxi[u]+1);
        }else{
            if(maxi[u]+1>maxi[v]){
                smaxi[v]=max(smaxi[v], maxi[v]);
                maxi[v]=maxi[u]+1;
                nmaxi[v]=u;
            }else smaxi[v]=max(smaxi[v], maxi[u]+1);
        }
        reroot(v, u);
    }
}

void solve(){
    int n; cin>>n;
    for(int i=1 ; i<n ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    reroot(1, -1);
    for(int i=1 ; i<=n ; i++) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}