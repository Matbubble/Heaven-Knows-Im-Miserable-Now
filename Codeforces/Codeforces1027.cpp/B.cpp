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
    string s; cin>>s;
    int a=0, b=0;
    for(char ch:s){
        a+=(ch=='1');
        b+=(ch=='0');
    }
    int xd=min(a, b);
    int xd1=max(a, b);
    xd1-=xd;
    k-=(xd1/2);
    if(k<0){
        cout<<"NO\n";
        return;
    }
    if(k%2==1) cout<<"NO\n";
    else{
        if(k/2<=xd/2) cout<<"YES\n";
        else cout<<"NO\n";
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