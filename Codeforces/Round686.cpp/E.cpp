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
Gabriel, creo que tu idea no funciona.
Segun yo deberia dar pero xd, capaz hice mal el codigo
pero igual gracias a tu idea se me ocurrio esta otra, gracias uwu


El que lea esto es gay...
*/

void solve(){
    long long n, actual; cin>>n;
    actual=0;
    vector<set<long long> >g(n+1);
    for(int i=0 ; i<n ; i++){
        long long a, b; cin>>a>>b;
        g[a].insert(b);
        g[b].insert(a);
    }
    queue<long long>leafs;
    for(int i=1 ; i<=n ; i++){
        if((int)g[i].size()==1) leafs.push(i);
    }
    vector<long long>childs(n+1, 1);
    while(!leafs.empty()){
        long long now=leafs.front();
        leafs.pop();
        long long to=*g[now].begin();
        g[to].erase(now);
        childs[to]+=childs[now];
        childs[now]=0;
        if((int)g[to].size()==1){
            leafs.push(to);
        }
    }
    for(int i=1 ; i<=n ; i++){
        //caminos dentro del arbol
        actual+=childs[i]*(childs[i]-1)/2;
        //caminos que empizan en el arbol
        actual+=childs[i]*(n-childs[i]);
    }
    cout<<actual<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}