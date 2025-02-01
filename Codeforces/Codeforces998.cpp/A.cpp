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
    vector<int>v(4);
    for(int &x:v) cin>>x;
    int a=v[0]+v[1];
    int b=v[2]-v[1];
    int c=v[3]-v[2];
    map<int, int>mp;
    mp[a]++; mp[b]++; mp[c]++;
    int ans=0;
    for(auto it:mp){
        ans=max(ans, it.second);
    }
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