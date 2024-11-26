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
I love DP
*/

void solve(){
    string aux="vika";
    int n, m; cin>>n>>m;
    char lab[n][m];
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cin>>lab[i][j];
    }
    int now=0;
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(lab[j][i]==aux[now]){
                now++;
                break;
            }
        }
        // dbg(now)
        if(now>=4){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}