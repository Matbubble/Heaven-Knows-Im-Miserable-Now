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
const int maxN=2e5;
int diff[maxN+2];
void solve(){
    int n, k, q; cin>>n>>k>>q;
    for(int i=0 ; i<n ; i++){
        int a, b; cin>>a>>b;
        diff[a]++;
        diff[b+1]--;
    }
    int curr=0;
    vector<int>pref;
    pref.push_back(0);
    for(int i=0 ; i<=maxN ; i++){
        curr+=diff[i];
        if(curr>=k) pref.push_back(pref.back()+1);
        else pref.push_back(pref.back());
    }
    for(int i=0 ; i<q ; i++){
        int a, b; cin>>a>>b;
        cout<<pref[b+1]-pref[a]<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}