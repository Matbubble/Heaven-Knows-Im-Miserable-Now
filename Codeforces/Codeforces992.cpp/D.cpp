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
I love DP
*/

const int maxN=2e5;
vector<int> g[maxN+1];

void solve(){
    int n; cin>>n;
    for(int i=0 ; i<=n ; i++) g[i].clear();
    for(int i=0 ; i<n-1 ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int curr=1;
    vector<int>ans(n+1);
    auto dfs=[&](auto&& self, int u, int root=-1) -> void{
        ans[u]=curr;
        bool first=0;
        for(int v:g[u]){
            // dbg(v)
            if(v==root) continue;
            if(!first){
                first=1;
                curr++;
                self(self, v, u);
                curr++;
            }else{
                curr+=2;
                self(self, v, u);
            }
        }
        
    };
    dfs(dfs, 1);
    for(int i=1 ; i<=n ; i++) cout<<ans[i]<<" ";
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