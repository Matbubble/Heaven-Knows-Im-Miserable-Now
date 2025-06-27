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
#include <cassert>

using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
MC lover
*/

long long binpow(long long a, long long b){
    long long res=1;
    while(b>0){
        if((b&1ll)){
            res*=a;
        }
        a*=a;
        b>>=1ll;
    }
    return res;
}

void solve(){
    long long x, y, ans=1e18; cin>>x>>y;
    for(long long i=0 ; i<=60 ; i++){
        for(long long j=0 ; j<=i ; j++){
            long long a=binpow(2, j), b=binpow(2, i-j);
            if(max(x, y)/max(a, b)==min(x, y)/min(a, b)){
                
            }
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}