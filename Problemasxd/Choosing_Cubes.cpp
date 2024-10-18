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
When she passes, I smile
And she makes brmmmmmmm
And I am like <3
*/

void solve(){
    int n, f, k, favorites=0; cin>>n>>f>>k;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    int cube=v[f-1], cont=0;
    for(int i=0 ; i<n ; i++){
        if(v[i]==cube) favorites++;
    }
    sort(v.rbegin(), v.rend());
    for(int i=0 ; i<k ; i++){
        if(v[i]==cube) cont++;
    }
    // dbg(cont)
    // dbg(favorites)
    if(cont>=favorites) cout<<"YES\n";
    else if(cont>0) cout<<"MAYBE\n";
    else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}