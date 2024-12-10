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
I love DP
*/

const int maxN=2e5;
bool prime[maxN+1], vis[maxN+1];
vector<int> g[maxN+1];
set<int>val;

void init(){
    for(int i=1 ; i<=maxN ; i++) prime[i]=1;
    prime[0]=prime[1]=0;
    for(int i=2 ; i<=maxN ; i++){
        if(prime[i]==1){
            for(int j=i+i ; j<=maxN ; j+=i) prime[j]=0;
        }
    }
}

void solve(){
    // dbg(prime[56081])
    int n; cin>>n;
    for(int i=1 ; i<2*n ; i++){
        val.insert(i);
        vis[i]=0;
    }
    for(int i=1 ; i<n ; i++){
        int x, y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int>ans(n+1);
    int start=1, cont=(int)g[1].size();
    for(int i=1 ; i<=n ; i++){
        if((int)g[i].size()>cont){
            cont=(int)g[i].size();
            start=i;
        }
    }
    set<pair<int, int> >bfs;
    bfs.insert({0, start});
    ans[start]=2*n;
    while(!bfs.empty()){
        auto u=prev(bfs.end());
        vis[u->second]=1;
        bfs.erase(prev(bfs.end()));
        set<pair<int, int> >aux;
        for(int v:g[u->second]){
            if(vis[v]) continue;
            // dbg(u)
            // dbg(v)
            auto it=val.end();
            it--;
            bool ok=0;
            while(1){
                if(prime[abs((*it)-(ans[u->second]))]==0){
                    dbg(*it)
                    dbg(ans[u->second])
                    dbg(abs((*it)-(ans[u->second])))
                    ok=1;
                    ans[v]=*it;
                    val.erase(it);
                    break;
                }
                if(it==val.begin()) break;
                it--;
            }
            dbg("=------------")
            if(!ok){
                cout<<-1<<"\n";
                return;
            }
            if(!vis[v]) aux.insert({(int)g[v].size(), v});
        }
        while(!aux.empty()){
            bfs.insert(*aux.begin());
            aux.erase(aux.begin());
        }
    }
    for(int i=0 ; i<n ; i++) cout<<ans[i+1]<<" ";
    cout<<"\n";
    for(int i=0 ; i<=n ; i++) g[i].clear();
    val.clear();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}