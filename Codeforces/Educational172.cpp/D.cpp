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

struct point{
    long long x, y, z;
};

void solve(){
    long long n; cin>>n;
    using T=point;
    vector<T>vp(n);
    vector<long long>ans(n);
    map<pair<long long, long long>, long long>freq;
    for(T& x:vp){
        cin>>x.x>>x.y;
        freq[{x.x, x.y}]++;
    }
    for(int i=0 ; i<n ; i++) vp[i].z=i;
    sort(vp.begin(), vp.end(), [&](T a, T b) -> bool {
        return (a.x == b.x) ? a.y>b.y : a.x<b.x;
    });
    set<long long>S;
    for(int i=0 ; i<n ; i++){
        auto it=S.lower_bound(vp[i].y);
        if(it==S.end()) ans[i]+=0;
        else ans[vp[i].z]+=(*it)-vp[i].y;
        S.insert(vp[i].y);
    }
    sort(vp.begin(), vp.end(), [&](T a, T b) -> bool {
        return (a.y == b.y) ? a.x<b.x : a.y>b.y;
    });
    S.clear();
    for(int i=0 ; i<n ; i++){
        // dbg(vp[i].x);
        auto it=S.upper_bound(vp[i].x);
        if(S.empty() || it==S.begin()) ans[i]+=0;
        else{
            it--;
            // dbg(*it)
            ans[vp[i].z]+=vp[i].x-(*it);
        }
        //ojala
        S.insert(vp[i].x);

    }
    for(int i=0 ; i<n ; i++){
        if(freq[{vp[i].x, vp[i].y}]>=2) ans[vp[i].z]=0;
    }
    for(long long x:ans) cout<<x<<"\n";
    // dbg("123123123")
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}