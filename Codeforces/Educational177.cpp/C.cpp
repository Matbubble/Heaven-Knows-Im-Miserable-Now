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
    vector<int>repre(n+1), val(n+1);
    vector<int>v(n+1);
    for(int i=1 ; i<=n ; i++) cin>>v[i];
    vector<bool>vis(n+1, 0);
    auto dfs=[&](auto&&self, int u, int depth, int original) -> void{
        // dbg(u)
        repre[u]=original;
        // dbg(depth)
        vis[u]=1;
        if(vis[v[u]]) val[original]=depth;
        else self(self, v[u], depth+1, original);
    };
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            dfs(dfs, i, 1, i);
        }
    }
    int ans=0;
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        // dbg(val[repre[aux]])
        ans+=val[repre[aux]];
        val[repre[aux]]=0;
        cout<<ans<<" ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}