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
using T=pair<long long, long long>;
/*  
Time waits for nobody
*/




void solve(){
    long long n; cin>>n;
    vector<T>vp(n);
    for(T& x:vp) cin>>x.first>>x.second;
    sort(vp.begin(), vp.end(), [&](T a, T b) -> bool {
        return (a.first == b.first) ? a.second > b.second : a.first < b.first;
    });
    pair<int, int>a={1, 1};
    for(int i=0 ; i<n ; i++) cout<<vp[i].first<<" "<<vp[i].second<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}