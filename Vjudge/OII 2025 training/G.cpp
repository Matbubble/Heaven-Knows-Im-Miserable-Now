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

const long long maxN=1e5;
long long tree[maxN+1];

void add(long long posi){
    while(posi<=maxN){
        tree[posi]++;
        posi+=posi&-posi;
    }
}
long long querie(long long posi){
    long long res=0;
    while(posi>0){
        res+=tree[posi];
        posi-=posi&-posi;
    }
    return res;
}

void solve(){
    long long n, original=0; cin>>n;
    vector<long long>v(n), dp(n);
    map<long long, vector<long long>>freq;
    for(long long i=0 ; i<n ; i++){
        cin>>v[i];
        v[i]++;
        freq[v[i]].push_back(i);
        add(v[i]);
        dp[i]=i+1-querie(v[i]);
        original+=i+1-querie(v[i]);
    }
    vector<long long>ans;
    long long extra=0;
    for(long long i=n+1 ; i>0 ; i--){
        for(long long it:freq[i]) extra+=dp[it];
        if(i==n+1) continue;
        ans.push_back(original-extra);
    }
    for(long long i=(long long)ans.size()-1 ; i>=0 ; i--) cout<<ans[i]<<"\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    solve();
    return 0;
}