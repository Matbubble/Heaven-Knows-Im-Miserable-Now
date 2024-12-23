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
Shhhhh!
*/

const int maxN=200;
long long dp[maxN+1][maxN+1][maxN+1];
long long lab[maxN+1][maxN+1];
long long mini[maxN+1][maxN+1];

void solve(){
    int n, m; cin>>n>>m;
    long long k; cin>>k;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>lab[i][j];
            mini[i][j]=1e18;
            for(int l=0 ; l<=m ; l++){
                dp[i][j][l]=0;
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            int shift=0, posi=j;
            if(i==0 && j==0){
                while(shift<m){
                    dp[i][j][shift]+=lab[i][posi]+(k*shift);
                    // dbg(dp[i][j][shift])
                    
                    mini[i][j]=min(mini[i][j], dp[i][j][shift]);
                    posi=(posi+1)%m;
                    shift++;
                }
            }else if(j==0){
                while(shift<m){
                    dp[i][j][shift]+=lab[i][posi]+mini[i-1][j]+(k*shift);
                    
                    mini[i][j]=min(mini[i][j], dp[i][j][shift]);
                    posi=(posi+1)%m;
                    shift++;
                }
            }else if(i==0){
                while(shift<m){
                    dp[i][j][shift]+=lab[i][posi]+dp[i][j-1][shift];
                    
                    mini[i][j]=min(mini[i][j], dp[i][j][shift]);
                    posi=(posi+1)%m;
                    shift++;
                }
            }else{
                while(shift<m){
                    dp[i][j][shift]+=lab[i][posi]+min(dp[i][(j-1)][shift]-(k*shift), mini[i-1][j])+(k*shift);
                    // dbg(dp[i][j][shift])
                    // dbg(dp[i][j-1][shift])
                    // dbg(mini[i-1][j])
                    // dbg(lab[i][posi])
                    // dbg(i)
                    // dbg(j)
                    mini[i][j]=min(mini[i][j], dp[i][j][shift]);
                    posi=(posi+1)%m;
                    shift++;
                }
            }
        }
    }
    cout<<mini[n-1][m-1]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}