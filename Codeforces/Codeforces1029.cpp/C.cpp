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
#include <cassert>

using namespace std;
#define dbg(x) cerr<<#x<<": "<<x<<"\n";

/*  
MC lover
*/

void solve(){
    int n; cin>>n;
    map<int, set<int>>freq;
    vector<int>v(n);
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
        freq[v[i]].insert(i);
    }
    int fin=0, start=0;
    int ans=1;
    while(1){
        int posi=-1;
        for(int i=start ; i<=fin ; i++){
            auto it=freq[v[i]].upper_bound(fin);
            if(it!=freq[v[i]].end()) posi=max(posi, (*it));
            else{
                posi=-1;
                break;
            }
        }
        if(posi==-1){
            cout<<ans<<"\n";
            return;
        }else{
            start=fin+1;
            fin=posi;
            ans++;
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