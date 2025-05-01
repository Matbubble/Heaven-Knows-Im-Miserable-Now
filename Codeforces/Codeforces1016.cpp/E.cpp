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
    int n, k; cin>>n>>k;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    int l=1, r=n+5;
    auto check=[&](int mid){
        int use=0;
        set<int>s;
        for(int x:v){
            if(x<mid) s.insert(x);
            if((int)s.size()==mid){
                s.clear();
                use++;
            }
        }
        return use>=k;
        // if(!s.empty()) return false;
    };
    // dbg(check(2))
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else r=mid-1;
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