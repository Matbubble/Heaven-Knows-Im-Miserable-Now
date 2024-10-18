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
Me regalaron un HOTWHEELS de la F1
*/

void solve(){
    int ans=1;
    string s; cin>>s;
    bool one=0;
    for(int i=0 ; i<int(s.size())-1 ; i++){
        if(s[i]!=s[i+1]) ans++;
        if(s[i]=='0' && s[i+1]=='1') one=1;
    }
    cout<<(one?ans-1:ans)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}