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
Mireeeen, mirenla bien
*/

const int maxN=1000;
bool vis[maxN+1][maxN+1];

void solve(){
    int n; cin>>n;
    vector<pair<int, int>>vp;
    for(int i=0 ; i<n ; i++){
        int x, y; cin>>x>>y;
        vp.push_back({x, y});
    }
    int ans=0;
    for(int i=0 ; i<n ; i++){
        if(vis[vp[i].first][vp[i].second]==0){
            ans++;
            queue<pair<int, int>>bfs;
            bfs.push({vp[i].first, vp[i].second});
            vis[vp[i].first][vp[i].second]=1;
            while(!bfs.empty()){
                auto [xx, yy]=bfs.front();
                vis[xx][yy]=1;
                bfs.pop();
                for(int i=0 ; i<n ; i++){
                    if(xx==vp[i].first || yy==vp[i].second){
                        if(!vis[vp[i].first][vp[i].second]){
                            bfs.push({vp[i].first, vp[i].second});
                        }
                    }
                }
            }
        }
    }
    cout<<ans-1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}