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
    int n, k; cin>>n>>k;
    set<int>s;
    for(int i=1 ; i<=n ; i++) s.insert(i);
    vector<int>ans(n);
    bool first=0;
    int cont=0;
    for(int i=0 ; i<n ; i++){
        cont++;
        if(cont==k){
                ans[i]=*s.begin();
                s.erase(s.begin());
                first=1;
                cont=0;
            }
    }
    for(int i=n-1 ; i>=0 ; i--){
        if(ans[i]==0){
            ans[i]=*s.begin();
            s.erase(s.begin());
        }
    }
    for(int i=0 ; i<n ; i++) cout<<ans[i]<<" \n"[i==n-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}