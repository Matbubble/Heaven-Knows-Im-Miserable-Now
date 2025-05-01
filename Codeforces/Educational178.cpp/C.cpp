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
    string s; cin>>s;
    int cont=0;
    bool ok=0;
    for(int i=n-1 ; i>=0 ; i--){
        if(s[i]=='B') cont++;
        else{
            if(i==n-1){
                if(s[0]=='A') ok=1;
            }else if(i==0){
                if(s[n-1]=='B') cont--;
                if(cont==0) ok=1;
            }else{
                if(cont==0) ok=1;
            }
        }
    }
    if(ok==1) cout<<"Alice\n";
    else cout<<"Bob\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}