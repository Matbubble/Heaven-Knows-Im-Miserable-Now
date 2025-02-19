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

const long long maxN=2e5;
long long freq[maxN+1][40];

void solve(){
    long long n, q; cin>>n>>q;
    for(long long i=1 ; i<=n ; i++){
        long long aux; cin>>aux;
        for(long long j=0 ; j<40 ; j++){
            long long bit=((aux>>j)&1);
            freq[i][j]=freq[i-1][j]+bit;
        }
    }
    while(q--){
        long long ans=0;
        long long a, b; cin>>a>>b;
        for(long long j=0 ; j<40 ; j++){
            if((freq[b][j]-freq[a-1][j])&1) ans+=(1ll<<j);
        }
        cout<<ans<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}