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
    fenwick(int n):n(n), ft(n+1){}
    int querie(int posi){
        int res=0;
        while(posi>0){
            res+=ft[posi];
            posi-=posi&-posi;
        }
        return res;
    }
    void add(int posi, int val){
        while(posi<=n){
            ft[posi]+=val;
            posi+=posi&-posi;
        }
    }
};  

void solve(){
    int n; cin>>n;
    deque<int>dq(n), ans;
    set<int>cast;
    map<int, int>mp;
    for(int &x:dq) cin>>x;
    deque<int>aux, auxi;
    int mini=1e9;
    for(int i=n-1 ; i>=0 ; i--){
        int x=dq[i];
        if(x>mini) aux.push_back(x+1);
        else auxi.push_front(x);
        mini=min(mini, x);
    }
    dq=auxi;
    mini=*min_element(aux.begin(), aux.end());
    auxi.clear();
    for(int x:dq){
        if(x>mini) aux.push_back(x+1);
        else auxi.push_back(x);
    }
    dq=auxi;
    for(int x:dq) aux.push_back(x);
    sort(aux.begin(), aux.end());
    for(int x:aux) cout<<x<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}