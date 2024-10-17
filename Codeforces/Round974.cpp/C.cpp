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

const long long maxN=1e6;
long long tree[maxN+1];
void add(long long x){
    while(x<=maxN){
        tree[x]++;
        x+=x&-x;
    }
}
long long query(long long x){
    long long res=0;
    if(x>maxN) x=maxN;
    while(x>0){
        res+=tree[x];
        x-=x&-x;
    }
    return res;
}

void solve(){
    long long n; cin>>n;
    vector<long long>v(n);
    for(long long &x:v){
        cin>>x;
        add(x);
    }
    sort(v.begin(), v.end());
    if(n<3){
        cout<<-1<<"\n";
        return;
    }
    long long sum=accumulate(v.begin(), v.end(), 0ll);
    long long l=0, r=1e18, ans=-1;
    while(l<=r){
        long long mid=(l+r);
        mid>>=1ll;
        long long temp=((sum+mid)+(2*n)-1)/(2*n);
        // dbg(temp)
        // dbg(mid)
        // dbg(q)
        long long pro=v[n/2];
        if(temp-1>=pro){
            r=mid-1;
            ans=mid;
        }else l=mid+1;
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