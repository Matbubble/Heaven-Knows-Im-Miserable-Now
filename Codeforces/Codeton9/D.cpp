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
Una noche espectacular
*/

void solve(){
    long long n, m; cin>>n>>m;
    vector<long long>v(m), ans(n+1, m-1);
    for(long long &x:v) cin>>x;
    for(int i=1 ; i<=n ; i++){
        for(int j=i+i ; j<=n ; j+=i){
            if(ans[j]==ans[i]) ans[j]--;
            if(ans[j]<0){
                cout<<"-1\n";
                return;
            }
        }
    }
    for(int i=1 ; i<=n ; i++) cout<<v[ans[i]]<<" ";
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