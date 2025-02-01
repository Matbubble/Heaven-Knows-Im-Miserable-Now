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

struct dsu{
    long long n;
    vector<long long>p;
    dsu(long long n):n(n), p(n+1){
        for(long long i=0 ; i<=n ; i++) p[i]=i;
    }
    long long find(long long x){
        return (p[x]==x?x:p[x]=find(p[x]));
    }
    void united(long long a, long long b){
        a=find(a); b=find(b);
        if(a==b) return;
        p[a]=b;
        return;   
    }
    bool confirm(long long a, long long b){
        a=find(a); b=find(b);
        if(a==b) return true;
        return false;   
    }
};

void solve(){
    long long n, m1, m2; cin>>n>>m1>>m2;
    vector<pair<long long, long long>>g;
    for(long long i=0 ; i<m1 ; i++){
        long long a, b; cin>>a>>b;
        g.push_back({a, b});
    }
    dsu d1(n+1), d2(n+1);
    for(long long i=0 ; i<m2 ; i++){
        long long a, b; cin>>a>>b;
        d2.united(a, b);
    }
    long long ans=0;
    // set<long long>s;
    for(long long i=0 ; i<m1; i++){
        if(d2.confirm(g[i].first, g[i].second)){
            d1.united(g[i].first, g[i].second);
        }else ans++;
    }
    for(int it=1 ; it<=n ; it++){
        long long papi=d2.find(it);
        if(d1.confirm(papi, it)) continue;
        else{
            ans++;
            d1.united(papi, it);
        }
    }
    cout<<ans<<"\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}