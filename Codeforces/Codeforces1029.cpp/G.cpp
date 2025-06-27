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

struct dsu{
    long long n;
    vector<long long>p;
    dsu(long long n):n(n){
        for(long long i=0 ; i<=n ; i++) p.push_back(i);
    }
    long long find(long long x){
        return (p[x]==x?x:p[x]=find(p[x]));
    }
    bool united(long long a, long long b){
        a=find(a); b=find(b);
        if(a==b) return true;
        p[a]=b;
        return false;
    }
};

struct edge{
    long long a, b, w;
};

void solve(){
    long long n, m; cin>>n>>m;
    vector<vector<pair<long long, long long>>>g(n+1);
    vector<edge>e;
    for(long long i=0 ; i<m ; i++){
        long long a, b, c; cin>>a>>b>>c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        e.push_back({a, b, c});
    }
    using T=pair<long long, pair<long long, long long>>;
    priority_queue<T, vector<T>, greater<T>>bfs;
    vector<long long>dis1(n+1, 1e10), dis2(n+1, 1e10);
    dis1[1]=0;
    dis2[n]=0;
    bfs.push(make_pair(0, make_pair(0, 1)));
    while(!bfs.empty()){
        long long u=bfs.top().second.second;
        long long peso=bfs.top().first;
        long long pesoo=bfs.top().second.first;
        bfs.pop();
        if(dis1[u]==1e10){
            dis1[u]=max(peso, pesoo);
        }else if(dis1[u]>0) continue;
        for(pair<long long, long long> v:g[u]){
            if(dis1[v.first]==1e10){
                bfs.push(make_pair(v.second, make_pair(dis1[u], v.first)));
            }
        }
    }
    bfs.push(make_pair(0, make_pair(0, n)));
    while(!bfs.empty()){
        long long u=bfs.top().second.second;
        long long peso=bfs.top().first;
        long long pesoo=bfs.top().second.first;
        bfs.pop();
        if(dis2[u]==1e10){
            dis2[u]=max(peso, pesoo);
        }else if(dis2[u]>0) continue;
        for(pair<long long, long long> v:g[u]){
            if(dis2[v.first]==1e10){
                bfs.push(make_pair(v.second, make_pair(dis2[u], v.first)));
            }
        }
    }
    long long ans=1e10;
    for(edge it:e){
        ans=min(ans, it.w+max({it.w, dis1[it.a], dis2[it.b]}));
        ans=min(ans, it.w+max({it.w, dis2[it.a], dis1[it.b]}));
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