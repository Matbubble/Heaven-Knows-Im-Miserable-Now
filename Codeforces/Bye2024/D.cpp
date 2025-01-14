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
    long long n, q; cin>>n>>q;
    vector<long long>a(n), b(n);
    using T=pair<long long, long long>;
    vector<T>aa, bb;
    long long posi=0;
    for(long long &x:a){
        cin>>x;
        aa.push_back({x, posi});
        posi++;
    }
    posi=0;
    for(long long &x:b){
        cin>>x;
        bb.push_back({x, posi});
        posi++;
    }
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    vector<long long>realA(n), realB(n), unrealA(n), unrealB(n);
    long long xdxd=0;
    for(long long i=0 ; i<n ; i++){
        realA[i]=aa[i].second;
        realB[i]=bb[i].second;
        unrealA[aa[i].second]=i;
        unrealB[bb[i].second]=i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans=1;
    for(long long i=0 ; i<n ; i++){
        ans*=min(a[i], b[i]);
        ans%=MOD;
    }
    cout<<ans<<" ";
    while(q--){
        long long o, x; cin>>o>>x;
        x--;
        long long curr, diff, diff1;
        if(o==1){
            long long auxx=unrealA[x];
            // cout<<a[auxx]<<" "<<auxx<<"\n";
            diff=min(a[auxx], b[auxx]);
            a[auxx]++;
            auto it=upper_bound(a.begin(), a.end(), a[auxx]);
            curr=it-a.begin()-1;
            if(curr==auxx){
                cout<<ans<<" ";
                continue;
            }
            long long curx=realA[curr];
            swap(unrealA[x], unrealA[curx]);
            swap(realA[x], realA[curx]);
            diff1=min(a[curr], b[curr]);
            swap(a[auxx], a[curr]);
            xdxd=auxx;
            dbg(auxx)
            dbg(curr)
            // realA[unrealA[x]]
        }else{
            long long auxx=unrealB[x];
            diff=min(b[auxx], a[auxx]);
            b[auxx]++;
            auto it=upper_bound(b.begin(), b.end(), b[auxx]);
            curr=it-b.begin()-1;
            if(curr==auxx){
                cout<<ans<<" ";
                continue;
            }
            long long curx=realB[curr];
            swap(unrealB[x], unrealB[curx]);
            swap(realB[x], realB[curx]);
            diff1=min(b[curr], a[curr]);
            dbg(auxx)
            dbg(curr)
            swap(b[auxx], b[curr]);
            xdxd=auxx;
        }
        // for(long long x:a) cout<<x<<" ";
        // cout<<"\n";
        // for(long long x:b) cout<<x<<" ";
        // cout<<"\n\n";
        dbg(q)
        diff1=binpow(diff1, MOD-2);
        diff=binpow(diff, MOD-2);
        ans=(ans*diff%MOD)%MOD;
        ans=(ans*diff1%MOD)%MOD;
        dbg(xdxd)
        dbg(curr)
        ans*=min(a[xdxd], b[xdxd]);
        ans%=MOD;
        ans*=min(a[curr], b[curr]);
        ans%=MOD;
        cout<<ans<<" ";
    }
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