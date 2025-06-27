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
    set<int>s;
    int n; cin>>n;
    for(int i=0 ; i<n ; i++){
        int a; cin>>a;
        s.insert(a);
    }
    vector<int>xd;
    for(int x:s) xd.push_back(x);
    vector<int>pref;
    pref.push_back(1);
    for(int i=1 ; i<(int)xd.size() ; i++){
        if(xd[i]==xd[i-1]+1) pref.back()=pref.back()+1;
        else pref.push_back(1);
    }
    int ans=0;
    for(int x:pref) ans+=((x+1)/2);
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