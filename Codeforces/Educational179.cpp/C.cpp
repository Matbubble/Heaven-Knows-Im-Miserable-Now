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

struct point{
    long long l, r;
    long long val;
};

void solve(){
    long long n; cin>>n;
    vector<point>v;
    for(long long i=1 ; i<=n ; i++){
        long long curr; cin>>curr;
        if(v.empty()) v.push_back({i, i, curr});
        else{
            if(curr==v.back().val) v.back().r=i;
            else v.push_back({i, i, curr});
        }
    }
    long long ans=1e18;
    for(point x:v){
        ans=min(ans, x.val*(x.l-1 + n-x.r));
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