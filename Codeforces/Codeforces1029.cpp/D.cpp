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
#include <cassert>

using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
MC lover
*/

void solve(){
    long long n; cin>>n;
    vector<long long>v(n);
    for(long long &x:v) cin>>x;
    if(v[n-1]<v[0]) reverse(v.begin(), v.end());
    if(!is_sorted(v.begin(), v.end())){
        cout<<"NO\n";
        return;
    }
    long long curr=n, currr=1;
    set<long long>s;
    for(int i=n-1 ; i>0 ; i--){
        long long a=(curr*v[0])-v[i];
        long long b=(curr*n)-currr;
        if(a%b>0 || a<0 || b<=0){
            cout<<"NO\n";
            return;
        }else s.insert(a/b);
        curr--;
        currr++;
    }
    cout<<((int)s.size()==1?"YES\n":"NO\n");
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}