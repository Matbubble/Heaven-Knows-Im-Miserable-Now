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
    int n; cin>>n;
    vector<int>freq(n+1);
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        freq[aux]++;
    }
    int ans=0, extra=0, need=0;
    for(int i=0 ; i<=n ; i++){
        int noneed=freq[i];
        int auxi=need;
        if(need<=noneed) need=0;
        else{
            need-=noneed;
        }
        // dbg(need)
        cout<<noneed+need<<"\n";
        swap(auxi, need);
        if(freq[i]==0) need++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}