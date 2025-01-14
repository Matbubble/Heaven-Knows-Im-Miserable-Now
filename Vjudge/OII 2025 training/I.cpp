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
Shhhhh!
*/

const int maxN=1e5;

class tree{
    public:
        int n;
        vector<int>f;
        tree (int _n) : n(_n){
            f.resize(n, 0);
        }
        inline void add(int posi, int val){
            while(posi<=n){
                f[posi]+=val;
                posi+=posi&-posi;
            }
        }
        inline int querie(int posi){
            int res=0;
            while(posi>0){
                res+=f[posi];
                posi-=posi&-posi;
            }
            return res;
        }
};

void solve(){
    int n, auxn; cin>>n;
    auxn=n;
    vector<int>v(n);
    set<int>cast;
    map<int, int>mp;
    for(int &x:v){
        cin>>x;
        cast.insert(x);
    }
    int posi=1;
    for(int x:cast) mp[x]=posi++;
    n=posi;
    tree pref(n), suf(n);
    int ans=0;
    for(int x:v) suf.add(mp[x], 1);
    for(int i=0 ; i<auxn ; i++){
        int l=i-pref.querie(mp[v[i]]), r=n-i-1-suf.querie(mp[v[i]]);
        if(max(l, r)>2*min(l, r)) ans++;
        pref.add(mp[v[i]], 1);
        suf.add(mp[v[i]], -1);
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    solve();
    return 0;
}