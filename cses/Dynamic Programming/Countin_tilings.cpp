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

const int maxN=1e5, dpmask=(1<<10);
long long dp[maxN+1][dpmask];
const long long MOD=1e9+7;
int n, m;

void propagate(int column, int row, int mask, int next_mask){
    if(row==n){
        dp[column+1][next_mask]+=dp[column][mask];
        dp[column+1][next_mask]%=MOD;
        return;
    }
    if((mask>>row)&1) propagate(column, row+1, mask, next_mask);
    else{
        propagate(column, row+1, mask, next_mask|(1<<row));
        if(row+1<n && !((mask>>(1+row))&1)) propagate(column, row+2, mask, next_mask);
    }
}

void solve(){
    cin>>n>>m;
    int subsets=(1<<n);
    dp[0][0]=1;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<subsets ; j++){
            if(dp[i][j]<=0) continue;
            propagate(i, 0, j, 0);
        }
    }
    cout<<dp[m][0]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}