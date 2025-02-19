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

struct fentree{
    int n;
    vector<int>ft;
    fentree(int n):n(n), ft(n+1){}
    int querie(int posi){
        int res=0;
        while(posi>0){
            res+=ft[posi];
            posi-=posi&-posi;
        }
        return res;
    }
    int bs(int k){
        int l=1, r=n;
        int ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(querie(mid)>=k){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
    void update(int posi, int val){
        while(posi<=n){
            ft[posi]+=val;
            posi+=posi&-posi;
        }
    }
};

void solve(){
    int n; cin>>n;
    vector<int>v(n+1);
    fentree ft(n);
    for(int i=1 ; i<=n ; i++){
        cin>>v[i];
        ft.update(i, 1);
    }
    for(int i=0 ; i<n ; i++){
        int aux; cin>>aux;
        int posi=ft.bs(aux);
        ft.update(posi, -1);
        cout<<v[posi]<<" ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}