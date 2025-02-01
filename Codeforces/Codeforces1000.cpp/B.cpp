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
    long long n, l, r, uwu=0; cin>>n>>l>>r;
    vector<long long>v(n);
    for(long long &x:v) cin>>x;
    vector<long long>a, b;
    for(long long i=l-1 ; i<n ; i++) b.push_back(v[i]);
    for(long long i=0 ; i<r ; i++) a.push_back(v[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long left=0, right=0;
    for(long long i=0 ; i<=r-l ; i++) left+=a[i];
    for(long long i=0 ; i<=r-l ; i++) right+=b[i];
    cout<<min(left, right)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}