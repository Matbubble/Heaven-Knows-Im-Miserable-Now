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
Y si me gusta alguien de brasil?
*/

void solve(){
    long long n; cin>>n;
    vector<pair<long long, long long>>v(n);
    for(long long i=0 ; i<n ; i++){
        cin>>v[i].first;
        v[i].first+=i+1;
        v[i].second=i;
    }
    sort(v.begin(), v.end());
    long long now=n, ans=n+1;
    map<long long, bool>freq;
    freq[n+1]=1;
    for(long long i=0 ; i<n ; i++){
        if(freq[v[i].first]){
            freq[v[i].first+v[i].second]=1;
            ans=max(ans, v[i].first+v[i].second);
        }
    }
    cout<<ans-1<<"\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}