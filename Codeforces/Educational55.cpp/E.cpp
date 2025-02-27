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
    int n, c, ans=0; cin>>n>>c;
    vector<int>freq, v(n);
    freq.push_back(0);
    int posi=1;
    map<int, vector<int>>mp;
    for(int& x:v){
        cin>>x;
        mp[x].push_back(posi++);
        freq.push_back(freq.back()+(x==c));
    }
    for(auto it:mp){
        vector<int>max_subarray;
        max_subarray.push_back(1);
        for(int i=1 ; i<(int)it.second.size() ; i++){
            dbg(it.second[i])
            dbg(it.second[i-1])
            max_subarray.push_back(freq[it.second[i]]-freq[it.second[i-1]-1]);
            freq.push_back(1);
        }
        int mini=0, pref=0;
        int maxi=0;
        for(int x:max_subarray){
            dbg(x)
            pref+=x;
            maxi=max(maxi, pref-mini);
            mini=min(mini, pref);
        }
        dbg(maxi)
        ans=max(ans, maxi);
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}