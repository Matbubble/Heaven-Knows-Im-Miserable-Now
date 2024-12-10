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
Ella me dejo esperando tanto
*/

map<long long, long long>mp;
const long long maxN=1e5;
void init(){
    long long now=1, use=1;
    mp[now]=use;
    while(now<=maxN){
        now=(now+1)*2;
        use++;
        mp[now]=use;
    }
}

void solve(){
    long long n; cin>>n;
    auto it=mp.lower_bound(n);
    cout<<it->second<<"\n";
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