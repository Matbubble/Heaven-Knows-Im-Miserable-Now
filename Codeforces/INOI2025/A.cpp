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

const int maxN=2e5+5;

set<int>freq[maxN+1];
int jump[maxN+1][20];
int arr[maxN+1];
int n;

void dfs(int curr){
    if(curr<0) return;
    auto it=freq[arr[curr]+1].lower_bound(curr);
    int next;
    if(it==freq[arr[curr]+1].end()) next=n;
    else next=*it;
    // dbg(next)
    jump[curr][0]=next;
    for(int i=1 ; i<20 ; i++) jump[curr][i]=jump[jump[curr][i-1]][i-1];
    dfs(curr-1);
}

int busca(int l, int r){
    auto it=freq[1].lower_bound(l);
    if(it==freq[1].end()) return 1;
    if(*it>r) return 1;
    int u=*it;
    for(int i=19 ; i>=0 ; i--){
        if(jump[u][i]>r) continue;
        // dbg(jump[u][i])
        u=jump[u][i];
    }
    return arr[u]+1;
}

void solve(){
    int q; cin>>n>>q;
    for(int i=0 ; i<n+5 ; i++){
        freq[i].clear();
        for(int j=0 ; j<20 ; j++) jump[i][j]=n;
    }
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
        freq[arr[i]].insert(i);
    }
    dfs(n-1);
    while(q--){
        int l, r; cin>>l>>r;
        l--; r--;
        cout<<busca(l, r)<<" ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}