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
    vector<long long>a(n), b(n);
    for(long long &x:a) cin>>x;
    for(long long &x:b) cin>>x;
    long long cant=0, need=0, extra=1e18;
    for(int i=0 ; i<n ; i++){
        if(a[i]<b[i]){
            cant++;
            need=b[i]-a[i];
        }else{
            extra=min(extra, a[i]-b[i]);
        }
    }
    if(cant>=2) cout<<"NO\n";
    else{
        if(need<=extra) cout<<"YES\n";
        else cout<<"NO\n";
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