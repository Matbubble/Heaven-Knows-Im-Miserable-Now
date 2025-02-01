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
    long long n; cin>>n;
    vector<long long>v(n), pref(n), suf(n);
    long long posi=0;
    for(long long &x:v){
        cin>>x;
        pref[posi]=x+posi;
        suf[posi]=x-posi;
        posi++;
    }
    for(long long i=1 ; i<n ; i++) pref[i]=max(pref[i], pref[i-1]);
    for(long long i=n-2 ; i>=0 ; i--) suf[i]=max(suf[i], suf[i+1]);
    long long ans=0;
    for(long long i=1 ; i<n-1 ; i++){
        ans=max(ans, v[i]+pref[i-1]+suf[i+1]);
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}