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
Ya no te quiero veeer, mentirosaaa
*/

void solve(){
    int n, s, m; cin>>n>>s>>m;
    vector<pair<int, int>>vp;
    vp.push_back({0, 0});
    for(int i=0 ; i<n ; i++){
        int x, y; cin>>x>>y;
        vp.push_back({x, y});
    }
    vp.push_back({m, m});
    bool ok=0;
    for(int i=0 ; i<=n ; i++){
        if(vp[i+1].first-vp[i].second>=s) ok=1;
    }
    cout<<(ok?"YES\n":"NO\n");
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}