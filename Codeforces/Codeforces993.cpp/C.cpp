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
Shhhhh!
*/

void solve(){
    long long m, a, b, c; cin>>m>>a>>b>>c;
    long long ans=0;
    long long one=m, two=m;
    ans+=min(one, a);
    one-=min(one, a);
    ans+=min(one, c);
    c-=min(one, c);
    ans+=min(two, b);
    two-=min(two, b);
    ans+=min(two, c);
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}