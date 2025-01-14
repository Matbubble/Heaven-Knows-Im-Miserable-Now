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
Arrullo de estrellas
Zoe
*/

const int maxN=2e5+10;
int tree[4*maxN];
int dp[maxN];

void update(int root, int l, int r, int posi){
    if(l==r){
        tree[root]=dp[posi];
        return;
    }
    int mid=(l+r)>>1;
    if(posi<=mid) update(2*root, l, mid, posi);
    else update(2*root+1, mid+1, r, posi);
    tree[root]=max(tree[2*root], tree[2*root+1]);
}

int querie(int root, int l, int r, int ql, int qr){
    if(r<ql || l>qr) return 0;
    if(l>=ql && r<=qr) return tree[root];
    int mid=((l+r)>>1);
    return max(querie(2*root, l, mid, ql, qr), querie(2*root+1, mid+1, r, ql, qr));
}

void solve(){
    int n; cin>>n;
    vector<vector<int>>aux(n+2);
    for(int i=1 ; i<=n ; i++){
        int x, y; cin>>x>>y;
        x=max(0, i-x-1);
        y=min(n+1, i+y+1);
        for(int it:aux[i]) update(1, 1, n, it);
        dp[i]=querie(1, 1, n, 0, x)+1;
        aux[y].push_back(i);
    }
    int ans=0;
    for(int i=0 ; i<=n+2 ; i++) ans=max(ans, dp[i]);
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}