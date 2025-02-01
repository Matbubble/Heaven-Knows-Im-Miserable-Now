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

struct fenwick{
    int n;
    vector<int>ft;
    fenwick(int n):n(n), ft(n+1){};
    void bs(int look){
        int l=1, r=n, ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            int now=querie(mid);
            if(now>=look){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        add(ans, -1);
    }

    void add(int posi, int val){
        while(posi<=n){
            ft[posi]+=val;
            posi+=posi&-posi;
        }
    }
    int querie(int posi){
        int res=0;
        while(posi>0){
            res+=ft[posi];
            posi-=posi&-posi;
        }
        return res;
    }
};

void solve(){
    int n, q; cin>>n>>q;
    fenwick ft(n);
    vector<int>v(n);
    for(int &x:v){
        cin>>x;
        ft.add(x, 1);
    }
    while(q--){
        int aux; cin>>aux;
        if(aux<0) ft.bs(-aux);
        else ft.add(aux, 1);
    }
    int ans=0;
    for(int i=1 ; i<=n ; i++){
        if(ft.ft[i]>=1){
            ans=i;
            break;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}