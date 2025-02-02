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
    segtree(long long n):n(n), st(4*(n+1)){}
    void update(long long root, long long l, long long r, long long posi, long long val){
        if(l==r){
            st[root]=max(st[root], val);
            return;
        }
        long long mid=(l+r)>>1;
        if(posi<=mid) update(2*root, l, mid, posi, val);
        else update(2*root+1, mid+1, r, posi, val);
        st[root]=max(st[2*root], st[2*root+1]);
    }
    long long querie(long long root, long long l, long long r, long long ql, long long qr){
        // dbg(root)
        if(l>=ql && r<=qr) return st[root];
        if(l>qr || r<ql) return 0;
        long long mid=(l+r)>>1;
        return max(querie(2*root, l, mid, ql, qr), querie(2*root+1, mid+1, r, ql, qr));
    }
};

struct point{
    long long x, y, z;
};

void solve(){
    long long n; cin>>n;
    vector<point>v(n);
    set<long long>cast;
    map<long long, long long>posi;
    for(point &x:v){
        cin>>x.x>>x.y>>x.z;
        cast.insert(x.x); cast.insert(x.y);
        cast.insert(x.y+1);
    }
    long long val=0;
    for(long long x:cast) posi[x]=val++;
    sort(v.begin(), v.end(), [](point a, point b){
        return a.y<b.y;
    });
    segtree st(val);
    for(point x:v){
        long long maxi=st.querie(1, 0, val-1, 0, posi[x.x]);
        // dbg(maxi)
        // dbg(x.x)
        st.update(1, 0, val-1, posi[x.y+1], maxi+x.z);
    }
    cout<<st.querie(1, 0, val-1, 0, val-1)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}