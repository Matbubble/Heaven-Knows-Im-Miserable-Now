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
const long long MOD=1e9+7;
void solve(){
    long long n; cin>>n;
    vector<long long>dp(n+1);
    dp[0]=1;
    for(long long i=1 ; i<=n ; i++){
        for(long long j=1 ; j<=6 ; j++){
            long long curr=i-j;
            if(curr<0) continue;
            dp[i]+=dp[i-j];
        }
        dp[i]%=MOD;
    }
    cout<<(dp[n]%MOD)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}