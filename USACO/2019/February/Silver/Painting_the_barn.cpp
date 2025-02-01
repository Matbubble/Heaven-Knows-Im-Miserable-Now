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
    int n, k; cin>>n>>k;
    using T=pair<int, int>;
    vector<vector<T>>lab(1001, vector<T>(1001));
    for(int i=0 ; i<n ; i++){
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        for(int j=x1 ; j<x2 ; j++){
            lab[j][y1].first++;
            lab[j][y2].second++;
        }
    }
    int ans=0;
    for(int i=0 ; i<=1000 ; i++){
        int curr=0;
        for(int j=0 ; j<=1000 ; j++){
            curr+=lab[i][j].first;
            curr+=-lab[i][j].second;
            ans+=(curr==k);
        }
    }
    cout<<ans<<"\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    solve();
    return 0;
}