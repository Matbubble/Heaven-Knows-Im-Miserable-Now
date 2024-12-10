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
Noche de brujas
*/

void solve(){
    string a, b; cin>>a>>b;
    // if((int)b.size()>(int)a.size()){
    //     cout<<"NO\n";
    //     return;
    // }
    int now=0;
    for(int i=0 ; i<(int)b.size() ; i++){
        // dbg(i)
        bool ok=0;
        while(now<(int)a.size()){
            if(a[now]==b[i]){
                now++;
                ok=1;
                break;
            }
            if(a[now]=='?'){
                a[now]=b[i];
                now++;
                ok=1;
                break;
            }
            now++;
        }
        if(!ok){
            cout<<"NO\n";
            return;
        }
    }
    for(int i=0 ; i<(int)a.size() ; i++) a[i]=(a[i]=='?'?'a':a[i]);
    cout<<"YES\n"<<a<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}