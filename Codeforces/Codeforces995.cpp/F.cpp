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
Navidad sin ti
Bukis
*/

void solve(){
    long long n, m, q; cin>>n>>m>>q;
    long long ans=0;
    long long l=m, r=m;
    long long izq=0, der=n+1;
    vector<long long>qq(q);
    for(long long &x:qq) cin>>x;
    if(qq[0]==m){
        izq=1, der=n;
        for(long long i=0 ; i<q ; i++){
            if(i>0){
                long long aux=qq[i];
                if(aux<=izq) der--;
                else if(aux>=der) izq++;
                else{
                    izq++;
                    der--;
                }
                der=max(1ll, der);
                izq=min(der-1, izq);
            }
            cout<<izq+n-der+1<<" ";
        }
        cout<<"\n";
    }else{
        bool ok=0;
        for(long long i=0 ; i<q ; i++){
            long long aux=qq[i];
            // dbg(i)
            if(aux>=l && aux<=r){
                // l--; r++;
                if(!ok){
                    ok=1;
                }
            }else if(aux>r) r++;
            else l--;
            if(ok){
                izq=min(l-1, izq);
                der=max(r+1, der);
                if(aux<=izq) der--;
                else if(aux>=der) izq++;
                else{
                    izq++;
                    der--;
                }
                izq=min(l-1, izq);
                der=max(r+1, der);
            }
            l=max(1ll, l);
            r=min(r, n);
            cout<<r-l+izq+n-der+2<<" ";
        }
        cout<<"\n";
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}