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
long long dp[maxN+1];
const long long MOD=1e9+7;

long long binpow(long long a, long long b){
    long long res=1;
    while(b>0){
        if(b&1){
            res*=a;
            res%=MOD;
        }
        a*=a;
        a%=MOD;
        b>>=1;
    }
    return res%MOD;
}

void solve(){
    int n; cin>>n;
    int maxi=n*(n+1)/2;
    if(maxi&1) cout<<0<<"\n";
    else{
        maxi/=2;
        for(int i=0 ; i<=maxi ; i++) dp[i]=0;
        dp[0]=1;
        for(int i=1 ; i<=n ; i++){
            for(int j=maxi ; j>=0 ; j--){
                if(j+i>maxi || dp[j]==0) continue;
                dp[i+j]+=dp[j];
                dp[i+j]%=MOD;
            }
        }
        cout<<(dp[maxi]*binpow(2, MOD-2))%MOD<<"\n";
    }
    // dbg(dp[3])
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}