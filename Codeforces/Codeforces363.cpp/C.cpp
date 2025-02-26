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
    vector<vector<int>>dp(n+1, vector<int>(3));
    for(int i=0 ; i<3 ; i++) dp[0][i]=0;
    for(int i=1 ; i<=n ; i++){
        int aux; cin>>aux;
        if(aux==0){
            int mini=min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
            for(int j=0 ; j<3 ; j++) dp[i][j]=mini+1;
        }else if(aux==1){
            int mini=min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
            dp[i][2]=mini+1;
            dp[i][0]=mini+1;
            dp[i][1]=min({mini+1, dp[i-1][2], dp[i-1][0]});
        }else if(aux==2){
            int mini=min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
            dp[i][1]=mini+1;
            dp[i][0]=mini+1;
            dp[i][2]=min({mini+1, dp[i-1][1], dp[i-1][0]});
        }else{
            int mini=min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
            dp[i][0]=mini+1;
            dp[i][2]=min({mini+1, dp[i-1][1], dp[i-1][0]});
            dp[i][1]=min({mini+1, dp[i-1][2], dp[i-1][0]});
        }
    }
    int ans=min({dp[n][0], dp[n][1], dp[n][2]});;
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}