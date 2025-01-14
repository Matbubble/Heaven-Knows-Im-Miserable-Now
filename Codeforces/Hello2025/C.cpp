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
Somethin' Stupid
Frank Sinatra
*/

void solve(){
    int l, r; cin>>l>>r;
    int log=31-__builtin_clz(l^r);
    int a=(l|((1<<log)-1))+1;
    int b=a-1;
    int c=(a==r?l:r);
    cout<<a<<" "<<b<<" "<<c<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}