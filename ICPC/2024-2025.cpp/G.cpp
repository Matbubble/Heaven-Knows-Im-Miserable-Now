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
Kissy face uuuu
*/

const long long maxN=1e5;
vector<pair<long long, long long> > g[maxN+1];
long long dp[maxN+1];
pair<long long, long long> dis[maxN+1];
bool vis[maxN+1];
vector<vector<pair<long long, long long> > >queries(maxN+1);
long long ans[maxN+1];

void dfs(long long u, long long root){
    bool leaf=1;
    vis[u]=1;
    for(auto v:g[u]){
        if(v.first==root) continue;
        leaf=0;
        dfs(v.first, u);
    }
    if(leaf){
        dp[u]++;
        dis[u]=make_pair(u, 0);
        return;
    }
    for(auto v:g[u]){
        if(v.first==root) continue;
        long long curr=dis[v.first].second+v.second;
        if(curr<dis[u].second){
            dis[u].second=curr;
            dis[u].first=dis[v.first].first;
        }else if(curr==dis[u].second){
            dis[u].first=min(dis[u].first, dis[v.first].first);
        }
    }
    dp[dis[u].first]++;
}

void dfs1(long long u, long long root, long long izq, long long der){
    dp[izq]++;
    dp[der]--;
    for(auto x:queries[u]){
        ans[x.second]=dp[x.first];
    }
    pair<long long, long long>temp;
    long long curr=1e18, num=1e18;
    for(auto v:g[u]){
        if(dis[u].first==dis[v.first].first) continue;
        if(curr>dis[v.first].second+v.second){
            curr=dis[v.first].second+v.second;
            num=dis[v.first].first;
        }
        else if(curr==dis[v.first].second+v.second){
            num=min(num, dis[v.first].first);
        }
    }
    temp=make_pair(num, curr);
    for(auto v:g[u]){
        if(v.first==root) continue;
        if(dis[u].first==dis[v.first].first){
            auto[xx, yy]=dis[u];
            dis[u]=temp;
            dfs1(v.first, u, temp.first, xx);
            dis[u]=make_pair(xx, yy);
        }else{
            pair<long long, long long> temp1=dis[v.first];
            if(dis[u].second+v.second < dis[v.first].second){
                temp1.first=dis[u].first;
                temp1.second=dis[u].second+v.second;
            }else if(dis[u].second+v.second == dis[v.first].second){
                temp1.first=min(dis[u].first, dis[v.first].first);
            }
            auto[xx, yy]=dis[v.first];
            dis[v.first]=temp1;
            dfs1(v.first, u, temp1.first==xx?0:temp1.first, temp1.first==xx?0:xx);
            dis[v.first]=make_pair(xx, yy);
        }
    }
    dp[izq]--;
    dp[der]++;
    return;
}

int main(){
    long long n; cin>>n;
    for(long long i=0 ; i<=n ; i++){
        dis[i]=make_pair(0, 1e18);
        vis[i]=0;
    }
    for(long long i=1 ; i<n ; i++){
        long long a, b, c; cin>>a>>b>>c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    long long aux=-1;
    for(long long i=1 ; i<=n ; i++){
        if((long long)g[i].size() > 1) aux=i;
    }
    dfs(aux, -1);
    long long q, posi=0; cin>>q;
    for(long long i=0 ; i<q ; i++){
        long long a, b; cin>>a>>b;
        queries[b].push_back(make_pair(a, posi));
        posi++;
    }
    dfs1(aux, -1, 0, 0);
    for(long long i=0 ; i<q ; i++) cout<<ans[i]<<"\n";
    return 0;
}
