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
    vector<int>a(n), b(m);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    sort(b.begin(), b.end());
    int curr=0;
    vector<int>ans;
    ans.push_back(min(a[0], b[0]-a[0]));
    for(int i=1 ; i<n ; i++){
        while(1){
            int mini=min(a[i], b[curr]-a[i]);
            int maxi=max(a[i], b[curr]-a[i]);
            if(mini>=ans.back()){
                ans.push_back(mini);
                break;
            }else if(maxi>=ans.back()){
                ans.push_back(maxi);
                break;
            }else{
                curr++;
            }
            if(curr==m){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}