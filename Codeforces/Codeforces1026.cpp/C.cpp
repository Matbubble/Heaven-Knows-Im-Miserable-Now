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
    vector<int>extra;
    int curr=0;
    int n; cin>>n;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    vector<pair<int, int>>vp(n);
    for(pair<int, int> &it:vp) cin>>it.first>>it.second;
    for(int i=0 ; i<n ; i++){
        if(v[i]==1) curr++;
        if(curr>vp[i].second){
            cout<<-1<<"\n";
            return;
        }
        // if(curr==vp[i].second){
        //     if(v[i]==-1) v[i]=0;
        // }
        if(v[i]==-1) extra.push_back(i);
        while((int)extra.size()+curr>vp[i].second){
            v[extra.back()]=0;
            extra.pop_back();
        }
        if(curr<vp[i].first){
            int need=vp[i].first-curr;
            if(need>(int)extra.size()){
                cout<<-1<<"\n";
                return;
            }
            while(need--){
                curr++;
                v[extra.back()]=1;
                extra.pop_back();
            }
        }
    }
    for(int x:extra) v[x]=0;
    for(int i=0 ; i<n ; i++) cout<<v[i]<<" ";
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