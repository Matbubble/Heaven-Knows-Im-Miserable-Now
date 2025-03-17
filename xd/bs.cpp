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

//Calcula la respuesta MODULO 1e9+7

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>>g(n+1);
    vector<bool>vis(n+1, 0);
    for(int i=0 ; i<m ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int>bfs;
    bfs.push(0);
    vis[0]=1;
    while(!bfs.empty()){
        int u=bfs.front();
        vis[u]=1;
        bfs.pop();
        for(int v:g[u]){
            if(vis[v]!=1){
                bfs.push(v);
            }
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