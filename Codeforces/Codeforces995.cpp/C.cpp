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
    int n, m, k; cin>>n>>m>>k;
    vector<int>a(m), q(k);
    for(int &x:a) cin>>x;
    for(int &x:q) cin>>x;
    if(k<n-1){
        for(int i=0 ; i<m ; i++) cout<<0;
        cout<<"\n";
        return;
    }else if(k==n-1){
        set<int>s;
        for(int i=1 ; i<=n ; i++) s.insert(i);
        for(int x:q) s.erase(x);
        for(int x:a){
            if(s.count(x)) cout<<1;
            else cout<<0;
        }
        cout<<"\n";
        return;
    }else{
        for(int i=0 ; i<m ; i++) cout<<1;
        cout<<"\n";
        return;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}