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
int dp[100][1000001];

void solve(){
    int n, x; cin>>n>>x;
    vector<int>coins(n);
    for(int &x:coins) cin>>x;
    // sort(coins.begin(), coins.end());
    // vector<vector<int>>dp(n, vector<int>(x+1));
    for(int i=0 ; i<n ; i++){
        int curr=coins[i];
        for(int j=0 ; j<=x ; j++){
            if(j==0) dp[i][j]=0;
            else{
                if(i==0){
                    if(j<curr) dp[i][j]=1e6+1;
                    else{
                        int last=dp[i][j-curr];
                        dp[i][j]=last+1;
                    }
                }else{
                    if(j<curr) dp[i][j]=dp[i-1][j];
                    else{
                        dp[i][j]=min({dp[i][j-curr]+1, dp[i-1][j-curr]+1, dp[i-1][j]});
                    }
                }
            }
        }
    }
    cout<<(dp[n-1][x]>1e6?-1:dp[n-1][x]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}