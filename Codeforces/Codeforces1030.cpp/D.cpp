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

void solve(){
    long long n, k; cin>>n>>k;
    vector<long long>v(n), d(n), legal(n);
    set<long long>posible;
    for(long long &x:v) cin>>x;
    long long posi=0;
    for(long long i=0 ; i<n ; i++){
        long long x;
        cin>>x;
        x%=k;
        if(x==0) posible.insert(v[i]);
        // posi++;
    }
    long long q; cin>>q;
    while(q--){
        long long start; cin>>start;
        auto it=posible.lower_bound(start);
        if(it==posible.end() || it==posible.begin()) cout<<"YES\n";
        else cout<<"NO\n";
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