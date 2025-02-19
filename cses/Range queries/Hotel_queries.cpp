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
    vector<pair<int, set<int>>>st;
    segtree(int n):n(n), st(4*(n+1)){}
    pair<int, int> querie(int root, int l, int r, int ql, int qr){
        if(l>=ql && r<=qr){
            return {*st[root].second.begin(), st[root].first};
        }
        if(l>qr || r<ql) return {1e9, -1};
        int mid=(l+r)>>1;
        pair<int, int>a=querie(2*root, l, mid, ql , qr);
        pair<int, int>b=querie(2*root+1, mid+1, r, ql, qr);
        if(a.first<b.first) return a;
        else return b;
    }
    void kill(int root, int l, int r, int rkill){
        if(l==r){
            st[root].second.erase(st[root].second.begin());
            if(st[root].second.empty()) st[root].second.insert(1e9);
            st[root].first=l;
            return;
        }
        int mid=(l+r)>>1;
        if(rkill<=mid) kill(2*root, l, mid, rkill);
        else kill(2*root+1, mid+1, r, rkill);
        pair<int, set<int>>a=st[2*root];
        pair<int, set<int>>b=st[2*root+1];
        if(*a.second.begin()<*b.second.begin()){
            set<int> aux;
            aux.insert(*a.second.begin());
            st[root]={a.first, aux};
        }
        else{
            set<int> aux;
            aux.insert(*b.second.begin());
            st[root]={b.first, aux};
        }
    }
    void update(int root, int l, int r, int posi, int val){
        if(l==r){
            st[root].second.insert(val);
            st[root].first=l;
            return;
        }
        int mid=(l+r)>>1;
        if(posi<=mid) kill(2*root, l, mid, posi);
        else kill(2*root+1, mid+1, r, posi);
        pair<int, set<int>>a=st[2*root];
        pair<int, set<int>>b=st[2*root+1];
        if(*a.second.begin()<*b.second.begin()){
            set<int> aux;
            aux.insert(*a.second.begin());
            st[root]={a.first, aux};
        }
        else{
            set<int> aux;
            aux.insert(*b.second.begin());
            st[root]={b.first, aux};
        }
    }
};

void solve(){
    int n, m; cin>>n>>m;
    set<int>cast;
    map<int, int>val;
    vector<int>v(n), q(m);
    for(int &x:v){
        cin>>x;
        cast.insert(x);
    }
    for(int &x:q){
        cin>>x;
        cast.insert(x);
    }
    int posi=1;
    for(int x:cast) val[x]=posi++;
    posi++;
    segtree st(n);
    for(int i=1 ; i<=n ; i++){
        int x=v[i];
        st.update(1, 1, posi, val[x], i);
    }
    for(int x:q){
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}