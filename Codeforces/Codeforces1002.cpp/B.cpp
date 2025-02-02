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
    int need=k/2, extra=n-need;
    vector<int>v(n);
    for(int &x:v) cin>>x;
    v.push_back(0);
    v.push_back(0);
    bool turn=0;
    int now=1;
    for(int i=0 ; i<n ; i++){
        if(!turn){
            i++;
            extra--;
            while(v[i]==now){
                if(need+extra>n-(i+1)-1) break;
                else i++;
            }
            i--;
            turn^=1;
        }else{
            need--;
            if(v[i]==now && need+extra>n-(i+1)-1){
                if(v[i+1]!=now+1){
                    cout<<now+1<<"\n";
                    return;
                }
            }else{
                cout<<now<<"\n";
                return;
            }
            now++;
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