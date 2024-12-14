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
Ven quiero saber
Por que te fuiste sin mi?
*/

void solve(){
    long long b, c, d, b_mask, c_mask, d_mask; cin>>b>>c>>d;
    long long a=0;
    for(long long i=0 ; i<62 ; i++){
        b_mask=((b>>i)&1ll);
        c_mask=((c>>i)&1ll);
        d_mask=((d>>i)&1ll);
        if((b_mask && !c_mask && !d_mask) || (!b_mask && c_mask && d_mask)){
            cout<<-1<<"\n";
            return;
        }
        long long need=((b_mask&c_mask)?(1ll-d_mask):d_mask);
        need<<=i;
        a+=need;
    }
    cout<<a<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}