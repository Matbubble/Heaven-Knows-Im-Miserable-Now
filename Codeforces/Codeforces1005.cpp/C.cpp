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

void solve(){
    int n; cin>>n;
    vector<long long>v(n);
    vector<long long>suf, pref;
    suf.push_back(0);
    pref.push_back(0);
    for(long long &x:v) cin>>x;
    for(int i=0 ; i<n ; i++){
        if(v[i]>0) pref.push_back(pref.back()+v[i]);
        else pref.push_back(pref.back());
        if(v[n-i-1]<0) suf.push_back(suf.back()+abs(v[n-i-1]));
        else suf.push_back(suf.back());
    }
    reverse(suf.begin(), suf.end());
    long long ans=0;
    for(int i=0 ; i<=n ; i++){
        // dbg(pref[i])
        // dbg(suf[i+1])
        ans=max(ans, pref[i]+suf[i]);
    }
    // ans=max({ans, pref[0], suf[n]});
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}