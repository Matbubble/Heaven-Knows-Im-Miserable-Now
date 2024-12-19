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
Lovers Rock
Tv girl
*/

struct dsu{
    vector<int>p;
    int n;
    dsu(int _n):n(_n){
        p.resize(n+1);
        iota(p.begin(), p.end(), 0);
    }
    inline int get(int x){
        return (p[x]==x?x:p[x]=get(p[x]));
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
    int n, m; cin>>n>>m;
    vector<pair<int, int>>list;
    vector<vector<int>>g(n+1);
    for(int i=0 ; i<m ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        list.push_back({a, b});
    }
    dsu d(n);
    // int h=0;
    vector<int>last(n+1);
    auto dfs=[&](auto &&self, int v) -> int{
        int h=0;
        for(int u:g[v]){
            
        }
    };
    for(int i=0 ; i<m ; i++){
        if(d.united(list[i].first, list[i].second)){
            
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}