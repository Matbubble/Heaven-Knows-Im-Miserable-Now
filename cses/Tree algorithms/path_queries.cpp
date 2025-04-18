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

const long long maxN=2e5;

struct segtree{
    long long n;
    vector<long long>st;
    segtree(long long n):n(n), st(2*n){}
    void update(long long posi, long long val){
        for(st[posi+=n]=val ; posi>1 ; posi/=2) st[posi/2]=st[posi]+st[posi^1];
    }
    long long querie(long long l, long long r){
        r++;
        long long res=0;
        for(l+=n, r+=n ; l<r ; l/=2, r/=2){
            if(l&1) res+=st[l++];
            if(r&1) res+=st[--r];
        }
        return res;
    }
}st(maxN+1);

long long depth[maxN+1], sub[maxN+1], papi[maxN+1];
vector<long long>g[maxN+1];

void dfs(long long u, long long root){
    for(long long v:g[u]){
        if(v==root) continue;
        depth[v]=depth[u]+1;
        papi[v]=u;
        dfs(v, u);
        sub[u]+=sub[v];
    }
    sub[u]++;
}

long long chainColor[maxN+1], chainHead[maxN+1], repre[maxN+1];
long long chainNo=0, position=1;
long long val[maxN+1];
vector<long long>arr;

void hld(long long u, long long root){
    chainColor[u]=chainNo;
    if(chainHead[chainColor[u]]==-1) chainHead[chainColor[u]]=u;
    repre[u]=position++;
    arr.push_back(val[u]);
    long long node=0, maxi=0;
    for(long long v:g[u]){
        if(v==root) continue;
        if(sub[v]>maxi){
            maxi=sub[v];
            node=v;
        }
    }
    if(node==0) return;
    bool ok=0;
    hld(node, u);
    for(long long v:g[u]){
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

long long padre(long long x){
    return chainHead[chainColor[x]];
}

long long path(long long u, long long v){
    long long res=0;
    while(padre(u)!=padre(v)){
        if(depth[padre(u)]<depth[padre(v)]) swap(u, v);
        res+=st.querie(repre[padre(u)], repre[u]);
        u=papi[padre(u)];
    }
    if(depth[u]>depth[v]) swap(u, v);
    res+=st.querie(repre[u], repre[v]);
    return res;
}

void solve(){
    long long n, q; cin>>n>>q;
    for(long long i=1 ; i<=n ; i++) cin>>val[i];
    for(long long i=1 ; i<n ; i++){
        long long a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    arr.push_back(0);
    dfs(1, -1);
    hld(1, -1);
    for(long long i=1 ; i<position ; i++) st.update(i, arr[i]);
    while(q--){
        long long a, b, c; cin>>a;
        if(a==1){
            cin>>b>>c;
            st.update(repre[b], c);
        }else{
            cin>>b;
            cout<<path(1, b)<<" ";
        }
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(chainHead, -1, sizeof(chainHead));
    solve();
    return 0;
}