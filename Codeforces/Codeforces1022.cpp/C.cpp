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
    map<int, vector<int>>freq;
    int aux;
    vector<int>v;
    set<int>xdd;
    for(int i=0 ; i<n ; i++){
        cin>>aux;
        xdd.insert(aux);
        if(v.empty()) v.push_back(aux);
        else if(v.back()!=aux) v.push_back(aux);
    }
    vector<int>mayor;
    for(int x:xdd) mayor.push_back(x);
    // sort(mayor.rbegin(), mayor.rend());
    n=(int)v.size();
    for(int i=0 ; i<n ; i++) freq[v[i]].push_back(i);
    vector<bool>use(n);
    int ans=0;
    for(int i=(int)mayor.size()-1 ; i>=0 ; i--){
        if(i==(int)mayor.size()-1){
            for(int posi:freq[mayor[i]]){
                use[posi]=1;
                ans++;
            }
        }else{
            for(int posi:freq[mayor[i]]){
                int l=posi-1;
                if(l==-1) l=0;
                else l=use[l];
                int r=posi+1;
                if(r==n) r=0;
                else r=use[r];
                use[posi]=max(r, l);
                if(use[posi]==0) ans++;
                use[posi]=1;
            }
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