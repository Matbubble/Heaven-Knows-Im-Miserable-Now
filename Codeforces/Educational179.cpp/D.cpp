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
    int n, m; cin>>n>>m;
    deque<int>v(m);
    for(int &x:v) cin>>x;
    sort(v.begin(), v.end());
    vector<vector<int>>ans(n, vector<int>(6));
    for(int i=0 ; i<n ; i++){
        int curr=(i%2==0?1:0);
        for(int j=0 ; j<6 ; j++){
            if(curr==1) ans[i][j]=v.back();
            else ans[i][j]=v.front();
            curr^=1;
        }
        if(i%2==1){
            v.pop_back();
            v.pop_front();
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<6 ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}