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

const int maxN=5000;
long long dp[maxN+1][maxN+1];
vector<long long>v;

long long recursive(int i, int j){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==j) return dp[i][j]=v[i];
    else if(i+1==j) return dp[i][j]=max(v[i], v[i+1]);
    else{
        long long one=v[i]+min(recursive(i+2, j), recursive(i+1, j-1));
        long long two=v[j]+min(recursive(i, j-2), recursive(i+1, j-1));
        return dp[i][j]=max(one, two);
    }
}

void solve(){
    int n; cin>>n;
    v.resize(n);
    for(long long &x:v) cin>>x;
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=n ; j++) dp[i][j]=-1;
    }
    recursive(0, n-1);
    cout<<dp[0][n-1]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}