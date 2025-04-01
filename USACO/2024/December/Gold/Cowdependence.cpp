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
    int n; cin>>n;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    vector<int>grups(n+1);
    vector<vector<int>>freq(n+1);
    for(int i=1 ; i<=n ; i++) freq[v[i]].push_back(i);
    for(int i=1 ; i<=n ; i++){
        vector<int>maxSub;
        maxSub.push_back(1);
        for(int j=1 ; j<(int)freq[i].size() ; j++){
            maxSub.push_back(-(freq[i][j]-freq[i][j-1]));
            maxSub.push_back(1);
        }
        int pref=0, curr=0;
        int maxi=0;
        for(int x:maxSub){
            curr+=x;
            maxi=max(maxi, curr-pref);
            pref=min(pref, curr);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}