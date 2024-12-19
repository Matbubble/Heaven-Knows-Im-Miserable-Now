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
    long long k, l1, r1, l2, r2; cin>>k>>l1>>r1>>l2>>r2;
    long long now=1, ans=0;
    while(now<=1e9){
        long long lower=max((l2+now-1)/now, l1);
        long long upper=min((r2)/now, r1);
        if(lower*now>r2 || upper*now<l2){
            now*=k;
            continue;
        }
        // dbg(now)
        // dbg(upper)
        // dbg(lower)
        ans+=upper-lower+1;
        now*=k;
    }
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