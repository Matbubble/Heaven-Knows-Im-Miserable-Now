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

const int maxN=1e6;
int jump[maxN+2][20];
int n, k;
string s;
map<char, vector<int>>freq;

void dfs(int posi){
    if(posi<0) return;
    int root=posi;
    for(int i=0 ; i<k ; i++){
        char uwu=i+'a';
        // dbg(uwu)
        auto it=upper_bound(freq[uwu].begin(), freq[uwu].end(), posi);
        if(it==freq[uwu].end()) root=n;
        else root=max(root, (*it));
    }
    // dbg(root)
    // dbg(posi)
    // if(posi==1) dbg(root)
    jump[posi][0]=root;
    for(int i=1 ; i<20 ; i++) jump[posi][i]=jump[jump[posi][i-1]][i-1];
    dfs(posi-1);
}

int querie(int posi){
    int ans=0;
    for(int i=19 ; i>=0 ; i--){
        if(jump[posi][i]>=n) continue;
        // dbg(jump[posi][i])
        // dbg(posi)
        // dbg(i)
        posi=jump[posi][i];
        // dbg(posi)
        ans+=(1<<i);
    }
    return ans+1;
}

void solve(){
    cin>>n>>k;
    cin>>s;
    for(int i=0 ; i<n ; i++) freq[s[i]].push_back(i);
    // dbg(n)
    for(int i=0 ; i<n+2 ; i++){
        for(int j=0 ; j<20 ; j++){
            jump[i][j]=n;
            // dbg(jump[i][j])
        }
    }
    dfs(n-1);
    int q; cin>>q;
    while(q--){
        string xd; cin>>xd;
        int i=-1;
        bool ok=0;
        for(int j=0 ; j<(int)xd.size() ; j++){
            auto it=upper_bound(freq[xd[j]].begin(), freq[xd[j]].end(), i);
            if(it==freq[xd[j]].end()) i=n;
            else i=(*it);
            if(i==n){
                ok=1;
                break;
            }
        }
        if(ok) cout<<0<<"\n";
        else cout<<querie(i)<<"\n";
        // dbg(i)
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}