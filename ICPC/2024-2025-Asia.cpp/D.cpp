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
Shhhhh!
*/

int dirx[]={1, 0, -1, 0};
int diry[]={0, -1, 0, 1};

void solve(){
    int n, m; cin>>n>>m;
    char lab[n][m];
    bool vis[n][m];
    using T=pair<int, int>;
    T dp[n][m];
    T init, last;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>lab[i][j];
            if(lab[i][j]=='S') init={i, j};
            if(lab[i][j]=='T') last={i, j};
            dp[i][j]={0, 0};
            vis[i][j]=0;
        }
    }
    vis[init.first][init.second]=1;
    queue<T>bfs;
    bfs.push(init);
    while(!bfs.empty()){
        auto[x, y]=bfs.front();
        vis[x][y]=1;
        bfs.pop();
        for(int i=0 ; i<4 ; i++){
            T curr={x+dirx[i], y+diry[i]};
            auto[xx, yy]=curr;
            if(vis[xx][yy] || lab[xx][yy]=='#') continue;
            dp[xx][yy]={-dirx[i], -diry[i]};
            bfs.push({xx, yy});
        }
    }
    if(!vis[last.first][last.second]){
        cout<<"-1\n";
        return;
    }
    bfs.push(last);
    int ans=0, cont=1;
    vector<int>v;
    while(!bfs.empty()){
        auto[x, y]=bfs.front();
        bfs.pop();
        T curr={x+dp[x][y].first, y+dp[x][y].second};
        auto[xx, yy]=curr;
        if(dp[xx][yy]==dp[x][y]) cont++;
        else{
            v.push_back(cont);
            cont=1;
        }
        if(dp[x][y]==make_pair(0, 0)){
            cont++;
            break;
        }
        bfs.push({xx, yy});
    }
    for(int x:v){
        ans+=x+2*(x/3);
        dbg(x)
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