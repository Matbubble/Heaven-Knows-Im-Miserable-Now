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
    segtree(int n):n(n), st(4*(n+1), 1e9){}
    void update(int root, int l, int r, int posi, int val){
        if(l==r){
            st[root]=val;
            return;
        }
        int mid=((l+r)>>1);
        if(mid>=posi) update(2*root, l, mid, posi, val);
        else update(2*root+1, mid+1, r, posi, val);
        st[root]=min(st[2*root], st[2*root+1]);
    }

    long long querie(int root, int l, int r, int ql, int qr){
        if(l>=ql && r<=qr) return st[root];
        if(l>qr || r<ql) return 1e9;
        int mid=(l+r)>>1;
        return min(querie(2*root, l, mid, ql, qr), querie(2*root+1, mid+1, r, ql, qr));
    }
};

void solve(){
    int n, q; cin>>n>>q;
    segtree st(n);
    for(int i=0 ; i<n ; i++){
        long long aux; cin>>aux;
        st.update(1, 0, n-1, i, aux);
    }
    while(q--){
        int type, a, b; cin>>a>>b;
        cout<<st.querie(1, 0, n-1, a-1, b-1)<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}