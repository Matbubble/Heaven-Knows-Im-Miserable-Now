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
A crying Diamond
Mon Laferte
*/

void solve(){
    string s; cin>>s;
    map<long long, bool> freq;
    string a, b;
    long long n=(long long)s.size(), mid=(long long)s.size()/2;
    if(n<=2){
        cout<<"NO\n";
        return;
    }
    long long l, r;
    long long one=0ll, two=0ll;
    long long p=2ll, p_powA=1ll, p_powB=1ll;
    long long MOD=1e17;
    l=mid;
    for(long long i=0 ; i<=mid ; i++){
        one=(one+(s[i]-'a'+1)*p_powA)%MOD;
        p_powA=(p_powA*p)%MOD;
    }
    if(!(n&1)) mid--;
    r=mid;
    for(long long i=mid ; i<n ; i++){
        two=(two+(s[i]-'a'+1)*p_powB)%MOD;
        p_powB=(p_powB*p)%MOD;
    }
    freq[one]=1;
    if(freq[two]==1){
        cout<<"YES\n";
        for(long long i=mid ; i<n ; i++) cout<<s[i];
        cout<<"\n";
        return;
    }
    while(1){
        r--;
        l++;
        if(r==0 || l==n-1) break;
        one=(one+(long long)(s[l]-'a'+1ll)*p_powA)%MOD;
        p_powA=(p_powA*p)%MOD;
        two=((two*p)+(s[r]-'a'+1ll))%MOD;
        freq[one]=1;
        if(freq[two]==1){
            cout<<"YES\n";
            for(long long i=r ; i<n ; i++) cout<<s[i];
            cout<<"\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}