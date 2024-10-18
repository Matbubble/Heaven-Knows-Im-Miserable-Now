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
I love DP
*/

void solve(){
    long long n, k; cin>>n>>k;
    vector<long long>health(n), dp(n+1);
    for(long long &x:health) cin>>x;
    for(int i=0 ; i<n ; i++){
        long long x; cin>>x;
        dp[abs(x)]+=health[i];
    }
    long long bullets=0;
    for(int i=1 ; i<=n ; i++){
        bullets+=k;
        bullets-=dp[i];
        if(bullets<0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}