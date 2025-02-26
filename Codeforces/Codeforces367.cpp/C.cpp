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

void solve(){
    long long n; cin>>n;
    vector<vector<long long>>dp(n+1, vector<long long>(2));
    vector<long long>price(n);
    for(long long &x:price) cin>>x;
    vector<string>cs(n);
    for(string &x:cs) cin>>x;
    dp[0][0]=0;
    dp[0][1]=price[0];
    auto ok=[&](string a, string b){
        for(long long i=0 ; i<min((long long)a.size(), (long long)b.size()); i++){
            if(a[i]<b[i]) return 0;
            if(a[i]>b[i]) return 1;
        }
        if((long long)a.size()<(long long)b.size()) return 0;
        return 1;
    };
    for(long long i=1 ; i<n ; i++){
        string aux=cs[i-1];
        reverse(aux.begin(), aux.end());
        string auxi=cs[i];
        reverse(auxi.begin(), auxi.end());
        //no reverse
        long long mini=1e18;
        if(ok(cs[i], cs[i-1])) mini=min(mini, dp[i-1][0]);
        if(ok(cs[i], aux)) mini=min(mini, dp[i-1][1]);
        dp[i][0]=mini;
        //reverse
        mini=1e18;
        if(ok(auxi, cs[i-1])) mini=min(mini, dp[i-1][0]+price[i]);
        if(ok(auxi, aux)) mini=min(mini, dp[i-1][1]+price[i]);
        dp[i][1]=mini;
    }
    long long mini=min(dp[n-1][0], dp[n-1][1]);
    cout<<(mini==1e18?-1:mini)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}