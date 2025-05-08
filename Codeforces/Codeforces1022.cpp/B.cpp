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
    long long n, x; cin>>n>>x;
    if(n==1){
        if(x==0) cout<<-1<<"\n";
        else cout<<x<<"\n";
        return;
    }
    long long ans=1e18;
    for(long long i=1 ; i<32 ; i++){
        long long a=(n-i)%2;
        long long aux=x^a;
        
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