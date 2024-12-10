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
Ya no puedo seguiiir asi
*/

void solve(){
    long long x, y; cin>>x>>y;
    long long ans=0;
    for(long long i=1 ; i<min(2*x, y+1) ; i++){
        long long now=(x^i);
        if(now==0) continue;
        if(x%now==0 || i%now==0) ans++;
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