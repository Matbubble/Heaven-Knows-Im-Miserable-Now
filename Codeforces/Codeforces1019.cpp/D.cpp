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
    int now=n;
    map<int, deque<int>>freq;
    int start=0;
    vector<int>v(n);
    for(int i=0 ; i<n ; i++){
        int val; cin>>val;
        v[i]=val;
        if(val==-1) start=i;
    }
    vector<bool>vis(n);
    vis[start]=1;
    queue<int>bfs;
    bfs.push(start);
    while(!bfs.empty()){
        int u=bfs.front();
        vis[u]=1;
        if(v[u]%2==1) freq[v[u]].push_front(u);
        else freq[v[u]].push_back(u);
        bfs.pop();
        if(u-1>=0){
            if(vis[u-1]==0) bfs.push(u-1);
        }
        if(u+1<n){
            if(vis[u+1]==0) bfs.push(u+1);
        }

    }
    vector<int>ans(n);
    for(int i=1 ; i<=20 ; i+=2){
        for(int it:freq[i]){
            ans[it]=now--;
        }
    }
    // dbg(freq[-1][0])
    ans[freq[-1][0]]=now--;
    for(int i=20 ; i>=0 ; i-=2){
        for(int it:freq[i]) ans[it]=now--;
    }
    for(int i=0 ; i<n ; i++) cout<<ans[i]<<" ";
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