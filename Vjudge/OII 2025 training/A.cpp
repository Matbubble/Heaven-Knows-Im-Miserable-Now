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

long long ones(long long n){
    long long res=0;
    long long num=1;
    while(num<=n){
        long long aux=num*10;
        res+=(n/aux*num)+min(max(n%aux-num+1, 0ll), num);
        num=aux;
    }
    return res;
}

void solve(){
    long long n; cin>>n;
    long long l=1, r=1e18;
    long long ans=0;
    while(l<=r){
        long long mid=((l+r)>>1ll);
        if(ones(mid)<=n){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}