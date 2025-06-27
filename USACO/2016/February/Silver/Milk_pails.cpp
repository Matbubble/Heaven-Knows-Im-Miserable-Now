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
#include <cassert>

using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
MC lover
*/

const int maxN=200;
int dp[maxN+1][maxN+1];
int mprima, ans=1e9, x, y, K;

struct point{
    int n, m, k;
};

void solve(){
    cin>>x>>y>>K>>mprima;
    queue<point>bfs;
    bfs.push({0, 0, 0});
    while(!bfs.empty()){
        auto[n, m, k]=bfs.front();
        bfs.pop();
        if(dp[n][m]==1 || k>K) continue;
        dp[n][m]=1;
        ans=min(ans, abs(n+m-mprima));
        bfs.push({x, m,  k+1});
        bfs.push({n, y, k+1});
        bfs.push({n+min(m, x-n), m-min(m, x-n), k+1});
        bfs.push({n-min(n, y-m), m+min(n, y-m), k+1});
        bfs.push({0, m, k+1});
        bfs.push({n, 0, k+1});
    }
    // pre(0, 0, 0);
    assert(ans<1e9);
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    solve();
    return 0;
}