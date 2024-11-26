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
Enamorado de dp uuu
*/

void solve(){
    int n; cin>>n;
    vector<int> freq(101);
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        freq[aux]++;
    }
    for(int i=100 ; i>0 ; i--){
        if(freq[i]>freq[i-1]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}