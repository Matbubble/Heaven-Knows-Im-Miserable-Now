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
Shhhhh!
*/

void solve(){
    int n; cin>>n;
    long long m; cin>>m;
    using T=pair<long long, long long>;
    vector<T>v(n), bound(n);
    for(T &x:v) cin>>x.first>>x.second;
    stack<T>s;
    s.push({1e18, 0});
    for(int i=0 ; i<n ; i++){
        while(s.top().first<=v[i].second) s.pop();
        bound[i].first=s.top().second;
        s.push({v[i].second, i+1});
    }
    while(!s.empty()) s.pop();
    s.push({1e18, n});
    for(int i=n-1 ; i>=0 ; i--){
        while(s.top().first<=v[i].second) s.pop();
        bound[i].second=s.top().second;
        s.push({v[i].second, i});
    }
    vector<long long>pref;
    pref.push_back(0);
    for(int i=0 ; i<n ; i++) pref.push_back(pref.back()+v[i].first);
    long long ans=1e18;
    for(int i=0 ; i<n ; i++){
        int l=bound[i].first, r=bound[i].second;
        if(pref[r]-pref[l]>=m) ans=min(ans, v[i].second);
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    solve();
    return 0;
}