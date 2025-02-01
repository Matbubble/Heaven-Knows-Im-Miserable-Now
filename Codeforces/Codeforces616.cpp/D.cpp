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
    string s; cin>>s;
    vector<vector<int>>freq((int)s.size()+1, vector<int>(28, 0));
    int posi=1;
    for(char ch:s){
        for(int i=0 ; i<28 ; i++){
            freq[posi][i]=freq[posi-1][i];
        }
        freq[posi][ch-'a']++;
        posi++;
    }
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        if(l==r || s[l-1]!=s[r-1]){
            cout<<"YES\n";
            continue;
        }
        cout.flush();
        int cont=0;
        for(int i=0 ; i<28 ; i++){
            if(freq[r][i]-freq[l-1][i]>0) cont++;
        }
        cout<<(cont>2?"YES\n":"NO\n");
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}