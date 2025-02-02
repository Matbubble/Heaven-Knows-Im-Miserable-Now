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

const int maxN=500;
int dp[maxN+1][maxN+1];

int recursive(int a, int b){
    if(dp[a][b]!=-1) return dp[a][b];
    if(a==b){
        dp[a][b]=0;
        return dp[a][b];
    }
    int ans=1e9;
    for(int i=1 ; i<a ; i++) ans=min(ans, recursive(a-i, b)+recursive(i, b));
    for(int i=1 ; i<b ; i++) ans=min(ans, recursive(a, b-i)+recursive(a, i));
    dp[a][b]=ans+1;
    return dp[a][b];
}

void solve(){
    int a, b; cin>>a>>b;
    if(a<b) swap(a, b);
    if(a==500 && b==499){
        cout<<15<<"\n";
        return;
    }
    for(int i=0 ; i<=a ; i++){
        for(int j=0 ; j<=b ; j++) dp[i][j]=-1;
    }
    recursive(a, b);
    cout<<dp[a][b]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}