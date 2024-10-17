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
uwu
*/

void solve(){
    long long n, m, h; cin>>n>>m>>h;
    vector<bool>horse(n+1);
    for(int i=0 ; i<h ; i++){
        int aux; cin>>aux;
        horse[aux]=1;
    }
    vector<vector<pair<int, int> > >g(n+1);
    for(int i=0 ; i<m ; i++){
        int a, b, c; cin>>a>>b>>c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
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