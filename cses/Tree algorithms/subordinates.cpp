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

int sub[maxN+1];
vector<int>g[maxN+1];

void dfs(int u, int root){
    for(int v:g[u]){
        if(v==root) continue;
        dfs(v, u);
        sub[u]+=sub[v];
    }
    sub[u]++;
}

void solve(){
    int n; cin>>n;
    for(int i=1 ; i<n ; i++){
        int x; cin>>x;
        g[i+1].push_back(x);
        g[x].push_back(i+1);
    }
    dfs(1, -1);
    for(int i=1 ; i<=n ; i++){
        cout<<sub[i]-1<<" ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}