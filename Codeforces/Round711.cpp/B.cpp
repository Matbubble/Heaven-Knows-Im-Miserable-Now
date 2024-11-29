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
Secreto de amor
*/

void solve(){
    long long n, w; cin>>n>>w;
    map<long long, long long>freq, use;
    for(int i=0 ; i<n ; i++){
        long long x; cin>>x;
        freq[x]++;
    }
    vector<pair<long long, long long> >vp;
    for(auto it:freq){
        vp.push_back(make_pair(it.second, it.first));
    }
    sort(vp.begin(), vp.end(), greater<pair<long long, long long> >());
    long long posi=0, tam=(long long)vp.size(), sum=0;
    while(sum<=w){
        if(vp[posi].first==0) break;
        sum+=vp[posi].second;
        if(sum>w) break;
        vp[posi].first--;
        use[vp[posi].second]++;
        posi++;
        posi%=tam;
    }
    long long ans=0;
    for(auto it:freq){
        if(use[it.first]==0) continue;
        ans=max(ans, (it.second+use[it.first]-1)/use[it.first]);
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