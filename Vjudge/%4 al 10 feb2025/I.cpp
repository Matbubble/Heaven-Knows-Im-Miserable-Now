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
    vector<int>v(n), ans(n);
    for(int &x:v) cin>>x;
    cout<<n-1<<"\n";
    for(int i=0 ; i<n-1 ; i++){
        if(i==0){
            int curr=min(v[i], v[i+1]);
            v[i]=curr+1; v[i+1]=curr;
            cout<<i+1<<" "<<i+2<<" "<<curr+1<<" "<<curr<<"\n";
        }else{
            int curr=min(v[i], v[i+1]);
            if(curr==v[i]){
                v[i+1]=curr+1;
                cout<<i+1<<" "<<i+2<<" "<<curr<<" "<<curr+1<<"\n";
            }else{
                if(curr%2==v[i]%2){
                    v[i]=curr;
                    v[i+1]=curr+1;
                    cout<<i+1<<" "<<i+2<<" "<<curr<<" "<<curr+1<<"\n";
                }else{
                    v[i]=curr+1;
                    v[i+1]=curr;
                    cout<<i+1<<" "<<i+2<<" "<<curr+1<<" "<<curr<<"\n";
                }
            }
        }
    }
    // for(int x:v) cout<<x<<" ";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}