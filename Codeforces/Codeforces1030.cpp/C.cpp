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
#include <cassert>

using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
MC lover
*/

void solve(){
    long long n, k; cin>>n>>k;
    long long ans=0;
    vector<long long>freq(61, 0);
    for(long long i=0 ; i<n ; i++){
        long long aux; cin>>aux;
        bitset<61>temp=aux;
        for(long long j=0 ; j<=60 ; j++){
            if(temp[j]==0) freq[j]++;
            else ans++;
        }
    }
    for(long long i=0; i<=60 ; i++){
        // dbg(freq[i])
        // dbg(i)
        while(freq[i]>0){
            // if(i==0){
            //     dbg(k)
            // }
            if((k-(1ll<<i))>=0){
                k-=(1ll<<i);
                // dbg(i)
                // dbg(k)
                // dbg(freq[i])
                ans++;
                freq[i]--;
            }else break;
            // dbg(k)
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