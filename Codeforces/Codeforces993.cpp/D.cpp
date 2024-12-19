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
    int n; cin>>n;
    set<int>s;
    for(int i=1 ; i<=n ; i++) s.insert(i);
    vector<int>ans, v(n);
    for(int &x:v) cin>>x;
    for(int i=0 ; i<n ; i++){
        if(s.find(v[i])!=s.end()){
            ans.push_back(v[i]);
            s.erase(v[i]);
        }
    }
    while(!s.empty()){
        ans.push_back(*s.begin());
        s.erase(s.begin());
    }
    for(int i=0 ; i<n ; i++) cout<<ans[i]<<" \n"[i==n-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}