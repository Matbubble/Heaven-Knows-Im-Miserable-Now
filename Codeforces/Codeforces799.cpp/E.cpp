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
Como te voy a olvidar
Los Angeles Azules
*/

void solve(){
    int n, k; cin>>n>>k;
    vector<int>s(n);
    for(int &x:s) cin>>x;
    int sum=0, l=0, ans=1e9;
    for(int r=0 ; r<n ; r++){
        sum+=(s[r]);
        while(sum>k){
            sum-=(s[l]);
            l++;
        }
        if(sum==k) ans=min(ans, l+n-r-1);
    }
    cout<<(ans==1e9?-1:ans)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}