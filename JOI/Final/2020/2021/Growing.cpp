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
    vector<long long>v(n);
    for(long long &x:v) cin>>x;
    vector<long long>pref, suf;
    for(int i=0 ; i<n ; i++){
        if(i==0) pref.push_back(0);
        else{
            long long need=pref.back();
            if(v[i-1]>=v[i]){
                need+=v[i-1]-v[i]+1;
            }
            pref.push_back(need);
        }
    }
    reverse(v.begin(), v.end());
    for(int i=0 ; i<n ; i++){
        if(i==0) suf.push_back(0);
        else{
            long long need=suf.back();
            if(v[i-1]>=v[i]){
                need+=v[i-1]-v[i]+1;
            }
            suf.push_back(need);
        }
    }
    reverse(suf.begin(), suf.end());
    long long ans=1e18;
    for(int i=0 ; i<n ; i++) ans=min(ans, max(suf[i], pref[i]));
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}