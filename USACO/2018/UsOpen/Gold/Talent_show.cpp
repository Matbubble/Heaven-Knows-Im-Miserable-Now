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

const int maxN=1000;
long long dp[maxN+1];

void solve(){
    int n, w; cin>>n>>w;
    using T=pair<int, int>;
    vector<T>v(n);
    for(T &x:v) cin>>x.first>>x.second;
    auto check=[&](long long y){
        for(int i=0 ; i<=maxN ; i++) dp[i]=-1e18;
        dp[0]=0;
        for(int i=0 ; i<n ; i++){
            long long curr=(1000*v[i].second)-(y*v[i].first);
            // dbg(curr)
            for(int j=w ; j>=0 ; j--){
                int upper=min(w, j+v[i].first);
                // dbg(upper)
                if(dp[j]!=-1e18){
                    dp[upper]=max(dp[upper], dp[j]+curr);
                    // dbg(dp[upper])
                }
            }
        }
        // dbg(dp[w])
        return dp[w]>=0;
    };
    long long l=0, r=1e9, ans=0;
    while(l<=r){
        long long mid=((l+r)>>1ll);
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    solve();
    return 0;
}