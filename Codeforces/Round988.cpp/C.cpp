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

void solve(){
    int n; cin>>n;
    if(n<5){
        cout<<-1<<"\n";
        return;
    }
    set<int>even, odd;
    for(int i=2 ; i<=n ; i+=2) even.insert(i);
    for(int i=1 ; i<=n ; i+=2) odd.insert(i);
    even.erase(4);
    odd.erase(5);
    while(!even.empty()){
        cout<<*even.begin()<<" ";
        even.erase(even.begin());
    }
    cout<<4<<" "<<5<<" ";
    while(!odd.empty()){
        cout<<*odd.begin()<<" ";
        odd.erase(odd.begin());
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}