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

void solve(){
    int n, m, q; cin>>n>>m>>q;
    map<long long, bool>freqA, freqB;
    vector<long long>a(n), b(m);
    long long sumA=0, sumB=0;
    for(long long &x:a){
        cin>>x;
        sumA+=x;
    }
    for(long long &x:b){
        cin>>x;
        sumB+=x;
    }
    for(int i=0 ; i<n ; i++) freqA[sumA-a[i]]=1;
    for(int i=0 ; i<m ; i++) freqB[sumB-b[i]]=1;
    while(q--){
        long long x; cin>>x;
        bool ok=0;
        for(long long i=1 ; i*i<=abs(x) ; i++){
            if(x%i==0){
                long long one=i, two=x/i;
                if((freqA[one] && freqB[two]) || (freqA[two] && freqB[one])){
                    ok=1;
                    break;
                }
                one=-one; two=-two;
                if((freqA[one] && freqB[two]) || (freqA[two] && freqB[one])){
                    ok=1;
                    break;
                }
            }
        }
        cout<<(ok?"YES":"NO")<<"\n";
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}