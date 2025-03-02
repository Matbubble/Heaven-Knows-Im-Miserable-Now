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

struct fentree{
    int n;
    vector<int>ft;
    fentree(int n):n(n), ft(n+1){}
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
    int n;
    vector<int>v(n);
    int maxi=0;
    set<int>s;
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
        s.insert(v[i]);
    }
    map<int, int>mp;
    int posi=1;
    for(int x:s){
        mp[x]=posi;
        posi++;
    }
    fentree ft(s.size());
    int ans=0;
    for(int i=n-1 ; i>=0 ; i--){
        ft.add(mp[v[i]], 1);
        ans+=ft.querie(mp[v[i]-1]);
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}