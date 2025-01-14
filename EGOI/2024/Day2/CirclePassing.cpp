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
    long long n, m, q; cin>>n>>m>>q;
    vector<long long>friends;
    for(long long i=0 ; i<m ; i++){
        long long aux; cin>>aux;
        friends.push_back(aux);
        friends.push_back((aux+n)%(2*n));
    }
    sort(friends.begin(), friends.end());
    auto dist=[&](long long x, long long y){
        if(x>y) swap(x, y);
        return min((2*n+x)-y, y-x);
    };
    while(q--){
        long long x, y; cin>>x>>y;
        long long ans=1e9;
        long long l=0, r=0;
        auto it=lower_bound(friends.begin(), friends.end(), x);
        if(it==friends.end()) l=friends[0];
        else l=*it;
        it=upper_bound(friends.begin(), friends.end(), x);
        if(it==friends.begin()) r=friends.back();
        else{
            it--;
            r=*it;
        }
        cout<<min({dist(x, y), dist(x, l)+dist(y, (l+n)%(2*n))+1, dist(x, r)+dist(y, (r+n)%(2*n))+1})<<"\n";
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}