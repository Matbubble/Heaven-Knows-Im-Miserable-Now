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
mas claro que el agua
*/

class dsu{
    public:
        vector<int>p;
        int n;
        dsu(int _n): n(_n){
            p.resize(n);
            iota(p.begin(), p.end(), 0);
        }
        inline int get(int x){
            return p[x]==x?x:(p[x]=get(p[x]));
        }
        inline bool united(int x, int y){
            x=get(x); y=get(y);
            if(x!=y){
                p[x]=y;
                return false;
            }
            return true;
        }
};

void solve(){
    int n, ans=0; cin>>n;
    vector<int>v(n);
    vector<vector<int>>g(n);
    vector<bool>on_cycle(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
        v[i]--;
        g[v[i]].push_back(i);
    }
    dsu d(n);
    auto dfs=[&](auto &&self, int v) -> int{
        int h=1;
        for(int u:g[v]){
            if(on_cycle[u]) continue;
            h=max(h, self(self, u)+1);
        }
        return h;
    };
    for(int i=0 ; i<n ; i++){
        if(d.united(i, v[i])){
            int x=i;
            vector<int>cycle;
            while(1){
                cycle.push_back(x);
                on_cycle[x]=1;
                x=v[x];
                if(x==i) break;
            }
            for(int v:cycle){
                ans=max(ans, dfs(dfs, v));
            }
        }
    }
    cout<<ans+1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}