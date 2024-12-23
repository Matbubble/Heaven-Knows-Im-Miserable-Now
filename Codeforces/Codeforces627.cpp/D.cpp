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
Te quiero a ti
Kumbia Kings
*/

const long long maxN=4e5;
long long tree[maxN+1];

void add(long long posi){
    while(posi<=maxN){
        tree[posi]++;
        posi+=posi&-posi;
    }
}
long long querie(long long posi){
    long long res=0;
    while(posi>0){
        res+=tree[posi];
        posi-=posi&-posi;
    }
    return res;
}

void solve(){
    set<long long>cast;
    map<long long, long long>posi;
    using T=pair<long long, long long>;
    long long n; cin>>n;
    vector<T>vp(n);
    for(T &x:vp) cin>>x.first;
    for(T &x:vp) cin>>x.second;
    for(T x:vp){
        long long diff=x.second-x.first;
        cast.insert(diff);
        cast.insert(-diff);
    }
    long long curr=1;
    for(long long x:cast){
        posi[x]=curr;
        curr++;
    }
    long long ans=0;
    for(long long i=n-1 ; i>=0 ; i--){
        long long now=vp[i].second-vp[i].first;
        ans+=(n-1-i)-querie(posi[now]);
        add(posi[-now]);
    }
    cout<<ans<<"\n"; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}