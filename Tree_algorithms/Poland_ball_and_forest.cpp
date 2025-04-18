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

struct dsu{
    int n;
    vector<int>p;
    dsu(int n):n(n){
        for(int i=0 ; i<=n ; i++) p.push_back(i);
    }
    int findP(int x){
        return (p[x]==x?x:p[x]=findP(p[x]));
    }

    bool united(int a, int b){
        a=findP(a); b=findP(b);
        if(a==b) return true;
        p[a]=b;
        return false;
    }
};

void solve(){
    int n; cin>>n;
    dsu d(n);
    for(int i=1 ; i<=n ; i++){
        int x; cin>>x;
        d.united(i, x);
    }
    int ans=0;
    for(int i=1 ; i<=n ; i++) ans+=(d.p[i]==i);
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}