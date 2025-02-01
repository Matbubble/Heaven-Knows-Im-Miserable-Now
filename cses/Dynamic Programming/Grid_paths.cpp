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

int dirX[]={-1, 0};
int dirY[]={0, -1};

const long long MOD=1e9+7;

void solve(){
    int n; cin>>n;
    vector<vector<char>>lab(n, vector<char>(n));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++) cin>>lab[i][j];
    }
    vector<vector<long long>>dp(n, vector<long long>(n));
    dp[0][0]=(lab[0][0]=='*'?0:1);
    auto legal=[&](int x, int y){
        return x>=0 && y>=0 && x<n && y<n && lab[x][y]=='.';
    };
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if((i==0 && j==i) || lab[i][j]=='*') continue;
            for(int k=0 ; k<2 ; k++){
                auto[x, y]=make_pair(i+dirX[k], j+dirY[k]);
                if(legal(x, y)) dp[i][j]+=dp[x][y];
            }
            dp[i][j]%=MOD;
        }
    }
    cout<<dp[n-1][n-1]%MOD<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}