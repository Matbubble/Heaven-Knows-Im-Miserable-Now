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

const int maxN=1e6;
int dp[maxN+1];

void init(){
    for(int i=1 ; i<=maxN ; i++){
        int aux=i;
        int mini=1e9;
        while(aux>0){
            if(aux%10>0)mini=min(mini, dp[i-(aux%10)]);
            aux/=10;
        }
        dp[i]=mini+1;
    }
}

void solve(){
    int n; cin>>n;
    cout<<dp[n]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}