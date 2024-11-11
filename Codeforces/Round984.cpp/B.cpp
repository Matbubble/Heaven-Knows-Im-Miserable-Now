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
I miss you
*/

void solve(){
    int n, k; cin>>n>>k;
    vector<long long>v(k+1);
    for(int i=0 ; i<k ; i++){
        long long a, b; cin>>a>>b;
        v[a]+=b;
    }
    sort(v.begin(), v.end(), greater<long long>());
    long long ans=0;
    for(int i=0 ; i<min(n, k) ; i++) ans+=v[i];
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