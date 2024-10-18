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
I love DP
*/

void solve(){
    long long n, k; cin>>n>>k;
    string s; cin>>s;
    if(k>=2){
        bool ok=0;
        for(char ch:s) ok|=(ch!=s[0]);
        if(ok) cout<<2<<"\n";
        else cout<<1<<"\n";
    }else if(k==1){
        if(s==string(s.rbegin(), s.rend())) cout<<1<<"\n";
        else cout<<2<<"\n";
    }else cout<<1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}