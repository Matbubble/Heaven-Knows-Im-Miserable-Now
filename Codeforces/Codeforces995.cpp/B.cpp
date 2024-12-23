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

void solve(){
    long long n, a, b, c; cin>>n>>a>>b>>c;
    long long sum=a+b+c;
    long long ans=(n/sum)*3;
    n%=sum;
    if(n>0){
        n-=a;
        ans++;
    }
    if(n>0){
        n-=b;
        ans++;
    }
    if(n>0){
        n-=c;
        ans++;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}