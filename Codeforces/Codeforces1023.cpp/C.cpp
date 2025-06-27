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

struct point{
    int l, r, val;
};

void solve(){
    int n; cin>>n;
    vector<int>v(n), posi(31), xd(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
        posi[v[i]]=i;
    }
    vector<point>vp;
    for(int i=0 ; i<n ; i++){
        // dbg(xd[i])
        // dbg(v[i])
        if(xd[i]!=v[i]){
            vp.push_back({i+1, posi[v[i]]+1, v[i]});
            for(int j=i ; j<=posi[v[i]] ; j++) xd[j]=v[i];
        }
    }
    cout<<(int)vp.size()<<"\n";
    for(point x:vp) cout<<x.l<<" "<<x.r<<" "<<x.val<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}