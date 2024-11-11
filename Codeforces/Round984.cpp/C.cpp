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
Me voy a quitar de en medio
*/

void solve(){
    string s, aux="1100"; cin>>s;
    int q, ans=0; cin>>q;
    for(int i=0 ; i<(int)s.size()-3 ; i++){
        string temp=s.substr(i, 4);
        if(temp==aux) ans++;
    }
    while(q--){
        int a, b; cin>>a>>b;
        for(int i=max(0, a-4) ; i<=min((int)s.size()-4, a-1) ; i++){
            string temp=s.substr(i, 4);
            if(temp==aux) ans--;
        }
        s[a-1]=b+'0';
        for(int i=max(0, a-4) ; i<=min((int)s.size()-4, a-1) ; i++){
            string temp=s.substr(i, 4);
            if(temp==aux) ans++;
        }
        cout<<(ans?"YES\n":"NO\n");
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}