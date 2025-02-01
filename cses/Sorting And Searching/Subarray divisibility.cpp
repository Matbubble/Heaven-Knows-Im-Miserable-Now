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

void solve(){
    long long n; cin>>n;
    vector<long long>pref;
    map<long long, long long>freq;
    pref.push_back(0);
    for(int i=0 ; i<n ; i++){
        long long aux; cin>>aux;
        pref.push_back((((pref.back()+aux)%n)+n)%n);
    }
    long long ans=0;
    freq[0]++;
    for(int i=1 ; i<=n ; i++){
        ans+=freq[pref[i]];
        // dbg(pref[i])
        freq[pref[i]]++;
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}