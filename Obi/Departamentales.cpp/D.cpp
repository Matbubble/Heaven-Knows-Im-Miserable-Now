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
I love DP
*/

int num(char x){
    if(x=='P') return 2;
    if(x=='S') return 1;
    return 0;
}

void solve(){
    int a, b; cin>>a>>b;
    string s; cin>>s;
    int l=a-1, r=a, ans=0;
    while(1){
        if(l<0) break;
        int currA=num(s[l]), currB=num(s[r]);
        if(currA==currB || ((currA+1)%3==currB)) r++;
        else l--;
        if(r>=a+b) break;
    }
    ans=l+1;
    l=a-1, r=a;
    while(1){
        if(r>=a+b) break;
        int currA=num(s[l]), currB=num(s[r]);
        if(currA==currB || ((currB+1)%3==currA)) l--;
        else r++;
        if(l<0) break;
    }
    ans+=(a+b)-r;
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}