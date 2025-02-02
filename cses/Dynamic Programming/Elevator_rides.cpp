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

void solve(){
    int n, gorda; cin>>n>>gorda;
    int subsets=(1<<n);
    vector<int>v(n);
    for(int &x:v) cin>>x;
    using T=pair<int, int>;
    vector<T>dp(subsets, {1e9, 1e9});
    dp[0]={1, 0};
    for(int i=0 ; i<subsets ; i++){
        vector<int>val;
        int curr=0;
        for(int j=0 ; j<n ; j++){
            if((i>>j)&1){
                val.push_back(j);
                curr+=(1<<j);
            }
        }
        for(int x:val){
            curr-=(1<<x);
            T aux;
            if(dp[curr].second+v[x]>gorda) aux={dp[curr].first+1, v[x]};
            else aux={dp[curr].first, dp[curr].second+v[x]};
            // dbg(aux.first)
            // dbg(aux.second)
            curr+=(1<<x);
            if(dp[curr].first>aux.first) dp[curr]=aux;
            else if(dp[curr].first==aux.first) dp[curr].second=min(dp[curr].second, aux.second);
        }
    }
    cout<<dp[subsets-1].first<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}