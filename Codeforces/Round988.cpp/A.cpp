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
const int maxN=20;
int freq[maxN+1];

void solve(){
    memset(freq, 0, sizeof(freq));
    int n; cin>>n;
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        freq[aux]++;
    }
    int ans=0;
    for(int i=0 ; i<=20 ; i++) ans+=freq[i]/2;
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