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
I love DP
*/

void solve(){
    long long n, k, q; cin>>n>>k>>q;
    vector<pair<long long, long long> >v(k);
    for(int i=0 ; i<k ; i++) cin>>v[i].first;
    for(int i=0 ; i<k ; i++) cin>>v[i].second;
    vector<long long>dp(k+1);
    for(int i=0 ; i<k ; i++){
        dp[i+1]=dp[i]+v[i].second;
    }
    while(q--){
        long long curr; cin>>curr;
        auto it=lower_bound(v.begin(), v.end(), make_pair(curr, 0));
        // dbg(it-v.begin())
        if(it==v.begin()){
            long long ans=curr*((it->second))/((it->first));
            cout<<ans<<" ";
        }else{
            long long xx=it->first, yy=it->second;
            it--;
            curr-=it->first;
            long long ans=curr*(yy-(it->second))/(xx-(it->first));
            cout<<ans+dp[(it-v.begin())+1]<<" ";
        }
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