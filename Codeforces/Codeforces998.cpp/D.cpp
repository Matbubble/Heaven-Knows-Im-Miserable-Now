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
    long long n; cin>>n;
    vector<long long>v(n);
    for(long long &x:v) cin>>x;
    for(long long i=1 ; i<n ; i++){
        long long aux=min(v[i-1], v[i]);
        v[i-1]-=aux;
        v[i]-=aux;
        if(v[i]<v[i-1]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}