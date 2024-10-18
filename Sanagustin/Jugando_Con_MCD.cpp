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
I love DP
*/

long long gcd(long long a, long long b){
    return !b?a:gcd(b, a%b);
}

long long lcm(long long a, long long b){
    return a/gcd(a, b)*b;
}

void solve(){
    int n; cin>>n;
    vector<long long>v(n), b(n+1);
    for(long long &x:v) cin>>x;
    for(int i=0 ; i<=n ; i++){
        if(!i){
            b[i]=lcm(1, v[i]);
        }else if(i==n) b[i]=lcm(v[i-1], 1);
        else b[i]=lcm(v[i], v[i-1]);
    }
    for(int i=0 ; i<n ; i++){
        if(gcd(b[i], b[i+1])!=v[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}