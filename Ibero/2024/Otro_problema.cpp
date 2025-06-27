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

struct segtree{
    int n;
    vector<int>st;
    segtree (int n):n(n), st(2*n){}
    void update(int posi, int val){
        for(st[posi+=n]=val ; posi>1 ; posi/=2) st[posi/2]=min(st[posi], st[posi^1]);
    }
    int querie(int l, int r){
        r++;
        int res=2*1e9;
        for(l+=n, r+=n ; l<r ; l/=2, r/=2){
            if(l&1) res=min(res, st[l++]);
            if(r&1) res=min(res, st[--r]);
        }
        return res;
    }
};

void solve(){
    int n, k; cin>>n>>k;
    vector<int>v(n+1), dp(n+1);
    segtree st(n+1);
    for(int i=1 ; i<=n ; i++) cin>>v[i];
    for(int i=1 ; i<=n ; i++){
        int busca=k-v[i];
        if(busca>v[i]) busca=v[i];
        auto it=upper_bound(v.begin(), v.end(), busca);
        int mini=0;
        it--;
        dp[i]=(it-v.begin());
        st.update(i, dp[i]+i);
        // dbg(dp[i])
    }
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        if(l==r){
            if(v[l]<=k) cout<<1<<"\n";
            else cout<<0<<"\n";
            continue;
        }
        if((r-l+1)%2==1){
            if(v[r]>k){
                cout<<0;
                continue;
            }
            r--;
        }
        // dbg(st.querie(((l+r)/2)+1, r))
        if(st.querie(((l+r)/2)+1, r)>=(l+r) && dp[r]>=l) cout<<1;
        else cout<<0;
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}