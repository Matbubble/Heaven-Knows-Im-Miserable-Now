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
#include <cassert>

using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
MC lover
*/

struct q{
    int i, l, r;
};

void solve(){
    int n; cin>>n;
    vector<q>ans;
    ans.push_back({1, 1, n});
    for(int i=2 ; i<=n ; i++){
        // ans.push_back({i, 1, n});
        ans.push_back({i, 1, n-i+1});
        if(n-i+2<n) ans.push_back({i, n-i+2, n});
    }
    cout<<ans.size()<<"\n";
    for(q it:ans) cout<<it.i<<" "<<it.l<<" "<<it.r<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}