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
    long long n, q; cin>>n>>q;
    vector<long long>v(n), diff(n+2);
    for(long long &x:v) cin>>x;
    for(long long i=0 ; i<q ; i++){
        long long a, b; cin>>a>>b;
        a--; b--;
        diff[a]++; diff[b+1]--;
    }
    vector<long long>pref;
    long long curr=0;
    for(long long i=0 ; i<n ; i++){
        curr+=diff[i];
        pref.push_back(curr);
    }
    sort(pref.begin(), pref.end(), greater<long long>());
    sort(v.begin(), v.end(), greater<long long>());
    long long ans=0;
    for(long long i=0 ; i<n ; i++){
        ans+=pref[i]*v[i];
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}