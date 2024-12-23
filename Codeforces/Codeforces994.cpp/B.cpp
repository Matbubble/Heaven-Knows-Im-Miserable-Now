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
Shhhhh!
*/

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    bool a=0, b=0;
    for(char ch:s){
        if(ch=='s') a=1;
        if(ch=='p') b=1;
    }
    if(a && b){
        int posi=-1;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='s') posi=i;
            if(posi==-1 && s[i]=='p'){
                cout<<"NO\n";
                return;
            }
            if(posi>=0){
                if(s[i]=='p'){
                    if(posi==0 || i==n-1) continue;
                    cout<<"NO\n";
                    return;
                }
            }
        }
        cout<<"YES\n";
    }else cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}