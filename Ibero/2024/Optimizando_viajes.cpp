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
#include <cassert>

using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
MC lover
*/

struct fentree{
    long long n;
    vector<long long>ft;
    fentree (long long n):n(n), ft(n){}
    void update(long long posi, long long val){
        while(posi<=n){
            ft[posi]+=val;
            posi+=posi&-posi;
        }
    }
    long long querie(long long posi){
        long long res=0;
        while(posi>0){
            res+=ft[posi];
            posi-=posi&-posi;
        }
        return res;
    }
};

void solve(){
    long long n, m, k; cin>>n>>m>>k;
    long long a, b; cin>>a>>b;
    long long l, r; cin>>l>>r;
    vector<vector<pair<long long, long long>>>g(n+1);
    for(long long i=0 ; i<m ; i++){
        long long u, v, w; cin>>u>>v>>w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    using T=pair<long long, long long>;
    set<long long>cast;
    priority_queue<T, vector<T>, greater<T>>bfs;
    vector<long long>dis1(n+1, 1e18), dis2(n+1, 1e18);
    dis1[a]=0;
    bfs.push({0, a});
    while(!bfs.empty()){
        long long u=bfs.top().second;
        bfs.pop();
        for(pair<long long, long long> v:g[u]){
            if(dis1[v.first]>dis1[u]+v.second){
                dis1[v.first]=dis1[u]+v.second;
                bfs.push({dis1[v.first], v.first});
            }
        }
    }
    dis2[b]=0;
    bfs.push({0, b});
    while(!bfs.empty()){
        long long u=bfs.top().second;
        bfs.pop();
        for(pair<long long, long long> v:g[u]){
            if(dis2[v.first]>dis2[u]+v.second){
                dis2[v.first]=dis2[u]+v.second;
                bfs.push({dis2[v.first], v.first});
            }
        }
    }
    if(dis1[b]<k){
        cout<<0<<"\n";
        return;
    }else if(dis1[b]==k){
        long long ans=0;
        vector<set<int>>op(n+1);
        for(int i=1 ; i<=n ; i++){
            for(pair<int, int> v:g[i]) op[i].insert(v.first);
        }
        for(long long i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(op[i].count(j) || i==j) continue;
                int x=i, y=j;
                if(dis2[y]<dis2[x]) swap(x, y);
                if(min(dis1[x], dis1[y])>=k) ans+=r-l+1;
                else ans+=max(0ll, dis1[y]+r-max(dis1[y]+l, k-dis2[x])+1);
                // dbg(ans)
                // dbg(i)
                // dbg(j)
                // dbg("---")
            }
        }
        cout<<ans/2<<"\n";
        return;
    }
    map<long long, long long>val;
    long long posi=0;
    for(long long i=1 ; i<=n ; i++){
        cast.insert(k-dis1[i]-l);
        cast.insert(k-dis1[i]-r);
        cast.insert(dis2[i]);
    }
    for(long long x:cast) val[x]=++posi;
    fentree ft(posi+1);
    for(long long i=1 ; i<=n ; i++) ft.update(val[dis2[i]], 1);
    long long ans=0;
    for(long long i=1 ; i<=n ; i++){
        for(pair<long long, long long> v:g[i]) ft.update(val[dis2[v.first]], -1);
        ans+=ft.querie(val[k-dis1[i]-l])-ft.querie(val[k-dis1[i]-r]-1);
        for(pair<long long, long long> v:g[i]) ft.update(val[dis2[v.first]], 1);
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}