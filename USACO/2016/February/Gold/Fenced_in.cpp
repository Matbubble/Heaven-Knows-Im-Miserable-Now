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
    long long A, B, n, m, maxi=0; cin>>A>>B>>n>>m;
    vector<long long>a(n), b(m);
    for(long long &x:a) cin>>x;
    for(long long &x:b) cin>>x;
    b.push_back(A);
    a.push_back(B);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto posi=[&](long long i, long long j){
        long long curr;
        if(n<m)curr=i+((m+1)*j);
        else curr=((n+1)*i)+j;
        maxi=max(maxi, curr);
        return curr;
    };;
    vector<pair<long long, pair<long long, long long>>>edge;
    for(long long i=0 ; i<=n ; i++){
        for(long long j=0 ; j<=m ; j++){
            // if(i==n && j==m) continue;
            if(i==0 && j<m){
                edge.push_back(make_pair(a[i], make_pair(posi(i, j), posi(i, j+1))));
            }else if(j<m){
                edge.push_back(make_pair(a[i]-a[i-1], make_pair(posi(i, j), posi(i, j+1))));
            }
            // dbg(edge.back().first)
            // dbg(posi(i, j+1))
            // dbg("---")
            if(j==0 && i<n){
                edge.push_back(make_pair(b[j], make_pair(posi(i, j), posi(i+1, j))));
            }else if(i<n){
                edge.push_back(make_pair(b[j]-b[j-1], make_pair(posi(i, j), posi(i+1, j))));
            }
        }
    }
    // dbg(edge.size())
    sort(edge.begin(), edge.end());
    // dbg(edge.size())
    // dbg(maxi)
    dsu d(maxi+1);
    long long ans=0;
    for(long long i=0 ; i<(long long)edge.size() ; i++){
        // dbg(edge[i].second.first)
        // dbg(edge[i].second.second)
        // dbg("---")
        if(!d.united(edge[i].second.first, edge[i].second.second)){
            ans+=edge[i].first;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("fencedin.in", "r", stdin);
    // freopen("fencedin.out", "w", stdout);
    solve();
    return 0;
}