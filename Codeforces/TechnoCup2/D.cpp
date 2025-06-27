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

const long long maxN=1e5;
map<long long, long long>freq;

long long binpow(long long a, long long b){
    long long res=1;
    while(b>0){
        if(b&1){
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}

void solve(){
    long long n, k; cin>>n>>k;
    vector<long long>v(n), numeros;
    for(long long &x:v) cin>>x;
    long long ans=0;
    long long cont=1;
    while(1){
        long long curr=binpow(cont, k);
        if(curr>pow(maxN, 2)) break;
        cont++;
        dbg(curr)
        numeros.push_back(curr);
    }
    for(long long i=0 ; i<n ; i++){
        for(long long curr:numeros){
            if(curr%v[i]==0) ans+=freq[curr/v[i]];
        }
        freq[v[i]]++;
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