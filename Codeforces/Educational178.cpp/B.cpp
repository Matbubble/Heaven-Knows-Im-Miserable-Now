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

struct segtree{
    long long n;
    vector<long long>st;
    segtree(long long n):n(n), st(2*n){}
    long long querie(long long l, long long r){
        r++;
        long long res=0;
        for(l+=n, r+=n ; l<r ; l/=2, r/=2){
            if(l&1) res=max(res, st[l++]);
            if(r&1) res=max(res, st[--r]);
        }
        return res;
    }
    void update(long long posi, long long val){
        for(st[posi+=n]=val ; posi>1 ; posi/=2) st[posi/2]=max(st[posi], st[posi^1]);
    }
};

void solve(){
    long long n; cin>>n;
    vector<long long>v(n+1);
    segtree st(n+1);
    for(long long i=1 ; i<=n ; i++){
        cin>>v[i];
        st.update(i, v[i]);
    }
    long long res=0;
    for(long long i=n ; i>=1 ; i--){
        res+=v[i];
        cout<<max(res, res-v[i]+st.querie(1, i-1))<<" ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t; cin>>t;
    while(t--) solve();
    return 0;
}