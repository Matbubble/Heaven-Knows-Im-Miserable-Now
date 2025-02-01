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

void solve(){
    int n; cin>>n;
    vector<vector<char>>mat(n, vector<char>(n));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++) cin>>mat[i][j];
    }
    deque<int>ans;
    vector<bool>vis(n+1, 0);
    deque<int>aux;
    auto dfs=[&](auto &&self, int i)->void{
        bool ok=0;
        vis[i]=1;
        for(int j=i ; j<n ; j++){
            // dbg(mat[i][j])
            if(!vis[j] && mat[i][j]=='1'){
                // dbg(j)
                self(self, j);
                ok=1;
            }
        }
        // dbg(i+1)
        aux.push_front(i+1);
    };
    for(int i=0 ; i<n ; i++){
        aux.clear();
        if(!vis[i]){
            dfs(dfs, i);
        }
        if(!aux.empty()){
            for(int j=(int)aux.size()-1 ; j>=0 ; j--) ans.push_front(aux[j]);
        }
    }
    for(int i=0 ; i<n ; i++) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}