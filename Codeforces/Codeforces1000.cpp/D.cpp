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
const int maxN=2e5;
long long dp[maxN+1][2][1];

void solve(){
    int n, m; cin>>n>>m;
    vector<long long>a(n), b(m);
    for(long long &x:a) cin>>x;
    for(long long &x:b) cin>>x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}