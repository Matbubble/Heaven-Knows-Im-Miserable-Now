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
    int n; cin>>n;
    float k, l; cin>>k>>l;
    vector<float>v(n);
    for(float &x:v) cin>>x;
    float ans=v[0];
    // dbg(ans)
    for(int i=0 ; i<n ; i++){
        if(i==0) v[i]=0;
        else{
            float diff=v[i]-v[i-1];
            if(diff>=k){
                diff-=k;
                v[i]-=min(ans, diff);
            }
            else{
                v[i]+=ans;
            }
            
        }
    }
    float extra=0, rest=0;
    for(int i=1 ; i<n ; i++){
        v[i]-=rest;
        float diff=v[i]-v[i-1];
        // dbg(extra)
        if(diff>k)diff-=k;
        else continue;
        extra+=diff/2.;
        rest+=extra;
        v[i]-=rest;
    }
    float posi=v[n-1]+k;
    if(posi<=l) ans+=l-posi;
    // dbg(posi)
    ans+=extra;
    ans*=2.;
    long long aux=ans;
    cout<<aux<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}