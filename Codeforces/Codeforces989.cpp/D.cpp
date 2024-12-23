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
Te aprovechas
Grupo Limite
*/

void solve(){
    int n; cin>>n;
    vector<int>freq(3), v(n);
    vector<set<int>>vs(3);
    int posi=0;
    for(int &x:v){
        cin>>x;
        vs[x].insert(posi++);
        freq[x]++;
    }
    using T=pair<int, int>;
    queue<T>ans;
    for(int i=n-1 ; i>=0 ; i--){
        if(freq[2]>0){
            freq[2]--;
            if(v[i]==0){
                int a=*vs[1].begin(), b=*vs[2].begin();
                vs[1].erase(a); vs[2].erase(b);
                vs[1].insert(b);
                ans.push({a, i});
                ans.push({b, i});
                v[i]=2;
                v[b]=1;
                v[a]=0;
            }else if(v[i]==1){
                int a=*vs[2].begin();
                vs[2].erase(a);
                vs[1].insert(a);
                ans.push({a, i});
                v[i]=2;
                v[a]=1;
            }
        }else if(freq[1]>0){
            freq[1]--;
            if(v[i]==0){
                int a=*vs[1].begin();
                vs[1].erase(a);
                ans.push({a, i});
                v[i]=1;
                v[a]=0;
            }
        }
    }
    cout<<(int)ans.size()<<"\n";
    while(!ans.empty()){
        cout<<ans.front().first+1<<" "<<ans.front().second+1<<"\n";
        ans.pop();
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