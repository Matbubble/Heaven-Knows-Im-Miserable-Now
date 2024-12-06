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
Castigadoooo
*/

void solve(){
    long long n, k; cin>>n>>k;
    vector<long long>dif(n);
    string s; cin>>s;
    long long a=0, b=0;
    for(int i=n-1 ; i>0 ; i--){
        if(s[i]=='1') a++;
        else b++;
        dif[i]=a-b;
    }
    sort(dif.begin(), dif.end(), greater<int>());
    long long ans=0, sum=0;
    for(int i=0 ; i<n ; i++){
        // dbg(dif[i])
        sum+=dif[i];
        ans++;
        if(sum>=k) break;
        // ans++;
    }
    // dbg(sum)
    cout<<((sum<k)?-1:ans+1)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}