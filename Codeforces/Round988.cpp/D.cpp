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
    vector<pair<long long, long long> >a, b;
    for(long long i=0 ; i<n ; i++){
        long long x, y; cin>>x>>y;
        a.push_back(make_pair(x, y));
    }
    for(long long i=0 ; i<m ; i++){
        long long x, y; cin>>x>>y;
        b.push_back(make_pair(x, y));
    }
    long long jump=1, curr=0, ans=0;
    /* 01000010 */ map<long long, long long> freq;
    for(long long i=0 ; i<n ; i++){
        for(long long j=curr ; j<m ; j++){
            if(b[j].first>=a[i].first){
                curr=j;
                break;
            }
            freq[b[j].second]++;
        }
        long long need=a[i].second-a[i].first+2;
        dbg(need)
        while(jump<need){
            auto it=prev(freq.end());
            while(1){
                if(it->second==0) it--;
                if(it==prev(freq.begin())) break;
            }
            long long x=it->first, y=it->second;
            // dbg(it->first)
            jump+=x;
            // dbg(freq[x])
            // dbg(x)
            ans++;
            freq[x]--;
            
        }
        if(jump<need){
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