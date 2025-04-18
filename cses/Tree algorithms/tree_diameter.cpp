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

int maxi=0, node=0;
void dfs(int u, int root, int depth){
    if(depth>maxi){
        maxi=depth;
        node=u;
    }
    for(int v:g[u]){
        if(v==root) continue;
        dfs(v, u, depth+1);
    }
}

void solve(){
    int n; cin>>n;
    for(int i=1 ; i<n ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1, 0);
    int auxi=node;
    node=maxi=0;
    dfs(auxi, -1, 0);
    cout<<maxi<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}