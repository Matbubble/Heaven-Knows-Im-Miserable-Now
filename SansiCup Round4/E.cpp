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

void solve(){
    long long n; cin>>n;
    vector<long long>v(n);
    for(long long &x:v) cin>>x;
    long long xd=0;
    long long l=-1, r=n, a=0, b=0, ans=0;
    while(l<r){
        if(a<b){
            l++;
            if(l==r) break;
            xd++;
            a+=v[l];
        }else{
            r--;
            if(l==r) break;
            xd++;
            b+=v[r];
        }
        if(a==b){
            ans=xd;
        }
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