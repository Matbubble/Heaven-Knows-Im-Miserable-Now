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

const int maxN=2e5;
int val[maxN+1], papi[maxN+1], sub[maxN+1], depth[maxN+1];
vector<int>g[maxN+1];

struct segtree{
    int n;
    vector<int>st;
    segtree(int n):n(n), st(2*n){}
    int querie(int l, int r){
        int res=0;
        for(l+=n, r+=n ; l<r ; l/=2, r/=2){
            if(l&1) res=max(res, st[l++]);
            if(r&1) res=max(res, st[--r]);
        }
        return res;
    }
    void update(int posi, int val){
        for(st[posi+=n]=val ; posi>1 ; posi/=2) st[posi/2]=max(st[posi], st[posi^1]);
    }
}st(maxN+1);

void dfs(int u, int root){
    // dbg(u)
    for(int v:g[u]){
        if(v==root) continue;
        papi[v]=u;
        depth[v]=depth[u]+1;
        dfs(v, u);
        sub[u]+=sub[v];
    }
    sub[u]++;
}

int chainNo=0, posi=0;
int repre[maxN+1], chainColor[maxN+1], chainHead[maxN+1];
vector<int>xd;

void hld(int u, int root){
    chainColor[u]=chainNo;
    if(chainHead[chainColor[u]]==-1){
        chainHead[chainColor[u]]=u;
    }
    repre[u]=++posi;
    xd.push_back(val[u]);
    int node=0, maxi=0;
    for(int v:g[u]){
        if(v==root) continue;
        if(sub[v]>maxi){
            maxi=sub[v];
            node=v;
        }
    }
    if(node==0) return;
    bool ok=0;
    hld(node, u);
    for(int v:g[u]){
        if(v==root) continue;
        if(!ok){
            if(v==node) ok=1;
            else{
                chainNo++;
                hld(v, u);
            }
        }else{
            chainNo++;
            hld(v, u);
        }
    }
}

int padre(int x){
    return chainHead[chainColor[x]];
}

int querie(int u, int v){
    int res=0;
    while(padre(u)!=padre(v)){
        if(depth[padre(u)]<depth[padre(v)]) swap(u, v);
        res=max(res, st.querie(repre[padre(u)], repre[u]));
        // dbg(res)
        u=papi[padre(u)];
    }
    if(depth[u]>depth[v]) swap(u, v);
    res=max(res, st.querie(repre[u], repre[v]));
    // dbg(res)
    return res;
}

void solve(){
    int n, q; cin>>n>>q;
    for(int i=1 ; i<=n ; i++) cin>>val[i];
    for(int i=1 ; i<n ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    hld(1, -1);
    for(int i=0 ; i<posi-1 ; i++) st.update(i+1, xd[i]);
    while(q--){
        int a, b, c; cin>>a>>b>>c;
        // dbg(repre[b])
        if(a==1) st.update(repre[b], c);
        else cout<<querie(b, c)<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(chainHead, -1, sizeof(chainHead));
    solve();
    return 0;
}