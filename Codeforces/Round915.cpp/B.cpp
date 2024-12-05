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
Diametro uwu
*/

const int maxN=2e5;

void solve(){
    int n; cin>>n;
    vector<int>tree(n+1);
    for(int i=0 ; i<n-1 ; i++){
        int a, b; cin>>a>>b;
        tree[a]++;
        tree[b]++;
    }
    int cont=0;
    for(int i=0 ; i<=n ; i++){
        if(tree[i]==1) cont++;
    }
    cout<<(cont+1)/2<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}