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
    string s; cin>>s;
    int ans=0;
    vector<vector<int>>dp((int)s.size(), vector<int>(3));
    for(int i=0 ; i<=2 ; i++){
        char ch=s[0];
        if(ch=='W') dp[0][1]=2;
        if(ch=='D') dp[0][0]=1;
    }
    for(int i=1 ; i<(int)s.size() ; i++){
        char ch=s[i];
        if(ch=='L'){
            for(int j=0 ; j<=2 ; j++){
                dp[i][j]=dp[i-1][j];
            }
        }else if(ch=='D'){
            for(int j=0 ; j<=2 ; j++){
                dp[i][j]=dp[i-1][j];
                dp[i][0]=max(dp[i-1][j]+1, dp[i][0]);
            }
        }else{
            dp[i][0]=dp[i-1][0];
            for(int j=1 ; j<=2 ; j++){
                if(j==2 && dp[i-1][j-1]==0) continue;
                dp[i][j]=dp[i-1][j-1]+2;
                // dbg(dp[i-1][j-1])
                if(j==2){
                    if(dp[i-1][j]==0) continue;
                    dp[i][j]=max(dp[i][j], dp[i-1][j]+3);
                }
                // dbg(dp[i][j])
                // dbg(i)
                // dbg(j)
            }
        }
        for(int j=0 ; j<=2 ; j++){
            ans=max(ans, dp[i][j]);
            // dbg(dp[i][j])
        }
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