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
SI no hago esto no me gusta Kate uuuu :(
*/

const long long maxN=2e5;
long long tree[4*(maxN+1)][46];
long long arr[maxN];
long long aux[46];

void build(long long root, long long l, long long r){
    if(l==r){
        tree[root][45]=arr[l];
    }else{
        long long mid=(l+r)/2;
        build(2*root, l, mid);
        build(2*root+1, mid+1, r);
        long long tl=45, tr=45;
        for(long long i=45 ; i>=0 ; i--){
            if(tree[2*root+1][tr]>tree[2*root][tl]){
                tree[root][i]=tree[2*root+1][tr];
                tr--;
            }else{
                tree[root][i]=tree[2*root][tl];
                tl--;
            }
        }
    }
}

void update(long long root, long long l, long long r, long long pos, long long val){
    if(l==r){
        tree[root][45]=val;
    }else{
        long long mid=(l+r)/2;
        if(pos<=mid){
            update(2*root, l, mid, pos, val);
        }else{
            update(2*root+1, mid+1, r, pos, val);
        }
        long long tl=45, tr=45;
        for(long long i=45 ; i>=0 ; i--){
            if(tree[2*root+1][tr]>tree[2*root][tl]){
                tree[root][i]=tree[2*root+1][tr];
                tr--;
            }else{
                tree[root][i]=tree[2*root][tl];
                tl--;
            }
        }
    }
}

void query(long long root, long long tl, long long tr, long long l, long long r){
    if(tl>r || tr<l) return;
    if(tl>=l && tr<=r){
        long long temp[46];
        long long izq=45, der=45;
        for(long long i=45 ; i>=0 ; i--){
            temp[i]=0;
            if(tree[root][izq]>aux[der]){
                temp[i]=tree[root][izq];
                izq--;
            }else{
                temp[i]=aux[der];
                der--;
            }
        }
        for(long long i=0 ; i<46 ; i++) aux[i]=temp[i];
        return;
    }
    long long mid=(tl+tr)/2;
    query(2*root, tl, mid, l, r);
    query(2*root+1, mid+1, tr, l, r);
}

void solve(){
    long long n, q; cin>>n>>q;
    for(long long i=0 ; i<n ; i++) cin>>arr[i];
    build(1, 0, n-1);
    
    while(q--){
        long long type, p, v; cin>>type>>p>>v;
        if(type==1){
            for(long long i=0 ; i<46 ; i++) aux[i]=0;
            query(1, 0, n-1, p, v);
            long long ans=0;
            bool ok=1;
            for(long long i=45 ; i>=2 ; i--){
                for(long long j=i-1 ; j>=1 ; j--){
                    for(long long k=j-1 ; k>=0 ; k--){
                        if(aux[k]+aux[j]>aux[i]){
                            ans=aux[k]+aux[j]+aux[i];
                            ok=0;
                            break;
                        }
                    }
                    if(!ok) break;
                }
                if(!ok) break;
            }
            cout<<ans<<"\n";
        }else{
            update(1, 0, n-1, p, v);
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