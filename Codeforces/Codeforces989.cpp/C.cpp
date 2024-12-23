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
#define dbg(x) cerr << #x << ": " << x << "\n";

/*
Chiquilla
Kumbia Kings
*/

const int maxN=1000;
char lab[maxN+1][maxN+1];
bool vis[maxN+1][maxN+1];

int dirX[]={1, 0, -1, 0};
int dirY[]={0, 1, 0, -1};
char coming[]={'U', 'L', 'D', 'R'};      

void solve(){
    int n, m; cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>lab[i][j];
            vis[i][j]=0;
        }
    }
    auto in=[&](int x, int y){
        return x>=0 && y>=0 && x<n && y<m;
    };
    auto border=[&](int x, int y){
        return x==-1 || y==-1 || x==n || y==m;
    };
    using T=pair<int, int>;
    for(int i=-1 ; i<=n ; i++){
        for(int j=-1 ; j<=m ; j++){
            if(border(i, j)){
                queue<T>bfs;
                bfs.push({i, j});
                while(!bfs.empty()){
                    auto [xx, yy]=bfs.front();
                    if(in(xx, yy)) vis[xx][yy]=1;
                    bfs.pop();
                    for(int k=0 ; k<4 ; k++){
                        int newX=xx+dirX[k], newY=yy+dirY[k];
                        if(in(newX, newY) && vis[newX][newY]==0){
                            if(lab[newX][newY]==coming[k]) bfs.push({newX, newY});
                        }
                    }
                }
            }
        }
    }
    int ans=n*m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            // dbg(vis[i][j])
            ans-=vis[i][j];
            if(lab[i][j]=='?'){
                // dbg(i)
                // dbg(j)
                bool ok=0;
                for(int k=0 ; k<4 ; k++){
                    int ii=i+dirX[k], jj=j+dirY[k];
                    // dbg(ii)
                    // dbg(jj)
                    if(in(ii, jj)){
                        ok|=(vis[ii][jj]^1);
                        // dbg(vis[ii][jj])
                    }
                }
                // dbg(ok)
                ans-=(ok^1);
            }
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while (t--) solve();
    return 0;
}