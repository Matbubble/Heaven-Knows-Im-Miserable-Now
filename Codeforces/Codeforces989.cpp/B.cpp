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
Na na na 
Kumbia King
*/

void solve(){
    int n, m, k; cin>>n>>m>>k;
    string s; cin>>s;
    int count=0, ans=0;
    for(int i=0 ; i<n ; i++){
        if(s[i]=='0') count++;
        else count=0;
        if(count==m){
            count=0;
            int now=0;
            ans++;
            while(now<k){
                if(i>=n) break;
                s[i]='1';
                now++;
                i++;
            }
            i--;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}