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
Vuela muy alto
*/

void solve(){
    long long n, m, l; cin>>n>>m>>l;
    using T=pair<long long, long long>;
    vector<T>h(n), p(m);
    for(T &x:h) cin>>x.first>>x.second;
    for(T &x:p) cin>>x.first>>x.second;
    sort(h.begin(), h.end(), [&](T a, T b){
        return a.first<b.first;
    });
    sort(p.begin(), p.end(), [&](T a, T b){
        return a.first>b.first;
    });
    priority_queue<long long>val;
    long long ans=0, jump=1;
    for(T x:h){
        while(!p.empty() && p.back().first<=x.first){
            val.push(p.back().second);
            p.pop_back();
        }
        while(!val.empty() && jump<=x.second-x.first+1){
            jump+=val.top();
            ans++;
            val.pop();
        }
        if(jump<=x.second-x.first+1){
            cout<<-1<<"\n";
            return;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}