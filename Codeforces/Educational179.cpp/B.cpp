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

vector<int>sobra;
void acomodar(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0 || sobra.empty()) return;
    int mini=min({a, b, c});
    for(int i=(int)sobra.size()-1 ; i>=0 ; i--){
        if(mini>=sobra[i]){
            int xd=sobra[i];
            sobra.erase(sobra.begin()+i);
            acomodar(a-xd, b, c);
            acomodar(xd, xd, c-xd);
            acomodar(a, b-xd, c);
            
            return;
        }
    }
}

void solve(){
    int n, m; cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        sobra.clear();
        for(int i=0 ; i<n ; i++){
            if(i==0) sobra.push_back(1);
            else if(i==1) sobra.push_back(2);
            else sobra.push_back(sobra.back()+sobra[(int)sobra.size()-2]);
            // dbg(sobra.back())
        }
        int a, b, c; cin>>a>>b>>c;
        acomodar(a, b, c);
        if(sobra.empty()) cout<<1;
        else cout<<0;
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}