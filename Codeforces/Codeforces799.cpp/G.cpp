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
    int n, k; cin>>n>>k;
    vector<long long>v(n);
    for(long long &x:v) cin>>x;
    vector<bool>use(n, 1);
    for(int i=0 ; i<n ; i++){
        if(i==0 || v[i]*2 <= v[i-1]) use[i]=0;
    }
    int ans=0, auxi=1;
    for(int i=0 ; i<n ; i++){
        if(use[i]==0){
            // dbg(i)
            // dbg(auxi)
            ans+=max(0, auxi-k);
            auxi=1;
        }else auxi++;
    }
    ans+=max(0, auxi-k);
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