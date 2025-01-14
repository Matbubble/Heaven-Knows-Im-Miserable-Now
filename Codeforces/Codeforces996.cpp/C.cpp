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

const int maxN=1000;
long long lab[maxN+1][maxN+1];

void solve(){
    int n, m; cin>>n>>m;
    string s; cin>>s;
    reverse(s.begin(), s.end());
    long long maxi=0;
    vector<long long>row(n), column(m);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            // dbg(j)
            cin>>lab[i][j];
            row[i]+=lab[i][j];
            column[j]+=lab[i][j];
        }
    }
    using T=pair<int, int>;
    queue<T>bfs;
    bfs.push({0, 0});
    long long prev=0;
    while(!bfs.empty()){
        auto[x, y]=bfs.front();
        bfs.pop();
        if(s.empty()){
            long long now=column[y];
            lab[x][y]=prev-now;
            column[y]+=prev-now;
            row[x]+=prev-now;
            prev=column[y];
        }else if(s.back()=='R'){
            bfs.push({x, y+1});
            long long now=column[y];
            lab[x][y]=prev-now;
            column[y]+=prev-now;
            row[x]+=prev-now;
            prev=column[y];
        }else if(s.back()=='D'){
            bfs.push({x+1, y});
            long long now=row[x];
            lab[x][y]=prev-now;
            column[y]+=prev-now;
            row[x]+=prev-now;
            prev=row[x];
        }
        s.pop_back();
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cout<<lab[i][j]<<" ";
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