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

struct moves{
    int x, y;
    int last, m;
};

void solve(){
    int n, m, k; cin>>n>>m>>k;
    vector<vector<char>>lab(n, vector<char>(m));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cin>>lab[i][j];
    }
    int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
    deque<moves>bfs;
    bfs.push_back({x1-1, y1-1, -1, 1});
    vector<int>dirX={1, 0, -1, 0}, dirY={0, -1, 0, 1};
    auto in=[&](int i, int j){
        return i>=0 && j>=0 && i<n && j<m;
    };
    vector<vector<int>>dp(n, vector<int>(m, 1e9));
    dp[x1-1][y1-1]=0;
    while(!bfs.empty()){
        moves curr=bfs.front();
        bfs.pop_front();
        for(int i=0 ; i<4 ; i++){
            int nx=curr.x+dirX[i], ny=curr.y+dirY[i];
            if(!in(nx, ny)) continue;
            if(lab[nx][ny]=='#') continue;
            if(i==curr.last){
                int paso=curr.m+1;
                int w;
                if(paso>k){
                    paso=1;
                    w=1;
                }else w=0;
                if(dp[curr.x][curr.y]+w<dp[nx][ny]){
                    dp[nx][ny]=dp[curr.x][curr.y]+w;
                    if(w==1) bfs.push_back({nx, ny, i, paso});
                    else bfs.push_front({nx, ny, i, paso});
                }
            }else{
                int w=1;
                if(dp[curr.x][curr.y]+w<dp[nx][ny]){
                    dp[nx][ny]=dp[curr.x][curr.y]+w;
                    if(w==1) bfs.push_back({nx, ny, i, 1});
                    else bfs.push_front({nx, ny, i, 1});
                }
            }
        }
    }
    cout<<(dp[x2-1][y2-1]==1e9?-1:dp[x2-1][y2-1])<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}