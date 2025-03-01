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

//Calcula la respuesta MODULO 1e9+7


const int maxN=1e5;
int segtree[4*maxN];
vector<int>v;

void build(int l, int r, int root){
    if(l==r){
        segtree[root]=v[l];
        return;
    }
    int mitad=(l+r)/2;
    build(l, mitad, 2*root);
    build(mitad+1, r, 2*root+1);
    segtree[root]=min(segtree[2*root], segtree[2*root+1]);
}

int querie(int l, int r, int root, int ql, int qr){
    if(l>qr || r<ql) return 1e9;
    if(l>=ql && r<=qr) return segtree[root];
    int mitad=(l+r)/2;
    int a=querie(l, mitad, 2*root, ql, qr);
    int b=querie(mitad+1, r, 2*root+1, ql, qr);
    return min(a, b);
}

void update(int l, int r, int root, int posi, int val){
    if(l==r){
        segtree[root]=val;
        v[l]=val;
        return;
    }
    int mitad=(l+r)/2;
    //[l, mitad] -- [mitad+1, r]
    if(mitad>=posi) update(l, mitad, 2*root, posi, val);
    else update(mitad+1, r, 2*root+1, posi, val);
    segtree[root]=min(segtree[2*root], segtree[2*root+1]);
}

void solve(){
    int n; cin>>n;
    v.resize(n);
    for(int i=0 ; i<n ; i++) cin>>v[i];
    build(0, n-1, 1);
    update(0, n-1, 1, 3, 5);
    cout<<querie(0, n-1, 1, 1, 5);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}