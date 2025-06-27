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
    long long n; cin>>n;
    vector<pair<long long, long long>>xd, xd1, total;
    pair<long long, long long>uno, dos, tres={1e9, 1e9}, cuatro={1e9, 1e9};
    for(long long i=0 ; i<n ; i++){
        long long a, b; cin>>a>>b;
        if(a>uno.second) uno={a, b};
        else if(a==uno.second){
            if(b>=uno.first) uno={a, b};
        }
        if(b>dos.second) dos={a, b};
        else if(b==dos.second){
            if(a>=dos.first) dos={a, b};
        }
        if(a<tres.second) tres={a, b};
        else if(a==tres.second){
            if(b<=tres.first) tres={a, b};
        }
        if(b<cuatro.second) cuatro={a, b};
        else if(b==cuatro.second){
            if(a<=cuatro.first) cuatro={a, b};
        }
        total.push_back({a, b});
    }
    if(n==1){
        cout<<1<<"\n";
        return;
    }
    long long ans=1e18;
    {
        long long maxiX=0, maxiY=0;
        long long miniX=1e9, miniY=1e9;
        for(long long i=0 ; i<n ; i++){
            if(total[i]==uno) continue;
            maxiX=max(maxiX, total[i].first);
            maxiY=max(maxiY, total[i].second);
            miniX=min(miniX, total[i].first);
            miniY=min(miniY, total[i].second);
        }
        long long up=maxiX-miniX+1;
        long long down=maxiY-miniY+1;
        // dbg(up)
        // dbg(down)
        if(up*down==n-1) ans=min(ans, min(up, down)*(max(up, down)+1));
        else ans=min(ans, up*down);
        // dbg(ans)
    }
    {
        long long maxiX=0, maxiY=0;
        long long miniX=1e9, miniY=1e9;
        for(long long i=0 ; i<n ; i++){
            if(total[i]==dos) continue;
            maxiX=max(maxiX, total[i].first);
            maxiY=max(maxiY, total[i].second);
            miniX=min(miniX, total[i].first);
            miniY=min(miniY, total[i].second);
        }
        long long up=maxiX-miniX+1;
        long long down=maxiY-miniY+1;
        
        if(up*down==n-1) ans=min(ans, min(up, down)*(max(up, down)+1));
        else ans=min(ans, up*down);
        // dbg(ans)
    }
    {
        long long maxiX=0, maxiY=0;
        long long miniX=1e9, miniY=1e9;
        for(long long i=0 ; i<n ; i++){
            if(total[i]==cuatro) continue;
            maxiX=max(maxiX, total[i].first);
            maxiY=max(maxiY, total[i].second);
            miniX=min(miniX, total[i].first);
            miniY=min(miniY, total[i].second);
        }
        long long up=maxiX-miniX+1;
        long long down=maxiY-miniY+1;
        if(up*down==n-1) ans=min(ans, min(up, down)*(max(up, down)+1));
        else ans=min(ans, up*down);
        // dbg(ans)
    }
    {
        long long maxiX=0, maxiY=0;
        long long miniX=1e9, miniY=1e9;
        for(long long i=0 ; i<n ; i++){
            if(total[i]==tres) continue;
            maxiX=max(maxiX, total[i].first);
            maxiY=max(maxiY, total[i].second);
            miniX=min(miniX, total[i].first);
            miniY=min(miniY, total[i].second);
        }
        long long up=maxiX-miniX+1;
        long long down=maxiY-miniY+1;
        if(up*down==n-1) ans=min(ans, min(up, down)*(max(up, down)+1));
        else ans=min(ans, up*down);
        // dbg(ans)
    }
    // dbg(tres.first)
    // dbg(tres.second)
    // dbg(cuatro.first)
    // dbg(cuatro.second)
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}