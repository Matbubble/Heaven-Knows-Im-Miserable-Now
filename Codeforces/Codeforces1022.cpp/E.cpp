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
vector<int>g[maxN+1];
using T=pair<int, int>;
priority_queue<T>pq;
set<int>s;
int ans=0, sum=0;
T borrar;

void reroot(int u, int root){
    int a=g[u].size();
    if(s.count(u)){

    }
    for(int v:g[u]){
        
    }
}

void solve(){
    int n; cin>>n;
    for(int i=1 ; i<n ; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1 ; i<=n ; i++){
        pq.push(make_pair((int)g[i].size(), i));
        sum+=(int)g[i].size();
        s.insert(i);
        if((int)pq.size()>=((n-1)/2)+1){
            s.erase(pq.top().second);
            sum-=pq.top().first;
            pq.pop();
        }
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