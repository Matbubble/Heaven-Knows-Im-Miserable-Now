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

const long long maxN=2e5;
long long arr[maxN+1];

void solve(){
    long long n, k; cin>>n>>k;
    for(long long i=0 ; i<n ; i++) cin>>arr[i];
    long long ans=arr[n-1]-arr[0]+1;
    vector<long long>v;
    for(long long i=0 ; i<n-1 ; i++){
        v.push_back(arr[i+1]-1-arr[i]);
    }
    sort(v.begin(), v.end(), greater<long long>());
    for(long long i=0 ; i<k-1; i++) ans-=v[i];
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}