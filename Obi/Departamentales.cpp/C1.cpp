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
En un caso hipoteticooooooo xdddd
*/

int dirX[]={1, 0, -1, 0};
int dirY[]={0, -1, 0, 1};

void solve(){
    int n, m; cin>>n>>m;
    char lab[n][m];
    pair<int, int>A;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>lab[i][j];
            if(lab[i][j]=='A'){
                A.first=i;
                A.second=j;
            }
        }
    }
    auto in = [&](int x, int y){return x>=0 && y>=0 && x<n && y<m;};
    queue<pair<int, int> >bfs;
    bfs.push(A);
    while(!bfs.empty()){
        auto [xx, yy]=bfs.front();
        bfs.pop();
        for(int i=0 ; i<4 ; i++){
            int newX=xx+dirX[i], newY=yy+dirY[i];
            if(in(newX, newY)){
                if(lab[newX][newY]=='.'){
                    bfs.push(make_pair(newX, newY));
                    lab[newX][newY]='A';
                }
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cout<<lab[i][j];
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}