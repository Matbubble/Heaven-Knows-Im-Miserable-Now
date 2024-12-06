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
Kate uwu
*/

void solve(){
    int n, m, ans=0, nose=0; cin>>n>>m;
    vector<string>v(n);
    for(string &s:v) cin>>s;
    set<char>xd;
    for(string s:v){
        for(char ch:s) nose++;
        if(nose>m) break;
        ans++;
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