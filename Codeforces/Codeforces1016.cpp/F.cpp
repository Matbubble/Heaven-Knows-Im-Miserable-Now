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

void solve(){
    long long n, m; cin>>n>>m;
    vector<string>curr(n);
    vector<long long>posible(n);
    for(string &x:curr) cin>>x;
    long long ans=1e18;
    for(long long i=0 ; i<m ; i++){
        long long a=0, b=0;
        for(long long j=0 ; j<n ; j++){
            string aux; cin>>aux;
            if(aux==curr[j]){
                posible[j]=1;
                a++;
            }else b++;
        }
        ans=min(ans, a+(3*b));
    }
    bool ok=1;
    for(long long x:posible) ok&=x;
    if(!ok) cout<<-1<<"\n";
    else cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}