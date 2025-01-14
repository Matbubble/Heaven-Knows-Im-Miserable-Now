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
    long long n, k; cin>>n>>k;
    deque<long long>v(n);
    for(long long &x:v) cin>>x;
    // reverse(v.begin(), v.end());
    using T=long long;
    priority_queue<T, vector<T>, greater<T>>pq;
    map<long long, set<long long>>mp;
    map<long long, bool>freq;
    for(long long i=0 ; i<k ; i++){
        long long now=v[i];
        freq[v[i]]=1;
        // dbg(now)
        if(mp[now].empty()) pq.push(v[i]);
        mp[now].insert(i);
        // v.pop_front();
    }
    for(long long i=0 ; i<k ; i++) v.pop_front();
    while(!v.empty()){
        long long mini=1e18;
        long long now=pq.top();
        freq[now]=1;
        // dbg(now)
        long long n=mp[now].size();
        // dbg(n)
        while(n--){
            mini=min(mini, v.front());
            v.pop_front();
            if(v.empty()) break;
        }
        mini+=now;
        // dbg(mini)
        pq.pop();
        for(long long x:mp[now]) mp[mini].insert(x);
        if(freq[mini]==0) pq.push(mini);
    }
    // dbg(pq.size())
    cout<<pq.top()<<"\n";
    string ans;
    for(long long i=0 ; i<k ; i++) ans+='0';
    for(long long x:mp[pq.top()]) ans[x]='1';
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}