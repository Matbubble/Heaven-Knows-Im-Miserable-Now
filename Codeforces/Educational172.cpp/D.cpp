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
Time waits for nobody
*/

void solve(){
    long long n; cin>>n;
    using T=pair<long long, long long>;
    vector<T>vp(n);
    vector<long long>ans(n);
    for(T& x:vp) cin>>x.first>>x.second;
    sort(vp.begin(), vp.end(), [&](T a, T b) -> bool {
        return (a.first == b.first) ? a.second>b.second : a.first<b.first;
    });
    set<long long>S;
    for(int i=0 ; i<n ; i++){
        auto it=S.lower_bound(vp[i].second);
        if(it==S.end()) ans[i]+=0;
        else ans[i]+=(*it)-vp[i].second;
        S.insert(vp[i].second);
    }
    S.clear();
    sort(vp.begin(), vp.end(), [&](T a, T b) -> bool{
        return (a.second==b.second) ? a.first>b.first : a.second<b.second;
    });
    for(int i=0 ; i<n ; i++){
        auto it=S.lower_bound(vp[i].first);
        if(it==S.end()) ans[i]+=0;
        else ans[i]+=-vp[i].first+(*it);
        S.insert(vp[i].first);
    }
    for(long long x:ans) cout<<x<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}