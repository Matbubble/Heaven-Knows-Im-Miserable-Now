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
#include <cassert>

using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
MC lover
*/

void solve(){
    int n; cin>>n;
    vector<int>a(n), b(n);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    map<int, set<int>>freq;
    for(int i=0 ; i<n ; i++){
        freq[a[i]].insert(i);
        freq[b[i]].insert(i);
    }
    int ans=-1;
    for(int i=0 ; i<n ; i++){
        if(a[i]==b[i]) ans=i;
        else{
            auto it=freq[a[i]].upper_bound(i+1);
            auto it1=freq[b[i]].upper_bound(i+1);
            if(it!=freq[a[i]].end() || it1!=freq[b[i]].end()) ans=i;
            else{
                if(i<n-1){
                    if(a[i]==a[i+1] || b[i]==b[i+1]) ans=i;
                }
            }
        }
    }
    cout<<ans+1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}