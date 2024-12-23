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
    int n; cin>>n;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    int l=-1, r=-1;
    for(int i=0 ; i<n ; i++){
        if(v[i]>0 && l==-1) l=i;
        if(v[n-i-1]>0 && r==-1) r=n-i-1;
    }
    // dbg(l)
    // dbg(r)
    if(l==-1 || l>r){
        cout<<"0\n";
        return;
    }
    bool ok=0;
    for(int i=l ; i<=r ; i++){
        if(v[i]==0) ok=1;
    }
    cout<<(ok?2:1)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}