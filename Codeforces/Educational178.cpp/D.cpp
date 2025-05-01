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

vector<long long>p;
const long long maxN=1e7;
bool prime[maxN+1];

void init(){
    for(long long i=2 ; i<=maxN ; i++){
        if(prime[i]==0){
            p.push_back(p.back()+i);
            for(long long j=i+i ; j<=maxN ; j+=i){
                prime[j]=1;
            }
        }
    }
}

void solve(){
    long long n, ans; cin>>n;
    ans=n-1;
    vector<long long>v(n);
    for(long long &x:v) cin>>x;
    sort(v.begin(), v.end());
    long long sum=v[n-1];
    for(long long i=n-2 ; i>=0 ; i--){
        sum+=v[i];
        // dbg(sum)
        // dbg(n-i)
        
        if(sum>=p[n-i]) ans=min(ans, i);
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    p.push_back(0);
    init();
    // dbg(p.size())
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}