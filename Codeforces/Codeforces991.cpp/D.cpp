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
Navidad sin ti
*/

void solve(){
    string s; cin>>s;
    for(int i=1 ; i<(int)s.size() ; i++){
        int now=s[i]-'0', posi=0;
        bool ok=0;
        for(int j=i-1 ; j>=max(0, i-9) ; j--){
            now--;
            if(now==(int)s[j]-'0' || now<(int)s[j]-'0'){
                // dbg(now)
                // dbg(j)
                ok=1;
                posi=j+1;
                break;
            }
        }
        s[i]=(char)now+'0'+(ok?1:0);
        for(int j=i ; j>posi ; j--){
            swap(s[j], s[j-1]);
        }
    }
    cout<<s<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}