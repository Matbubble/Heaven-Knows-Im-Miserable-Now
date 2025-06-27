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

set<int>S;
map<int, int>xd;

void solve(){
    string s; cin>>s;
    int x=0;
    for(char ch:s){
        x*=10;
        x+=(ch-'0');
    }
    // dbg(x)
    if(S.find(x)!=S.end()) cout<<0<<" "<<xd[x]<<"\n";
    else cout<<-1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0 ; i<=1000 ; i++){
        S.insert(i*i);
        xd[i*i]=i;
    }
    int t; cin>>t;
    while(t--) solve();
    return 0;
}