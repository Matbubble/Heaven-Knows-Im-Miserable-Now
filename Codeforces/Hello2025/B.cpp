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
My way
Frank Sinatra
*/

void solve(){
    long long n, k; cin>>n>>k;
    map<long long, long long>freq;
    for(long long i=0 ; i<n ; i++){
        long long aux; cin>>aux;
        freq[aux]++;
    }
    vector<long long>v;
    for(auto it:freq) v.push_back(it.second);
    sort(v.begin(), v.end());
    long long need=0;
    for(long long i=0 ; i<(long long)v.size()-1 ; i++){
        long long auxi=min(v[i], k);
        need+=auxi;
        v[i]-=auxi;
        k-=auxi;
    }
    long long ans=0;
    for(long long x:v) ans+=(x!=0);
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