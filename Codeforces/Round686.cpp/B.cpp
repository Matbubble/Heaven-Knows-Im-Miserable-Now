#include <iostream>
using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
I love DP
*/

void solve(){
    int n; cin>>n;
    vector<int>freq(n+1), posi(n+1);
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        posi[aux]=i+1;
        freq[aux]++;
    }
    for(int i=1 ; i<=n ; i++){
        if(freq[i]==1){
            cout<<posi[i]<<"\n";
            return;
        }
    }
    cout<<-1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}