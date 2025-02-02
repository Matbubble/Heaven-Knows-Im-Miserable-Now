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
    int n; cin>>n;
    vector<int>ans;
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        if(ans.empty()) ans.push_back(aux);
        else{
            auto it=lower_bound(ans.begin(), ans.end(), aux);
            if(it==ans.end()) ans.push_back(aux);
            else ans[it-ans.begin()]=aux;
        }
    }
    cout<<(int)ans.size()<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}