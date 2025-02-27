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
    int n; cin>>n;
    vector<int>v(n+1);
    vector<vector<int>>dp(n+1, vector<int>(4, 0));
    for(int i=1 ; i<=n ; i++) cin>>v[i];
    dp[1][0]=v[1];
    dp[1][1]=v[1];
    dp[1][2]=v[1];
    dp[1][3]=v[1];
    for(int i=2 ; i<=n ; i++){
        dp[i][0]=min(dp[i-1][3], dp[i-1][1])+v[i];
        dp[i][1]=min(dp[i-1][0], dp[i-1][2]);
        dp[i][2]=dp[i-1][0]+v[i];
        dp[i][3]=dp[i-1][1];
    }
    cout<<min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]})<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}