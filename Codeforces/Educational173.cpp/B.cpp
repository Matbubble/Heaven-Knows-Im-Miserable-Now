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
La pareja ideal
Marisela
*/

void solve(){
    long long n, d; cin>>n>>d;
    vector<long long>fac;
    fac.push_back(1);
    while(fac.back()<=1e9){
        fac.push_back(fac.back()*(long long)(fac.size()));
    }
    if(n<=2){
        for(long long i=0 ; i<=4 ; i++){
            long long now=(2*i+1);
            if(d%now==0) cout<<now<<" "; 
        }
        cout<<"\n";
    }else{
        if(n<=5){
            cout<<1<<" "<<3<<" ";
            if(d%5==0) cout<<5<<" ";
            cout<<7<<" ";
            long long sum=fac[n]*d;
            if(sum%9==0) cout<<9<<"\n";
        }else{
            for(long long i=0 ; i<=4 ; i++){
                long long now=(2*i+1);
                if(now==5 && d!=5) continue;
                cout<<now<<" ";
            }
            cout<<"\n";
        }
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