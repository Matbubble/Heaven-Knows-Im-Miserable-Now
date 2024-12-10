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
Paisaje uwu
*/
const int maxN=2e5;
long long dp[maxN+1];

void init(){
    auto log3=[](long long x) -> long long{
        long long ans=0, res=1;
        while(res<=x){
            res*=3;
            ans++;
        }
        return ans;
    };
    for(long long i=1 ; i<=maxN ; i++){
        dp[i]=dp[i-1]+log3(i);
    }
}

void solve(){
    long long l, r; cin>>l>>r;
    auto log3=[](long long x) -> long long{
        long long ans=0, res=1;
        while(res<=x){
            res*=3;
            ans++;
        }
        return ans;
    };
    cout<<dp[r]-dp[l-1]+log3(l)<<"\n";;
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