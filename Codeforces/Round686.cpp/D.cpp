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
I love DP
*/

long long log(long long a, long long b){
    long long ans=-1;
    while(b%a==0){
        b/=a;
        ans++;
    }
    return ans;
}

void solve(){
    long long n; cin>>n;
    pair<long long, long long>ans;
    for(long long i=2 ; i*i<=n ; i++){
        if(n%i==0){
            long long temp=log(i, n);
            if(ans.first<temp){
                ans.first=temp;
                ans.second=i;
            }
        }
    }
    cout<<ans.first+1ll<<"\n";
    for(long long i=0 ; i<ans.first ; i++){
        cout<<ans.second<<" ";
        n/=ans.second;
    }
    if(n>1) cout<<n<<"\n";
    else cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}