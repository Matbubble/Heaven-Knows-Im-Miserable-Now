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
    int a, b; cin>>a>>b;
    if(b<=a) cout<<"YES\n";
    else{
        if(a==1){
            cout<<"NO\n";
            return;
        }
        if(a==2){
            if(b==3) cout<<"YES\n";
            else cout<<"NO\n";
            return;
        }
        if(a==3){
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}