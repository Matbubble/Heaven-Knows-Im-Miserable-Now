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

struct segtree{
    long long n;
    vector<long long>st;
    segtree(long long n):n(n), st(2*n){}
    long long querie(long long l, long long r){
        r++;
        long long res=0;
        for(l+=n, r+=n ; l<r ; l/=2, r/=2){
            if(l&1) res+=st[l++];
            if(r&1) res+=st[--r];
        }
        return res;
    }

    void update(long long posi, long long val){
        for(st[posi+=n]=val ; posi>1 ; posi/=2) st[posi/2]=st[posi]+st[posi^1];
    }
};

void solve(){
    long long n, m; cin>>n>>m;
    segtree st(m+1);
    vector<long long>v(m+1);
    n-=2;
    for(long long i=1 ; i<=m ; i++){
        cin>>v[i];
        v[i]=min(v[i]-1, n);
    }
    sort(v.begin(), v.end());
    for(long long i=1 ; i<=m ; i++) st.update(i, v[i]);
    long long ans=0;
    for(long long i=1 ; i<=m ; i++){
        long long left=n-v[i];
        auto it=lower_bound(v.begin(), v.end(), left);
        if(it==v.begin()) it++;
        long long posi=(it-v.begin());
        if(posi>=i) continue;
        // dbg(left)
        // dbg(posi)
        // dbg(st.querie(posi, i-1))
        // dbg((st.querie(posi, i-1)-(left*(i-posi))+(i-posi))*2)
        ans+=(st.querie(posi, i-1)-(left*(i-posi))+(i-posi))*2;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}