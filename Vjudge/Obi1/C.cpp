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
long long dp[100];

bool ra(long long x){
    for(long long i=0 ; ; i++){
        if(i*i>x) return false;
        if(i*i==x) return true;
    }
}

void init(){
    vector<long long>v(51, 0);
    for(long long i=1 ;  ; i++){
        bool ok=0;
        // dbg(i)
        for(long long j=1 ; j<=100 ; j++){
            if(v[j]==0){
                dp[j-1]=i-1;
                v[j]=i;
                ok=1;
                break;
            }else{
                long long sum=v[j]+i;
                if(ra(sum)){
                    v[j]=i;
                    ok=1;
                    break;
                }
            }
        }
        if(!ok) break;
    }
}

void solve(){
    long long n; cin>>n;
    cout<<dp[n]<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    // for(long long i=1 ; i<=50 ; i++) cout<<i<<"\n";
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}