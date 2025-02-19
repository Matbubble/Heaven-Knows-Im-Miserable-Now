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
    int n;
    vector<long long>st;
    vector<long long>lazy;
    segtree(int n):n(n), st(4*(n+1)), lazy(4*(n+1)){}
    void propagate(int root, int l, int r, int ql, int qr, int val){
        if(l>=ql && r<=qr){
            lazy[root]+=val;
            return;
        }
        if(l>qr || r<ql) return;
        int mid=(l+r)>>1;
        propagate(2*root, l, mid, ql, qr, val);
        propagate(2*root+1, mid+1, r, ql, qr, val);
    }

    long long querie(int root, int l, int r, int posi){
        st[root]+=lazy[root];
        if(l==r){
            lazy[root]=0;
            return st[root];
        }
        lazy[2*root]+=lazy[root];
        lazy[2*root+1]+=lazy[root];
        lazy[root]=0;
        int mid=(l+r)>>1;
        if(posi<=mid) return querie(2*root, l, mid, posi);
        else return querie(2*root+1, mid+1, r, posi);
    }
};

void solve(){
    int n, q; cin>>n>>q;
    segtree st(n);
    for(int i=0 ; i<n ; i++){
        long long aux; cin>>aux;
        st.propagate(1, 0, n-1, i, i, aux);
    }
    while(q--){
        int type; cin>>type;
        if(type==1){
            int a, b, u; cin>>a>>b>>u;
            st.propagate(1, 0, n-1, a-1, b-1, u);
        }else{
            int k; cin>>k;
            cout<<st.querie(1, 0, n-1, k-1)<<"\n";
        }
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}