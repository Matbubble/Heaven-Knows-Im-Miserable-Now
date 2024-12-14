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
Take out tonishhh
*/

const long long inf=1e18;

void solve(){
    int n, m; cin>>n>>m;
    long long dp[m][n];
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++) dp[i][j]=0;
    }
    vector<long long>a(n), b(m), last(m, -1);
    for(long long &x:a) cin>>x;
    for(long long &x:b) cin>>x;
    for(int i=0 ; i<m ; i++){
        for(int j=n-1 ; j>=0 ; j--){
            if(a[j]>b[i]){
                last[i]=j;
                break;
            }
        }
    }
    if(last[0]>=0){
        cout<<-1<<"\n";
        return;
    }
    // dbg(last[m-2])
    // dp[0][0]=m-1;
    for(int i=0 ; i<m ; i++){
        long long sum=0, extra=m-i-1;
        for(int j=0 ; j<n ; j++){
            // if(i==0 && j==0){
            //     sum=a[0];
            //     continue;
            // }
            long long izq=(j>0?dp[i][j-1]:0), up=(i>0?dp[i-1][j]:inf);
            // dbg(last[i])
            if(j<=last[i]){
                dp[i][j]=up;
                extra=m-i-1;
                continue;
            }
            sum+=a[j];
            // dbg(izq)
            // dbg(up)
            // dbg(sum)
            // dbg(b[i])
            if(sum>b[i]){
                sum=a[j];
                dp[i][j]=min(izq+m-i-1, up);
                if(up<=izq+m-i-1){
                    sum=0;
                    extra=m-i-1;
                }else extra=0;
                // dbg(j)
            }else{
                dp[i][j]=min(izq+extra, up);
                if(up<=izq+extra){
                    sum=0;
                    extra=m-i-1;
                }else extra=0;
            }
            // dbg(dp[i][j])
            // dbg("------")
        }
    }
    cout<<dp[m-1][n-1]<<"\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}