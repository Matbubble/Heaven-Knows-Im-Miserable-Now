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
Step on me
The cardigans
*/

void solve(){
    int n, k; cin>>n>>k;
    string s; cin>>s;
    // if(n==1){
    //     cout<<(s[0]=='1'?0:1)<<"\n";
    //     return;
    // }
    int l=0, r=n-1;
    int sum1=0, sum2=0;
    while(s[l]=='0'){
        sum1++;
        l++;
    }
    while(s[r]=='0'){
        sum2++;
        r--;
    }
    if(r<l){
        cout<<(sum1+k)/(k+1)<<"\n";
    }else{
        int ans=((sum1)/(k+1))+((sum2)/(k+1));
        int aux=0;
        for(int i=l ; i<=r ; i++){
            if(s[i]=='0') aux++;
            else{
                ans+=(max(aux-k, 0)/(k+1));
                aux=0;
            }
        }
        ans+=((aux+k)/(k+1));
        cout<<ans<<"\n";
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