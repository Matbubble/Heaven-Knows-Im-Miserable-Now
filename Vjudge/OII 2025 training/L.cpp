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

priority_queue<long long>ll;
priority_queue<long long, vector<long long>, greater<long long>>rr;
long long  l, r;

void add(long long x){
    long long median=(ll.empty()?1e18:ll.top());
    if(x<=median){
        ll.push(x); l+=x;
    }else{
        rr.push(x); r+=x;
    }
    if((long long)rr.size()+1<(long long)ll.size()){
        long long next=ll.top();
        ll.pop();
        rr.push(next);
        l-=next;
        r+=next;
    }else if((long long)rr.size()>(long long)ll.size()){
        long long next=rr.top();
        rr.pop();
        ll.push(next);
        r-=next;
        l+=next;
    }
}
const long long maxN=1e5;
long long pref[maxN+1];

void solve(){
    long long k, n, extra=0; cin>>k>>n;
    using T=pair<long long, long long>;
    vector<T>v;
    for(long long i=0 ; i<n ; i++){
        char p, q; long long s, t;
        cin>>p>>s>>q>>t;
        if(p==q) extra+=abs(s-t);
        else v.push_back({s, t});
    }
    n=(long long)v.size();
    sort(v.begin(), v.end(), [&](T a, T b){
        return a.first+a.second<b.second+b.first;
    });
    for(long long i=0 ; i<n ; i++){
        add(v[i].first);
        add(v[i].second);
        pref[i]=r-l;
    }
    long long ans=pref[n-1];
    if(k==2){
        while(!ll.empty()) ll.pop();
        while(!rr.empty()) rr.pop();
        l=r=0;
        for(long long i=n-1 ; i>=0 ; i--){
            add(v[i].first);
            add(v[i].second);
            ans=min(ans, r-l+pref[i-1]);
        }
    }
    cout<<ans+extra+n<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}