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
    long long n, k; cin>>n>>k;
    long long team=1ll, length=n, last;
    bool ok=0ll;
    long long ans=0ll;
    while(1){
        if(ok) last*=2ll;
        if(length%2ll==1ll){
            if(!ok){
                long long num=((length+1ll)/2ll);
                num*=team;
                long long sum=((team*(team-1ll))/2ll);
                last=num+(sum*length);
                ok=1;
            }
            ans+=last;
            // cout<<ans<<"\n";
        }
        team*=2ll;
        length/=2ll;
        if(length<k || length<=0ll) break;
    }    
    cout<<ans<<"\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}