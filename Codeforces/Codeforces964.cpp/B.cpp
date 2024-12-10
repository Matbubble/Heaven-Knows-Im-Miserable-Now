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
Tus besos se llegaron a recrear
*/

void solve(){
    vector<int>a(2), b(2);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    int x=0, y=0, ans=0;
    for(int i=0 ; i<2 ; i++){
        for(int j=0 ; j<2 ; j++){
            x=0, y=0;
            if(a[i]>b[j]) x++;
            else if(a[i]<b[j]) y++;
            if(a[i^1]>b[j^1]) x++;
            else if(a[i^1]<b[j^1]) y++;
            ans+=x>y;
        }
        
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