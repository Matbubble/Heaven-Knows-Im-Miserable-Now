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
Go ahead officer, chase me.
I don't have someone waiting for me
*/
 
const int MOD=1e9+7;
 
long long binpow(long long a, long long b){
    long long res=1;
    while(b>0){
        if(b&1){
            res*=a;
            res%=MOD;
        }
        a*=a;
        a%=MOD;
        b>>=1;
    }
    return res;
}
 
void solve(){
    long long a, b; cin>>a>>b;
    cout<<binpow(a, b)<<"\n";
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}