#include <iostream>
using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
I love DP
*/

void solve(){
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++){
        if(i==n) cout<<1;
        else cout<<i+1;
        cout<<" ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}