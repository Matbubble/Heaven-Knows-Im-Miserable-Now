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
    using T=pair<int, int>;
    vector<T>v(n);
    vector<int>vv(4*n);
    map<T, int>freq;
    for(T &x:v){
        cin>>x.first>>x.second;
        if(x.first==x.second){
            vv[x.first]=1;
            freq[x]++;
        }
    }
    for(int i=1 ; i<4*n ; i++) vv[i]+=vv[i-1];
    for(int i=0 ; i<n ; i++){
        int l=v[i].first, r=v[i].second;
        if(l==r){
            if(freq[v[i]]>=2) cout<<0;
            else cout<<1;
            continue;
        }
        int count=vv[r]-vv[l-1];
        // dbg(count)
        if(count==r-l+1) cout<<0;
        else cout<<1;
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