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
    vector<vector<int>>v(n, vector<int>(m));
    int posi=1;
    for(vector<int>&i:v){
        for(int &j:i) cin>>j;
        sort(i.begin(), i.end());
        i.push_back((n*m)+posi);
        posi++;
    }
    sort(v.begin(), v.end(), [&](vector<int>a, vector<int>b){
        return a[0]<b[0];
    });
    bool ok=1;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(j==0){
                ok&=v[i][j]==i;
            }else{
                ok&=(v[i][j]==v[i][j-1]+n);
            }
            if(!ok) break;
        }
        if(!ok) break;
    }
    if(ok){
        for(int i=0 ; i<n ; i++){
            cout<<v[i][m]-(n*m)<<" ";
        }
    }else cout<<-1;
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