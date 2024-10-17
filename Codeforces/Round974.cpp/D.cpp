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
I love DP
*/

void solve(){
    int n, d, k; cin>>n>>d>>k;
    vector<pair<int, int> >freq(n+1);
    for(int i=0 ; i<k ; i++){
        int a, b; cin>>a>>b;
        freq[a].first++;
        freq[b].second++;
    }
    int l=1, r=1;
    int cont=freq[1].first;
    pair<int, int>A, B;
    A.first=1e9;
    B.first=0;
    bool ok=0;
    while(r<=n){
        if(r-l+1<d){
            r++;
            cont+=freq[r].first;
        }else if (!ok){
            if(r>n) break;
            if(cont<A.first){
                A.first=cont;
                A.second=l;
            }
            if(cont>B.first){
                B.first=cont;
                B.second=l;
            }
            ok=1;
        }else{
            cont-=freq[l].second;
            l++;
            r++;
            if(r>n) break;
            cont+=freq[r].first;
            if(cont<A.first){
                A.first=cont;
                A.second=l;
            }
            if(cont>B.first){
                B.first=cont;
                B.second=l;
            }
        }
        // dbg(cont)
        
    }
    cout<<B.second<<" "<<A.second<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}