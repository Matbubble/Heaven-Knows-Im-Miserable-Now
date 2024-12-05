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

const int maxN=2e5;
int freq[maxN+1];

void solve(){
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) freq[i]=0;
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        freq[aux]++;
    }
    n-=2;
    for(int i=1 ; i<=n ; i++){
        if(n%i==0){
            if(freq[i]>0){
                freq[i]--;
                if(freq[n/i]>0){
                    cout<<i<<" "<<n/i<<"\n";
                    return;
                }
                freq[i]++;
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