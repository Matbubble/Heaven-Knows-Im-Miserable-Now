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
PLan IOIcancelado
*/

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    vector<char>vp;
    vector<int>posi;
    vp.push_back(s.back());
    posi.push_back(n-1);
    for(int i=n-2 ; i>=0 ; i--){
        if(s[i]>=vp.back()){
            vp.push_back(s[i]);
            posi.push_back(i);
        }
    }
    sort(vp.begin(), vp.end());
    sort(posi.begin(), posi.end());
    for(int i=0 ; i<(int)posi.size() ; i++){
        s[posi[i]]=vp[i];
    }
    bool ok=1;
    for(int i=0 ; i<n-1 ; i++){
        ok&=(s[i]<=s[i+1]);
    }
    if(!ok){
        cout<<-1<<"\n";
        return;
    }
    int cont=0;
    for(int i=0 ; i<(int)vp.size() ; i++){
        if(vp[i]==vp.back()) cont++;
    }
    cout<<(int)vp.size()-cont<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}