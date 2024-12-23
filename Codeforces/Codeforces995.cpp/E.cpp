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
Yo tomo
Bersuit Vergabat
*/

void solve(){
    long long n, k; cin>>n>>k;
    map<long long, long long>positive, negative;
    using T=pair<long long, long long>;
    vector<T>vp;
    vp.push_back({0, 0});
    vector<long long>idk, v;
    for(long long i=0 ; i<n ; i++){
        long long aux; cin>>aux;
        positive[aux]++;
        idk.push_back(aux);
    }
    for(long long i=0 ; i<n ; i++){
        long long aux;
        cin>>aux;
        negative[aux]++;
        idk.push_back(aux);
    }
    sort(idk.begin(), idk.end());
    for(long long x:idk){
        if(v.empty()) v.push_back(x);
        else if(x!=v.back()) v.push_back(x);
    }
    long long ans=0;
    for(long long i=(long long)v.size()-1 ; i>=0 ; i--){
        vp.push_back({vp.back().first+positive[v[i]], vp.back().second+negative[v[i]]-positive[v[i]]});
        if(vp.back().second<=k){
            ans=max({ans, v[i]*vp.back().first+v[i]*vp.back().second});
        }
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