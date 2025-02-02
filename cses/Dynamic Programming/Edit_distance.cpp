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

const int maxN=5001;
int dp[maxN][maxN];

void solve(){
    string a, b; cin>>a>>b;
    int n=(int)a.size(), m=(int)b.size();
    vector<int>one(30), two(30);
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=m ; j++){
            if(i==0){
                dp[i][j]=j;
            }else if(j==0){
                dp[i][j]=i;
            }else{
                if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
            }
            // dbg(dp[i][j])
        }
    }
    cout<<dp[n][m];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}