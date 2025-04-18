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

const int maxN=5e3;

struct segtree{
    int n;
    vector<int>st;
    segtree(int n):n(n), st(2*n){}
    int querie(int ql, int qr){
        qr++;
        if(ql>=qr) return 1e9;
        int res=1e9;
        for(ql+=n, qr+=n ; ql<qr ; ql/=2, qr/=2){
            if(ql&1) res=min(res, st[ql++]);
            if(qr&1) res=min(res, st[--qr]);
        }
        return res;
    }

    void update(int posi, int val){
        for(st[posi+=n]=val ; posi>1 ; posi/=2) st[posi/2]=min(st[posi],st[posi^1]);
    }
}st(maxN+1);

vector<pair<int, int>>g[maxN+1];
int value[maxN+1];
int sub[maxN+1], depth[maxN+1], papi[maxN+1];
int chainColor[maxN+1], chainHead[maxN+1], repre[maxN+1];
int chainNo=1, position=1;

void dfs(int v, int root){
    for(pair<int, int> u:g[v]){
        if(u.first==root) continue;
        value[u.first]=u.second;
        papi[u.first]=v;
        depth[u.first]=depth[v]+1;
        dfs(u.first, v);
        sub[v]+=sub[u.first]; 
    }
    sub[v]++;
}


vector<long long>arr;

void hld(int u, int root){
    chainColor[u]=chainNo;
    if(chainHead[chainColor[u]]==-1) chainHead[chainColor[u]]=u;
    repre[u]=position++;
    arr.push_back(value[u]);
    int maxi=0, node=0;
    for(pair<int, int> v:g[u]){
        if(v.first==root) continue;
        if(sub[v.first]>maxi){
            maxi=sub[v.first];
            node=v.first;
        }
    }
    if(node==0) return;
    hld(node, u);
    bool ok=0;
    for(pair<int, int> v:g[u]){
        if(v.first==root) continue;
        if(!ok){
            if(v.first==node) ok=1;
            else{
                chainNo++; 
                hld(v.first, u);
            }
        }else{
            chainNo++;
            hld(v.first, u);
        }
    }
}

int dad(int x){
    return chainHead[chainColor[x]];
}

int path(int u, int v){
    int ans=1e9;
    while(dad(u)!=dad(v)){
        if(depth[dad(v)]>depth[dad(u)]) swap(u, v);
        ans=min(ans, st.querie(repre[dad(u)], repre[u]));
        u=papi[dad(u)];
    }
    if(depth[v]<depth[u]) swap(u, v);
    ans=min(ans, st.querie(repre[u]+1, repre[v]));
    return ans;
}


void solve(){
    arr.push_back(1e9);
    int n, q; cin>>n>>q;
    value[1]=1e9;
    for(int i=1 ; i<n ; i++){
        int a, b, w; cin>>a>>b>>w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    for(int i=1 ; i<=n ; i++) chainHead[i]=-1;
    dfs(1, -1);
    hld(1, -1);
    for(int i=1 ; i<position ; i++) st.update(i, arr[i]);
    while(q--){
        int k, init; cin>>k>>init;
        int ans=0;
        for(int i=1 ; i<=n ; i++){
            if(i==init) continue;
            // dbg(i)
            // dbg(init)
            // dbg(path(i, init))
            // dbg("----")
            if(path(i, init)>=k) ans++;
        }
        cout<<ans<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    solve();
    return 0;
}