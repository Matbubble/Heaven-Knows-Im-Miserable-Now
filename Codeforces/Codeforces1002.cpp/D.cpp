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

struct point{
    long long dis;
    int a, b;
    bool operator >(point &x){
        if(x.dis==dis){
            if(x.a==a) return x.b>b;
            return x.a>a;
        }
        return x.dis>dis;
    }
};


void solve(){
    int n, s1, s2; cin>>n>>s1>>s2;
    vector<vector<int>>g1(n+1), g2(n+1);
    vector<vector<long long>>dis(n+1, vector<long long>(n+1, 1e18));
    dis[s1][s2]=0;
    int m1; cin>>m1;
    for(int i=0 ; i<m1 ; i++){
        int a, b; cin>>a>>b;
        g1[a].push_back(b);
        g1[b].push_back(a);
    }
    int m2; cin>>m2;
    for(int i=0 ; i<m2 ; i++){
        int a, b; cin>>a>>b;
        g2[a].push_back(b);
        g2[b].push_back(a);
    }
    vector<bool>use(n+1);
    for(int i=1 ; i<=n ; i++){
        set<int>s;
        for(int v:g1[i]) s.insert(v);
        for(int v:g2[i]){
            if(s.count(v)){
                use[i]=1;
                break;
            }
        }
    }
    using T=tuple<long long, int, int>;
    priority_queue<T, vector<T>, greater<T>>pq;
    pq.push({0, s1, s2});
    while(!pq.empty()){
        auto[d, u, v]=pq.top();
        pq.pop();
        if(d!=dis[u][v]) continue;
        if(u==v && use[u]){
            cout<<d<<"\n";
            return;
        }
        for(int x:g1[u]){
            for(int y:g2[v]){
                long long curr=d+abs(x-y);
                if(curr<dis[x][y]){
                    dis[x][y]=curr;
                    pq.push({dis[x][y], x, y});
                }
            }
        }
    }
    cout<<-1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}