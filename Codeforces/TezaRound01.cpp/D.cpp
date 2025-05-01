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
    int n, m, k; cin>>n>>m>>k;
    auto check=[&](int mid){
        if(mid>n) return false;
        int mini=1e9;
        for(int i=0 ; i<=mid ; i++){
            mini=min(mini, (n-i+mid)/(mid+1));
        }
        dbg(mini)
        dbg(mid)
        if(mid<k){
            if(mini-m*((k+mid)/(mid+1))>0) return true;
            mini=n/k;
            dbg(mini)
            dbg(mid)
            return mini-m>0;
        }
        // if(mid==5) dbg(mini)
        return mini-m*((k+mid)/(mid+1))>0;
    };
    int l=1, r=n+5;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
        dbg("--")
    }
    vector<int>curr;
    for(int i=0 ; i<=ans ; i++) curr.push_back(i);
    for(int i=0 ; i<n ; i++){
        cout<<curr[i%((int)curr.size())]<<" ";
    }
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