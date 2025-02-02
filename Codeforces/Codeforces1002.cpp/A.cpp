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
    int n; cin>>n;
    set<int>a, b;
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        a.insert(aux);
    }
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        b.insert(aux);
    }
    if(a.size()>=2 && b.size()>=2) cout<<"YES\n";
    else{
        if(a.size()>=3 || b.size()>=3) cout<<"YES\n";
        else cout<<"NO\n";
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