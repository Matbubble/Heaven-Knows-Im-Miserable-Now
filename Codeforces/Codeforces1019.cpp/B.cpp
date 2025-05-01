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
    int n; cin>>n;
    int caca=1e9;
    int extra=0;
    int ans=n;
    string s; cin>>s;
    reverse(s.begin(), s.end());
    s+='0';
    reverse(s.begin(), s.end());
    s+='0';
    for(int i=1 ; i<=n+1 ; i++){
        if(s[i]!=s[i-1]) ans++;
    }
    int a=0, b=0;
    for(int i=0 ; i<=n+1 ; i++){
        if(s[i]=='0' && s[i+1]=='1') a++;
        else if(s[i]=='1' && s[i+1]=='0') b++;
    }
    if(a>=2 || b>=2) extra=2;
    caca=min(caca, ans-extra);
    s.pop_back();
    s+='1';
    ans=n;
    for(int i=1 ; i<=n+1 ; i++){
        if(s[i]!=s[i-1]) ans++;
    }
    a=0, b=0;
    for(int i=0 ; i<=n+1 ; i++){
        if(s[i]=='0' && s[i+1]=='1') a++;
        else if(s[i]=='1' && s[i+1]=='0') b++;
    }
    if(a>=2 || b>=2) extra=2;
    caca=min(caca, ans-extra);
    cout<<caca<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}