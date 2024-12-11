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
Que ganas de tomar una cervreza
*/

void solve(){
    int l=1, r=1000;
    int ans=1;
    while(l<=r){
        int mid=(l+r)/2;
        cout<<"? "<<mid<<" "<<mid<<"\n";
        cout.flush();
        int aux; cin>>aux;
        if(aux>mid*mid){
            ans=mid;
            r=mid-1;
        }
        else{
            // ans=mid;
            l=mid+1;
        }
    }
    cout<<"! "<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}