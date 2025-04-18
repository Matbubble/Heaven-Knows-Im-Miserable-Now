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

int dirX[]={1, 0, -1, 0};
int dirY[]={0, 1, 0, -1};

int n, m;

bool in(int x, int y){
    return x>=0 && y>=0 && x<n && y<m;
}

void solve(){
    int k; cin>>n>>m>>k;
    int cont=(n*m)/k;
    map<int, int>freq;
    for(int i=1 ; i<=k ; i++) freq[i]=cont;
    using T=pair<int, int>;
    queue<T>bfs;
    vector<vector<int>>mat(n, vector<int>(m, k+1));
    bfs.push({0, 0});
    while(!bfs.empty()){
        auto[x, y]=bfs.front();
        dbg(x)
        dbg(y)
        bfs.pop();
        set<int>s;
        for(int i=0 ; i<4 ; i++){
            int xx=x+dirX[i], yy=y+dirY[i];
            if(!in(xx, yy)) continue;
            if(mat[xx][yy]==k+1){
                bfs.push({xx, yy});
            }
            if(mat[xx][yy]==k+1) continue;
            s.insert(mat[xx][yy]);
        }
        int aux;
        for(pair<int, int>it:freq){
            if(!s.count(it.first)){
                mat[x][y]=it.first;
                freq[it.first]--;
                aux=it.first;
                break;
            }
        }
        if(freq[aux]==0) freq.erase(aux);
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cout<<mat[i][i]<<" ";
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}