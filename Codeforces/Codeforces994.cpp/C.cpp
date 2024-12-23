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

void solve(){
    int n, x, y; cin>>n>>x>>y;
    vector<vector<int>>g(n+1);
    vector<bool>vis(n+1);
    vector<int>ans(n+1);
    for(int i=1 ; i<=n ; i++){
        if(i==1){
            g[i].push_back(i+1);
            g[i].push_back(n);
        }else if(i==n){
            g[i].push_back(i-1);
            g[i].push_back(1);
        }else{
            g[i].push_back(i+1);
            g[i].push_back(i-1);
        }
    }
    g[x].push_back(y);
    g[y].push_back(x);
    vis[2]=1;
    ans[2]=1;
    ans[1]=0;
    vis[1]=1;
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            vector<bool>mex(5);
            for(int u:g[i]){
                if(!vis[u]) continue;
                mex[ans[u]]=1;
            }
            for(int j=0 ; j<=4 ; j++){
                if(!mex[j]){
                    ans[i]=j;
                    break;
                }
            }
            vis[i]=1;
        }
    }
    for(int i=1 ; i<=n ; i++) cout<<ans[i]<<" \n"[i==n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}