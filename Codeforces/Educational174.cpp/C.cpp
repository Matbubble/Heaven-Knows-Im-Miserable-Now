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

const long long MOD=998244353;

void solve(){
    long long n; cin>>n;
    vector<long long>v(n);
    for(long long &x:v) cin>>x;
    vector<long long>dp(4);
    dp[0]=1;
    for(long long i=0 ; i<n ; i++){
        if(v[i]==2) dp[v[i]]*=2;
        dp[v[i]]+=dp[v[i]-1];
        dp[i]%=MOD;
    }
    cout<<dp[3]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}