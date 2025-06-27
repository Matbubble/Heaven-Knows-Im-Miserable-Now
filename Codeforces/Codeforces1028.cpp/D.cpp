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

struct point{
    int x, y, z;
};

void solve(){
    int n, q; cin>>n>>q;
    vector<int>v(n), b(n);
    for(int &x:v) cin>>x;
    vector<point>paso(q);
    for(int i=0 ; i<q ; i++){
        point temp; cin>>temp.x>>temp.y>>temp.z;
        temp.x--; temp.y--; temp.z--;
        paso[i]=temp;
        
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