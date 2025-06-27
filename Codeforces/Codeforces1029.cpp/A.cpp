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
    int n, x; cin>>n>>x;
    int primero=-1, last=-1;
    for(int i=0 ; i<n ; i++){
        int x; cin>>x;
        if(x==1){
            if(primero==-1) primero=i;
            last=i;
        }
    }
    int cantidad=last-primero+1;
    // dbg(cantidad)
    cout<<(x>=cantidad?"YES\n":"NO\n");
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}