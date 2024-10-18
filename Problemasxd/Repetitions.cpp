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
typedef long long ll;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";
 
/*
I'll drive fast to feel alive uwu
*/
 
void solve(){
    string s; cin>>s;
    int ans=1;
    vector<int>dp(s.size());
    dp[0]=1;
    for(int i=1 ; i<s.size() ; i++){
        if(s[i]==s[i-1]) dp[i]=dp[i-1]+1;
        else dp[i]=1;
        ans=max(ans, dp[i]);
    }
    cout<<ans<<"\n";
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //test cases
    solve();
    return 0;
}