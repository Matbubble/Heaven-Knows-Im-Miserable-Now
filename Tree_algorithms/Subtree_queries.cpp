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
    segtree(long long n):n(n), st(2*n){};
    long long querie(long long l, long long r){
        long long res=0;
        for(l+=n, r+=n ; l<r ; l/=2, r/=2){
            if(l&1) res+=st[l++];
            if(r&1) res+=st[--r];
        }
        return res;
    }
    void update(long long posi, long long val){
        for(st[posi+=n]=val ; posi>1 ; posi/=2){
            st[posi/2]=st[posi]+st[posi^1];
        }
    }
};

long long repre[maxN+1], sub[maxN+1];
vector<long long>g[maxN+1];
long long position=1;
vector<long long>val, curr;

void dfs(long long u, long long root){
    repre[u]=position++;
    curr.push_back(val[u]);
    for(long long v:g[u]){
        if(v==root) continue;
        dfs(v, u);
        sub[u]+=sub[v];
    }
    sub[u]++;
}

void solve(){
    val.push_back(0);
    curr.push_back(0);
    long long n, q; cin>>n>>q;
    for(long long i=1 ; i<=n ; i++){
        long long aux; cin>>aux;
        val.push_back(aux);
    }
    for(long long i=1 ; i<n ; i++){
        long long a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    segtree st(position+1);
    for(long long i=1 ; i<=position ; i++){
        st.update(i, curr[i]);
    }
    while(q--){
        long long type; cin>>type;
        if(type==1){
            long long s, x; cin>>s>>x;
            st.update(repre[s], x);
        }else{
            long long s; cin>>s;
            cout<<st.querie(repre[s], repre[s]+sub[s])<<"\n";
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