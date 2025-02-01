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

const long long MOD=1e9+7, maxN=1e6;
long long dp[maxN+1][2];
void init(){
    dp[1][1]=dp[1][0]=1;
    for(int i=2 ; i<=maxN ; i++){
        dp[i][1]=4*dp[i-1][1];
        dp[i][1]+=dp[i-1][0];
        dp[i][0]=2*dp[i-1][0];
        dp[i][0]+=dp[i-1][1];
        dp[i][0]%=MOD; dp[i][1]%=MOD;
    }
}

void solve(){
    int n; cin>>n;
    long long ans=dp[n][1]+dp[n][0];
    cout<<ans%MOD<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}