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
#include <cassert>

using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
MC lover
*/

struct dsu{
    long long n;
    vector<long long>p;
    dsu(long long n):n(n){
        for(long long i=0 ; i<=n ; i++) p.push_back(i);
    }
    long long find(long long x){
        return (p[x]==x?x:p[x]=find(p[x]));
    }
    bool united(long long a, long long b){
        a=find(a); b=find(b);
        if(a==b) return true;
        else{
            p[a]=b;
            return false;
        }
    }
};

void solve(){
    long long n, m; cin>>n>>m;
    vector<pair<long long, pair<long long, long long>>>edge;
    for(long long i=0 ; i<m ; i++){
        long long a, b, c; cin>>a>>b>>c;
        edge.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(edge.begin(), edge.end());
    long long ans=0;
    dsu d(n);
    for(long long i=0 ; i<m ; i++){
        if(!d.united(edge[i].second.first, edge[i].second.second)){
            ans+=edge[i].first;
        }
    }
    int xd=0;
    for(int i=1 ; i<=n ; i++) xd+=(d.p[i]==i);
    if(xd>1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<(ans)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}