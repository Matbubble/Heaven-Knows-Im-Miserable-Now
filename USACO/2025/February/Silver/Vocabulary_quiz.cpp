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

void solve(){
    int n; cin>>n;
    vector<int>cant(n+1), tam(n+1);
    set<int>s;
    for(int i=1 ; i<=n ; i++) s.insert(i);
    vector<int>v(n+1);
    for(int i=0 ; i<n ; i++){
        int x;
        cin>>x;
        tam[i+1]=tam[x]+1;
        cant[x]++;
        v[i+1]=x;
        s.erase(x);
    }
    int m=(int)s.size();
    vector<int>ans;
    while(m--){
        int aux; cin>>aux;
        if(cant[v[aux]]==1){
            cant[v[aux]]--;
            ans.push_back(tam[aux]-1);
        }else{
            cant[v[aux]]--;
            ans.push_back(tam[aux]);
        }
    }
    for(int i=0 ; i<(int)ans.size()-1 ; i++) cout<<ans[i]<<"\n";
    cout<<0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}