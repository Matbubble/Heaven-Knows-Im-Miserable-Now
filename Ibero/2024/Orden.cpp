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
    vector<int>v(n);
    int maxi=0;
    for(int &x:v){
        cin>>x;
        maxi=max(maxi, x);
    }
    if(maxi<=2){
        map<int, set<int>>freq;
        for(int i=0 ; i<n ; i++) freq[v[i]].insert(i+1);
        int q; cin>>q;
        while(q--){
            int l, r; cin>>l>>r;
            auto it1=freq[1].lower_bound(l), it2=freq[2].lower_bound(l);
            if(it1==freq[1].end() || it2==freq[2].end()) cout<<r-l+1<<"\n";
            else{
                it1=freq[1].upper_bound(r);
                it1--;
                int extra=0;
                if(*it1>*it2) extra=(*it1)-(*it2);
                cout<<r-l+1-extra<<"\n";
            }
        }
    }else{
        int q; cin>>q;
        while(q--){
            int l, r; cin>>l>>r;
            vector<int>orden;
            for(int i=l-1 ; i<r ; i++) orden.push_back(v[i]);
            sort(orden.begin(), orden.end());
            map<int, int>a, b;
            int ans=0;
            for(int i=l-1 ; i<r ; i++){
                a[v[i]]++;
                b[orden[i-(l-1)]]++;
                if(a==b){
                    a.clear();
                    b.clear();
                    ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}