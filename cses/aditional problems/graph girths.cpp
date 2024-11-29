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
Katetilin de Mati
*/
const int maxN=2500;
vector<int>g[maxN+1];
bool vis[maxN+1];
int dis[maxN+1];

void solve(){
    int n, m; cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<pair<int, int> >bfs;
    bfs.push(make_pair(1, 0));
    dis[1]=1;
    int ans=1e9;
    while(!bfs.empty()){
        int u=bfs.front().first;
        if(vis[u]){
            dbg(dis[u])
            dbg(u)
            dbg(bfs.front().second)
            ans=min(ans, abs(dis[u]-bfs.front().second+1));
            bfs.pop();
            continue;
        }else vis[u]=1;
        bfs.pop();
        for(int v:g[u]){
            if(v==u) continue;
            if(!vis[v]) dis[v]=dis[u]+1;
            bfs.push(make_pair(v, u));
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}