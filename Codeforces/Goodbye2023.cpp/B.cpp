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
Sunflower
Rex Orange County
*/

long long gcd(long long a, long long b){
    return (b==0?a:gcd(b, a%b));
}
long long lcm(long long a, long long b){
    return a/gcd(a, b)*b;
}

void solve(){
    long long a, b; cin>>a>>b;
    long long c=lcm(a, b);
    if(c==max(a, b)){
        c*=max(a, b)/min(a, b);
    }
    cout<<c<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}