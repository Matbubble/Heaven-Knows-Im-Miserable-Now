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
long long dp[maxN+1][102];
int dir[]={-1, 0, 1};
const long long MOD=1e9+7;

void solve(){
    int n, m; cin>>n>>m;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    if(v[0]==0){
        for(int i=1 ; i<=m ; i++) dp[1][i]=1;
    }else dp[1][v[0]]=1;
    for(int i=2 ; i<=n ; i++){
        if(v[i-1]>0){
            for(int j=0 ; j<3 ; j++){
                int now=v[i-1]+dir[j];
                dp[i][v[i-1]]+=dp[i-1][now];
            }
            dp[i][v[i]]%=MOD;
            // dbg(dp[i][v[i]])
        }else{
            for(int j=1 ; j<=m ; j++){
                for(int k=0 ; k<3 ; k++){
                    int now=j+dir[k];
                    dp[i][j]+=dp[i-1][now];
                }
                dp[i][j]%=MOD;
            }
        }
    }
    long long ans=0;
    for(int i=1 ; i<=m ; i++) ans+=dp[n][i];
    cout<<ans%MOD<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}