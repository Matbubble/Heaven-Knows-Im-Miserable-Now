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
    long long n, x; cin>>n>>x;
    vector<long long>dp(x+1);
    vector<long long>coins(n);
    for(long long &x:coins) cin>>x;
    dp[0]=1;
    for(long long y:coins){
        for(long long i=1 ; i<=x ; i++){
            long long curr=i-y;
            if(curr<0) continue;
            dp[i]+=dp[i-y];
            dp[i]%=MOD;
        }
    }
    cout<<dp[x]%MOD<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}