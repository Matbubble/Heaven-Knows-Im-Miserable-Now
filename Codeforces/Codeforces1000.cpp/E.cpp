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
    vector<vector<long long>>g(n+1);
    for(int i=0 ; i<n-1 ; i++){
        long long a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    long long ans=0;
    auto dfs=[&](auto &&self, long long u, long long root)->vector<pair<long long, long long>>{
        map<long long, long long>freq;
        vector<vector<pair<long long, long long>>>nose;
        for(long long v:g[u]){
            if(v==root) continue;
            vector<pair<long long, long long>>aux=self(self, v, u);
            nose.push_back(aux);
            for(auto x:aux) freq[x.first]+=x.second;
        }
        for(auto it:nose){
            map<long long, long long>auxi;
            for(auto x:it){
                auxi[x.first]+=x.second;
            }
            for(auto x:it){
                for(auto uwu:auxi){
                    
                }
            }
        }
    };
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}