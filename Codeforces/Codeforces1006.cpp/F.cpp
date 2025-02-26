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
    long long n, k; cin>>n>>k;
    if(n==1){
        cout<<k<<"\n";
        return;
    }
    if(n&1){
        cout<<k<<" ";
        for(long long i=1 ; i<n-1 ; i++) cout<<0<<" ";
        cout<<k<<"\n";
    }else{
        for(long long i=0 ; i<n ; i++) cout<<k<<" ";
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}