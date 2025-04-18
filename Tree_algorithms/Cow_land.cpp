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

const int maxN=1e5;

struct segtree{
    int n;
    vector<int>st;
    segtree(int n):n(n), st(2*n){}
    void update(int posi, int val){
        for(st[posi+=n]=val ; posi>1 ; posi/=2) st[posi/2]=st[posi]^st[posi^1];
    }
    int querie(int l, int r){
        r++;
        int res=0;
        for(l+=n, r+=n ; l<r ; l/=2, r/=2){
            if(l&1) res^=st[l++];
            if(r&1) res^=st[--r];
        }
        return res;
    }
}st(maxN+1);

int val[maxN+1];
int depth[maxN+1], papi[maxN+1], sub[maxN+1];
int chainColor[maxN+1], chainHead[maxN+1], repre[maxN+1];
int chainNo=0, position=1;
vector<int> g[maxN+1];
void dfs(int u, int root){
    for(int v:g[u]){
        if(v==root) continue;
        papi[v]=u;
        depth[v]=depth[u]+1;
        dfs(v, u);
        sub[u]+=sub[v];
    }
    sub[u]++;
}

vector<int>arr;
void hld(int u, int root){
    chainColor[u]=chainNo;
    if(chainHead[chainColor[u]]==-1) chainHead[chainColor[u]]=u;
    repre[u]=position++;
    arr.push_back(val[u]);
    int maxi=0, node=0;
    for(int v:g[u]){
        if(v==root) continue;
        if(sub[v]>maxi){
            maxi=sub[v];
            node=v;
        }
    }
    if(node==0) return;
    hld(node, u);
    bool ok=0;
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

int path(int u, int v){
    // dbg(u)
    // dbg(v)
    int res=0;
    while(padre(u)!=padre(v)){
        if(depth[padre(u)]<depth[padre(v)]) swap(u, v);
        res^=st.querie(repre[padre(u)], repre[u]);
        // dbg(repre[padre(u)])
        u=papi[padre(u)];
    }
    if(depth[u]>depth[v]) swap(u, v);
    // dbg(u)
    // dbg(v)
    // dbg(repre[u])
    res^=st.querie(repre[u], repre[v]);
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
    arr.push_back(0);
    hld(1, -1);
    for(int i=1 ; i<position ; i++) st.update(i, arr[i]);
    while(q--){
        int a, b, c; cin>>a>>b>>c;
        if(a==1){
            st.update(repre[b], c);
        }else{
            cout<<path(b, c)<<"\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    memset(chainHead, -1, sizeof(chainHead));
    solve();
    return 0;
}