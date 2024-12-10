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
Vamos a amarla los dos 
*/

const long long MOD=1e9+7;
const int maxN=2e5;
long long fac[maxN+1], invfac[maxN+1];

void init(){
    auto binpow=[](long long x, long long y){
        long long res=1;
        while(y>0){
            if(y&1){
                res*=x;
                res%=MOD;
            }
            x*=x;
            x%=MOD;
            y>>=1;
        }
        return res;
    };
    fac[0]=invfac[0]=invfac[1]=1;
    for(long long i=1 ; i<=maxN ; i++){
        fac[i]=(fac[i-1]*i)%MOD;
        invfac[i]=binpow(fac[i], MOD-2);
    }
}

void solve(){
    long long n, k; cin>>n>>k;
    long long x=0, y=0;
    for(int i=0 ; i<n ; i++){
        char aux; cin>>aux;
        if(aux=='1') x++;
        else y++;
    }
    long long start=(k+1)/2;
    bool ok=0;
    auto binomial=[](long long a, long long b){
        // dbg(invfac[a-b]%MOD)
        // dbg(a)
        // dbg(b)
        return (fac[a]*invfac[b]%MOD*invfac[a-b]%MOD)%MOD;
    };
    long long ans=0;
    for(long long i=start ; i<=min(k, x) ; i++){
        long long zero=k-i;
        if(zero>y) continue;
        ok=1;
        // dbg(binomial(x, i))
        // dbg(binomial(y, zero))
        // dbg(x)
        // dbg(i)
        ans+=(binomial(x, i)*binomial(y, zero))%MOD;
        ans%=MOD;
    }
    // dbg(ans)
    cout<<ans<<"\n";
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