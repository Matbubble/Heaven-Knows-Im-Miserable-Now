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

void solve(){
    int n, m, r, c; cin>>n>>m>>r>>c;
    int X, Y; cin>>X>>Y;
    vector<vector<char>>lab(n, vector<char>(m));
    for(int i=0 ; i <n ; i++){
        for(int j=0 ; j<m ; j++) cin>>lab[i][j];
    }
    using T=pair<int, int>;
    deque<T>bfs;
    bfs.push_back({r-1, c-1});
    vector<vector<int>>dp(n, vector<int>(m, 1e9+1));
    dp[r-1][c-1]=0;
    vector<int>dirX={1, 0, -1, 0}, dirY={0, -1, 0, 1};
    auto in=[&](int x, int y){
        return x>=0 && y>=0 && x<n && y<m;
    };
    while(!bfs.empty()){
        auto [x, y]=bfs.front();
        bfs.pop_front();
        for(int i=0 ; i<4 ; i++){
            int nx=x+dirX[i], ny=y+dirY[i];
            if(!in(nx, ny)) continue;
            if(lab[nx][ny]=='*') continue;
            int w=(i==1);
            if(dp[x][y]+w<dp[nx][ny]){
                dp[nx][ny]=dp[x][y]+w;
                if(w==1) bfs.push_back({nx, ny});
                else bfs.push_front({nx, ny});
            }
        }
    }
    int ans=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            int r=dp[i][j]+j-(c-1);
            ans+=(r<=Y && dp[i][j]<=X && lab[i][j]!='*');
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