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
    int ans=0;
    vector<vector<int>>g(n+1);
    for(int i=1 ; i<n ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto dfs=[&](auto &&self, int u, int root, int mid)->int{
        int aux=0;
        for(int v:g[u]){
            if(v==root) continue;
            aux+=self(self, v, u, mid)+1;
        }
        return max(0, aux-mid);
    };
    int l=0, r=1e9;
    while(l<=r){
        int mid=(l+r)>>1;
        if(dfs(dfs, 1, -1, mid)==0){
            r=mid-1;
            ans=mid;
        }else l=mid+1;
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