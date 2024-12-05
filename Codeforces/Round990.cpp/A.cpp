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
La playa
*/

void solve(){
    int n; cin>>n;
    set<int>s;
    for(int i=1 ; i<=101 ; i+=2) s.insert(i*i);
    int cont=0, ans=0;
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        cont+=aux;
        if(s.count(cont)) ans++;
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