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
Codear internado en el hospital es GOD
Igual es mi primer choque grave en la moto uwuwuw
*/

void solve(){
    int n; cin>>n;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    int ans=1e9;
    for(int i=0 ; i<n ; i++){
        if(i==0){
            int aux=max(v[i], v[i+1]);
            ans=min(ans, aux);
        }else if(i==n-1){
            int aux=max(v[i], v[i-1]);
            ans=min(ans, aux);
        }else{
            int a=max(v[i], v[i-1]);
            int b=max(v[i], v[i+1]);
            ans=min(ans, min(a, b));
        }
    }
    cout<<ans-1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}