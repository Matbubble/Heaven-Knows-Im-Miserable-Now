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
Mi primer dia sin ti
Los enanitos verdes
*/

const int maxN=2e5;
struct node{
    int pref, suf, sub, tot;
};
node tree[4*maxN];

node merge(node a, node b){
    node c;
    c.pref=max(a.pref, a.tot+b.pref);
    c.suf=max(b.suf, b.tot+a.suf);
    c.sub=max({a.sub, b.sub, a.suf+b.pref});
    c.tot=a.tot+b.tot;
    return c;
}

void build(int root, int l, int r){
    if(l==r){
        tree[root]={0, 0, 0, -1};
        return;
    }
    int mid=((l+r)>>1);
    build(2*root, l, mid);
    build(2*root+1, mid+1, r);
    tree[root]=merge(tree[2*root], tree[2*root+1]);
}

void update(int root, int l, int r, int posi, int val){
    if(l==r){
        int auxi=(val==1?1:0);
        tree[root]={auxi, auxi, auxi, val};
        return;
    }
    int mid=((l+r)>>1);
    if(posi<=mid) update(2*root, l, mid, posi, val);
    else update(2*root+1, mid+1, r, posi, val);
    tree[root]=merge(tree[2*root+1], tree[2*root]);
}

node querie(int root, int l, int r, int ql, int qr){
    if(l>=ql && r<=qr) return tree[root];
    if(l>qr || r<ql) return {0, 0, 0, 0};
    int mid=((l+r)>>1);
    return merge(querie(2*root, l, mid, ql, qr), querie(2*root+1, mid+1, r, ql, qr));
}

void solve(){
    int n; cin>>n;
    map<int, vector<int>>freq;
    build(1, 0, n-1);
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        freq[aux].push_back(i);
    }
    int ans=0, num=0;
    for(auto it:freq){
        vector<int>v=it.second;
        for(auto x:v) update(1, 0, n-1, x, 1);
        int curr=querie(1, 0, n-1, 0, n-1).sub;
        if(curr>ans){
            ans=curr;
            num=it.first;
        }
        for(auto x:v) update(1, 0, n-1, x, -1);
    }
    vector<int>v(n, -1);
    for(int x:freq[num]) v[x]=1;
    //kadane's algorithm
    int l=0, r=0, auxl=0, sum=0, actual=0;
    for(int i=0 ; i<n ; i++){
        sum+=v[i];
        if(sum<=0){
            if(v[i]<0) auxl=i+1;
            else auxl=i;
            sum=max(v[i], 0);
        }else if(sum>actual){
            actual=sum;
            r=i;
            l=auxl;
        }
    }
    cout<<num<<" "<<l+1<<" "<<r+1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}