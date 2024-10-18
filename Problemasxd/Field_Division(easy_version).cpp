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
LA ODIO DEMASIADO, que caca
*/

void solve(){
    long long n, m, k; cin>>n>>m>>k;
    map<long long, long long>maxi;
    maxi[m]=1;
    maxi[1]=1-1;
    vector<pair<long long, long long> >vp, aux;
    for(int i=0 ; i<k ; i++){
        long long a, b; cin>>a>>b;
        maxi[b]=max(maxi[b], a);
        vp.push_back(make_pair(a, b));
    }
    map<pair<int, int>, bool> xd;
    for(auto x:maxi){
        if(!aux.empty()){
            if(aux.back().second>=x.second) continue;
        }
        aux.push_back(make_pair(x.first, x.second));
        xd[make_pair(x.second, x.first)]=1;
    }
    long long ans=0, now=1;
    for(int i=0 ; i<(int)aux.size() ; i++){
        // dbg(n-aux[i].second)
        // dbg(aux[i+1].first-now)
        if(i==(int)aux.size()-1){
            ans+=(m-now+1)*(n-aux[i].second);
            // dbg((m-now+1)*(n-aux[i].second))
        }else{
            ans+=(aux[i+1].first-now)*(n-aux[i].second);
            // dbg((aux[i+1].first-now)*(n-aux[i].second))
            now=aux[i+1].first;
            
        }
    }
    cout<<ans<<"\n";
    for(auto it:vp){
        if(xd[make_pair(it.first, it.second)]==1) cout<<1<<" ";
        else cout<<0<<" ";
    }
    cout<<"\n";
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}