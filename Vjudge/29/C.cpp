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

const long long MOD=998244353;
long long dp[5001];

void solve(){
    long long q, k; cin>>q>>k;
    dp[0]=1;
    while(q--){
        char type; cin>>type;
        long long x; cin>>x;
        if(type=='+'){
            for(long long i=k ; i>=x ; i--){
                dp[i]+=dp[i-x];
                dp[i]%=MOD;
            }
        }else{
            for(long long i=x ; i<=k ; i++){
                dp[i]-=dp[i-x];
                dp[i]+=MOD;
                dp[i]%=MOD;
            }
        }
        cout<<dp[k]%MOD<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}