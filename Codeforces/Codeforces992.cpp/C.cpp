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
Como me hacess faltaa
*/

void solve(){
    long long n, k; cin>>n>>k;
    if(n==1){
        if(k>=2){
            cout<<-1<<"\n";
            return;
        }else{
            cout<<1<<"\n";
            return;
        }
    }
    vector<long long>v(n);
    for(long long i=1 ; i<=n ; i++) v[i-1]=i;
    k--;
    long long curr=1;
    bool ok=0;
    // if(curr>=k) ok=1;
    for(long long i=1 ; i<n ; i++){
        if(curr>=k){
            // dbg(curr)
            ok=1;
            break;
        }
        curr*=2;
        curr++;
        if(curr>=1e13) break;
    }
    if(!ok){
        cout<<-1<<"\n";
        return;
    }
    long long l=n-2;
    for(long long i=0 ; i<64 ; i++){
        // long long num=(1<<i);
        // dbg(num)
        // dbg(k)
        if((k>>i)&1ll==1ll){
            // dbg(l)
            for(long long j=l ; j<n-1 ; j++) swap(v[j], v[j+1]);
        }
        l--;
        if(l<0) break;
    }
    for(long long x:v) cout<<x<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}