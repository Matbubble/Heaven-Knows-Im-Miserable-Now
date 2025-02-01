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
    auto ask=[&](int m, vector<int>q){
        cout<<"? "<<m<<" ";
        for(int x:q) cout<<x<<" ";
        cout<<"\n";
        cout.flush();
        int inv; cin>>inv;
        return inv;
    };
    vector<int>ans(n), pref;
    pref.push_back(0);
    for(int i=1 ; i<n ; i++){
        vector<int>aux;
        for(int j=0 ; j<(int)pref.size() ; j++){
            if(j==0) aux.push_back(pref[j]);
            else{
                aux.push_back(pref[j]);
                aux.push_back(pref[0]);
            }
            aux.push_back(i);
        }
        int q=ask((int)aux.size(), aux);
        q-=i-1;
        // if(q==i) q=0;
        aux.clear();
        if(q==i){
            aux.push_back(i);
            q=1e9;
        }
        for(int j=0 ; j<(int)pref.size() ; j++){
            aux.push_back(pref[j]);
            if(j==q) aux.push_back(i);
        }
        swap(pref, aux);
    }
    int curr=0;
    for(int x:pref) ans[x]=curr++;
    cout<<"! ";
    for(int x:ans) cout<<x<<" ";
    // cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}