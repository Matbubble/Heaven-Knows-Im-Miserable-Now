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
Creo que tengo depresion uwu
*/

const long long INF=1e18;

void solve(){
    long long n, m, h; cin>>n>>m>>h;
    vector<bool>horse(n+1), arriveA(n+1), arriveB(n+1);
    for(int i=0 ; i<h ; i++){
        int aux; cin>>aux;
        horse[aux]=1;
    }
    vector<vector<pair<int, int> > >g(n+1);
    for(int i=0 ; i<m ; i++){
        long long a, b, c; cin>>a>>b>>c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > >pq;
    vector<long long>disA(n+1, INF), disB(n+1, INF);
    long long src=1;
    pq.push(make_pair(0, src));
    while(!pq.empty()){
        long long u=pq.top().second;
        pq.pop();
        for(auto &neighbor:g[u]){
            auto[v, weight]=neighbor;
            if(!arriveA[u]) arriveA[u]=horse[u];
            weight>>=(1*arriveA[u]);
            if(disA[v]>disA[u]+weight){
                disA[v]=disA[u]+weight;
                arriveA[v]=arriveA[u];
                pq.push(make_pair(disA[v], v));
            }
        }
    }
    while(!pq.empty()) pq.pop();
    src=n;
    pq.push(make_pair(0, src));
    while(!pq.empty()){
        long long u=pq.top().second;
        pq.pop();
        for(auto &neighbor:g[u]){
            auto[v, weight]=neighbor;
            if(!arriveB[u]) arriveB[u]=horse[u];
            weight>>=(1*arriveB[u]);
            if(disB[v]>disB[u]+weight){
                disB[v]=disB[u]+weight;
                arriveB[v]=arriveB[u];
                pq.push(make_pair(disB[v], v));
            }
        }
    }
    if(disA[n]==INF){
        cout<<-1<<"\n";
        return;
    }
    long long ans=1e18;
    for(int i=1 ; i<=n ; i++){
        ans=min(ans, max(disA[i], disB[i]));
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}