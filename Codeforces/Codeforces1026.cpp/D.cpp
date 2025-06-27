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
    long long n, m; cin>>n>>m;
    vector<bool>vis(n+1);
    vector<long long>v(n+1);
    for(long long i=1 ; i<=n ; i++) cin>>v[i];
    vector<vector<pair<long long, long long>>>g(n+1);
    for(long long i=0 ; i<m ; i++){
        long long a, b, w; cin>>a>>b>>w;
        g[b].push_back({a, w});
    }
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
    pq.push({0, n});
    vector<pair<long long, long long>>dp(n+1);
    vis[1]=1;
    while(!pq.empty()){
        long long u=pq.top().second;
        // dbg(u)
        vis[u]=1;
        pq.pop();
        dp[u].first+=v[u];
        for(pair<long long, long long> v:g[u]){
            // dbg(v.first)
            if(!vis[v.first]){
                // dbg(dp[u].first)
                // dbg(v.second)
                if(dp[u].first>=v.second){
                    // dbg(v.first)
                    // vis[v.first]=1;
                    dp[v.first].second=max(dp[u].second, v.second);
                    dp[v.first].first=dp[u].first;
                    // dbg(dp[v.first].second)
                    pq.push({dp[v.first].second, v.first});
                }
            }
        }
    }
    if(!vis[n]) cout<<-1<<"\n";
    else cout<<dp[n].second<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}