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
    long long n, ans=0; cin>>n;
    vector<long long>v(n);
    for(long long &x:v) cin>>x;
    vector<map<long long, long long>>freq(11), froq(11);
    vector<long long>curr(11);
    for(long long x:v){
        long long mayor=0, menor=0;
        for(long long i=1 ; i<=10 ; i++){
            if(i<=x) menor+=curr[i];
            else mayor+=curr[i];
        }
        ans+=freq[x][menor-mayor];
        if(curr[x]>=1){
            ans+=froq[x][mayor-menor-1]+froq[x][mayor-menor+1];
        }
        for(long long i=1 ; i<=10 ; i++){
            for(long long j=1 ; j<=10 ; j++){

            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}