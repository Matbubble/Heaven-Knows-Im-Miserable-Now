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
Visita
Enjambre
*/

void solve(){
    int n; cin>>n;
    vector<int>v(n);
    using T=pair<int, int>;
    vector<T>ans;
    for(int &x:v) cin>>x;
    // reverse(v.begin(), v.end());
    vector<int>aux;
    for(int i=n ; i>0 ; i--) aux.push_back(i);
    for(int i=n ; i>=1 ; i--){
        for(int j=i+1 ; j<=n ; j++){
            ans.push_back({j, i});
        }
    }
    sort(ans.begin(), ans.end());
    for(int i=0 ; i<n ; i++){
        int j;
        for(j=i ; j<n ; j++){
            if(v[i]==aux[j]) break;
        }
        // dbg(j)
        for(int k=j ; k>i ; k--){
            ans.push_back({aux[k], aux[k-1]});
            swap(aux[k], aux[k-1]);
        }
    }
    cout<<(int)ans.size()<<"\n";
    for(auto it:ans) cout<<it.first<<" "<<it.second<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}