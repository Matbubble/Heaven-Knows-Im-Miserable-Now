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

void solve(){
    int n, m, k; cin>>n>>m>>k;
    map<pair<int, int>, vector<pair<int, pair<int, int>>>>g;
    set<pair<int, int>>s;
    for(int i=0 ; i<k ; i++){
        int a, b, c, d, w; cin>>a>>b>>c>>d>>w;
        g[make_pair(a, b)].push_back(make_pair(c, make_pair(d, w)));
        s.insert({c, d});
    }
    map<pair<int, int>, int>dp;
    for(int i=1 ; i<=n ; i++){
        vector<pair<int, int>>extra;
        if(i==1) extra.push_back(1, )
        while(!g.empty() && (g.begin()->first.first)==i){

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