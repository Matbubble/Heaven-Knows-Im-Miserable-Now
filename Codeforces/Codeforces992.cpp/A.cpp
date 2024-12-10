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
No se que hacer
*/

void solve(){
    int n, k; cin>>n>>k;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    for(int i=0 ; i<n ; i++){
        bool ok=1;
        for(int j=0 ; j<n ; j++){
            if(i==j) continue;
            int curr=abs(v[i]-v[j]);
            if(curr%k==0){
                ok=0;
            }
        }
        if(ok){
            cout<<"YES\n"<<i+1<<"\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}