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

void solve(){
    int n; cin>>n;
    vector<int>v, freq(n+1);
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        if(v.empty()) v.push_back(aux);
        else{
            if(aux!=v.back()) v.push_back(aux);
        }
    }
    int ans=1e9;
    for(int i=0 ; i<(int)v.size() ; i++) freq[v[i]]++;
    for(int i=1 ; i<=n ; i++){
        int aux=0;
        if(freq[i]>0){
            aux+=freq[i]-1;
            if(v[0]!=i) aux++;
            if(v.back()!=i) aux++;
            ans=min(ans, aux);
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