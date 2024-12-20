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
VeeEeEn AquIiiiIii
*/
const long long MOD=1e9+7;

void solve(){
    int n; cin>>n;
    vector<long long>v(n);
    for(long long &x:v) cin>>x;
    auto pow=[&](long long a, long long b){
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
    };
    using T=pair<long long, long long>;
    stack<T>s, aux;
    long long sum=0;
    for(long long x:v){
        long long temp=__builtin_ctz(x), curr=(x>>temp);
        while(!s.empty()){
            long long aux=(curr<<temp);
            if(temp>=31 || s.top().first <= aux){
                // long long aux=(x<<temp);
                // dbg(aux)
                temp+=s.top().second;
                sum+=s.top().first;
                s.pop();
            }else break;
        }
        if(temp==0) sum+=x;
        else s.push({curr, temp});
        long long ans=sum;
        aux=s;
        while(!aux.empty()){
            ans+=(pow(2, aux.top().second)*aux.top().first)%MOD;
            // dbg(aux.top().second)
            // dbg(aux.top().first)
            ans%=MOD;
            aux.pop();
        }
        // dbg("---")
        cout<<ans%MOD<<" ";
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