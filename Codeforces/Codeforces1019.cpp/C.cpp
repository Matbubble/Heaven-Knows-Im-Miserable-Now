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
    int n, k; cin>>n>>k;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    vector<int>pref;
    for(int x:v) pref.push_back(x<=k);
    //case 1
    {
        int l=-1;
        int a=0, b=0;
        for(int i=0 ; i<n ; i++){
            if(pref[i]==0) a++;
            else b++;
            if(a<=b){
                l=i;
                break;
            }
        }
        if(l>=0){
            int r=-1;
            a=0; b=0;
            for(int i=n-1 ; i>=0 ; i--){
                if(pref[i]==0) a++;
                else b++;
                if(a<=b){
                    r=i;
                    break;
                }
            }
            if(r>l+1){
                cout<<"YES\n";
                return;
            }
        }
    }

    //case 2
    {
        int a=0, b=0;
        set<int>ss;
        bool ok=0;
        for(int i=0 ; i<n-1 ; i++){
            if(pref[i]==0) a++;
            else b++;
            if(!ss.empty()){
                if(b-a>=*ss.begin()){
                    cout<<"YES\n";
                    return;
                }
            }
            if(a<=b){
                ss.insert(b-a);
            }
        }
        
    }
    reverse(pref.begin(), pref.end());
    //case 3
    {
        int a=0, b=0;
        set<int>ss;
        bool ok=0;
        for(int i=0 ; i<n-1 ; i++){
            if(pref[i]==0) a++;
            else b++;
            // dbg(a)
            // dbg(b)
            if(!ss.empty()){
                if(b-a>=*ss.begin()){
                    cout<<"YES\n";
                    return;
                }
            }
            if(a<=b){
                ss.insert(b-a);
            }
        }
    }
    cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}