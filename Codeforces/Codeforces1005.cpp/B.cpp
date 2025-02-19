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
    vector<int>v(n), freq(n+1);
    for(int &x:v){
        cin>>x;
        freq[x]++;
    }
    vector<int>posi;
    for(int i=0 ; i<n ; i++){
        if(freq[v[i]]==1) posi.push_back(i+1);
    }
    if(posi.empty()) cout<<0<<"\n";
    else{
        int maxi=0;
        int l=posi[0], r=posi[0];
        int auxl=l, auxr=r;
        for(int i=1 ; i<(int)posi.size() ; i++){
            if(posi[i]-1==posi[i-1]) auxr=posi[i];
            else{
                if(maxi<auxr-auxl){
                    maxi=auxr-auxl;
                    l=auxl; r=auxr;
                }
                auxl=posi[i];
                auxr=posi[i];
            }
        }
        if(maxi<auxr-auxl){
            maxi=auxr-auxl;
            l=auxl; r=auxr;
        }
        cout<<l<<" "<<r<<"\n";
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