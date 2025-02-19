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
One more hour
Tame Impala
*/



void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int l=32-__builtin_clz(n);
    vector<vector<int>>bl(n+1, vector<int>(l+1));
    set<int>a, e, I, o, u;
    for(int i=0 ; i<n ; i++){
        if(s[i]=='a') a.insert(i);
        if(s[i]=='e') e.insert(i);
        if(s[i]=='i') I.insert(i);
        if(s[i]=='o') o.insert(i);
        if(s[i]=='u') u.insert(i);
    }
    for(int i=0 ; i<=l ; i++) bl[n][i]=n;
    for(int i=n-1 ; i>=0 ; i--){
        int maxi=i;
        maxi=max(maxi, (a.upper_bound(i)==a.end()?n:(*a.upper_bound(i))));
        maxi=max(maxi, (e.upper_bound(i)==e.end()?n:(*e.upper_bound(i))));
        maxi=max(maxi, (I.upper_bound(i)==I.end()?n:(*I.upper_bound(i))));
        maxi=max(maxi, (o.upper_bound(i)==o.end()?n:(*o.upper_bound(i))));
        maxi=max(maxi, (u.upper_bound(i)==u.end()?n:(*u.upper_bound(i))));
        bl[i][0]=maxi;
        for(int j=1 ; j<=l ; j++){
            bl[i][j]=bl[bl[i][j-1]][j-1];
        }
    }
    // for(int i=0 ; i<n ; i++){
    //     for(int j=0 ; j<l ; j++) cout<<bl[i][j]<<" ";
    //     cout<<"\n";
    // }
    int q; cin>>q;
    while(q--){
        int L, r; cin>>L>>r;
        L--; r--;
        int auxi=L;
        L=max(L, (a.lower_bound(auxi)==a.end()?n:(*a.lower_bound(auxi))));
        L=max(L, (e.lower_bound(auxi)==e.end()?n:(*e.lower_bound(auxi))));
        L=max(L, (I.lower_bound(auxi)==I.end()?n:(*I.lower_bound(auxi))));
        L=max(L, (o.lower_bound(auxi)==o.end()?n:(*o.lower_bound(auxi))));
        L=max(L, (u.lower_bound(auxi)==u.end()?n:(*u.lower_bound(auxi))));
        if(L>r){
            cout<<1<<"\n"; continue;
        }
        // L=auxi;
        int ans=1;
        for(int i=l ; i>=0 ; i--){
            if(bl[L][i]<=r){
                ans+=(1<<i);
                L=bl[L][i];
                // dbg(L)
            }
        }
        cout<<ans+1<<"\n";
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}