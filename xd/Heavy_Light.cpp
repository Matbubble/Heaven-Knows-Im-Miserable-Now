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

long long n;
long long chainNo=1, posi=0;
vector<vector<long long>>g;
vector<long long>val;
vector<long long>depth, papi, sub;
vector<long long>arr, repre;
vector<long long>chainColor, chainhead;

struct segtree{
    long long n;
    vector<long long>st;
    segtree(long long n):n(n), st(2*n){}
    void update(long long root, long long l, long long r, long long val, long long posi){
        if(l==r){
            st[root]=val;
            return;
        }
        long long mid=(l+r)/2;
        if(mid>=posi) update(2*root, l, mid, val, posi);
        else update(2*root+1, mid+1, r, val, posi);
        st[root]=max(st[2*root], st[2*root+1]);
    }
    long long querie(long long root, long long l, long long r, long long ql, long long qr){
        if(l>qr || r<ql) return 0;
        if(l>=ql && r<=qr) return st[root];
        long long mid=(l+r)/2;
        return max(querie(2*root, l, mid, ql, qr), querie(2*root+1, mid+1, r, ql, qr));
    }
}st(200001);

void dfs1(long long u, long long root){
    for(long long v:g[u]){
        if(v==root) continue;
        papi[v]=u;
        depth[v]=depth[u]+1;
        dfs1(v, u);
        sub[u]+=sub[v];
    }
    sub[u]++;
}

long long padre(long long node){
    return chainhead[chainColor[node]];
}

void hld(long long u, long long root){
    chainColor[u]=chainNo;
    repre[u]=posi++;
    arr.push_back(val[u]);
    if(chainhead[chainColor[u]]==-1){
        chainhead[chainColor[u]]=u;
    }
    long long maxi=0, node=0;
    for(long long v:g[u]){
        if(v==root) continue;
        if(sub[v]>maxi){
            maxi=sub[v];
            node=v;
        }
    }
    bool ok=0;
    if(node==0) return;
    hld(node, u);
    for(long long v:g[u]){
        if(v==root) continue;
        if(!ok){
            if(v==node){
                ok=1;
            }else{
                chainNo++;
                hld(v, u);
            }
        }else{
            chainNo++;
            hld(v, u);
        }
    }
}

long long path(long long u, long long v){
    long long res=0;
    while(padre(u)!=padre(v)){
        if(depth[padre(u)]>depth[padre(v)]) swap(u, v);
        res=max(res, st.querie(1, 0, n-1, repre[padre(v)], repre[v]));
        v=papi[padre(v)];
    }
    if(depth[u]>depth[v]) swap(u, v);
    res=max(res, st.querie(1, 0, n-1, repre[u], repre[v]));
    return res;
}

void solve(){
    long long q; cin>>n>>q;
    g.resize(n+1);
    val.resize(n+1);
    for(long long i=1 ; i<=n ; i++){
        long long uwu; cin>>uwu;
        val[i]=uwu;
    }
    for(long long i=1 ; i<n ; i++){
        long long a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    depth.resize(n+1);
    papi.resize(n+1);
    sub.resize(n+1);
    depth[1]=0;
    dfs1(1, -1);
    chainColor.resize(n+1);
    chainhead.resize(n+1, -1);
    repre.resize(n+1);
    hld(1, -1);
    for(long long i=0 ; i<(long long)arr.size() ; i++) st.update(1, 0, n-1, arr[i], i);
    while(q--){
        long long one, two, three; cin>>one>>two>>three;
        if(one==1){
            st.update(1, 0, n-1, three, repre[two]);
        }else{
            cout<<path(two, three)<<" ";
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