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

int gcd(int a, int b){
    return (b==0?a:gcd(b, a%b));
}

void solve(){
    int x, y, k; cin>>x>>y>>k;
    int g=gcd(x, y);
    x/=g; y/=g;
    auto dp=[&](int a, int b){
        if(a==1) return 0;
        vector<int>div;
        for(int i=1 ; i*i<=a ; i++){
            if(a%i==0){
                div.push_back(i);
                div.push_back(a/i);
            }
        }
        sort(div.begin(), div.end());
        vector<int>dpsito((int)div.size(), 1e9);
        dpsito[0]=0;
        for(int i=1 ; i<(int)div.size() ; i++){
            for(int j=i-1 ; j>=0 ; j--){
                if(div[i]/div[j]>b) break;
                if(div[i]%div[j]==0){
                    dpsito[i]=min(dpsito[i], dpsito[j]+1);
                    // dbg(i)
                }
            }
        }
        return (dpsito.back()==1e9?-1:dpsito.back());
    };
    int a=dp(x, k), b=dp(y, k);
    if(a==-1 || b==-1) cout<<-1<<"\n";
    else cout<<a+b<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}