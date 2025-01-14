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
Como tu
Leon Larregui
*/

void solve(){
    int n; cin>>n;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    // sort(v.begin(), v.end());
    bool ok=0;
    for(int i=0 ; i<n-1 ; i++){
        int a=min(v[i], v[i+1]);
        int b=max(v[i], v[i+1]);
        if(2*a>b) ok=1;
    }
    cout<<(ok?"YES":"NO")<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}