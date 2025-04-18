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

const long long maxN=1e5;
long long depth[maxN+1];
vector<long long>g[maxN+1];
long double ans[maxN+1];

void dfs(long long u, long long root){
    bool leaf=1;
    long double cont=0;
    for(long long v:g[u]){
        if(v==root) continue;
        leaf=0;
        dfs(v, u);
        cont+=1.;
        ans[u]+=ans[v];
    }
    if(leaf){
        ans[u]=0.;
        return;
    }
    ans[u]/=cont;
    ans[u]+=1.;
}

void solve(){
    long long n; cin>>n;
    for(long long i=1 ; i<n ; i++){
        long long a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    depth[1]=0;
    dfs(1, -1);
    // long double ans=(long double)cont/(long double)num;
    cout<<fixed<<setprecision(10)<<ans[1]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}