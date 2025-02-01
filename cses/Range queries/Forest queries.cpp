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
    int n, m, q; cin>>n>>q;
    m=n;
    vector<vector<char>>lab(n+1, vector<char>(m+1));
    vector<vector<int>>pref(n+1, vector<int>(m+1, 0));
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            char curr; cin>>curr;
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+(curr=='*'?1:0);
        }
    }
    while(q--){
        int y1, x1, y2, x2; cin>>y1>>x1>>y2>>x2;
        cout<<pref[y2][x2]-pref[y1-1][x2]-pref[y2][x1-1]+pref[y1-1][x1-1]<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}