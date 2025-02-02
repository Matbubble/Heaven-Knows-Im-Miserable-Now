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

const int maxN=300;
int lab[maxN+1][maxN+1];
vector<int> suf[maxN+1];
vector<vector<int>>g;
vector<int>dis, a, b;


void add(int a, int b){
    g[a].push_back(b);
}

long long check(int n, int mex){
    long long ans=0;
    a.clear();
    b.clear();
    dis.clear();
    a.resize(mex, -1);
    b.resize(n, -1);
    dis.resize(mex, -1);
    auto dfs=[&](auto &&self, int u)->bool{
        for(int v:g[u]){
            if(b[v]==-1 || (dis[b[v]]==dis[u]+1 && self(self, b[v]) )){
                b[v]=u;
                a[u]=v;
                return true;
            }
        }
        dis[u]=-1;
        return false;
    };
    while(1){
        for(int i=0 ; i<mex ; i++) dis[i]=-1;
        queue<int>bfs;
        for(int i=0 ; i<mex ; i++){
            if(a[i]==-1){
                dis[i]=0;
                bfs.push(i);
            }
        }
        bool ok=0;
        while(!bfs.empty()){
            int u=bfs.front();
            bfs.pop();
            for(int v:g[u]){
                if(b[v]==-1) ok=1;
                else if(dis[b[v]]==-1){
                    dis[b[v]]=dis[u]+1;
                    bfs.push(b[v]);
                }
            }
        }
        if(!ok) break;
        for(int i=0 ; i<mex ; i++){
            if(a[i]==-1 && dfs(dfs, i)) ans++;
        }
    }
    return ans;

}

void solve(){
    int n; cin>>n;
    g.resize(n);
    if(n==1){
        cout<<1<<"\n";
        return;
    }
    for(int i=0 ; i<n ; i++){
        suf[i].clear();
        suf[i].push_back(0);
        for(int j=0 ; j<n ; j++){
            cin>>lab[i][j];
        }
        for(int j=n-1 ; j>=0 ; j--){
            suf[i].push_back(suf[i].back()+lab[i][j]);
        }
        reverse(suf[i].begin(), suf[i].end());
    }
    vector<bool>possible(n+1);
    vector<vector<int>>xd(n+1);
    for(int i=0 ; i<=n ; i++){
        possible[i]=0;
        for(int j=0 ; j<n ; j++){
            if(suf[j][i]==i){
                xd[i].push_back(j);
                possible[i]=1;
            }
        }
    }
    for(int m=n ; m>0 ; m--){
        bool ok=1;
        for(int j=0 ; j<m ; j++){
            if(!possible[j]){
                ok=0;
                break;
            }
        }
        if(!ok) continue;
        for(int i=0 ; i<n ; i++) g[i].clear();
        for(int j=0 ; j<m ; j++){
            for(int k:xd[j]) add(j, k);
        }
        if(check(n, m)==m){
            cout<<m<<"\n";
            return;
        }
    }
    cout<<0<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}