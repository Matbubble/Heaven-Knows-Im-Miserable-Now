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
#define inf 1e18;
using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
aaa
*/

const int maxN=1e5;
const long long MOD=1e9+7;
long long dis[maxN+1], dis_ways[maxN+1], min_way[maxN+1], max_way[maxN+1];
vector<pair<int, long long> > g[maxN+1], g1[maxN+1];
bool vis[maxN+1];

void dfs(int u){
    vis[u]=1;
    for(pair<int, long long> v:g1[u]){
        if(vis[v.first]==1) continue;
        dfs(v.first);
    }
    if(u==1){
        // dbg(123)
        dis_ways[u]=1;
        min_way[u]=0;
        max_way[u]=1;
    }else{
        for(pair<int, long long> v:g1[u]){
            if(dis[v.first]+v.second==dis[u]){
                dis_ways[u]*=dis_ways[v.first];
                // dbg(v.first)
                // dbg(min_way[v.first]);
                min_way[u]=min(min_way[u], min_way[v.first]+1);
                max_way[u]=max(max_way[u], max_way[v.first]+1);
            }
        }
    }


}

void solve(){
    for(int i=1 ; i<=maxN ; i++){
        dis[i]=inf;
        dis_ways[i]=1;
        min_way[i]=inf;

    }
    int n, m; cin>>n>>m;
    for(int i=0 ; i<n ; i++){
        int a, b; cin>>a>>b;
        long long c; cin>>c;
        g[a].push_back(make_pair(b, c));
        g1[b].push_back(make_pair(a, c));
    }
    using T = pair<long long, int>;
    priority_queue<T, vector<T>, greater<T> >dijkstra;
    dijkstra.push(make_pair(0, 1));
    dis[1]=0;
    while(!dijkstra.empty()){
        auto [kate, u]=dijkstra.top();
        dijkstra.pop();
        for(pair<int, long long> &v:g[u]){
            if(kate+v.second < dis[v.first]){
                dijkstra.push(make_pair(dis[v.first]=kate+v.second, v.first));
            }
        }
    }
    dfs(n);
    cout<<dis[n]<<" "<<dis_ways[n]<<" "<<min_way[n]<<" "<<max_way[n]<<"\n";
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}