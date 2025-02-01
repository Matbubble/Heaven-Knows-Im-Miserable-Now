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
That's life
Frank Sinatra
*/

const long long inf=1e18;
struct segtree{
    const vector<long long> init={-inf, -inf, -inf, -inf};
    vector<long long>st;
    long long n;
    vector<vector<long long>>dp;
    segtree(long long n):n(n){
        st.resize(4*n+1, 0);
        dp.resize(4*n+1, init);
    }
    void update(long long posi, long long val){update(1, 0, n-1, posi, val);}
    void update(long long root, long long l, long long r, long long posi, long long val){
        if(l==r){
            st[root]=0;
            dp[root][0]=-val-posi;
            dp[root][1]=-val+posi;
            dp[root][2]=val-posi;
            dp[root][3]=val+posi;
        }else{
            long long mid=(l+r)>>1ll;
            if(posi<=mid) update(2*root, l, mid, posi, val);
            else update(2*root+1, mid+1, r, posi, val);
            st[root]=max({st[2*root], st[2*root+1], dp[2*root][1]+dp[2*root+1][2], dp[2*root][3]+dp[2*root+1][0]});
            for(long long i=0 ; i<4 ; i++) dp[root][i]=max(dp[2*root][i], dp[2*root+1][i]);
        }
    }
};  

void solve(){
    long long n, q; cin>>n>>q;
    segtree st(n);
    for(long long i=0 ; i<n ; i++){
        long long aux; cin>>aux;
        st.update(i, aux);
    }
    cout<<st.st[1]<<"\n";
    while(q--){
        long long posi, val; cin>>posi>>val;
        st.update(posi-1, val);
        cout<<st.st[1]<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}