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

const long long maxN=2e5;

vector<long long>g[maxN+1];
long long dp[maxN+1], sub[maxN+1], ans[maxN+1];

void dfs(long long u, long long root){
    for(long long v:g[u]){
        if(v==root) continue;
        dfs(v, u);
        dp[u]+=sub[v]+dp[v];
        sub[u]+=sub[v];
    }
    sub[u]++;
}

void reroot(long long u, long long root){
    ans[u]=dp[u];
    for(long long v:g[u]){
        if(v==root) continue;
        dp[v]+=dp[u]-dp[v]-sub[v]+sub[u]-sub[v];
        sub[v]=sub[u];
        reroot(v, u);
    }
}

void solve(){
    long long n; cin>>n;
    for(long long i=1 ; i<n ; i++){
        long long a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    reroot(1, -1);
    for(long long i=1 ; i<=n ; i++) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}