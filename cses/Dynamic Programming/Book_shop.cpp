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

const int maxN=1e5;
int dp[maxN+1];

void solve(){
    int n, x; cin>>n>>x;
    using T=pair<int, int>;
    vector<T>v(n);
    for(T &x:v) cin>>x.first;
    for(T &x:v) cin>>x.second;
    for(int i=0 ; i<=maxN ; i++) dp[i]=-1e9;
    dp[0]=0;
    for(int i=0 ; i<n ; i++){
        for(int j=x ; j>=0 ; j--){
            int upper=j+v[i].first;
            if(upper>x) continue;
            if(dp[j]!=-1e9) dp[upper]=max(dp[upper], dp[j]+v[i].second);
        }
    }
    int ans=0;
    for(int i=0 ; i<=x ; i++) ans=max(ans, dp[i]);
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}