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
    int a, b, c; cin>>a>>b>>c;
    int xd=(a+b+c);
    if(xd%3!=0){
        cout<<"No\n";
        return;
    }
    xd/=3;
    if(a>xd || b>xd){
        cout<<"No\n";
        return;
    }
    int dif=a-xd+b-xd;
    if(c-xd>=dif){
        cout<<"Yes\n";
    }else cout<<"No\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}