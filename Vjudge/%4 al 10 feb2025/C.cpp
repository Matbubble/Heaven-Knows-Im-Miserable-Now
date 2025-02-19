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
    string s; cin>>s;
    int a=0, b=0;
    for(char ch:s){
        if(ch=='4') a++;
        if(ch=='7') b++;
    }
    if(a==0 && b==0) cout<<-1<<"\n";
    else if(a>=b && a>0) cout<<4<<"\n";
    else cout<<7<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}