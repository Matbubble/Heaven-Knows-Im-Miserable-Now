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
De que maneraaa te olvido
*/

void solve(){
    int n, k; cin>>n>>k;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    sort(v.begin(), v.end());
    vector<pair<int, int>>vp;
    int l=0, aux=0;
    for(int i=0 ; i<=n ; i++){
        // dbg(i)
        if(v[i]==v[l] && i<n) aux++;
        else{
            vp.push_back({v[l], aux});
            aux=0;
            l=i;
            if(i==n) break;
            i--;
        }
    }
    int x=0, y=0, ans=0, temp=vp[0].second;
    while(x<=y && y<(int)vp.size()){
        // dbg(123)
        int curr=(y-x+1);
        // dbg(curr)
        if(curr>k){
            temp-=vp[x].second;
            x++;
        }else{
            ans=max(ans, temp);
            if(y<(int)vp.size()-1 && vp[y+1].first-vp[y].first>=2){
                y++;
                x=y;
                temp=vp[y].second;
            }else{
                y++;
                temp+=vp[y].second;
            }

        }
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