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
    long long n, k; cin>>n>>k;
    vector<vector<long long>>lab(4*n+5, vector<long long>(4*n+5));
    for(long long i=0 ; i<n ; i++){
        for(long long j=0 ; j<n ; j++) cin>>lab[i+j][n-i+j-1];
    }
    vector<vector<long long>>pref(4*n+5, vector<long long>(4*n+5));
    n=(4*n)+2;
    for(long long i=0 ; i<n ; i++){
        for(long long j=0 ; j<n ; j++){
            pref[i+1][j+1]=pref[i][j+1]+pref[i+1][j]-pref[i][j]+lab[i][j];
        }
    }
    k=(2*k)+1;
    long long ans=0;
    for(long long i=k ; i<n ; i++){
        for(long long j=k ; j<n ; j++){
            ans=max(ans, pref[i][j]-pref[i-k][j]-pref[i][j-k]+pref[i-k][j-k]);
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    solve();
    return 0;
}