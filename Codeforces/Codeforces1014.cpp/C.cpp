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
    long long sum=0, cont=0, maxi=0;
    long long n; cin>>n;
    for(long long i=0 ; i<n ; i++){
        long long x; cin>>x;
        maxi=max(maxi, x);
        cont+=(x&1);
        sum+=x;
    }
    if(cont==0 || cont==n) cout<<maxi<<"\n";
    else cout<<sum-cont+1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}