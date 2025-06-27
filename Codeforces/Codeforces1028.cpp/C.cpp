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

int gcd(int a, int b){
    return (b==0?a:gcd(b, a%b));
}

void solve(){
    int n; cin>>n;
    vector<int>v(n);
    int res=0;
    for(int &x:v){
        cin>>x;
        res=((!res)?x:gcd(res, x));
    }
    int cont=0;
    for(int x:v) cont+=(x==res);
    if(cont>0){
        cout<<n-cont<<"\n";
        return;
    }
    int ans=1e9;
    map<int, int>mp;
    for(int i=0 ; i<n ; i++){
        for(pair<int, int> it:mp){
            int g=gcd(it.first, v[i]);
            mp[g]=((!mp[g])?it.second+1:min(mp[g], it.second+1));
            if(g==res) ans=min(ans, mp[g]);
        }
        mp[v[i]]=1;
    }
    cout<<ans+n-2<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}