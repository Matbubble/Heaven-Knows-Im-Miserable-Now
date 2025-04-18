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

const int maxN=2e5;

int bj[maxN+1][21];
vector<int>g[maxN+1];

void dfs(int u, int root){
    bj[u][0]=root;
    for(int i=1 ; i<20 ; i++){
        int aux=bj[u][i-1];
        if(aux==-1) aux=1;
        bj[u][i]=bj[aux][i-1];
    }
    for(int v:g[u]){
        if(v==root) continue;
        dfs(v, u);
    }
}

int padre(int u, int k){
    for(int i=0 ; i<20 ; i++){
        if(((k>>i)&1)==1){
            u=bj[u][i];
            if(u==-1) return -1;
        }
    }
    return u;
}

void solve(){
    int n, q; cin>>n>>q;
    for(int i=2 ; i<=n ; i++){
        int x; cin>>x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(1, -1);
    while(q--){
        int u, k; cin>>u>>k;
        cout<<padre(u, k)<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}