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
    map<int, int>freq;
    vector<int>v(n);
    for(int &x:v){
        cin>>x;
        freq[x]++;
    }
    for(int x:v){
        if(freq[x]>=4){
            cout<<"Yes\n";
            return;
        }
        if(freq[x]>=2 && freq[x+1]>=1 && freq[x+2]>=2){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}