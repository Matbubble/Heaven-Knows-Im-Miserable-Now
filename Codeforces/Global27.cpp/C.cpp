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
La espera me agota
*/

void solve(){
    int n; cin>>n;
    if(n==5){
        cout<<5<<"\n";
        cout<<"2 1 3 4 5\n";
        return;
    }
    int maxi=1;
    while(1){
        if(2*maxi>n) break;
        maxi<<=1;
    }
    vector<int>ans(n);
    vector<bool>use(n+1);
    int last=-1;
    for(int i=n-1 ; i>=0 ; i--){
        if(i&1){
            if(maxi>0){
                last=i;
                ans[i]=maxi;
                use[maxi]=1;
                maxi>>=1;
            }
        }
    }
    int now=0;
    while(1){
        now<<=1;
        now++;
        if(now>=n) break;
    }
    for(int i=n-1 ; i>last+1 ; i--){
        if(!(i&1)){
            if(i==n-1){
                ans[i]=min(n, now);
                use[min(n, now)]=1;
                now>>=1;
            }else{
                if(now>n) now>>=1;
                ans[i]=now;
                use[now]=1;
                now>>=1;
            }
        }
    }
    use[5]=1;
    ans[last+1]=5;
    int posi=1;
    for(int i=0 ; i<last ; i++){
        while(use[posi]) posi++;
        ans[i]=posi;
        use[posi]=1;
    }
    int curr=0;
    for(int i=0 ; i<n ; i++){
        if(i&1) curr|=ans[i];
        else curr&=ans[i];
    }
    cout<<curr<<"\n";
    for(int i=0 ; i<n ; i++) cout<<ans[i]<<" \n"[i==n-1];

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}