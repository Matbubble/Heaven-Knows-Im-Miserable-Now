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
Te lo pido de rodillas
Los iracundos
*/

void solve(){
    int n; cin>>n;
    vector<int>a(n), b(n);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    int ans=a[n-1];
    for(int i=0 ; i<n-1 ; i++){
        if(a[i]>b[i+1]) ans+=a[i]-b[i+1];
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