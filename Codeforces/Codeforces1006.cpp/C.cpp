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
    int n, x; cin>>n>>x;
    if(n==1){
        cout<<x<<"\n";
        return;
    }
    vector<int>ans;
    ans.push_back(0);
    n--;
    int now=0;
    for(int i=1 ; i<=n ; i++){
        if(i==n){
            if((now|i)==x) ans.push_back(i);
            else ans.push_back(x);
            continue;
        }
        bool ok=1;
        for(int j=0 ; j<=31 ; j++){
            if(((x>>j)&1)==0 && ((i>>j)&1)==1){
                ok=0;
                break;
            }
        }
        if(ok){
            ans.push_back(i);
            now|=i;
        }else ans.push_back(0);
    }
    for(int y:ans) cout<<y<<" ";
    cout<<"\n"; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}