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
    vector<int>v(n);
    int aux=0, maxi=0;
    for(int &x:v) cin>>x;
    for(int i=n-1 ; i>=0 ; i--){
        if(i==n-1) maxi=v[i];
        else{
            maxi=max(maxi, v[i]);
            if(v[i]<v[i+1]) aux=max(aux, maxi);
        }
    }
    bool ok=0, use=0;
    vector<int>ans;
    for(int i=0 ; i<n ; i++){
        if(!ok){
            if(v[i]<aux){
                ok=1;
                ans.push_back(aux);
                ans.push_back(v[i]);
            }else ans.push_back(v[i]);
        }else{
            if(v[i]==aux && !use){
                use=1;
                continue;
            }else ans.push_back(v[i]);
            
        }
    }
    stack<int>s;
    for(int i=0 ; i<n ; i++){
        if(s.empty()) s.push(ans[i]);
        else{
            while(!s.empty()){
                if(s.top()<ans[i]) s.pop();
                else break;
            }
            s.push(ans[i]);
        }
    }
    vector<int>xd;
    while(!s.empty()){
        xd.push_back(s.top());
        s.pop();
    }
    for(int i=(int)xd.size()-1 ; i>=0 ; i--){
        cout<<xd[i];
        if(i>0) cout<<" ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
        if(t>0) cout<<"\n";
    }
    return 0;
}