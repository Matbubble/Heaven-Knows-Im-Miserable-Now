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
Secreto de amor
Joan Sebastian
*/

void solve(){
    long long n; cin>>n;
    vector<long long>v(n), dp;
    long long sum=0;
    set<long long>ans;
    map<long long, long long>pref;
    for(long long &x:v){
        cin>>x;
        sum+=x;
        pref[sum]++;;
        dp.push_back(sum);
    }
    // ans.insert(0);
    set<long long>uwu, unu;
    for(long long i=n-1 ; i>=0 ; i--){
        long long auxi=dp[i];
        // if(i<n-1){
        //     if(v[i]!=v[i+1] && unu.count(v[i])){
        //         pref[dp[i]]--;
        //         if(pref[dp[i]]<=0) pref.erase(dp[i]);
        //         continue;
        //     }
        // }
        if(uwu.count(auxi)){
            pref[dp[i]]--;
            if(pref[dp[i]]<=0) pref.erase(dp[i]);
            continue;
        }
        uwu.insert(auxi);
        unu.insert(v[i]);
        ans.insert(auxi);
        for(auto x:pref){
            ans.insert(auxi-x.first);
        }
        pref[dp[i]]--;
        if(pref[dp[i]]<=0) pref.erase(dp[i]);
    }
    cout<<(long long)(ans.size())<<"\n";
    for(long long x:ans) cout<<x<<" ";
    cout<<"\n";
    // ans.insert(sum);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}