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
    int n, k; cin>>n>>k;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    sort(v.begin(), v.end());
    int aux=n-k;
    int l=0, r=0;
    vector<int>xd;
    for(int i=0 ; i<aux ; i++) xd.push_back(v[i]);
    l=xd[(aux-1)/2];
    // dbg(l)
    xd.clear();
    for(int i=n-1 ; i>k-1 ; i--) xd.push_back(v[i]);
    r=xd[(aux-1)/2];
    // dbg(r)
    cout<<r-l+1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}