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
vector<int> g[maxN+1];
int dp[maxN+1][2];

void dfs(int u, int root){
    bool leaf=1;
    for(int v:g[u]){
        if(v==root) continue;
        leaf=0;
        dfs(v, u);
        dp[u][0]+=max(dp[v][0], dp[v][1]);
    }
    if(leaf){
        dp[u][0]=dp[u][1]=0;
        return;
    }
    for(int v:g[u]){
        if(v==root) continue;
        dp[u][1]=max(dp[u][1], 1+dp[u][0]-max(dp[v][0], dp[v][1])+dp[v][0]);
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
    cout<<max(dp[1][0], dp[1][1])<<"\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}