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
Casi me fracturo una costilla
Pero no me importa
Soy el mejor conductor uwuwuwuwu
*/

void solve(){
    int n; cin>>n;
    map<int, int>mp;
    for(int i=0 ; i<n ; i++){
        int x; cin>>x;
        mp[x]++;
    }
    vector<int>pref;
    for(auto it:mp) pref.push_back(it.second);
    int cc=0;
    for(int i=(int)pref.size()-1 ; i>=0 ; i--){
        cc+=pref[i];
        if(cc&1){
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