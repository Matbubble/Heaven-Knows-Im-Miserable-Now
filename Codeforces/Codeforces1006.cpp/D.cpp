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
    vector<int>ft;
    int n;
    fentree(int n):n(n), ft(n+1){}
    int querie(int posi){
        int res=0;
        while(posi>0){
            res+=ft[posi];
            posi-=posi&-posi;
        }
        return res;
    }
    void add(int posi){
        while(posi<=n){
            ft[posi]++;
            posi+=posi&-posi;
        }
    }
};

void solve(){
    int n; cin>>n;
    int maxi=0, l=1, r=1;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    for(int i=0 ; i<n ; i++){
        fentree ft(2001);
        for(int j=i ; j>=0 ; j--){
            ft.add(v[j]);
            int gana=(i-j+1)-ft.querie(v[j]);
            int pierde=ft.querie(v[j]-1);
            if(gana-pierde<=maxi){
                maxi=gana-pierde;
                l=j; r=i;
            }
        }
    }
    cout<<l+1<<" "<<r+1<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}