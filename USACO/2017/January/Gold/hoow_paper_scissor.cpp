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

const int maxN=1e5;
int dp[maxN+1][21][3];

void solve(){
    int n, k; cin>>n>>k;
    vector<char>v(n);
    for(char &x:v) cin>>x;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<=k ; j++){
            dp[i+1][j][0]=(v[i]=='H');
            dp[i+1][j][1]=(v[i]=='S');
            dp[i+1][j][2]=(v[i]=='P');
            int mini=dp[i][j][0];
            if(j!=0) mini=max({mini, dp[i][j-1][0], dp[i][j-1][1], dp[i][j-1][2]});
            dp[i+1][j][0]+=mini;

            mini=dp[i][j][1];
            if(j!=0) mini=max({mini, dp[i][j-1][0], dp[i][j-1][1], dp[i][j-1][2]});
            dp[i+1][j][1]+=mini;

            mini=dp[i][j][2];
            if(j!=0) mini=max({mini, dp[i][j-1][0], dp[i][j-1][1], dp[i][j-1][2]});
            dp[i+1][j][2]+=mini;
        }
    }
    int ans=0;
    for(int i=0 ; i<=k ; i++) ans=max({ans, dp[n][i][0], dp[n][i][1], dp[n][i][2]});
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    solve();
    return 0;
}