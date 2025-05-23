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
I love DP
*/

void solve(){
    int n, k, x=0, ans=0; cin>>n>>k;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    for(int i=0 ; i<n ; i++){
        if(v[i]>=k) x+=v[i];
        if(v[i]==0){
            if(x>0){
                ans++;
                x--;
            }
        }
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