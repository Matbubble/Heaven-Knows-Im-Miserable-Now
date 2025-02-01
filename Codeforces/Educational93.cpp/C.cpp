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
    long long n; cin>>n;
    string s; cin>>s;
    vector<long long>pref;
    pref.push_back(0);
    for(char ch:s){
        pref.push_back(pref.back()+(ch-'0'));
    }
    map<long long, long long>freq;
    long long ans=0;
    for(long long i=0 ; i<=n ; i++){
        ans+=freq[pref[i]-i];
        freq[pref[i]-i]++;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}