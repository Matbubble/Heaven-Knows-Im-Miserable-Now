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
talento o esfuerzo
*/

void solve(){
    long long n, sum=0; cin>>n;
    vector<long long>v(n);
    for(long long &x:v){
        cin>>x;
        sum+=x;
    }
    if(sum%n>0){
        cout<<"NO\n";
        return;
    }
    sum=(sum)/n;
    // dbg(sum)
    for(int i=1 ; i<n-1 ; i++){
        while(v[i-1]!=sum){
            if(v[i-1]==0 || v[i+1]==0) break;
            if(v[i-1]>sum){
                v[i-1]--;
                v[i+1]++;
            }else{
                v[i-1]++;
                v[i+1]--;
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        if(v[i]!=sum){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}