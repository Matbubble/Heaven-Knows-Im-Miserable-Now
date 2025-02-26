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
int k;
vector<vector<int>>dp(505, vector<int>(1e5+5, 1e9));

void init(){
    for(int j=2 ; j<=500 ; j++){
        int jump=(j)*(j-1)/2;
        for(int i=1 ; i<=1e5 ; i++){
            int before=i-jump;
            if(j==2) dp[j][i]=dp[j][i-1]+2;
            else{
                if(before<0) dp[j][i]=dp[j-1][i];
                else{
                    dp[j][i]=min({dp[j-1][i], dp[j][before]+j, dp[j-1][before]+j});
                }
            }
        }
    }
}

void solve(){
    cin>>k;
    if(k==0){
        cout<<0<<"\n";
        return;
    }
    int last=500;
    for(int i=2 ; i<=last ; i++){
        if(i*(i-1)/2 > k){
            last=i-1;
        }
    }
    vector<int>ans;
    pair<int, int>posi;
    posi.first=last;
    posi.second=k;
    while(1){
        if(dp[posi.first][posi.second]==dp[posi.first-1][posi.second]){
            posi.first=posi.first-1;
        }else{
            int jump=posi.first*(posi.first-1)/2;
            ans.push_back(posi.first);
            posi.second=posi.second-jump;
            if(dp[posi.first][posi.second]<=dp[posi.first-1][posi.second]) posi.first=posi.first-1;
        }
        
        if(posi.second<=0 || posi.first<=1) break;
    }
    int n=0;
    for(int x:ans){
        n+=x;
    }
    int xdxd=1;
    cout<<n<<"\n";
    for(int i=0 ; i<(int)ans.size() ; i++){
        while(ans[i]--){
            cout<<i+1<<" "<<xdxd<<"\n";
            xdxd++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}