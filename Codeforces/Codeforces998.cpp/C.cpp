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
    vector<int>v(n), freq(n+1);
    vector<bool>vis(n+1);
    for(int &x:v){
        cin>>x;
        freq[x]++;
    }
    using T=pair<int, int>;
    vector<T>temp;
    int ans=0, extra=0;
    for(int x:v){
        if(vis[x]) continue;
        int a=freq[x], b=k-x;
        if(b<=0 || b>n) b=0;
        else{
            // dbg(b)
            b=freq[b];
            vis[k-x]=1;
            if(x==k-x){
                a=(freq[x]+1)/2;
                b=freq[k-x]/2;
            }
        }
        vis[x]=1;
        ans+=min(a, b);
        // dbg(a);
        // dbg(b)
        // extra+=max(a, b)-min(a, b);
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