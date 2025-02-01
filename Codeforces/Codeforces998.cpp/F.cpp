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


vector<bool>cribe(1000000, 1);
vector<long long>v(1000000);
void init(){
    cribe[0]=cribe[1]=0;
    for(long long i=2 ; i<=100000 ; i++){
        if(cribe[i]){
            for(long long j=i ; j<=100000 ; j+=i){
                cribe[j]=0;
                v[j]++;
            }
        }
    }
}

long long MOD=998244353;
long long binpow(long long a, long long b){
    long long res=1;
    while(b>0){
        if(b&1){
            res*=a;
            res%=MOD;
        }
        a*=a;
        a%=MOD;
        b>>=1ll;
    }
    return res%MOD;
}
void solve(){
    long long k, n; cin>>k>>n;
    cout<<n<<" ";
    map<long long, long long>ans;
    for(long long i=1 ; i<=100000 ; i++){
        if(i==1) ans[1]=n*(n+1)/2;
        else{
            ans[i]=pow(2, i)+n;
        }
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