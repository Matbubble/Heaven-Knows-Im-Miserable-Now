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

const int maxN=100;
char lab[maxN+1][maxN+1];

void solve(){
    int n, m; cin>>n>>m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) cin>>lab[i][j];
    }
    int ans=0;
    for(int i=0 ; i<n-1 ; i++){
        if(lab[i][m-1]!='D') ans++;
    }
    for(int i=0 ; i<m-1 ; i++){
        if(lab[n-1][i]!='R') ans++;
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